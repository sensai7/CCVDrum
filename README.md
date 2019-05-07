# CCVDrum
Energia code and Kicad files for a Korg Volca Drum MIDI CC board

![Board](https://i.imgur.com/UoVhIPl.png)

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

Some features:

* The board is designed to fit inside a 1590B enclosure, a really common 
and cheap enclosure model for guitar pedals.
* The power plug is a 2.1mm barrel jack and with the current Voltage Regulator 
model, Voltages from 5V to 20V are fine.
* There's a optional MIDI input to use as MIDI thru if you need to chain your 
devices.

The Volca must be [up to date](https://www.korg.com/us/support/download/product/0/809/#software), or at least in version 1.11 which changed a critical bug on the MIDI implementation (BIT knob won't work and the others would be changed). It must also be set in Split Channel Mode, the CC messages needed (BIT, DRV,... etc) are not available in the Single Channel Mode. My unit came with Split mode by default, but to check and change it, turn it on while holding ●RECORD, then press one of the channels to select it, then press it again to change it to channels 1-6. Press the ●RECORD button again when your unit's screen shows [MID 1--6](https://i.imgur.com/e5hpA2r.jpg).

The easiest way to flash a different firmware would be owning a MSP430G2 
(MSP-EXP430G2) launchpad, or the newer MSP430G2ET (MSP-EXP430G2ET) LaunchPad, 
place your MCU in the LaunchPad socket and flash the new code using Energia. 

Useful links

 * Korg Volca Drum official site: https://www.korg.com/us/products/dj/volca_drum/
 * Energia Project site: http://energia.nu
 * KiCad footprints and 3D models http://smisioto.no-ip.org/elettronica/kicad/kicad-en.htm

Datasheets

 * MSP430G2553 Mixed Signal Microcontroller http://www.ti.com/lit/ds/symlink/msp430g2553.pdf
 * 6N139 High Speed Optocoupler https://www.vishay.com/docs/83605/6n139.pdf
 * 74HC14 Hex inverting Schmitt trigger https://assets.nexperia.com/documents/data-sheet/74HC_HCT14.pdf
 * LM1117IMP-3.3 LDO Voltage Regulator http://www.ti.com/lit/ds/symlink/lm1117.pdf
 
 (Only in older versions):
 * AMS1117-3.3 1A LOW DROPOUT VOLTAGE REGULATOR http://www.advanced-monolithic.com/pdf/ds1117.pdf
 * 74AUP1G17 SINGLE SCHMITT-TRIGGER BUFFER https://www.diodes.com/assets/Datasheets/74AUP1G17.pdf

TODO

 * Fix minor bugs
