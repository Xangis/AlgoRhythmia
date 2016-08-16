/////////////////////////////////////////////////////////////////////////////
// Name:        AlgoRhythmia.h
// Purpose:     
// Author:      Jason Champion
// Modified by: 
// Created:     26/09/2006 04:34:30
// RCS-ID:      
// Copyright:   Copyright (c) 2006 Zeta Centauri
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _ALGORHYTHMIA_H_
#define _ALGORHYTHMIA_H_

#include "wx/wx.h"
//#include "wx/config.h"
#include "wx/fileconf.h"
#include "wx/stdpaths.h"
#include "AboutDlg.h"
#include "wxSettingsFile.h"
#include "DrumControl.h"
#ifdef WIN32
#define INITGUID
#include <XAudio2.h>
#endif
#include "wavefile.h"

#define ID_ALGORHYTHMIA_DIALOG 11000
#define SYMBOL_ALGORHYTHMIA_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX|wxMINIMIZE_BOX
#define SYMBOL_ALGORHYTHMIA_TITLE _("AlgoRhythmia 4")
#define SYMBOL_ALGORHYTHMIA_IDNAME ID_ALGORHYTHMIA_DIALOG
#define SYMBOL_ALGORHYTHMIA_SIZE wxSize(399, 299)
#define SYMBOL_ALGORHYTHMIA_POSITION wxDefaultPosition
#define ID_DRUM1_ON 10000
#define ID_DRUM1_OFF 10001
#define ID_DRUMCOMBO1 10002
#define ID_DENSITY1 10003
#define ID_SURVIVE1 10004
#define ID_DIE1 10005
#define ID_INVERT1 10006
#define ID_SAMPLECHECK1 10007
#define ID_SAMPLE1 10008
#define ID_BROWSE1 10009
#define ID_DRUM2_ON 10010
#define ID_DRUM2_OFF 10011
#define ID_DRUMCOMBO2 10012
#define ID_DENSITY2 10013
#define ID_SURVIVE2 10114
#define ID_DIE2 10015
#define ID_INVERT2 10016
#define ID_SAMPLECHECK2 10017
#define ID_SAMPLE2 10018
#define ID_BROWSE2 10019
#define ID_DRUM3_ON 10020
#define ID_DRUM3_OFF 10021
#define ID_DRUMCOMBO3 10022
#define ID_DENSITY3 10023
#define ID_SURVIVE3 10024
#define ID_DIE3 10025
#define ID_INVERT3 10026
#define ID_SAMPLECHECK3 10027
#define ID_SAMPLE3 10028
#define ID_BROWSE3 10029
#define ID_DRUM4_ON 10030
#define ID_DRUM4_OFF 10031
#define ID_DRUMCOMBO4 10032
#define ID_DENSITY4 10033
#define ID_SURVIVE4 10034
#define ID_DIE4 10035
#define ID_INVERT4 10036
#define ID_SAMPLECHECK4 10037
#define ID_SAMPLE4 10038
#define ID_BROWSE4 10039
#define ID_DRUM5_ON 10040
#define ID_DRUM5_OFF 10041
#define ID_DRUMCOMBO5 10042
#define ID_DENSITY5 10043
#define ID_SURVIVE5 10044
#define ID_DIE5 10045
#define ID_INVERT5 10046
#define ID_SAMPLECHECK5 10047
#define ID_SAMPLE5 10048
#define ID_BROWSE5 10049
#define ID_DRUM6_ON 10050
#define ID_DRUM6_OFF 10051
#define ID_DRUMCOMBO6 10052
#define ID_DENSITY6 10053
#define ID_SURVIVE6 10054
#define ID_DIE6 10055
#define ID_INVERT6 10056
#define ID_SAMPLECHECK6 10057
#define ID_SAMPLE6 10058
#define ID_BROWSE6 10059
#define ID_DRUM7_ON 10060
#define ID_DRUM7_OFF 10061
#define ID_DRUMCOMBO7 10062
#define ID_DENSITY7 10063
#define ID_SURVIVE7 10064
#define ID_DIE7 10065
#define ID_INVERT7 10066
#define ID_SAMPLECHECK7 10067
#define ID_SAMPLE7 10068
#define ID_BROWSE7 10069
#define ID_DRUM8_ON 10070
#define ID_DRUM8_OFF 10071
#define ID_DRUMCOMBO8 10072
#define ID_DENSITY8 10073
#define ID_SURVIVE8 10074
#define ID_DIE8 10075
#define ID_INVERT8 10076
#define ID_SAMPLECHECK8 10077
#define ID_SAMPLE8 10078
#define ID_BROWSE8 10079
#define ID_KICKONE 10080
#define ID_SIMILARMEASURES 10081
#define ID_VARYVOLUME 10082
#define ID_ABOUT 10083
#define ID_CLEANSLATE 10084
#define ID_SAVEMIDI 10085
#define ID_EXIT 10086
#define ID_MUTATERATE 10087
#define ID_MEASURES_RADIOBOX 10088
#define ID_SIGNATURE_RADIOBOX 10089
#define ID_BASEPATTERN 10090
#define ID_MIDIDEVICE 10091
#define ID_MIDICHANNEL 10092
#define ID_CHECKMUTATE 10093
#define ID_MUTATEMEASURES 10094
#define ID_BPM 10095
#define ID_START 10096
#define ID_STOP 10097
#define ID_SAVE_PATTERN 10098
#define ID_DRUM_DATA_EDIT 10099
#define ID_LOAD_PATTERN 10103
#define ID_SWING_SLIDER 10190
#define ID_ALGORHYTHMIADIALOG 11000
#define ID_VOLUME1 10201
#define ID_VOLUME2 10202
#define ID_VOLUME3 10203
#define ID_VOLUME4 10204
#define ID_VOLUME5 10205
#define ID_VOLUME6 10206
#define ID_VOLUME7 10207
#define ID_VOLUME8 10208
#define ID_CHECK_MIDION 10209
#define ID_CHECK_HIHAT_CANCEL 10210
#define ID_DIVISION 10211
#define ID_FX1 10212
#define ID_FX2 10213
#define ID_FX3 10214
#define ID_FX4 10215
#define ID_FX5 10216
#define ID_FX6 10217
#define ID_FX7 10218
#define ID_FX8 10219
#define ID_PURCHASE 10220

#define DRUM_KICK			0
#define DRUM_SNARE			1
#define DRUM_CLOSED_HIHAT	2
#define DRUM_OPEN_HIHAT		3
#define DRUM_RIDE_CYMBAL	4
#define DRUM_LOW_TOM		5
#define DRUM_MID_TOM		6
#define DRUM_HIGH_TOM		7
#define DRUM_MAX			8

// Max of 11/8 and 4 measures = 22 beats x 4, expressed in 16th notes
#define MAX_PATTERN_SIZE	88
#define MAX_MEASURE_LENGTH  22
#define MAX_MEASURES        4

class DrumDialog;

class AlgoRhythmia : public wxDialog, public wxThread
{
    DECLARE_DYNAMIC_CLASS( AlgoRhythmia )
    DECLARE_EVENT_TABLE()
public:
    AlgoRhythmia( );
	~AlgoRhythmia();
    AlgoRhythmia( wxWindow* parent, wxWindowID id = SYMBOL_ALGORHYTHMIA_IDNAME, const wxString& caption = SYMBOL_ALGORHYTHMIA_TITLE, const wxPoint& pos = SYMBOL_ALGORHYTHMIA_POSITION, const wxSize& size = SYMBOL_ALGORHYTHMIA_SIZE, long style = SYMBOL_ALGORHYTHMIA_STYLE );
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_ALGORHYTHMIA_IDNAME, const wxString& caption = SYMBOL_ALGORHYTHMIA_TITLE, const wxPoint& pos = SYMBOL_ALGORHYTHMIA_POSITION, const wxSize& size = SYMBOL_ALGORHYTHMIA_SIZE, long style = SYMBOL_ALGORHYTHMIA_STYLE );
    void CreateControls();
	void MutateDrum(int drum);
	void MutateAllDrums( void );
	void RegenerateDrum(int drum);
	void RegenerateAllDrums( void );
	void InvertDrum( int drum );
	void SaveMIDI( void );
	void SampleBrowse( int sampleNumber );

    // Thread entry point
	void *Entry();

    //
    // Event Handlers
    //
    /// wxEVT_CLOSE_WINDOW event handler for ID_ALGORHYTHMIA_DIALOG
    void OnCloseWindow( wxCloseEvent& event );
    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_DRUM1_ON
    void OnDrum1OnSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_DRUM1_OFF
    void OnDrum1OffSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DRUMCOMBO1
    void OnDrumcombo1Selected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DENSITY1
    void OnDensity1Selected( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SURVIVE1
    void OnSurvive1Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DIE1
    void OnDie1Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_INVERT1
    void OnInvert1Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_SAMPLECHECK1
    void OnSamplecheck1Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BROWSE1
    void OnBrowse1Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_DRUM2_ON
    void OnDrum2OnSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_DRUM2_OFF
    void OnDrum2OffSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DRUMCOMBO2
    void OnDrumcombo2Selected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DENSITY2
    void OnDensity2Selected( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SURVIVE2
    void OnSurvive2Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DIE2
    void OnDie2Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_INVERT2
    void OnInvert2Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_SAMPLECHECK2
    void OnSamplecheck2Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BROWSE2
    void OnBrowse2Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_DRUM3_ON
    void OnDrum3OnSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_DRUM3_OFF
    void OnDrum3OffSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DRUMCOMBO3
    void OnDrumcombo3Selected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DENSITY3
    void OnDensity3Selected( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SURVIVE3
    void OnSurvive3Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DIE3
    void OnDie3Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_INVERT3
    void OnInvert3Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_SAMPLECHECK3
    void OnSamplecheck3Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BROWSE3
    void OnBrowse3Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_DRUM4_ON
    void OnDrum4OnSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_DRUM4_OFF
    void OnDrum4OffSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DRUMCOMBO4
    void OnDrumcombo4Selected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DENSITY4
    void OnDensity4Selected( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SURVIVE4
    void OnSurvive4Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DIE4
    void OnDie4Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_INVERT4
    void OnInvert4Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_SAMPLECHECK4
    void OnSamplecheck4Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BROWSE4
    void OnBrowse4Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_DRUM5_ON
    void OnDrum5OnSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_DRUM5_OFF
    void OnDrum5OffSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DRUMCOMBO5
    void OnDrumcombo5Selected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DENSITY5
    void OnDensity5Selected( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SURVIVE5
    void OnSurvive5Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DIE5
    void OnDie5Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_INVERT5
    void OnInvert5Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_SAMPLECHECK5
    void OnSamplecheck5Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BROWSE5
    void OnBrowse5Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_DRUM6_ON
    void OnDrum6OnSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_DRUM6_OFF
    void OnDrum6OffSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DRUMCOMBO6
    void OnDrumcombo6Selected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DENSITY6
    void OnDensity6Selected( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SURVIVE6
    void OnSurvive6Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DIE6
    void OnDie6Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_INVERT6
    void OnInvert6Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_SAMPLECHECK6
    void OnSamplecheck6Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BROWSE6
    void OnBrowse6Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_DRUM7_ON
    void OnDrum7OnSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_DRUM7_OFF
    void OnDrum7OffSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DRUMCOMBO7
    void OnDrumcombo7Selected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DENSITY7
    void OnDensity7Selected( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SURVIVE7
    void OnSurvive7Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DIE7
    void OnDie7Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_INVERT7
    void OnInvert7Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_SAMPLECHECK7
    void OnSamplecheck7Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BROWSE7
    void OnBrowse7Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_DRUM8_ON
    void OnDrum8OnSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_DRUM8_OFF
    void OnDrum8OffSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DRUMCOMBO8
    void OnDrumcombo8Selected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DENSITY8
    void OnDensity8Selected( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SURVIVE8
    void OnSurvive8Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DIE8
    void OnDie8Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_INVERT8
    void OnInvert8Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_SAMPLECHECK8
    void OnSamplecheck8Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BROWSE8
    void OnBrowse8Click( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_KICKONE
    void OnKickoneClick( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_SIMILARMEASURES
    void OnSimilarmeasuresClick( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_VARYVOLUME
    void OnVaryvolumeClick( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_BASEPATTERN
    void OnBasepatternSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_MIDIDEVICE
    void OnMidideviceSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_MIDICHANNEL
    void OnMidichannelSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKMUTATE
    void OnCheckmutateClick( wxCommandEvent& event );
    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_MUTATEMEASURES
    void OnMutatemeasuresUpdated( wxCommandEvent& event );
    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_BPM
    void OnBpmUpdated( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_START
    void OnStartClick( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_STOP
    void OnStopClick( wxCommandEvent& event );
    void OnEditNotesClick( wxCommandEvent& event );
    /// wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_RADIOBOX
    void OnMeasuresRadioboxSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_RADIOBOX1
    void OnSignatureRadioboxSelected( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ABOUT
    void OnAboutClick( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_CLEANSLATE
    void OnCleanslateClick( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SAVEMIDI
    void OnSavemidiClick( wxCommandEvent& event );
    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_EXIT
    void OnExitClick( wxCommandEvent& event );
	void OnLoadPatternClick( wxCommandEvent& event );
	void OnSavePatternClick( wxCommandEvent& event );
	void OnSwingSlider( wxScrollEvent& event );
	void OnVolume1Change( wxCommandEvent& event );
	void OnVolume2Change( wxCommandEvent& event );
	void OnVolume3Change( wxCommandEvent& event );
	void OnVolume4Change( wxCommandEvent& event );
	void OnVolume5Change( wxCommandEvent& event );
	void OnVolume6Change( wxCommandEvent& event );
	void OnVolume7Change( wxCommandEvent& event );
	void OnVolume8Change( wxCommandEvent& event );
	void OnFx1Click( wxCommandEvent& event );
	void OnFx2Click( wxCommandEvent& event );
	void OnFx3Click( wxCommandEvent& event );
	void OnFx4Click( wxCommandEvent& event );
	void OnFx5Click( wxCommandEvent& event );
	void OnFx6Click( wxCommandEvent& event );
	void OnFx7Click( wxCommandEvent& event );
	void OnFx8Click( wxCommandEvent& event );
	void OnDivisionSelected( wxCommandEvent& event );
    void OnPurchase( wxCommandEvent& event );
    void LoadPattern( wxString& filename );
    void SavePattern( wxString& filename );
    int PrepareMIDIBuffer( char* buffer, int bufferSize );    
	void OnMidiOnheck( wxCommandEvent& event );
	void OnHihatCancelCheck( wxCommandEvent& event );
private:
    void UpdateVolume( int channel );
    void ShowFxDialog( int channel );
	bool _playing;		// Are we playing?
	bool _midiOn;		// Is MIDI turned on?
	int _step;			// Keep track of which sequencer step we are on.
	int _measure;		// Current measure
	int _measures;		// Total measures.
	int _timesignature; // Keep track of total steps.
	int _division;		// Note division: quarter, eighth, or sixteenth.
	int _bpm;			// Beats per minute.
	// MIDI note number for each drum.
	bool _alwayskickone;// Always play kick drum on one beat?
	bool _varyvolume;	// Vary MIDI note volume?
	bool _periodicmutate;// Periodically mutate the drum pattern?
    bool _similarMeasures;// Generate with similar measures?
	bool _hihatCancel;	// Is hihat cancellation enabled?
	int _periodicmutatemeasures; // Number of measures to wait before mutating.
	int _midichannel;	// Current MIDI channel, 0-based.
	double _mutateRate;	// Mutation rate.
	double _swingRatio;	// Swing ratio.
	WaveFile* pLoader;
#ifdef WIN32
	LARGE_INTEGER _currtime;
	LARGE_INTEGER _lasttime;
	LARGE_INTEGER _tickspersec;
	HWND _hWnd;
	MSG _msg;
	HACCEL _hAccelTable;
	// Global Variables:
	HINSTANCE _hInstance;	
	HMIDIOUT _outHandle;
	IXAudio2* pXAudio2;
	IXAudio2MasteringVoice* pMasteringVoice;
	IXAudio2SourceVoice* pSourceVoice[DRUM_MAX];
	IXAudio2SubmixVoice* pPath[DRUM_MAX];
#endif
    AboutDlg* _aboutDlg;
    DrumDialog* _measureEditDlg;
	DrumControl* _drumControl[DRUM_MAX];
    wxCheckBox* _chkKickFirstBeat;
    wxCheckBox* _chkSimilarMeasures;
    wxCheckBox* _chkVaryVolume;
	wxCheckBox* _chkMidiOn;
	wxCheckBox* _chkHihatCancel;
    wxTextCtrl* _txtMutateRate;
    wxChoice* _basePattern;
    wxChoice* _midiDevice;
	wxChoice* _midiChannel;
	wxChoice* _chcDivision;
    wxCheckBox* _chkMutate;
    wxTextCtrl* _txtMutateMeasures;
    wxTextCtrl* _txtBPM;
    wxButton* _btnStart;
    wxButton* _btnStop;
    wxButton* _btnEditDrumData;
    wxButton* _btnPurchase;
    wxRadioBox* _radioMeasures;
    wxRadioBox* _radioTimeSignature;
    wxButton* _btnAbout;
    wxButton* _btnRegenerate;
    wxButton* _btnSaveMidi;
    wxButton* _btnSavePattern;
    wxButton* _btnLoadPattern;
    wxButton* _btnExit;	
	wxSettingsFile* _configData;
	wxSlider* _swingSlider;
	wxMutex _mutex;
	wxIcon _icon;
    void SetDrumEnabled( bool enable, int drum );
    void SetSampleState( int drumNumber, bool enable );
};

#endif
