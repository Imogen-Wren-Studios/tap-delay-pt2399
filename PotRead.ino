
 //set up initial delay time from pot. 
 //if pot is moved, button accumiator resets and delay value is read from pot again.
 //----------------------------------------------------------------
// Initial Delay & Pot Read & Reset
//-----------------------------------------------------------------
int PotRead2;

 int PotRead(){


 // read the value from the Pot:
  PotRead2 = analogRead(PotPin);

//Serial.println(PotRead2);
// Serial.println(PotRead1);

  //if (PotRead2  PotRead1){
 int difference = PotRead1-PotRead2;

    if (abs(difference) > 5) {
 


     interval = (PotRead2)+30; 
     
      
     activeLED = 1;
     
// Serial.print("interval                                                       "); 
// Serial.println(interval);   // debug line
 
     orangeState = LOW;    
      digitalWrite(OrangeLED, orangeState);     
    
     PotRead1 = PotRead2;

  }

 interval = constrain(interval, 43, 700); //  +30 set min delay time at 30 ms 
 Serial.println(interval);
 // Serial.println(PotRead1);
 }
