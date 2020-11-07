# MusicalFloppyDrives
This uses Teensy USBMIDI to make music with Floppy Drives straight from your favorite DAW.

Uses Teensyduino's implementation for [USB MIDI](https://www.pjrc.com/teensy/td_midi.html) library for [Teensy microcontrollers](https://www.pjrc.com/teensy/ "Paul Stroffregen's microcontroller!"). It is so nicely documented all on a single web page!

I use a [Teensy 3.6](https://amzn.to/38mGWqI) which has many pins and a rated speed of 180MHz so I don't worry about pitch bend floating point calculations.

## Uploading

You will need [Teensyduino installed](https://www.pjrc.com/teensy/td_download.html) for this to work properly on a Teensy. The Teensy USB MIDI implementation is different from the [MIDIUSB](https://www.arduino.cc/en/Reference/MIDIUSB) Arduino library or the [USBMIDI](https://www.arduino.cc/reference/en/libraries/usbmidi/) Arduino library, so this code will not work on:

- Arduino Micro
- Arduino Leonardo
- Arduino Mega
- Arduino Nano
- Arduino Uno
- Arduino Yún

You will need to follow the instructions at the very beginning of the [Teensy USB MIDI](https://www.pjrc.com/teensy/td_midi.html) page to tell the arduino IDE to configure the Teensy controller as a USB MIDI device.

## Things to note

- You may need to edit the pins of course. The step and direction pins are listed in STEPPIN and  DIRPIN arrays with indices corresponding to midi channel (zeroeth index is skipped since MIDI starts with channel 1, not channel 0).

- Octaves 0 through 3 all have the same octave microperiods which are too low to be useful. Microperiods allotted to octaves 4-7 are the most appropriate for floppy drives.

- If you play the note G10 (note == 127) on any channel, this will "reset" *all* the drives by going in one direction for 200 steps to home at the end of travel. This can be useful between power cycles

- Name.c is included to give the USBMIDI device a name so that you can distinguish it from other MIDI devices in your DAW. So long as it is in the same folder as the .ino file while uploading, it should work. It is named 'MOPPY' in honor of Sam Archer's M_usical Fl_oppy drives which set the [YouTube](https://youtu.be/qWkUFxItWmU) ablaze only about a year after the arduino uno was released.

- This is can be used with any Digital Audio Workstation (DAW) that recognizes usb MIDI devices. DAWs usually cost money, though. There is a free MIDI editor which can save, edit, and playback MIDI files called [MidiEditor](https://www.midieditor.org/). I don't like it for editing. You might consider [BRELS midi editor](https://breno.sarmen.to/midi/) for editing, but it is very buggy. I use [FL Studio](https://www.image-line.com/) because it's great once you get the hang of it (Honestly, I only use it to edit, save, and compose MIDI files plus recording the audio from instruments; It is totally possible to ignore all the plugins and VSTs if you want to!).
