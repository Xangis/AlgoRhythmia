/*
   Copyright 1997 Tim Kientzle.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
      This product includes software developed by Tim Kientzle
      and published in ``The Programmer's Guide to Sound.''
4. Neither the names of Tim Kientzle nor Addison-Wesley
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL TIM KIENTZLE OR ADDISON-WESLEY BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef MIDI_H_INCLUDED
#define MIDI_H_INCLUDED
#include "audio.h"
#include <iostream>
#include <cmath>

bool IsMidiFile(istream &file);

class MidiRead;

class MidiInstrumentMap {
private:
   AbstractInstrument *_instr;
public:
   enum {gmMelodyBank = 0, gmRhythmBank = (0x7f<<7)};

   MidiInstrumentMap() {
//      _instr = new PluckedStringInstrument;
      _instr = new SineWaveInstrument;
   };
   ~MidiInstrumentMap() { delete _instr;  };
   AbstractInstrument *Instrument(int bank, int program, int note);
   void SamplingRate(long s) {
      _instr->SamplingRate(s);
   }
};
class MidiTuningMap {
public:
   float Tuning(int, int note) {
      return 440.0*pow(2.0,(note-69)/12.0);
   }
};
// A channel keeps track of currently playing notes
class MidiChannelAbstract {
public:
   virtual ~MidiChannelAbstract() {};
   virtual void StartNote(int pitch, int velocity) = 0;
   virtual void EndNote(int pitch, int velocity) = 0;
   virtual void Program(int instrument) = 0;
   virtual void ChannelAftertouch(int velocity) = 0;
   virtual void KeyAftertouch(int note, int velocity) = 0;
   virtual void Mode(int mode, int value) = 0;
   virtual void PitchBend(int value) = 0;
   virtual size_t AddSamples(AudioSample *buffer, size_t numberSamples) = 0;
};
// A placeholder that does nothing
class MidiChannelSilent: public MidiChannelAbstract {
public:
   ~MidiChannelSilent() {};
   void StartNote(int, int) {};
   void EndNote(int, int) {};
   void Program(int) {};
   void ChannelAftertouch(int) {};
   void KeyAftertouch(int, int) {};
   void Mode(int, int) {};
   void PitchBend(int) {};
   size_t AddSamples(AudioSample *, size_t) { return 0; };
};
// A channel keeps track of currently playing notes
class MidiChannelStandard: public MidiChannelAbstract {
private:
   float _masterVolume;
   float _channelVolume;

   MidiRead *_midiRead;
   int _defaultInstrumentBank;
   int _currentInstrumentBank;
   int _currentInstrumentNumber;
   int _currentTuning;

   AbstractNote *_note[128]; // Current notes

   int _controllerLong[32]; // 14-bit controllers
   int _controllerShort[32]; // 7-bit controllers
   int _currentRegisteredParameter;
   int _registeredParameter[8]; // Registered parameters
   void AllNotesOff();
   void ResetControllers();
public:
   MidiChannelStandard(MidiRead *midiObject,
                      int instrumentBank,
                      float masterVolume);
   ~MidiChannelStandard();
   void StartNote(int pitch, int velocity);
   void EndNote(int pitch, int velocity);
   void Program(int instrument);
   void ChannelAftertouch(int velocity);
   void KeyAftertouch(int note, int velocity);
   void Mode(int mode, int value);
   void PitchBend(int value);
   size_t AddSamples(AudioSample *buffer, size_t numberSamples);
};
struct MidiExtendedEventData {
   long length;
   AudioByte *data;
   // Constructor and destructor
   MidiExtendedEventData() { data = 0; }
   ~MidiExtendedEventData() { if (data) delete [] data; }
};

struct MidiEvent {
   MidiEvent *next;
   unsigned long delay; // Delay since previous event
   unsigned char track; // Number of track for this event
   unsigned char status; // Event status byte
   unsigned char data[2]; // Data for MIDI event
   MidiExtendedEventData *metaData; // Long data for system messages, etc.

   MidiEvent() { // Constructor
      next = 0;
      metaData = 0;
      delay = track = status = 0;
   }
   ~MidiEvent() { // Destructor
      if(metaData)
         delete metaData;
   }
};

class MidiRead: public AudioAbstract {
private:
   // Information about song being played
   MidiInstrumentMap *_instrumentMap;
   MidiTuningMap *_tuningMap;
   MidiChannelAbstract *_channel[16];
public:
   MidiInstrumentMap *InstrumentMap() { return _instrumentMap; }
   MidiTuningMap *TuningMap() { return _tuningMap; }

private:
   int _fileType; // Standard MIDI file type
   int _numberTracks; // Number of tracks
   int _timeFormat; // Time Format code

   unsigned long _samplesRemaining; // Samples remaining until next event

   
private:
   MidiEvent *_events; // List of all MIDI events in song
   MidiEvent *_currentEvent; // Current event being processed

private:
   // General information
   void ReadTracks(); // Read File into memory
   void ReadHeader(); // Read File into memory
   void PostProcess(); // Post-process event stream
   istream &_stream; // File being read

public:
   MidiRead(istream &input = cin);
   ~MidiRead();
protected:
   void MinMaxSamplingRate(long *min, long *max, long *preferred) {
      *min = *max = *preferred = 11025;
   }
   void MinMaxChannels(int *min, int *max, int *preferred) {
      *min = *max = *preferred = 1;
   }
   size_t GetSamples(AudioSample *buffer, size_t numSamples);
};
#endif
