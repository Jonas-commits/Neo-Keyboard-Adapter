# Setup Hardware
## Without PCB
![view1](fix.jpg)
- 1: Take the Mirco UBS Host shield and cut the VBus Wire at the Spot marked in yellow. [Doublecheck](#Doublechecking-the-cut) the cut.
- 2: Solder a new wire to the pin marked in orange. This will be soldered directly to the RAW Pin of the Arduino Mirco

![view2](button_top.jpg)
- 3: Solder a wire to the reset pin of the host shield. (yellow circle 3rd from the left).
- 4: solder the pin headers to the Arduino. The yellow marked spots are the pins that have to be connected mandatorily. For convenience, I recommend cutting the pin headers to the length marked in green, as interconnecting the other pins does not hurt and is much faster
- 5: Before soldering the pin headers, solder the new VBus power line added in (2) directly to the RAW port of the Arduino. Leave just enough space, that you can connect the Arduino top to top as seen in the picture.
- 6: Place the host shield onto the pin headers from the Arduino micro.
- 7: solder the added reset cable from (3) to the VCC pin along with the pin from the Pin header. (yellow circle 4th from the left).
- 8: Solder the remaining pins.



## With PCB
![view1](fix.jpg)
- 1: Take the Mirco UBS Host shield and cut the VBus Wire at the Spot marked in yellow. [Doublecheck](#Doublechecking-the-cut) the cut.
- 2: Solder both components to the board (populate all pins for which a hole is at the corresponding position of the board)
- 3: If you have a revision 1.0 board, solder a wire as shown:
  ![view2](PCBBack.png)

### Doublechecking the cut
You should measure with a multimeter for continuity. The result should be an open loop (OL) - at least for my crappy multimeter. With a very good one you might be able to measure a quite high resitance. If you're not sure about the result, please consult a professional. 

![view1](Cut.png)