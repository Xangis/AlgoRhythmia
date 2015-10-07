#ifndef _PRESETDRUMPATTERN_H_
#define _PRESETDRUMPATTERN_H_

#define DRUM_MAX 8
#define MAX_PATTERN_LENGTH 88

struct PresetDrumPattern
{
    int timeSignature;
    int midiNote[DRUM_MAX];
    bool data[DRUM_MAX][MAX_PATTERN_LENGTH];
};

#endif