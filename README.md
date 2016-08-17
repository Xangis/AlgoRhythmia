# AlgoRhythmia

AlgoRhythmia is a programmable virtual drum machine based on algorhythmic and
evolving beats. It was originally available at http://zetacentauri.com

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

# Requirements

This requires wxWidgets 3.0, libportaudio-dev, and libsndfile-dev. On Windows it
uses DirectX, and on Linux it theoeretically used libasound2-dev.

## Problems

On Windows, the app thrives. It requires AudioFile and wxAudioControls

On Linux, the app probably does not build, and if it did, would not produce any sound. That's
because the Windows version uses XAudio2 and the Linux version doesn't have a replacement
(that code is just commented out).

In the installer version, saving and loading of data files does not currently work.
The app uses XML files to save and load data, but they aren't written correctly.

This was recently fixed in SigmaTizm, so should be fixable in AlgoRhythmia.
