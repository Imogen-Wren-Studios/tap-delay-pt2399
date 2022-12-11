


unsigned long currentTimer0 = 500;   // Current timer feeds value to INTERVAL

//unsigned long currentTimer1= 500;    // Values set up to store values for later
//unsigned long currentTimer2 = 500;   // UNUSED At The Moment
//unsigned long currentTimer3 = 500;

long indicatorTimeout = 2000;  // Sets 2nd tap indicator TIMEOUT

unsigned long lastTap;

int TapRead1;         // Integer to store the value of the button tap

int buttonAcc;       // Accumilator to Count Button Taps.

int lastTapState = LOW;  // the last tap button state


//----------Tap Tempo Function Declaration----------------------------------------------

unsigned long TapTempoV4() {


  TapRead1 = digitalRead(buttonPin);                   // Store Value of first Tap


  //------------------------------------1st IF Function--------------------------------------------------


  if (TapRead1 == 1 && TapRead1 != lastTapState) {    // IF the new tapread is 1 && does not equal the last tap state


    /*
      currentTimer3 = currentTimer2;       // Save these values for later if needed
      currentTimer2 = currentTimer1;
      currentTimer1 = currentTimer0;         // None of this is actually used yet
    */

    currentTimer0 = millis() - lastTap ;     // Current timer = current time - the time of the last tap

    lastTap = millis();                      // Save the current time as the time of the last tap


    buttonAcc++;                              // Increase the button press accumilator


    activeLED = 2;                            // Switch the active LED to 2 (Orange)

    /*
      if (currentTimer0 > 700){
      currentTimer0=700;                     // Sets max delay to 700   UNUSED at the Moment
      }
    */

    if (buttonAcc == 2) {                               // IF the Button press accumilator == 2
      interval = (currentTimer0 / 2);                      // Sets INTERVAL to half of the current timer value
      //interval = ((currentTimer0 + currentTimer1)/2);

      interval = constrain(interval, 43, 2000);            // TEST CODE DELETE IF UNWORKABLE Constrains interval to useable delay time
      // Edit this line to set MAX or MIN Tap Delay Times.

      blueState = LOW;                                // Turn off the BLUE LED
      digitalWrite(BlueLED, blueState);

      buttonAcc = 0;                                  // Reset the Button Accumilator
      orangeState = HIGH;                             // Turn ON the ORANGE LED
      digitalWrite(OrangeLED, orangeState);

      MasterClockState = HIGH;                               // State of Master Clock
      DivisionClockState = HIGH;                              // State of Division Clock
      digitalWrite(MasterClock, MasterClockState);             // set clock outputs high so they are synced
      digitalWrite(DivisionClock, DivisionClockState);        // to start of beat
    }


  }  //--------------------------------------------------------------End of 1st IF Statement---------------------------------



  lastTapState = TapRead1;                                         // Saves the last Tapstate as a new integer


  if (buttonAcc == 1 && (millis() - lastTap) > indicatorTimeout) { // IF Button Acc is 1 and the current time - the last tap time
    buttonAcc = 0;                                                // is GREATER than the timeout time, buttonAcc Resets
  }


  if (buttonAcc > 0 ) {                                          // IF buttonAcc is greater than 0 Sets BLUE LED high as indicator system is
    blueState = HIGH;                                             // Waiting for second tap
    digitalWrite(BlueLED, blueState);
    //  Serial.println(" Waiting For Second Tap");                   // debug/funsies
  }

  else if (buttonAcc == 0 && activeLED == 2) {                  // Else if the buttonAcc is 0 and the ORANGE led is active,
    blueState = LOW;                                              // Sets BLUE led LOW.
    digitalWrite(BlueLED, blueState);
  }

  // Serial.print("Interval                     ");
  // Serial.println(interval);

}  //---------------------------------------------------------------End Of Function----------------------------------------------------------
