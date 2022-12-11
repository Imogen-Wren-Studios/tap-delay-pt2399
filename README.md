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

## Operation Modes

### Manual Mode

Move the pot at any time to set the delay time manually. It has a small deadband to protect against unintentionally triggering manual delay mode. 
**Manual Delay Time set** Is indicated by a **Flashing Blue LED**

### TappTimer Active

Tapping the footswitch once starts the TappTimer, indicated by a **Solid Blue LED** and a **Flashing Orange LED** at the currently set Tempo. <br>

On a 2nd tap, unit indicates new tempo with **Flashing Orange LED** and turns **Blue LED Off** 
_The digital pot will update to reflect the new delay time._

If the TappTimer is started, but no 2nd tap is detected after 2 seconds, the unit will revert to its previous mode.

### SubDivision Switch

While TappTimer is active, the SubDivision switch sets the delay time to one of 3 different beat or tempo subdivisions.

***NOTE: Repeat Pattern assumes that TappTimer was tapped on Beats 1 and 2 for each mode, and that the first note being sampled (Designated SN:1 for Sampled Note) is played on beat 1 of the bar. Delayed notes are designated by brackets ().***

#### Subdivisions Table
| Mode | Switch Position | Note Length                    | Repeat Pattern*                                | Algorithm Used                                         |
|---   |---              |---                             |---                                             |---                                                     |
|Mode 1| (Switch Center) |Quarter notes, Crotchets        | (SN:1) & (2) & (3) & (4) &                     | delay time = Tap Interval                              |
|Mode 2| (Switch Up)     |Dotted Quater Notes, 1 1/2 Beats| (SN:1) & 2 (&) 3 & (4) &                       | delay time = Interval + interval/2  (Or interval x 1.5)|
|Mode 3| (Switch Down)   |Dotted 8th Notes, 3/4 of a beat | (SN:1) . & (.) 2 . (&) . 3 (.) & . (4) . & (.) | delay time = (BPM/4)\*3             (Or Interval x 0.75|                  
   
   
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
