# CCVDrum
Energia code and Kicad files for a Korg Volca Drum MIDI CC board

![Board](https://i.imgur.com/yiM4Lcg.jpg)

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

It's possible to select the MIDI channel by having the the DRV, FLD, PAN and 
GAN potentiometers all the way down or up when the board is being powered up, 
being the minimum value a '0' and the maximum value a '1', the combination of 
these 4 "binary" values is the selected channel, being DRV the most 
significant bit and GAN the least significant bit.

Useful links

 * Korg Volca Drum official site: https://www.korg.com/us/products/dj/volca_drum/
 * Energia Project site: http://energia.nu
 * KiCad footprints and 3D models http://smisioto.no-ip.org/elettronica/kicad/kicad-en.htm

Datasheets

 * MSP430G2553 MIXED SIGNAL MICROCONTROLLER http://www.ti.com/lit/ds/symlink/msp430g2553.pdf
 * AMS1117-3.3 1A LOW DROPOUT VOLTAGE REGULATOR http://www.advanced-monolithic.com/pdf/ds1117.pdf
 * 74AUP1G17 SINGLE SCHMITT-TRIGGER BUFFER https://www.diodes.com/assets/Datasheets/74AUP1G17.pdf

TODO

 * The MIDI implementation is finally out and there are two modes available, a 
 MIDI channel per part a la Volca Sample or a single channel for all. I'm 
 still undecided about what path to choose first, but both are certainly 
 possible  the addition of at least two pushbuttons, regrettably the LEDs will 
 have to  be removed, as the GPIO pins are going to be necessary for a non 
 aestethical feature.