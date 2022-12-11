/*//--------------- PT2399 Tap Tempo Delay Controller-----------------------//

    Controls the delay time of PT2399 delay chips, by replacing the
    current sink Pot with a MCP41XXX Digital Pot.

   Written by Imogen Wren Heard 10/2018

   https://github.com/PanGalacticTech
   https://github.com/ImogenWren

   TapDelay PT2399 by Imogen W.H. is licensed under a
   Creative Commons Attribution-ShareAlike 4.0 International License.
   To view a copy of this license, visit
   http://creativecommons.org/licenses/by-sa/4.0/.
*/




//-------------------SPI Code And Constants-----------------------------------
#include <SPI.h>

//-------SPI Pins-----------
// set pin 10 as the slave select for the digital pot:
const int slaveSelectPin = 10;  // CS Chip select

// CS = D10    // Slave Select / Chip Select Pin     -- Braid
// SCLK = D13  // Clock Pin                          -- Blue
// MOSI = D11  // Master Out Slave In / SI           -- White

/*
  //------Digital Pot MCP41XXX Connections -----

     Braid  -1| cs       V+ |8-
      Blue  -2| Sclk     PB |7-  | These outputs to PT2399 Current Sink (pin 6)
     White  -3| SI       PW |6-  |
            -4| GND      PA |5-
*/

//------- Input & Output Pins--------------
const int buttonPin = 2;     // the number of the pushbutton pin

const int beatpinSlow = 3 ;  //Slow       // number of beat division select pins
const int beatpinFast = 4 ;  // Fast

const int OrangeLED =  5;      // the number of the LED pin
const int BlueLED =  6;      // the number of the LED pin
const int MasterClock = 8;     // Master Clock output squarewave LFO
const int DivisionClock = 9;   // Clock that outputs squarewave at beat division frequency
int PotPin = A5;             // sets Pot Input Pin Analogue 5

int PotRead1 = 500;            //Initial Value for potread


// ---- Sets up variables for LED State and Active LED------
int blueState = 0; // status of blue LED
int orangeState = 0; // status of Orange LED
int MasterClockState = 0;    // State of Master Clock
int DivisionClockState = 0;  // State of Division Clock

int activeLED = 1; // Sets which LED blinks in blink section 1= blue 2= orange

//-------TIMING VARIABLES------------------
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated
unsigned long previousMillis2 = 0;        // will store last time Clock Output was updated

unsigned long interval = 1000;           // Delay Interval MASTER VALUE - Used to Blink LED &
// Passed to beatDivision Function

int delayTime;                            // Interval x beatDivision Algorithm
// Passed to Delay to Resistance Calculation

int D2R;                               //Delay to Resistance Calculation, gives a result in kOHM passed onto digitalpotvalue
int DPV;                               // Digital Pot Value calculated from Kohm value

unsigned long speedTest = 0;                 // TEST value for testing overal speed of program

void setup() { //----------------- VOID SETUP ------------------------------------------------------


  // initialize the LED pin as an output:
  pinMode(OrangeLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);

  // initialize clock pins as output
  pinMode(MasterClock, OUTPUT);
  pinMode(DivisionClock, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  // set the slaveSelectPin as an output:
  pinMode(slaveSelectPin, OUTPUT);

  SPI.begin();

  Serial.begin(9600);

  PotRead1 = analogRead(PotPin);        // reads Potvalue for inital delaytime

  interval = PotRead1;

  interval = constrain(interval, 43, 700);     // Constrains Value between 42 ms & ______________


}

void loop() { //-----------------------MAIN LOOP-------------------------------------------




  //set up initial delay time from pot. returns delay interval and activeLED =1 for Blue LED
  //if pot is moved, button accumiator resets and delay value is read from pot again.
  //----------------------------------------------------------------
  // Initial Delay & Pot Read & Reset
  //-----------------------------------------------------------------

  PotRead();




  //---------------------- TAP TEMPO SECTION:----------------

  TapTempoV4(); // returns a value for interval + LED 2 active





  //------------LED Blink----------------------------------
  LEDblink(activeLED, interval);   // interval variable only shows the BEAT of the pot/Tap Tempo, no subdivisions





  //--------------------------- Beat Divisions----------------------

  beatDivision(interval);     // Calculates Beat Division and returns variable delayTime

  // Beat Divisions Description
  // Functon to generate exact delay timing based on tempo & Subdivisions.
  // min delay time = 30 ms, max = 700 ms
  // Uses INTERVAL as its "Beat"
  // Subdivisions are calculated from this to be passed to DelayToResistor as variable: delayTime

  //Includes switch read and mode select-----
  //Mode 1 (Switch Center)  - Quarter notes, Crotchets ----------- If Tapped on 1 & 2,
  // Delay Happens on (NOTE) & (2) & (3) & (4) &
  // delay time = Interval

  //Mode 2 (Switch Up) - Dotted Quater Notes, 1 1/2 Beats ---------If Tapped on 1 & 2,
  // Delay happens on (NOTE) & 2 (&) 3 & (4) &
  // delay time = Interval + interval/2  (Or interval x 1.5)


  //Mode 3 (Switch Down) - Dotted 8th Notes, 3/4 of a beat---------If Tapped on 1 & 2
  // Delay Happns on (NOTE) . & (.) 2 . (&) . 3 (.) & . (4) . & (.)
  // delay time = Interval x 0.75


  //------------------------- Clock Outputs ------
  //Function to Generate clock pulses from both master clock & beat division clock


  ClockOutput(interval, delayTime); // Uses function of interval for master clock, Delaytime for beat division.



  //-------------------------Delay to Resistance Value --------------------
  // Function to generate Resistance value of digital pot, based on delay time generated by tempo (inc any subdivisions)
  //

  DelaytoResistor(delayTime); // Returns DVP = DigitalPotValue


  // Write value to the Digital Pot
  digitalPotWrite(0000, DPV);                // set address as 0000 - seems to work, as does  0001 Further exploration required


  // Serial.println(DPV);

  //----------------------------------------------------------------
  //Debug  Section

  // Serial.println(millis()-speedTest);                // used to time loops for TESTING
  // speedTest = millis();

}
