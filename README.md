# CCVDrum
Energia code and Kicad files for a Korg Volca Drum MIDI CC board

![Board](https://i.imgur.com/Zrqd26e.png)

In the Korg Volca Drum there's a hidden menu when you press the edit/step to 
change five adittional settings for each part and layer: bit resolution, 
overdrive, wave folding, pan, and pre-amp gain.

This repository contains the code, schematic, and PCB files to build and 
program a circuit board to control the 'hidden' paramenters from a Korg Volca 
Drum, having one dedicated knob control for each one and being able to select 
the first, second, or both layers with the provided push buttons. 
The circuit is based on a MSP430G2553, a common and cheap microprocessor from 
Texas Instruments, and it's coded in Energia, an Arduino port for TI 
processors, bringing the simplicity of the Wiring language and the huge 
Arduino community projects available to the Texas Instruments MCU ecosystem.

The easiest way to flash a different firmware would be owning a MSP430G2 
(MSP-EXP430G2) launchpad, or the newer MSP430G2ET (MSP-EXP430G2ET) LaunchPad, 
place your MCU in the LaunchPad socket and flash the new code using Energia. 
But if for any reason you want to flash the MCU on-board, the PCB has a 'JTAG' 
section to easily flash a new firmware or code mod. For doing so, I suggest 
following the tutorial [here](http://www.kerrywong.com/2012/04/02/using-msp430-launchpad-as-programmer/).

The Volca must be set in Split Channel Mode. The CC messages needed (BIT, 
DRV,... etc) are not available in the Single Channel Mode. To set your Volca 
Drum on Split Channel Mode turn it on while holding MEMORY, press one of the 
channels to select it, then press it again to change it to channels 1-6.

Useful links

 * Korg Volca Drum official site: https://www.korg.com/us/products/dj/volca_drum/
 * Energia Project site: http://energia.nu
 * KiCad footprints and 3D models http://smisioto.no-ip.org/elettronica/kicad/kicad-en.htm

Datasheets

 * MSP430G2553 MIXED SIGNAL MICROCONTROLLER http://www.ti.com/lit/ds/symlink/msp430g2553.pdf
 * AMS1117-3.3 1A LOW DROPOUT VOLTAGE REGULATOR http://www.advanced-monolithic.com/pdf/ds1117.pdf
 * 74AUP1G17 SINGLE SCHMITT-TRIGGER BUFFER https://www.diodes.com/assets/Datasheets/74AUP1G17.pdf

TODO

 * Testing.
