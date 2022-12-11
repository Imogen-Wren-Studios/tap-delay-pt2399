

/*

  // LED Blip Section, takes in delay time and active LED number (1 or 2) and blinks the LED
  in time with the delay
*/



//-------------------------------------------------------------------------
// LED BLINK CODE:
//-----------------------------------------------------------------

// check to see if it's time to blink the LED; that is, if the difference
// between the current time and last time you blinked the LED is bigger than
// the interval at which you want to blink the LED.
// unsigned long currentMillis = millis();

int LEDblink(int activeLED, unsigned long interval) {  //

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:

    // activeLED = 1;  // test function sets active LED

    //---Blue
    if (activeLED == 1) {
      orangeState ==  LOW;
      if (blueState == LOW) {
        blueState = HIGH;
      } else {
        blueState = LOW;
      }
    }

    //--- Orange
    if (activeLED == 2) {
      blueState == 0;
      // if the LED is off turn it on and vice-versa:
      if (orangeState == LOW) {
        orangeState = HIGH;
      } else {
        orangeState = LOW;
      }
    }

  }

  // set the LED with the ledState of the variable:

  digitalWrite(OrangeLED, orangeState);
  digitalWrite(BlueLED, blueState);


}
