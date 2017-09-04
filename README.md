# AlgoRhythmia

AlgoRhythmia is a programmable virtual drum machine based on algorhythmic and
evolving beats. 

It was originally available at http://zetacentauri.com and was downloaded more 
than 50,000 times before being open-sourced.

Main Window:

![AlgoRhythmia Screenshot](https://github.com/Xangis/AlgoRhythmia/blob/master/images/AlgoRhythmia4.png)

Pattern Editor:

![AlgoRhythmia Drum Grid](https://github.com/Xangis/AlgoRhythmia/blob/master/images/AlgoRhythmia4DrumGrid.png)

It is an 8-channel drum machine and beat generator. It supports .wav sample playback
and MIDI. It generates patterns up to 4 measures long in any of six time signatures
and at virtually any BPM. It allows the user to mutate or regenerate any or all of
the drum sounds in a pattern or to edit them by hand via the pattern editing window.

This is a great creative tool for inspiring new ideas, practicing along to strange
beats, or just tinkering for fun. With the ability to export patterns to MIDI, 
you can generate beats for use in your favorite sequencer or looping program.

AlgoRhythmia uses DirectX 9 (or newer). If you do not have DirectX 9, visit Microsoft's
download site to download or update the DirectX redistributable.

A prebuilt installer for Windows is available in the installer folder.

Just over 100 royalty-free samples recorded by me are included in this project. Your best
source of free .wav samples is http://freewavesamples.com and that's where all of the
original samples came from. However, that site has far more samples than were ever
included in AlgoRhythmia thanks massive growth of the free sample library in 2015 and 2016.

## Building

This application is written in C++ and requires wxWidgets 3.0, SDL2, SDL2_mixer, 
RtMidi, and libsndfile-dev.

It also requires the following libraries:

- AudioFile via https://github.com/Xangis/AudioFile
- wxAudioControls via https://github.com/Xangis/wxAudioControls

Each of these should be checked out into directories adjacent to Sigmatizm (same parent).

### Windows

A Visual Studio solution is included, but you'll need to edit the include and library paths
to match where you've put the library dependencies.

In addition, you'll need to copy SDL2.dll and SDL2_mixer.dll into the directory you want to
run the application from (Debug, or Release, for example).

### Linux

You may need to edit paths in the Makefile.linux makefile in order to build. To build, run
make -f Makefile.linux

### OSX

At one point I tried to build a version of this for the Apple store. I did not succeed,
but did get a working OSX build on my machine.

This application will theoretically build on OSX, but the process probably needs some work.
There is a shell script called OSXLibraryPaths.sh in the installer directory that should
help with setting library paths, and a package.sh script in the same file that goes through
some of the process of code signing.

## Changelog

### Changes Still Needed

Windows version needs to be ported to SDL.

### Changes from AlgoRhythmia Version 4.2 to 4.21 (September 2017):

- Ported Windows version to use SDL and SDL_mixer instead of XAudio2 so
  that it matches the Linux and OSX versions.

### Changes from AlgoRhtyhmia Version 4.1 to 4.2 (October 2016):

- Replaced WinMM MIDI engine with RtMidi engine for cross-platform compatibility.
- Ported XAudio2 to SDL for OSX version (Windows version still uses XAudio2).
- Help button for OSX to launch PDF manual.

### Changes from AlgoRhythmia Version 4.1 to 4.2 (October 2016):

- Improved MIDI file writing -- includes note off messages and always writes to channel 10.
- Switched to SDL for OSX and Linux. (should switch for Windows too, but need to verify).
- Switched to RtMidi for MIDI messages.
- Default MIDI output channel is now 10.

### Changes from AlgoRhythmia Version 4 to 4.1 (August 2016):

- Replaced entire sample set of 76 files with one ENTIRELY from freewavesamples.com,
with 100 samples, AND with names identical to those from FWS instead of those weird
DOS-style filenames we had. Also adjusted default starting drum sounds.
- Updated libsndfile and wxWidgets libraries.
- Added General MIDI Level 2 drum notes to MIDI note list.
- Bug fixes related to sample loading and voice allocation.
- Bug fixes in pattern save and load.

### Changes from AlgoRhythmia Version 3 to 4:

- Replaced the DirectMusic sound generation engine with XAudio2. DirectMusic
is no longer supported by Microsoft and does not work on 64-bit systems. 
AlgoRhythmia 4 now works on 64-bit Windows.
- User interface was modified to properly handle the 125% zoom level on Windows 
7 and Vista.
- Added more samples to the full version.

Changes version 2 to 3:

- Added Fibonacci, Sierpinski, and Sierpinski inverted to base pattern list.
- Converted application to use wxWidgets.
- Kick sample (first sample) also plays when 'kick on first beat' is selected.
- Added save and load of settings.
- Added ability to edit individual drum notes on a grid.
- Added swing setting.
- Added volume setting for individual samples which affects both MIDI and sample volume.
- Added 58 samples recorded from the Yamaha TG-55 tone generator.
- Now accepts mutation rate values of 0.
- Added ability to save to MIDI.
- Added 8 different effect types: Chorus, compression, distortion, echo, flange, 
gargle, parameteric eq, and reverb

Changes version 1 to 2:

- Added invert buttons.
- Changed from fixed drum sounds to user-selectable drum sounds.
- Switched to a multithreaded model so that changes could be made to settings 
without causing playback to stop or stutter.
- Added sample playback.
- Added ability to select MIDI channel and device.
- Added mutation every X bars.
- Added display and hand-editing of pattern data.
- Added ability to vary volume to make pattern sound vaguely more "Human".
- Added "emphasize beats" option to emphasize the one beat of each measure.
   Technically it actually de-emphasizes every other beat.
- Added base patterns so that drum beats could be initialized with "normal"
   sounding beats and tweaked from there.

## Known Issues

Individual sample .wav file volume controls are not working right now, but MIDI
volume controls do work.

## Development Status

I currently maintain this application and am willing to accept pull requests if
you have improvements to contribute.

Since this has only been developed on my own machines, some of the build process
and environment settings may be specific to how I do things, so there is 
probably room to contribute build process improvements.

There are not currently any new features planned.
