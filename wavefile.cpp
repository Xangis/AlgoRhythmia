#include "wavefile.h"
#include <iostream>

/**
* Default constructor.
*/
WaveFile::WaveFile()
{
    memset( &_sfinfo, 0, sizeof( _sfinfo ));
	_dataLength = 0;
	_sampleRate = 0;
	_numSamples = 0;
	_numChannels = 0;
    _blockAlign = 0;
	_bitsPerSample = 16;    
	_soundFile = NULL;
}

/**
* Static method that loads a wave file from disk and populates a new WaveFile with the data.
*/
WaveFile* WaveFile::Load(const char* filename, bool allowNull )
{
	WaveFile* waveFile = new WaveFile;
	if( waveFile->Load(filename))
	{
		return waveFile;
	}
	else if( allowNull )
	{
		return NULL;
	}
	else
	{
		return new WaveFile;
	}
}

/**
* Loads a wave file from disk and populates this class with the data.
*/
bool WaveFile::Load( const char* filename )
{
	memset(&_sfinfo, 0, sizeof(SF_INFO));
    _soundFile = sf_open( filename, SFM_READ, &_sfinfo );

    if( _soundFile == NULL )
    {
        return false;
    }

    _numSamples = _sfinfo.frames;
    _numChannels = _sfinfo.channels;
    _sampleRate = _sfinfo.samplerate;

	// Mask off bit rate.
	int format = _sfinfo.format & 0xFFFF;

    if( format == SF_FORMAT_PCM_S8 )
    {
        _bitsPerSample = 8;
        _blockAlign = _numChannels;
        _dataLength = _numSamples * _blockAlign;
    }
    else if( format == SF_FORMAT_PCM_16 )
    {
        _bitsPerSample = 16;
        _blockAlign = _numChannels * 2;
        _dataLength = _numSamples * _blockAlign;
    }
    else if( format == SF_FORMAT_PCM_24 )
    {
        _bitsPerSample = 24;
        _blockAlign = _numChannels * 3;
        _dataLength = _numSamples * _blockAlign;
    }
    else if( format == SF_FORMAT_PCM_32 )
    {
        _bitsPerSample = 32;
        _blockAlign = _numChannels * 4;
        _dataLength = _numSamples * _blockAlign;
    }
    else if( format == SF_FORMAT_FLOAT )
    {
        _bitsPerSample = 16;
        _blockAlign = _numChannels * 2;
        _dataLength = _numSamples * _blockAlign;
    }
    else if( format == SF_FORMAT_DOUBLE )
    {
        _bitsPerSample = 32;
        _blockAlign = _numChannels * 4;
        _dataLength = _numSamples * _blockAlign;
    }
	else if( format == SF_FORMAT_FLAC )
	{
		_bitsPerSample = 16;
		_blockAlign = _numChannels * 2;
		_dataLength = _numSamples * _blockAlign;
	}
	else if( format == SF_FORMAT_PCM_U8 )
	{
		//// Unsigned 8-bit does not work correctly.  In order to support it
		//// we would have to convert to signed 8-bit.
		//_bitsPerSample = 8;
		//_blockAlign = _numChannels;
		//_dataLength = _numSamples * _blockAlign;
		return false;
	}
	else
	{
		return false;
	}

    return true;
}

/**
 * Copies the sound data for this wave file into a new file.
 */
bool WaveFile::Save( const char *filename )
{
    SNDFILE* outfile = sf_open( filename, SFM_WRITE, &_sfinfo );
    if( outfile == NULL )
    {
        return false;
    }
	short* data = GetData();
    sf_write_short( outfile, data, (_numSamples * _numChannels));
	delete[] data;
    sf_close( outfile );

    return true;
}

/**
* This returns a new buffer containing data loaded from disk.  As such, changing or manipulating
* it does not have any effect on the original data.  The caller is responsible for destroying this
* data after they are done with it.  This should only be called for 16-bit files.
*/
short* WaveFile::GetData()
{
    sf_seek( _soundFile, 0, SEEK_SET );
    short* shortData = new short[_numSamples * _numChannels];
    sf_read_short( _soundFile, shortData, (_numSamples * _numChannels));
    return shortData;
}

/**
*  Gets a chunk of data at the specified start and end position in the file.
*
*  This function creates new data that must be destroyed by the caller.
*
*  The chunk of data is read as shorts, and the data length read is end-start.
*  This means a start of 400 and an end of 800 would read 400 bytes from 400-799.
*/
short* WaveFile::GetChunk( unsigned int start, unsigned int end )
{
	int dataLength = (end-start)*_numChannels;
    sf_seek( _soundFile, start, SEEK_SET );
    short* shortData = new short[dataLength];
    sf_read_short( _soundFile, shortData, dataLength);
    return shortData;
}

/**
* Retreives a WAVEFORMATEX structure based on the wave file data.
*/
#ifndef linux
WAVEFORMATEX* WaveFile::GetWaveFormatEx()
{
	WAVEFORMATEX* wfx = new WAVEFORMATEX;
	wfx->cbSize = GetDataLength();
	wfx->nBlockAlign = GetBlockAlign();
	wfx->nChannels = GetNumChannels();
	wfx->nSamplesPerSec = GetSampleRate();
	wfx->wBitsPerSample = GetBitsPerSample();
	wfx->wFormatTag = 0x0001;
	wfx->nAvgBytesPerSec = wfx->nBlockAlign * wfx->nSamplesPerSec;
	return wfx;
}

/**
* Gets an XAUDIO2_BUFFER filled with this wave file's data.  Having this
* method here ties us to having XAudio2 if we use the AudioFile project,
* so we may want to put this in a separate library at some point.
*/
XAUDIO2_BUFFER* WaveFile::GetXAudio2Buffer()
{
	XAUDIO2_BUFFER* buffer = new XAUDIO2_BUFFER;
	buffer->pAudioData = (unsigned char *)GetData();
	buffer->AudioBytes = GetDataLength();
	buffer->Flags = XAUDIO2_END_OF_STREAM;
	buffer->pContext = NULL;
	buffer->LoopLength = 0;
	buffer->LoopBegin = 0;
	buffer->PlayLength = GetNumSamples();
	buffer->PlayBegin = 0;
	buffer->LoopCount = 0;
	return buffer;

}
#endif
