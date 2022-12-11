 
//--------------Digital Pot Write Code-------------------------------------

int LastWrite;    // the last value written to the digital pot

void digitalPotWrite(int address, int digitalPotvalue) {    // function takes in an address (try 0000) and a value or other function (++) )
  // take the SS pin low to select the chip:


 if (LastWrite != digitalPotvalue){            // if the last value IS NOT the same as the current digital pot value
  
  digitalWrite(slaveSelectPin, LOW);           // slave select pin low puts SLAVE into WRITE mode
  delay(1);
  //  send in the address and value via SPI:
  SPI.transfer(address);
  SPI.transfer(digitalPotvalue);
  delay(1);
  // take the SS pin high to de-select the chip:
  digitalWrite(slaveSelectPin, HIGH);            

 // Serial.println(DPV);
 }

 LastWrite = digitalPotvalue;                   // save the current pot value as the last pot value
}
