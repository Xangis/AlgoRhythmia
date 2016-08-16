#include "DrumControl.h"

DrumControl::DrumControl()
{
	_onButton = NULL;
	_offButton = NULL;
	_drumSelection = NULL;
	_avgDensity = NULL;
	_btnSurvive = NULL;
	_btnDie = NULL;
	_btnInvert = NULL;
	_chkOn = NULL;
	_sampleName = NULL;
	_btnBrowse = NULL;
	_btnFx = NULL;
    //_knobVol = NULL;
    _volSlider = NULL;
    _label = NULL;
	_drumNote = 0;
	_drumOn = true;
	_sampleOn = true;
	_midiVolume = 127;
	int count;
	for( count = 0; count < MAX_PATTERN_SIZE; count++ )
	{
		_noteData[MAX_PATTERN_SIZE] = false;
	}
	//_fxManager = new SoundFxManager;
	//_fxDialog = 0;
}

DrumControl::~DrumControl()
{
	//delete _fxManager;
	//if( _fxDialog != 0 )
	//{
	//	delete _fxDialog;
	//}
}