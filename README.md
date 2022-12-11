# TapDelay_PT2399
Tap Tempo Digital Pot current control for PT2399 delay chips


 Controls the delay time of PT2399 delay chips, by replacing the
 current sink Pot with a MCP41XXX Digital Pot.

Written by Imogen Wren Heard 10/2018

https://github.com/PanGalacticTech   <br>
https://github.com/ImogenWren    <br>

TapDelay PT2399 by Imogen W.H. is licensed under a     <br>
Creative Commons Attribution-ShareAlike 4.0 Interntional License.    <br>
To view a copy of this license, visit     <br>
http://creativecommons.org/licenses/by-sa/4.0/.     <br>


## Useage

To use this for any PT2399 based delay, remove the origonal "delay time" pot and solder the digital pot (wired as Rheostat) in its place.

This program uses either a tapped tempo, or a manual pot to set the resistance of the digital pot, in turn controlling the delay time for the PT2399 delay chip.

## Operation

Tapping the footswitch once starts the TappTimer, indicated by a **Solid Blue LED**. On a 2nd tap, the **Orange LED** will flash at the interval of the taps (i.e. at the tempo of the taps) and the **Blue LED* will turn off. The digital pot will update to reflect the new delay time.

If the TappTimer is started, but no 2nd tap is detected after 2 seconds, the unit will revert to its previous mode.

Move the pot at any time to set the delay time manually. It has a small deadband to protect against unintentionally triggering manual delay mode. 
**Manual Delay Time set** Is indicated by a **Flashing Blue LED**
   
   
## Pin Definition & Wiring Scheme
_MCP41XXXX Pot uses SPI for communication. Please find pin to pin connection notes below_
   
 ### Arduino Uno/Nano Connections
```
CS = D10    // Slave Select / Chip Select Pin     -- Braid
SCLK = D13  // Clock Pin                          -- Blue
MOSI = D11  // Master Out Slave In / SI           -- White
```
   
 ###  Digital Pot MCP41XXX Connections 
```
     Braid  -1| cs       V+ |8-
      Blue  -2| Sclk     PB |7-  | Pins 6 & 7 to PT2399 Current Sink (pin 6)
     White  -3| SI       PW |6-  | 
            -4| GND      PA |5-
            
```            
