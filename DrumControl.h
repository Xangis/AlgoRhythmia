#ifndef _DRUMCONTROL_H_
#define _DRUMCONTROL_H_

//#include "SoundFxManager.h"
#include "EffectsDlg.h"

#include "wx/wx.h"

#define MAX_PATTERN_SIZE	88

// Information for a single drum channel.  Treated as a self-initializing struct
// rather than a real class.
class DrumControl
{
public:
	DrumControl();
	~DrumControl();
	wxRadioButton* _onButton;
	wxRadioButton* _offButton;
	wxChoice* _drumSelection;
	wxChoice* _avgDensity;
	wxButton* _btnSurvive;
	wxButton* _btnDie;
	wxButton* _btnInvert;
	wxButton* _btnFx;
	wxCheckBox* _chkOn;
	wxTextCtrl* _sampleName;
	wxButton* _btnBrowse;
    //wxKnob* _knobVol;
    wxSlider* _volSlider;
    wxStaticText* _label;
	int _drumNote;
	int _midiVolume;
	bool _drumOn;
	bool _sampleOn;
	bool _noteData[MAX_PATTERN_SIZE];
	//SoundFxManager* _fxManager;
	//EffectsDlg* _fxDialog;
};

#endif