# CCVDrum
Energia code and Kicad files for a Korg Volca Drum MIDI CC board

In the Korg Volca Drum there's a hidden menu when you press the edit/step to 
change five adittional settings for each part: bit resolution, overdrive, wave 
folding, pan, and pre-amp gain.

This repository contains the code, schematic, and PCB files to build and 
program a circuit board to control the 'hidden' paramenters from a Korg Volca 
Drum, having one dedicated knob control for each one. The circuit is based on
a MSP430G2553, a common and cheap microprocessor from Texas Instruments, and
it's coded in Energia, an Arduino port for TI processors, bringing the 
simplicity of the Wiring language and the huge Arduino community projects 
available to the Texas Instruments MCU ecosystem.

The board has a 'JTAG' section to easily flash a new firmware or code mod.

Useful links

Korg Volca Drum official site: https://www.korg.com/us/products/dj/volca_drum/
Energia Project site: http://energia.nu

Datasheets

MSP430G2553 MIXED SIGNAL MICROCONTROLLER http://www.ti.com/lit/ds/symlink/msp430g2553.pdf
AMS1117-3.3 1A LOW DROPOUT VOLTAGE REGULATOR http://www.advanced-monolithic.com/pdf/ds1117.pdf
74AUP1G17 SINGLE SCHMITT-TRIGGER BUFFER https://www.diodes.com/assets/Datasheets/74AUP1G17.pdf

TODO

 * Add a Bill Of Materials txt
 * Change the midi CC numbers once the Midi implementation is available on 
 Korg's site. The current numbers are a placeholder.
