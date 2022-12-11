
//-------------Code to send clock pulses on pins 8   &    9--------------------

/*
    MasterClock = 8;     // Master Clock output squarewave LFO
    DivisionClock = 9;
 * 
 * int MasterClockState = 0;    // State of Master Clock
   int DivisionClockState = 0;  // State of Division Clock
 * 
 */


void ClockOutput(long MasterClockTime, long DivisionClockTime){


 unsigned long currentMillis2 = millis();                       // save current time

 
//------Master Clock Code-----------------

  if (currentMillis2 - previousMillis2 >= MasterClockTime) {
    // save the last time you blinked the LED
     previousMillis2 = currentMillis2;

  // if the Clock is LOW turn it HIGH and vice-versa:
     
    if (MasterClockState == LOW) {
      MasterClockState = HIGH;
    } else {
      MasterClockState = LOW;
    }
    
    digitalWrite(MasterClock, MasterClockState);
 
  }
    

  //------Division Clock Code-----------------

  if (currentMillis2 - previousMillis2 >= DivisionClockTime) {
    // save the last time you blinked the LED
     previousMillis2 = currentMillis2;

  // if the Clock is LOW turn it HIGH and vice-versa:
     
    if (DivisionClockState == LOW) {
      DivisionClockState = HIGH;
    } else {
      DivisionClockState = LOW;
    }
    
    digitalWrite(DivisionClock, DivisionClockState);
 
  }
    
      


}




  
