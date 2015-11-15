#pragma once

// If this fails, get libsndfile-dev (or whatever the windows equivalent is)
#include "sndfile.h"
#include "wx/wx.h"
#ifndef linux
#include <audiodefs.h>
#include <xaudio2.h>
#endif

/**
* Represents a wave file.  Used for loading wave data from disk.
*/
class WaveFile
{
public:
    bool Load( const char* filename );
    bool Save( const char* filename );
    WaveFile();
    unsigned int GetSampleRate() { return _sampleRate; }
	unsigned int GetBytesPerSample() { return _bitsPerSample / 8; }
    unsigned short GetNumChannels() { return _numChannels; }
    unsigned int GetNumSamples() { return _numSamples; }
    unsigned short GetBitsPerSample() { return _bitsPerSample; }
    unsigned short GetBlockAlign() { return _blockAlign; }
	unsigned int GetDataLength() { return _dataLength; }
    short* GetData();
    SF_INFO* GetSFInfo() { return &_sfinfo; }
    short* GetChunk( unsigned int start, unsigned int end );
	static WaveFile* Load(const char* filename, bool allowNull );
#ifdef WIN32
#ifdef USE_XAUDIO
	WAVEFORMATEX* GetWaveFormatEx();
	XAUDIO2_BUFFER* GetXAudio2Buffer();
#endif
#endif
private:
    SF_INFO _sfinfo;
    SNDFILE* _soundFile;
	unsigned int _dataLength;
	unsigned int _sampleRate;
	unsigned int _numSamples;
	unsigned short _numChannels;
	unsigned short _bitsPerSample;
    unsigned short _blockAlign;
};
