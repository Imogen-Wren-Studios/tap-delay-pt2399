

/*--------------------------------------------------------------------------------
 * Delay msecs = (11.46 * Resistance KΩ) + 29.70
   Delay msecs = (683.21 / Clock Freq MHz) + 0.08
   Delay msecs = (683.21 * Clock Period usecs) + 0.08
   Delay msecs = (28.65/Current mA) + 29.70
   Current mA = 28.65 / (Delay msecs - 29.70)
 * 
 * 
 * 
 * Relationship of resistance and delay time is linear! 
 * - Use least Squares Method to find line of best fit for graph on PT2399 datasheet

    Delay msecs = (11.46 * Resistance KΩ) + 29.70
 * 
 * 
 * Delay msecs = (11.46 * 2.5 / Current mA) + 29.70 = (28.65 / Current mA) + 29.70
 * 
 * 
 * Current mA = 28.65 / (Delay msecs - 29.70)
 */




/*---------------------------------------TABLE-------------------------------------
 * 
 * 

|R        |Fclk     |  Delay      |   
|---      |---      |---          |
|27.6 KΩ  | 2 MHz   | 342 msecs   |
|21.3 KΩ  | 2.5 MHz | 273 msecs   |
|17.2 KΩ  | 3 MHz   | 228 msecs   |
|14.3 KΩ  | 3.5 MHz | 196 msecs   |
|12.1 KΩ  | 4 MHz   | 171 msecs   |
|10.5 KΩ  | 4.5 MHz | 151 msecs   |
|9.2 KΩ   | 5 MHz   | 136.6 msecs |
|8.2 KΩ   | 5.5 MHz | 124.1 msecs |
|7.2 KΩ   | 6 MHz   | 113.7 msecs |
|6.4 KΩ   | 6.5 MHz | 104.3 msecs |
|5.8 KΩ   | 7 MHz   | 97.1 msecs  |
|5.4 KΩ   | 7.5 MHz | 92.2 msecs  |
|4.9 KΩ   | 8 MHz   | 86.3 msecs  |
|4.5 KΩ   | 8.5 MHz | 81 msecs    |
|4 KΩ     | 9 MHz   | 75.9 msecs  |
|3.4 KΩ   | 10 MHz  | 68.1 msecs  | 
|2.8 KΩ   | 11 MHz  | 61.6 msecs  |
|2.4 KΩ   | 12 MHz  | 56.6 msecs  |
|2 KΩ     | 13 MHz  | 52.3 msecs  |
|1.67 KΩ  | 14 MHz  | 48.1 msecs  |
|1.47 KΩ  | 15 MHz  | 45.8 msecs  |
|1.28 KΩ  | 16 MHz  | 43 msecs    |
|1.08 KΩ  | 17 MHz  | 40.6 msecs  |
|0.894 KΩ | 18 MHz  | 38.5 msecs  |
|0.723 KΩ | 19 MHz  | 36.6 msecs  |
|0.519 KΩ | 20 MHz  | 34.4 msecs  |
|0.288 KΩ | 21 MHz  | 32.6 msecs  |
|0.005 KΩ | 22 MHz  | 31.3 msecs  |


 * 
 */



 /*------- Current Max on Arduino Output Pins--------------
  * 
  * 40mA MAX per Pin
  * 
  * 20mA x 10 outputs = 200mA   ----- WILL DESTROY ARDUINO
  * 
  * 20mA Optimum per output
  * 
  * 
  * 
  * V = IR
  * I = V/R
  * 
  *  5 v/220 ohm = 23 mA  
  *  5 v/330 ohm = 15 mA
  *
  * 
  */
 
