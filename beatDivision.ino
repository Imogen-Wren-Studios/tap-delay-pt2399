//-----Beat Division Algorithm----------
// Functon to generate exact delay timing based on tempo & Subdivisions.
// min delay time = 30 ms, max = 700 ms
// Uses INTERVAL as its "Beat"
// Subdivisions are calculated from this to be passed to DelayToResistor as variable: delayTime

//----------------------------------------MODE DESCRIPTIONS---------------------------

//Includes switch read and mode select
//Mode 1 (Switch Center)  - Quarter notes, Crotchets ----------- If Tapped on 1 & 2,
// Delay Happens on (NOTE) & (2) & (3) & (4) &
// delay time = Interval

//Mode 2 (Switch Up) - Dotted Quater Notes, 1 1/2 Beats ---------If Tapped on 1 & 2,
// Delay happens on (NOTE) & 2 (&) 3 & (4) &
// delay time = Interval + interval/2  (Or interval x 1.5)


//Mode 3 (Switch Down) - Dotted 8th Notes, 3/4 of a beat---------If Tapped on 1 & 2
// Delay Happns on (NOTE) . & (.) 2 . (&) . 3 (.) & . (4) . & (.)
// delay time = Interval x 0.75

//----------------------Variables--------------------------
int MODE = 1;

// float Mode2 = 1.5  ;  //Selects Beat division modifyer for modes 2 & 3  NOT NEEDED NOW TO AVOID FLOATING POINT MATHS
// float Mode3 = 0.75  ; 

// Alternative beat divisions to try( 0.66, 0.25, 0.5, 2, 0.33, 1.61803398875(golden ratio) )

//--------------------------beat Division Function-------------------------------------


void beatDivision(long BPM){                     // Takes in INTERVAL as inital BPM Value

int beatSelectSlow = digitalRead(beatpinSlow);                // Read both button pins to decide which beat 
int beatSelectFast = digitalRead(beatpinFast);              // Modifyer to use

//----Sets Mode Variable-- Can be used later to set other options------------
 if(beatSelectSlow == 0 && beatSelectFast == 0){                     // If both Beat Select Pins LOW  Select MODE 1

 MODE = 1;
  
  }
 else if(beatSelectSlow == 1 && beatSelectFast == 0 ){                //if beat pin slow = 1     Select MODE 2

  MODE = 2;
 }
 else if(beatSelectSlow == 0 && beatSelectFast == 1 ){                // if beat pin FAST = 1  Select MODE 3
  
  MODE = 3;
 }

// Serial.println (MODE);

//--------- Sets up beat divisions based on MODE selected-------

 if (MODE == 1){                               // MODE ONE --- On Beat
  
  delayTime = BPM;  
  
 }
 
 else if (MODE == 2){                        // Mode Two --- 1.5 beats. or BPM+(BPM/2) 
  
  delayTime = BPM + (BPM/2);                    // 1.5 beats
  // delayTime = BPM * 1.25;                     // 
 }
 
 else if (MODE == 3){                         // Mode Three -- 0.75 beats. Or (BPM/4)*3              

  delayTime = (BPM/4)*3;
  
 }

// Serial.print("Delay Time                                                         ");
//Serial.println (delayTime);
 
} //--------------------------End of Function -------------------------------------
