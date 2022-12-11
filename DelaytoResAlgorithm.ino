// Delay msecs = (11.46 * Resistance KΩ) + 29.70

// 

// Resistance in kohm per division = 100k/255 = 0.392 kohm per division

/* --------------------------EQUATIONS-------------------------
 * 
 * Therefore:
 * 
 * Resistance (kohm) = (Delay(ms)-29.70/11.46)
 * 
 * Digital Pot Value = (Resistance(-10k)/0.392)  
 * 
 * 
 * DPV - 10k for min resistor   OR NOT MADE WORSE
 */

int DPV2;

//float MOD = -1.2; //Modifyer for timing // POSITIVE numbers Drag the beat, NEGATIVE numbers lead the beat
//int MOD = -2;
int MOD = 0;
 // MOD of -1.5 works for faster speeds, for slower speeds
 // MOD needs to be _________
 
void DelaytoResistor(int delayLengthActual){

  
// int ResistorKohm = (delayLengthActual - 29.70)/11.46;  // int for faster processing
   float ResistorKohm = (delayLengthActual - 29.70)/11.46;  // float for greater accuracy
       
  //int DPV1 = (ResistorKohm-0.5)/0.392;                // added in -0.5k to improve timing
 //int DPV1 = (ResistorKohm)/0.392;                       // No Timing Modifyer
  float DPV1 = (ResistorKohm+MOD)/0.392;                    //
    
 //   int difference2 = DPV1-DPV2;

  //  if (abs(difference2) > 2) {
   
     DPV = DPV1;  
//}


   DPV2 = DPV1;


  
}
