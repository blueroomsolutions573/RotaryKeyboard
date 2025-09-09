\# RotaryKeyboard Library



RotaryKeyboard is a lightweight Arduino library for creating menus and character selection keyboards on 20x4 LCDs using a rotary encoder and pushbutton.



\## Features



\- Scrollable character keyboard

\- Custom characters (arrow, save, cancel, backspace)

\- Single click, long press, double click support

\- Fully OOP for easy integration

\- Example sketch included for quick start



\## Example Usage



Check the `examples/StarterMenu` folder for a fully working example.
There is a simulation ready for copying at [RotaryKeyboard Simulation](https://wokwi.com/projects/441642530815823873)
It is the example sketch provided in the library repo. 
-A long press opens a menu which is scrollable with the encoder. 
-A click on one of the set parameter items will open the RotaryEncoder
-A scroll through the characters and select each with a single click.
-A double click cancels the keyboard operation
-A long press accepts the selected characters into the function provided to the RotaryKeyboard
-There are three custom characters a custom lessthan for backspace, a custom X for cancel and a keyboard{enter} symbol which will initiate the save function provided.


