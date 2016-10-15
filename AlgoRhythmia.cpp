/////////////////////////////////////////////////////////////////////////////
// Name:        AlgoRhythmia.cpp
// Purpose:     
// Author:      Jason Champion
// Modified by: 
// Created:     26/09/2006 04:34:30
// RCS-ID:      
// Copyright:   Copyright (c) 2006 Zeta Centauri
// Licence:     
/////////////////////////////////////////////////////////////////////////////
#include "AlgoRhythmia.h"
#include "drumgrid.h"
#include "wx/aboutdlg.h"

#include <wx/apptrait.h>

// Values for style box, to keep from having to change switch statement every
// time we reorder them.
#define STYLE_RANDOM 0
#define STYLE_CLEAR 1
#define STYLE_ROCK1 2
#define STYLE_ROCK2 3
#define STYLE_ROCK3 4
#define STYLE_FUNK1 5
#define STYLE_OONTZ 6
#define STYLE_FIBONACCI 7
#define STYLE_SIERPINSKI 8
#define STYLE_SIERPINSKI_INV 9

#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }

IMPLEMENT_DYNAMIC_CLASS( AlgoRhythmia, wxDialog )

BEGIN_EVENT_TABLE( AlgoRhythmia, wxDialog )
    EVT_CLOSE( AlgoRhythmia::OnCloseWindow )
    EVT_RADIOBUTTON( ID_DRUM1_ON, AlgoRhythmia::OnDrum1OnSelected )
    EVT_RADIOBUTTON( ID_DRUM1_OFF, AlgoRhythmia::OnDrum1OffSelected )
    EVT_CHOICE( ID_DRUMCOMBO1, AlgoRhythmia::OnDrumcombo1Selected )
    EVT_CHOICE( ID_DENSITY1, AlgoRhythmia::OnDensity1Selected )
    EVT_BUTTON( ID_SURVIVE1, AlgoRhythmia::OnSurvive1Click )
    EVT_BUTTON( ID_DIE1, AlgoRhythmia::OnDie1Click )
    EVT_BUTTON( ID_INVERT1, AlgoRhythmia::OnInvert1Click )
    EVT_CHECKBOX( ID_SAMPLECHECK1, AlgoRhythmia::OnSamplecheck1Click )
    EVT_BUTTON( ID_BROWSE1, AlgoRhythmia::OnBrowse1Click )
    EVT_RADIOBUTTON( ID_DRUM2_ON, AlgoRhythmia::OnDrum2OnSelected )
    EVT_RADIOBUTTON( ID_DRUM2_OFF, AlgoRhythmia::OnDrum2OffSelected )
    EVT_CHOICE( ID_DRUMCOMBO2, AlgoRhythmia::OnDrumcombo2Selected )
    EVT_CHOICE( ID_DENSITY2, AlgoRhythmia::OnDensity2Selected )
    EVT_BUTTON( ID_SURVIVE2, AlgoRhythmia::OnSurvive2Click )
    EVT_BUTTON( ID_DIE2, AlgoRhythmia::OnDie2Click )
    EVT_BUTTON( ID_INVERT2, AlgoRhythmia::OnInvert2Click )
    EVT_CHECKBOX( ID_SAMPLECHECK2, AlgoRhythmia::OnSamplecheck2Click )
    EVT_BUTTON( ID_BROWSE2, AlgoRhythmia::OnBrowse2Click )
    EVT_RADIOBUTTON( ID_DRUM3_ON, AlgoRhythmia::OnDrum3OnSelected )
    EVT_RADIOBUTTON( ID_DRUM3_OFF, AlgoRhythmia::OnDrum3OffSelected )
    EVT_CHOICE( ID_DRUMCOMBO3, AlgoRhythmia::OnDrumcombo3Selected )
    EVT_CHOICE( ID_DENSITY3, AlgoRhythmia::OnDensity3Selected )
    EVT_BUTTON( ID_SURVIVE3, AlgoRhythmia::OnSurvive3Click )
    EVT_BUTTON( ID_DIE3, AlgoRhythmia::OnDie3Click )
    EVT_BUTTON( ID_INVERT3, AlgoRhythmia::OnInvert3Click )
    EVT_CHECKBOX( ID_SAMPLECHECK3, AlgoRhythmia::OnSamplecheck3Click )
    EVT_BUTTON( ID_BROWSE3, AlgoRhythmia::OnBrowse3Click )
    EVT_RADIOBUTTON( ID_DRUM4_ON, AlgoRhythmia::OnDrum4OnSelected )
    EVT_RADIOBUTTON( ID_DRUM4_OFF, AlgoRhythmia::OnDrum4OffSelected )
    EVT_CHOICE( ID_DRUMCOMBO4, AlgoRhythmia::OnDrumcombo4Selected )
    EVT_CHOICE( ID_DENSITY4, AlgoRhythmia::OnDensity4Selected )
    EVT_BUTTON( ID_SURVIVE4, AlgoRhythmia::OnSurvive4Click )
    EVT_BUTTON( ID_DIE4, AlgoRhythmia::OnDie4Click )
    EVT_BUTTON( ID_INVERT4, AlgoRhythmia::OnInvert4Click )
    EVT_CHECKBOX( ID_SAMPLECHECK4, AlgoRhythmia::OnSamplecheck4Click )
    EVT_BUTTON( ID_BROWSE4, AlgoRhythmia::OnBrowse4Click )
    EVT_RADIOBUTTON( ID_DRUM5_ON, AlgoRhythmia::OnDrum5OnSelected )
    EVT_RADIOBUTTON( ID_DRUM5_OFF, AlgoRhythmia::OnDrum5OffSelected )
    EVT_CHOICE( ID_DRUMCOMBO5, AlgoRhythmia::OnDrumcombo5Selected )
    EVT_CHOICE( ID_DENSITY5, AlgoRhythmia::OnDensity5Selected )
    EVT_BUTTON( ID_SURVIVE5, AlgoRhythmia::OnSurvive5Click )
    EVT_BUTTON( ID_DIE5, AlgoRhythmia::OnDie5Click )
    EVT_BUTTON( ID_INVERT5, AlgoRhythmia::OnInvert5Click )
    EVT_CHECKBOX( ID_SAMPLECHECK5, AlgoRhythmia::OnSamplecheck5Click )
    EVT_BUTTON( ID_BROWSE5, AlgoRhythmia::OnBrowse5Click )
    EVT_RADIOBUTTON( ID_DRUM6_ON, AlgoRhythmia::OnDrum6OnSelected )
    EVT_RADIOBUTTON( ID_DRUM6_OFF, AlgoRhythmia::OnDrum6OffSelected )
    EVT_CHOICE( ID_DRUMCOMBO6, AlgoRhythmia::OnDrumcombo6Selected )
    EVT_CHOICE( ID_DENSITY6, AlgoRhythmia::OnDensity6Selected )
    EVT_BUTTON( ID_SURVIVE6, AlgoRhythmia::OnSurvive6Click )
    EVT_BUTTON( ID_DIE6, AlgoRhythmia::OnDie6Click )
    EVT_BUTTON( ID_INVERT6, AlgoRhythmia::OnInvert6Click )
    EVT_CHECKBOX( ID_SAMPLECHECK6, AlgoRhythmia::OnSamplecheck6Click )
    EVT_BUTTON( ID_BROWSE6, AlgoRhythmia::OnBrowse6Click )
    EVT_RADIOBUTTON( ID_DRUM7_ON, AlgoRhythmia::OnDrum7OnSelected )
    EVT_RADIOBUTTON( ID_DRUM7_OFF, AlgoRhythmia::OnDrum7OffSelected )
    EVT_CHOICE( ID_DRUMCOMBO7, AlgoRhythmia::OnDrumcombo7Selected )
    EVT_CHOICE( ID_DENSITY7, AlgoRhythmia::OnDensity7Selected )
    EVT_BUTTON( ID_SURVIVE7, AlgoRhythmia::OnSurvive7Click )
    EVT_BUTTON( ID_DIE7, AlgoRhythmia::OnDie7Click )
    EVT_BUTTON( ID_INVERT7, AlgoRhythmia::OnInvert7Click )
    EVT_CHECKBOX( ID_SAMPLECHECK7, AlgoRhythmia::OnSamplecheck7Click )
    EVT_BUTTON( ID_BROWSE7, AlgoRhythmia::OnBrowse7Click )
    EVT_RADIOBUTTON( ID_DRUM8_ON, AlgoRhythmia::OnDrum8OnSelected )
    EVT_RADIOBUTTON( ID_DRUM8_OFF, AlgoRhythmia::OnDrum8OffSelected )
    EVT_CHOICE( ID_DRUMCOMBO8, AlgoRhythmia::OnDrumcombo8Selected )
    EVT_CHOICE( ID_DENSITY8, AlgoRhythmia::OnDensity8Selected )
    EVT_BUTTON( ID_SURVIVE8, AlgoRhythmia::OnSurvive8Click )
    EVT_BUTTON( ID_DIE8, AlgoRhythmia::OnDie8Click )
    EVT_BUTTON( ID_INVERT8, AlgoRhythmia::OnInvert8Click )
    EVT_CHECKBOX( ID_SAMPLECHECK8, AlgoRhythmia::OnSamplecheck8Click )
    EVT_BUTTON( ID_BROWSE8, AlgoRhythmia::OnBrowse8Click )
    EVT_CHECKBOX( ID_KICKONE, AlgoRhythmia::OnKickoneClick )
    EVT_CHECKBOX( ID_SIMILARMEASURES, AlgoRhythmia::OnSimilarmeasuresClick )
    EVT_CHECKBOX( ID_VARYVOLUME, AlgoRhythmia::OnVaryvolumeClick )
	EVT_CHECKBOX( ID_CHECK_MIDION, AlgoRhythmia::OnMidiOnheck )
	EVT_CHECKBOX( ID_CHECK_HIHAT_CANCEL, AlgoRhythmia::OnHihatCancelCheck )
    EVT_CHOICE( ID_BASEPATTERN, AlgoRhythmia::OnBasepatternSelected )
    EVT_CHOICE( ID_MIDIDEVICE, AlgoRhythmia::OnMidideviceSelected )
    EVT_CHOICE( ID_MIDICHANNEL, AlgoRhythmia::OnMidichannelSelected )
	EVT_CHOICE( ID_DIVISION, AlgoRhythmia::OnDivisionSelected )
    EVT_CHECKBOX( ID_CHECKMUTATE, AlgoRhythmia::OnCheckmutateClick )
    EVT_TEXT( ID_MUTATEMEASURES, AlgoRhythmia::OnMutatemeasuresUpdated )
    EVT_TEXT( ID_BPM, AlgoRhythmia::OnBpmUpdated )
    EVT_BUTTON( ID_START, AlgoRhythmia::OnStartClick )
    EVT_BUTTON( ID_STOP, AlgoRhythmia::OnStopClick )
	EVT_BUTTON( ID_DRUM_DATA_EDIT, AlgoRhythmia::OnEditNotesClick )
    EVT_RADIOBOX( ID_MEASURES_RADIOBOX, AlgoRhythmia::OnMeasuresRadioboxSelected )
    EVT_RADIOBOX( ID_SIGNATURE_RADIOBOX, AlgoRhythmia::OnSignatureRadioboxSelected )
    EVT_BUTTON( ID_ABOUT, AlgoRhythmia::OnAboutClick )
    EVT_BUTTON( ID_CLEANSLATE, AlgoRhythmia::OnCleanslateClick )
    EVT_BUTTON( ID_SAVEMIDI, AlgoRhythmia::OnSavemidiClick )
    EVT_BUTTON( ID_EXIT, AlgoRhythmia::OnExitClick )
	EVT_BUTTON( ID_SAVE_PATTERN, AlgoRhythmia::OnSavePatternClick )
	EVT_BUTTON( ID_LOAD_PATTERN, AlgoRhythmia::OnLoadPatternClick )
	EVT_SCROLL( AlgoRhythmia::OnSwingSlider )
    EVT_SLIDER( ID_VOLUME1, AlgoRhythmia::OnVolume1Change )
    EVT_SLIDER( ID_VOLUME2, AlgoRhythmia::OnVolume2Change )
    EVT_SLIDER( ID_VOLUME3, AlgoRhythmia::OnVolume3Change )
    EVT_SLIDER( ID_VOLUME4, AlgoRhythmia::OnVolume4Change )
    EVT_SLIDER( ID_VOLUME5, AlgoRhythmia::OnVolume5Change )
    EVT_SLIDER( ID_VOLUME6, AlgoRhythmia::OnVolume6Change )
    EVT_SLIDER( ID_VOLUME7, AlgoRhythmia::OnVolume7Change )
    EVT_SLIDER( ID_VOLUME8, AlgoRhythmia::OnVolume8Change )
	EVT_BUTTON( ID_FX1, AlgoRhythmia::OnFx1Click )
	EVT_BUTTON( ID_FX2, AlgoRhythmia::OnFx2Click )
	EVT_BUTTON( ID_FX3, AlgoRhythmia::OnFx3Click )
	EVT_BUTTON( ID_FX4, AlgoRhythmia::OnFx4Click )
	EVT_BUTTON( ID_FX5, AlgoRhythmia::OnFx5Click )
	EVT_BUTTON( ID_FX6, AlgoRhythmia::OnFx6Click )
	EVT_BUTTON( ID_FX7, AlgoRhythmia::OnFx7Click )
	EVT_BUTTON( ID_FX8, AlgoRhythmia::OnFx8Click )
    EVT_BUTTON( ID_PURCHASE, AlgoRhythmia::OnPurchase )
END_EVENT_TABLE()

#ifdef WIN32
#include "stdafx.h"
#include "Commdlg.h"
#endif
#include "AlgoRhythmiaApp.h"
#include "drumgrid.h"
//#include "..\CMidi\CMidi.h"
#include <ctime>
#include <fstream>

#include "wx/wx.h"

// Global Constants for Drum Kits
int midival[60] = { 36, 35, 38, 40, 42, 44, 46, 49, 57, 51, 59, 55, 52, 53, 41, 43,
		            45, 47, 48, 50, 61, 60, 62, 63, 65, 66, 67, 68, 69, 70, 71, 72,
				    73, 74, 75, 76, 77, 78, 79, 80, 81, 37, 39, 54, 56, 58,
	                // General MIDI Level 2 starts here.
	                27, 28, 29, 30, 31, 32, 33, 34, 82, 83, 84, 85, 86, 87 };

#define Swap4Bytes(data)	(data = ((((data) >> 24) & 0x000000FF) | (((data) >>  8) & 0x0000FF00) |	\
									 (((data) <<  8) & 0x00FF0000) | (((data) << 24) & 0xFF000000)))

AlgoRhythmia::AlgoRhythmia( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);
}

bool AlgoRhythmia::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
	int count;
	for( count = 0; count < DRUM_MAX; count++ )
	{
		_drumControl[count] = NULL;
		_wave[count] = NULL;
		_sourceVoice[count] = NULL;
	}
#ifdef WIN32
	_masteringVoice = NULL;
#endif
	_measureEditDlg = NULL;
    _aboutDlg = NULL;
	_chcDivision = NULL;
    _chkKickFirstBeat = NULL;
    _chkSimilarMeasures = NULL;
    _chkVaryVolume = NULL;
	_chkMidiOn = NULL;
    _txtMutateRate = NULL;
    _basePattern = NULL;
    _midiDevice = NULL;
    _chkMutate = NULL;
    _txtMutateMeasures = NULL;
    _txtBPM = NULL;
    _btnStart = NULL;
    _btnStop = NULL;
	_btnEditDrumData = NULL;
    _radioMeasures = NULL;
    _radioTimeSignature = NULL;
    _btnAbout = NULL;
    _btnRegenerate = NULL;
    _btnSaveMidi = NULL;
    _btnSavePattern = NULL;
    _btnLoadPattern = NULL;
    _btnExit = NULL;
	_configData = NULL;
	_midiChannel = NULL;
    _btnPurchase = NULL;
    _mutateRate = 0.06f;
	_similarMeasures = true;
	_hihatCancel = false;
	_playing = false;
	_alwayskickone = false;
	_varyvolume = false;
	_periodicmutate = false;
	_midiOn = false;
	_division = 8;
	_swingRatio = 1.0;
	_measures = 1;
	_bpm = 130;
	// Zero-based MIDI Channel
	_midichannel = 9;
	_periodicmutatemeasures = 8;
	_step = 0; // Keep track of which sequencer step we are on.
	_timesignature = 16; // Initial time signature is 4/4
    SetExtraStyle(GetExtraStyle()|wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );
    CreateControls();
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();

	_configData = new wxSettingsFile;

#ifdef WIN32
	// XAudio2 and Mastering Voice
#ifndef _XBOX
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
#endif
	HRESULT hr;
#ifdef DEBUG
	if ( FAILED(hr = XAudio2Create( &_xaudio2, XAUDIO2_DEBUG_ENGINE, XAUDIO2_DEFAULT_PROCESSOR ) ) )
#else
	if ( FAILED(hr = XAudio2Create( &_xaudio2, 0, XAUDIO2_DEFAULT_PROCESSOR ) ) )
#endif
		return hr;
	//
	// TODO: Enumerate audio devices instead of just using the default.
	//
	// Mastering Voice
	if ( FAILED(hr = _xaudio2->CreateMasteringVoice( &_masteringVoice, XAUDIO2_DEFAULT_CHANNELS,
                            XAUDIO2_DEFAULT_SAMPLERATE, 0, 0, NULL ) ) )
    return hr;
	// End XAudio Setup
#endif

	for( count = 0; count < DRUM_MAX; count++ )
	{
		_drumControl[count]->_drumNote = _drumControl[count]->_drumSelection->GetSelection();
	}

	// Create audiopaths and initialize effects for that audiopath.
	// _filenames is populated in CreateControls().
	for( count = 0; count < DRUM_MAX; count++ )
	{
		if( _wave[count] != NULL ) delete _wave[count];
		_wave[count] = WaveFile::Load(_filenames[count].wchar_str(), false);

#ifdef WIN32
		if( FAILED(hr = _xaudio2->CreateSourceVoice( &_sourceVoice[count], _wave[count]->GetWaveFormatEx(),
              0, XAUDIO2_DEFAULT_FREQ_RATIO, NULL, NULL, NULL ) ) )
		{
			wxMessageBox(wxString::Format(_("Could not load sample %s, CreateSourceVoice returned %d"), _wave[count], hr));
		    return hr;
		}

		// TODO: FIX THIS.  THE EFFECTS MANAGER IS BROKEN BECAUSE IT REQUIRES DIRECTMUSIC.
		//_drumControl[count]->_fxManager->Initialize( _path[count], true );
		// We have to create the effects dialogs in order to load settings properly [the dialogs hold on/off settings for effects].
		//if( _drumControl[count]->_fxDialog == NULL )
		//{
		//	_drumControl[count]->_fxDialog = new EffectsDlg(this, _drumControl[count]->_fxManager, ID_EFFECTSDIALOG, wxString::Format( "Edit Channel %d Effects", count ) );
		//}
		// This should not be necessary because it's one of the things that Initialize() covers.
		//_drumControl[count]->_fxManager->DisableAllFX();
        // We're not going to activate any effects here because they will all be disabled by
        // default and they can be enabled one by one on the effects dialog on a per-drum basis.
		//int effectNum;
		//for( effectNum = 0; effectNum < eNUM_SFX; effectNum++ )
		//{
		//	_drumControl[count]->_fxManager->SetFXEnable( effectNum );
		//}
		//_drumControl[count]->_fxManager->ActivateFX();
		// This should not be necessary since we called Initialize with true for load parameters.
		// _drumControl[count]->_fxManager->LoadCurrentFXParameters();
#endif
	}

#ifdef WIN32
	// Populate MIDI Device List
	int numDevices = midiOutGetNumDevs();
	MIDIOUTCAPS midiCaps;
	for( count = 0; count < numDevices; count++ )
	{
		hr = midiOutGetDevCaps( count, &midiCaps, sizeof( midiCaps ) );
		if( hr == MMSYSERR_BADDEVICEID || hr == MMSYSERR_INVALPARAM || hr == MMSYSERR_NODRIVER || hr == MMSYSERR_NOMEM )
		{
			continue;
		}
		// Add the device to a list box on the GUI.
		_midiDevice->Append( midiCaps.szPname );
	}
	_midiDevice->SetSelection(0);
	/* Open the MIDI Mapper */
	unsigned long result = midiOutOpen(&_outHandle, (UINT)-1, 0, 0, CALLBACK_WINDOW);
	if (result)
	{
        wxMessageBox( _("There was an error opening MIDI Mapper!"), _("MIDI Error"), wxOK );
	}
	// Set up timer
	QueryPerformanceFrequency( &_tickspersec );
	QueryPerformanceCounter( &_currtime );
	_lasttime = _currtime;
#endif

	srand((unsigned)time(0));

	// Now that everything else is done - Initialize Drum Array
	RegenerateAllDrums();

	// Create dialog for editing individual drum sounds.
    _measureEditDlg = new DrumDialog(this);
	for( count = 0; count < DRUM_MAX; count++ )
	{
		_measureEditDlg->SetDrumControls( count, _drumControl[count] );
	}

	// Create the playback thread
	if( wxThread::Create(wxTHREAD_JOINABLE) != wxTHREAD_NO_ERROR )
	{
		wxMessageBox( _("Unable to create playback thread."), _("ERROR"), wxOK );
		return false;
	}
	// Set thread priority just above default so we are less likely to have
	// stuttering on high system load.
	SetPriority( 75 );
	Run();
    return true;
}

void AlgoRhythmia::CreateControls()
{
    AlgoRhythmia* itemDialog1 = this;

	_filenames[0] = _("./samples/Kick-Drum-1.wav");
	_filenames[1] = _("./samples/Snare-Drum-1.wav");
	_filenames[2] = _("./samples/Closed-Hi-Hat-1.wav");
	_filenames[3] = _("./samples/Open-Hi-Hat-1.wav");
	_filenames[4] = _("./samples/Crash-Cymbal-1.wav");
	_filenames[5] = _("./samples/Low-Tom-1.wav");
	_filenames[6] = _("./samples/Mid-Tom-1.wav");
	_filenames[7] = _("./samples/Hi-Tom-1.wav");

	wxSize buttonSize = wxSize( 66, 30 );
	wxSize densitySize = wxSize( 68, 30 );
	wxSize instrumentSize = wxSize( 154, 30 );
	wxSize filenameSize = wxSize( 132, 30 );

	int count;
	for( count = 0; count < DRUM_MAX; count++ )
	{
		_drumControl[count] = new DrumControl;
	}

    wxString midiNoteChoices[] = {
        _("Bass Drum 1"), // 0
        _("Acoustic Kick"),
        _("Acoustic Snare"),
        _("Electric Snare"),
        _("Closed Hi-Hat"),
        _("Pedal Hi-Hat"),
        _("Open Hi-Hat"),
        _("Crash Cymbal"),
        _("Crash Cymbal 2"),
        _("Ride Cymbal"), 
        _("Ride Cymbal 2"), // 10
        _("Splash Cymbal"),
        _("Chinese Cymbal"),
        _("Ride Bell"),
        _("Low Floor Tom"),
        _("High Floor Tom"),
        _("Low Tom"),
        _("Low-Mid Tom"),
        _("High-Mid Tom"),
        _("High Tom"), 
        _("Low Bongo"), // 20
        _("High Bongo"),
        _("Mute High Conga"),
        _("Open High Conga"),
        _("High Timbale"),
        _("Low Timbale"),
        _("High Agogo"),
        _("Low Agogo"),
        _("Casaba"),
        _("Maracas"),
        _("Short Whistle"), // 30
        _("Long Whistle"),
        _("Short Guiro"),
        _("Long Guiro"),
        _("Claves"),
        _("High Wood Block"),
        _("Low Wood Block"),
        _("Mute Cuica"),
        _("Open Cuica"),
        _("Mute Triangle"),
        _("Open Triangle"), // 40
        _("Side Stick"),
        _("Hand Clap"),
        _("Tambourine"),
        _("Cowbell"),
        _("Vibraslap"),
		// General MIDI Level 2 Starts Here
		_("High Q"),
		_("Slap"),
		_("Scratch Push"),
		_("Scratch Pull"),
		_("Sticks"), // 50
		_("Square Click"),
		_("Metronome Click"),
		_("Metronome Bell"),
		_("Shaker"),
		_("Jingle Bell"),
		_("Belltree"),
		_("Castanets"),
		_("Mute Surdo"),
		_("Open Surdo") // 59
    };

    wxString drumDensityChoices[] = {
        _("0.040"),
        _("0.050"),
        _("0.063"),
        _("0.083"),
        _("0.091"),
        _("0.100"),
        _("0.111"),
        _("0.125"),
        _("0.166"),
        _("0.200"),
        _("0.250"),
        _("0.333"),
        _("0.400"),
        _("0.500"),
        _("0.666"),
        _("0.750"),
        _("0.800"),
        _("1.000")
    };

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxStaticBox* itemStaticBoxSizer3Static = new wxStaticBox(itemDialog1, wxID_ANY, _T(""));
    wxStaticBoxSizer* itemStaticBoxSizer3 = new wxStaticBoxSizer(itemStaticBoxSizer3Static, wxHORIZONTAL);
    itemBoxSizer2->Add(itemStaticBoxSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer4 = new wxFlexGridSizer(9, 11, 0, 0);
    itemStaticBoxSizer3->Add(itemFlexGridSizer4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 2);

    wxStaticText* itemStaticText4 = new wxStaticText( itemDialog1, wxID_STATIC, _("Ch"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(itemStaticText4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText5 = new wxStaticText( itemDialog1, wxID_STATIC, _("Active"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(itemStaticText5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText6 = new wxStaticText( itemDialog1, wxID_STATIC, _("MIDI Instrument"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(itemStaticText6, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText7 = new wxStaticText( itemDialog1, wxID_STATIC, _("Avg Density"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(itemStaticText7, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

	itemFlexGridSizer4->AddSpacer( 1 );

    wxStaticText* itemStaticText9 = new wxStaticText( itemDialog1, wxID_STATIC, _("Evolution"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(itemStaticText9, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

	itemFlexGridSizer4->AddSpacer( 1 );

    wxStaticText* itemStaticText14 = new wxStaticText( itemDialog1, wxID_STATIC, _("Vol"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(itemStaticText14, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

	// FX column.
	//itemFlexGridSizer4->AddSpacer( 1 );

	wxStaticText* itemStaticText11 = new wxStaticText( itemDialog1, wxID_STATIC, _("On"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(itemStaticText11, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText12 = new wxStaticText( itemDialog1, wxID_STATIC, _("Sample"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(itemStaticText12, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

	itemFlexGridSizer4->AddSpacer( 1 );

    _drumControl[0]->_label = new wxStaticText( itemDialog1, wxID_STATIC, _T("1:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[0]->_label, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 2);

    wxBoxSizer* itemBoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
    itemFlexGridSizer4->Add(itemBoxSizer14, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    _drumControl[0]->_onButton = new wxRadioButton( itemDialog1, ID_DRUM1_ON, _("On"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
    _drumControl[0]->_onButton->SetValue(true);
    itemBoxSizer14->Add(_drumControl[0]->_onButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[0]->_offButton = new wxRadioButton( itemDialog1, ID_DRUM1_OFF, _("Off"), wxDefaultPosition, wxDefaultSize, 0 );
    _drumControl[0]->_offButton->SetValue(false);
    itemBoxSizer14->Add(_drumControl[0]->_offButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[0]->_drumSelection = new wxChoice( itemDialog1, ID_DRUMCOMBO1, wxDefaultPosition, instrumentSize, 46, midiNoteChoices, 0 );
    _drumControl[0]->_drumSelection->SetStringSelection(_("Bass Drum 1"));
    itemFlexGridSizer4->Add(_drumControl[0]->_drumSelection, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[0]->_avgDensity = new wxChoice( itemDialog1, ID_DENSITY1, wxDefaultPosition, densitySize, 17, drumDensityChoices, 0 );
    _drumControl[0]->_avgDensity->SetStringSelection(_("0.250"));
    itemFlexGridSizer4->Add(_drumControl[0]->_avgDensity, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[0]->_btnSurvive = new wxButton( itemDialog1, ID_SURVIVE1, _("Survive"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[0]->_btnSurvive, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[0]->_btnDie = new wxButton( itemDialog1, ID_DIE1, _("Die"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[0]->_btnDie, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[0]->_btnInvert = new wxButton( itemDialog1, ID_INVERT1, _("Invert"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[0]->_btnInvert, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[0]->_volSlider = new wxSlider( itemDialog1, ID_VOLUME1, 100, 0, 200, wxDefaultPosition, wxSize(100, 22), wxNO_BORDER );
    itemFlexGridSizer4->Add(_drumControl[0]->_volSlider, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 1 );

	//_drumControl[0]->_btnFx = new wxButton( itemDialog1, ID_FX1, _("FX"), wxDefaultPosition, wxSize( 28, -1 ), 0 );
	//itemFlexGridSizer4->Add(_drumControl[0]->_btnFx, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3 );

    _drumControl[0]->_chkOn = new wxCheckBox( itemDialog1, ID_SAMPLECHECK1, _T(""), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    _drumControl[0]->_chkOn->SetValue(true);
    itemFlexGridSizer4->Add(_drumControl[0]->_chkOn, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[0]->_sampleName = new wxTextCtrl( itemDialog1, ID_SAMPLE1, wxFileName(_filenames[0]).GetName(), wxDefaultPosition, filenameSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[0]->_sampleName, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[0]->_btnBrowse = new wxButton( itemDialog1, ID_BROWSE1, _("Browse"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[0]->_btnBrowse, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[1]->_label = new wxStaticText( itemDialog1, wxID_STATIC, _T("2:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[1]->_label, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 2);

    wxBoxSizer* itemBoxSizer25 = new wxBoxSizer(wxHORIZONTAL);
    itemFlexGridSizer4->Add(itemBoxSizer25, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    _drumControl[1]->_onButton = new wxRadioButton( itemDialog1, ID_DRUM2_ON, _("On"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
    _drumControl[1]->_onButton->SetValue(true);
    itemBoxSizer25->Add(_drumControl[1]->_onButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[1]->_offButton = new wxRadioButton( itemDialog1, ID_DRUM2_OFF, _("Off"), wxDefaultPosition, wxDefaultSize, 0 );
    _drumControl[1]->_offButton->SetValue(false);
    itemBoxSizer25->Add(_drumControl[1]->_offButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[1]->_drumSelection = new wxChoice( itemDialog1, ID_DRUMCOMBO2, wxDefaultPosition, instrumentSize, 46, midiNoteChoices, 0 );
    _drumControl[1]->_drumSelection->SetStringSelection(_("Acoustic Snare"));
    itemFlexGridSizer4->Add(_drumControl[1]->_drumSelection, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[1]->_avgDensity = new wxChoice( itemDialog1, ID_DENSITY2, wxDefaultPosition, densitySize, 17, drumDensityChoices, 0 );
    _drumControl[1]->_avgDensity->SetStringSelection(_("0.333"));
    itemFlexGridSizer4->Add(_drumControl[1]->_avgDensity, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[1]->_btnSurvive = new wxButton( itemDialog1, ID_SURVIVE2, _("Survive"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[1]->_btnSurvive, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[1]->_btnDie = new wxButton( itemDialog1, ID_DIE2, _("Die"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[1]->_btnDie, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[1]->_btnInvert = new wxButton( itemDialog1, ID_INVERT2, _("Invert"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[1]->_btnInvert, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[1]->_volSlider = new wxSlider( itemDialog1, ID_VOLUME2, 100, 0, 200, wxDefaultPosition, wxSize(100, 22), wxNO_BORDER );
    itemFlexGridSizer4->Add(_drumControl[1]->_volSlider, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 1 );

	//_drumControl[1]->_btnFx = new wxButton( itemDialog1, ID_FX2, _("FX"), wxDefaultPosition, wxSize( 28, -1 ), 0 );
	//itemFlexGridSizer4->Add(_drumControl[1]->_btnFx, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3 );

	_drumControl[1]->_chkOn = new wxCheckBox( itemDialog1, ID_SAMPLECHECK2, _T(""), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    _drumControl[1]->_chkOn->SetValue(true);
    itemFlexGridSizer4->Add(_drumControl[1]->_chkOn, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[1]->_sampleName = new wxTextCtrl( itemDialog1, ID_SAMPLE2, wxFileName(_filenames[1]).GetName(), wxDefaultPosition, filenameSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[1]->_sampleName, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[1]->_btnBrowse = new wxButton( itemDialog1, ID_BROWSE2, _("Browse"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[1]->_btnBrowse, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[2]->_label = new wxStaticText( itemDialog1, wxID_STATIC, _T("3:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[2]->_label, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 2);

    wxBoxSizer* itemBoxSizer36 = new wxBoxSizer(wxHORIZONTAL);
    itemFlexGridSizer4->Add(itemBoxSizer36, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    _drumControl[2]->_onButton = new wxRadioButton( itemDialog1, ID_DRUM3_ON, _("On"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
    _drumControl[2]->_onButton->SetValue(true);
    itemBoxSizer36->Add(_drumControl[2]->_onButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[2]->_offButton = new wxRadioButton( itemDialog1, ID_DRUM3_OFF, _("Off"), wxDefaultPosition, wxDefaultSize, 0 );
    _drumControl[2]->_offButton->SetValue(false);
    itemBoxSizer36->Add(_drumControl[2]->_offButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[2]->_drumSelection = new wxChoice( itemDialog1, ID_DRUMCOMBO3, wxDefaultPosition, instrumentSize, 46, midiNoteChoices, 0 );
    _drumControl[2]->_drumSelection->SetStringSelection(_("Closed Hi-Hat"));
    itemFlexGridSizer4->Add(_drumControl[2]->_drumSelection, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[2]->_avgDensity = new wxChoice( itemDialog1, ID_DENSITY3, wxDefaultPosition, densitySize, 17, drumDensityChoices, 0 );
    _drumControl[2]->_avgDensity->SetStringSelection(_("0.750"));
    itemFlexGridSizer4->Add(_drumControl[2]->_avgDensity, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[2]->_btnSurvive = new wxButton( itemDialog1, ID_SURVIVE3, _("Survive"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[2]->_btnSurvive, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[2]->_btnDie = new wxButton( itemDialog1, ID_DIE3, _("Die"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[2]->_btnDie, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[2]->_btnInvert = new wxButton( itemDialog1, ID_INVERT3, _("Invert"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[2]->_btnInvert, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[2]->_volSlider = new wxSlider( itemDialog1, ID_VOLUME3, 100, 0, 200, wxDefaultPosition, wxSize(100, 22), wxNO_BORDER );
    itemFlexGridSizer4->Add(_drumControl[2]->_volSlider, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 1 );

	//_drumControl[2]->_btnFx = new wxButton( itemDialog1, ID_FX3, _("FX"), wxDefaultPosition, wxSize( 28, -1 ), 0 );
	//itemFlexGridSizer4->Add(_drumControl[2]->_btnFx, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3 );

    _drumControl[2]->_chkOn = new wxCheckBox( itemDialog1, ID_SAMPLECHECK3, _T(""), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    _drumControl[2]->_chkOn->SetValue(true);
    itemFlexGridSizer4->Add(_drumControl[2]->_chkOn, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[2]->_sampleName = new wxTextCtrl( itemDialog1, ID_SAMPLE3, wxFileName(_filenames[2]).GetName(), wxDefaultPosition, filenameSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[2]->_sampleName, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[2]->_btnBrowse = new wxButton( itemDialog1, ID_BROWSE3, _("Browse"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[2]->_btnBrowse, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[3]->_label = new wxStaticText( itemDialog1, wxID_STATIC, _T("4:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[3]->_label, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 2);

    wxBoxSizer* itemBoxSizer47 = new wxBoxSizer(wxHORIZONTAL);
    itemFlexGridSizer4->Add(itemBoxSizer47, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    _drumControl[3]->_onButton = new wxRadioButton( itemDialog1, ID_DRUM4_ON, _("On"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
    _drumControl[3]->_onButton->SetValue(true);
    itemBoxSizer47->Add(_drumControl[3]->_onButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[3]->_offButton = new wxRadioButton( itemDialog1, ID_DRUM4_OFF, _("Off"), wxDefaultPosition, wxDefaultSize, 0 );
    _drumControl[3]->_offButton->SetValue(false);
    itemBoxSizer47->Add(_drumControl[3]->_offButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[3]->_drumSelection = new wxChoice( itemDialog1, ID_DRUMCOMBO4, wxDefaultPosition, instrumentSize, 46, midiNoteChoices, 0 );
    _drumControl[3]->_drumSelection->SetStringSelection(_("Open Hi-Hat"));
    itemFlexGridSizer4->Add(_drumControl[3]->_drumSelection, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[3]->_avgDensity = new wxChoice( itemDialog1, ID_DENSITY4, wxDefaultPosition, densitySize, 17, drumDensityChoices, 0 );
    _drumControl[3]->_avgDensity->SetStringSelection(_("0.125"));
    itemFlexGridSizer4->Add(_drumControl[3]->_avgDensity, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[3]->_btnSurvive = new wxButton( itemDialog1, ID_SURVIVE4, _("Survive"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[3]->_btnSurvive, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[3]->_btnDie = new wxButton( itemDialog1, ID_DIE4, _("Die"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[3]->_btnDie, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[3]->_btnInvert = new wxButton( itemDialog1, ID_INVERT4, _("Invert"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[3]->_btnInvert, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[3]->_volSlider = new wxSlider( itemDialog1, ID_VOLUME4, 100, 0, 200, wxDefaultPosition, wxSize(100, 22), wxNO_BORDER );
    itemFlexGridSizer4->Add(_drumControl[3]->_volSlider, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 1 );

	//_drumControl[3]->_btnFx = new wxButton( itemDialog1, ID_FX4, _("FX"), wxDefaultPosition, wxSize( 28, -1 ), 0 );
	//itemFlexGridSizer4->Add(_drumControl[3]->_btnFx, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3 );

    _drumControl[3]->_chkOn = new wxCheckBox( itemDialog1, ID_SAMPLECHECK4, _T(""), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    _drumControl[3]->_chkOn->SetValue(true);
    itemFlexGridSizer4->Add(_drumControl[3]->_chkOn, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[3]->_sampleName = new wxTextCtrl( itemDialog1, ID_SAMPLE4, wxFileName(_filenames[3]).GetName(), wxDefaultPosition, filenameSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[3]->_sampleName, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[3]->_btnBrowse = new wxButton( itemDialog1, ID_BROWSE4, _("Browse"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[3]->_btnBrowse, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[4]->_label = new wxStaticText( itemDialog1, wxID_STATIC, _T("5:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[4]->_label, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 2);

    wxBoxSizer* itemBoxSizer58 = new wxBoxSizer(wxHORIZONTAL);
    itemFlexGridSizer4->Add(itemBoxSizer58, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    _drumControl[4]->_onButton = new wxRadioButton( itemDialog1, ID_DRUM5_ON, _("On"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
    _drumControl[4]->_onButton->SetValue(true);
    itemBoxSizer58->Add(_drumControl[4]->_onButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[4]->_offButton = new wxRadioButton( itemDialog1, ID_DRUM5_OFF, _("Off"), wxDefaultPosition, wxDefaultSize, 0 );
    _drumControl[4]->_offButton->SetValue(false);
    itemBoxSizer58->Add(_drumControl[4]->_offButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[4]->_drumSelection = new wxChoice( itemDialog1, ID_DRUMCOMBO5, wxDefaultPosition, instrumentSize, 46, midiNoteChoices, 0 );
    _drumControl[4]->_drumSelection->SetStringSelection(_("Crash Cymbal"));
    itemFlexGridSizer4->Add(_drumControl[4]->_drumSelection, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[4]->_avgDensity = new wxChoice( itemDialog1, ID_DENSITY5, wxDefaultPosition, densitySize, 17, drumDensityChoices, 0 );
    _drumControl[4]->_avgDensity->SetStringSelection(_("0.050"));
    itemFlexGridSizer4->Add(_drumControl[4]->_avgDensity, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[4]->_btnSurvive = new wxButton( itemDialog1, ID_SURVIVE5, _("Survive"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[4]->_btnSurvive, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[4]->_btnDie = new wxButton( itemDialog1, ID_DIE5, _("Die"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[4]->_btnDie, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[4]->_btnInvert = new wxButton( itemDialog1, ID_INVERT5, _("Invert"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[4]->_btnInvert, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[4]->_volSlider = new wxSlider( itemDialog1, ID_VOLUME5, 100, 0, 200, wxDefaultPosition, wxSize(100, 22), wxNO_BORDER );
    itemFlexGridSizer4->Add(_drumControl[4]->_volSlider, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 1 );

	//_drumControl[4]->_btnFx = new wxButton( itemDialog1, ID_FX5, _("FX"), wxDefaultPosition, wxSize( 28, -1 ), 0 );
	//itemFlexGridSizer4->Add(_drumControl[4]->_btnFx, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3 );

    _drumControl[4]->_chkOn = new wxCheckBox( itemDialog1, ID_SAMPLECHECK5, _T(""), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    _drumControl[4]->_chkOn->SetValue(true);
    itemFlexGridSizer4->Add(_drumControl[4]->_chkOn, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[4]->_sampleName = new wxTextCtrl( itemDialog1, ID_SAMPLE5, wxFileName(_filenames[4]).GetName(), wxDefaultPosition, filenameSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[4]->_sampleName, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[4]->_btnBrowse = new wxButton( itemDialog1, ID_BROWSE5, _("Browse"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[4]->_btnBrowse, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[5]->_label = new wxStaticText( itemDialog1, wxID_STATIC, _T("6:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[5]->_label, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 2);

    wxBoxSizer* itemBoxSizer69 = new wxBoxSizer(wxHORIZONTAL);
    itemFlexGridSizer4->Add(itemBoxSizer69, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    _drumControl[5]->_onButton = new wxRadioButton( itemDialog1, ID_DRUM6_ON, _("On"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
    _drumControl[5]->_onButton->SetValue(true);
    itemBoxSizer69->Add(_drumControl[5]->_onButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[5]->_offButton = new wxRadioButton( itemDialog1, ID_DRUM6_OFF, _("Off"), wxDefaultPosition, wxDefaultSize, 0 );
    _drumControl[5]->_offButton->SetValue(false);
    itemBoxSizer69->Add(_drumControl[5]->_offButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[5]->_drumSelection = new wxChoice( itemDialog1, ID_DRUMCOMBO6, wxDefaultPosition, instrumentSize, 46, midiNoteChoices, 0 );
    _drumControl[5]->_drumSelection->SetStringSelection(_("Low Tom"));
    itemFlexGridSizer4->Add(_drumControl[5]->_drumSelection, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[5]->_avgDensity = new wxChoice( itemDialog1, ID_DENSITY6, wxDefaultPosition, densitySize, 17, drumDensityChoices, 0 );
    _drumControl[5]->_avgDensity->SetStringSelection(_("0.063"));
    itemFlexGridSizer4->Add(_drumControl[5]->_avgDensity, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[5]->_btnSurvive = new wxButton( itemDialog1, ID_SURVIVE6, _("Survive"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[5]->_btnSurvive, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[5]->_btnDie = new wxButton( itemDialog1, ID_DIE6, _("Die"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[5]->_btnDie, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[5]->_btnInvert = new wxButton( itemDialog1, ID_INVERT6, _("Invert"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[5]->_btnInvert, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[5]->_volSlider = new wxSlider( itemDialog1, ID_VOLUME6, 100, 0, 200, wxDefaultPosition, wxSize(100, 22), wxNO_BORDER );
    itemFlexGridSizer4->Add(_drumControl[5]->_volSlider, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 1 );

	//_drumControl[5]->_btnFx = new wxButton( itemDialog1, ID_FX6, _("FX"), wxDefaultPosition, wxSize( 28, -1 ), 0 );
	//itemFlexGridSizer4->Add(_drumControl[5]->_btnFx, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3 );

    _drumControl[5]->_chkOn = new wxCheckBox( itemDialog1, ID_SAMPLECHECK6, _T(""), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    _drumControl[5]->_chkOn->SetValue(true);
    itemFlexGridSizer4->Add(_drumControl[5]->_chkOn, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[5]->_sampleName = new wxTextCtrl( itemDialog1, ID_SAMPLE6, wxFileName(_filenames[5]).GetName(), wxDefaultPosition, filenameSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[5]->_sampleName, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[5]->_btnBrowse = new wxButton( itemDialog1, ID_BROWSE6, _("Browse"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[5]->_btnBrowse, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[6]->_label = new wxStaticText( itemDialog1, wxID_STATIC, _T("7:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[6]->_label, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 2);

    wxBoxSizer* itemBoxSizer80 = new wxBoxSizer(wxHORIZONTAL);
    itemFlexGridSizer4->Add(itemBoxSizer80, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    _drumControl[6]->_onButton = new wxRadioButton( itemDialog1, ID_DRUM7_ON, _("On"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
    _drumControl[6]->_onButton->SetValue(true);
    itemBoxSizer80->Add(_drumControl[6]->_onButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[6]->_offButton = new wxRadioButton( itemDialog1, ID_DRUM7_OFF, _("Off"), wxDefaultPosition, wxDefaultSize, 0 );
    _drumControl[6]->_offButton->SetValue(false);
    itemBoxSizer80->Add(_drumControl[6]->_offButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[6]->_drumSelection = new wxChoice( itemDialog1, ID_DRUMCOMBO7, wxDefaultPosition, instrumentSize, 46, midiNoteChoices, 0 );
    _drumControl[6]->_drumSelection->SetStringSelection(_("Low-Mid Tom"));
    itemFlexGridSizer4->Add(_drumControl[6]->_drumSelection, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[6]->_avgDensity = new wxChoice( itemDialog1, ID_DENSITY7, wxDefaultPosition, densitySize, 17, drumDensityChoices, 0 );
    _drumControl[6]->_avgDensity->SetStringSelection(_("0.063"));
    itemFlexGridSizer4->Add(_drumControl[6]->_avgDensity, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[6]->_btnSurvive = new wxButton( itemDialog1, ID_SURVIVE7, _("Survive"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[6]->_btnSurvive, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[6]->_btnDie = new wxButton( itemDialog1, ID_DIE7, _("Die"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[6]->_btnDie, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[6]->_btnInvert = new wxButton( itemDialog1, ID_INVERT7, _("Invert"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[6]->_btnInvert, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[6]->_volSlider = new wxSlider( itemDialog1, ID_VOLUME7, 100, 0, 200, wxDefaultPosition, wxSize(100, 22), wxNO_BORDER );
    itemFlexGridSizer4->Add(_drumControl[6]->_volSlider, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 1 );

	//_drumControl[6]->_btnFx = new wxButton( itemDialog1, ID_FX7, _("FX"), wxDefaultPosition, wxSize( 28, -1 ), 0 );
	//itemFlexGridSizer4->Add(_drumControl[6]->_btnFx, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3 );

    _drumControl[6]->_chkOn = new wxCheckBox( itemDialog1, ID_SAMPLECHECK7, _T(""), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    _drumControl[6]->_chkOn->SetValue(true);
    itemFlexGridSizer4->Add(_drumControl[6]->_chkOn, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[6]->_sampleName = new wxTextCtrl( itemDialog1, ID_SAMPLE7, wxFileName(_filenames[6]).GetName(), wxDefaultPosition, filenameSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[6]->_sampleName, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[6]->_btnBrowse = new wxButton( itemDialog1, ID_BROWSE7, _("Browse"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[6]->_btnBrowse, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[7]->_label = new wxStaticText( itemDialog1, wxID_STATIC, _T("8:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[7]->_label, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 2);

    wxBoxSizer* itemBoxSizer91 = new wxBoxSizer(wxHORIZONTAL);
    itemFlexGridSizer4->Add(itemBoxSizer91, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    _drumControl[7]->_onButton = new wxRadioButton( itemDialog1, ID_DRUM8_ON, _("On"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
    _drumControl[7]->_onButton->SetValue(true);
    itemBoxSizer91->Add(_drumControl[7]->_onButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[7]->_offButton = new wxRadioButton( itemDialog1, ID_DRUM8_OFF, _("Off"), wxDefaultPosition, wxDefaultSize, 0 );
    _drumControl[7]->_offButton->SetValue(false);
    itemBoxSizer91->Add(_drumControl[7]->_offButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[7]->_drumSelection = new wxChoice( itemDialog1, ID_DRUMCOMBO8, wxDefaultPosition, instrumentSize, 46, midiNoteChoices, 0 );
    _drumControl[7]->_drumSelection->SetStringSelection(_("High-Mid Tom"));
    itemFlexGridSizer4->Add(_drumControl[7]->_drumSelection, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[7]->_avgDensity = new wxChoice( itemDialog1, ID_DENSITY8, wxDefaultPosition, densitySize, 17, drumDensityChoices, 0 );
    _drumControl[7]->_avgDensity->SetStringSelection(_("0.063"));
    itemFlexGridSizer4->Add(_drumControl[7]->_avgDensity, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[7]->_btnSurvive = new wxButton( itemDialog1, ID_SURVIVE8, _("Survive"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[7]->_btnSurvive, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[7]->_btnDie = new wxButton( itemDialog1, ID_DIE8, _("Die"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[7]->_btnDie, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[7]->_btnInvert = new wxButton( itemDialog1, ID_INVERT8, _("Invert"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[7]->_btnInvert, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[7]->_volSlider = new wxSlider( itemDialog1, ID_VOLUME8, 100, 0, 200, wxDefaultPosition, wxSize(100, 22), wxNO_BORDER );
    itemFlexGridSizer4->Add(_drumControl[7]->_volSlider, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 1 );

	//_drumControl[7]->_btnFx = new wxButton( itemDialog1, ID_FX8, _("FX"), wxDefaultPosition, wxSize( 28, -1 ), 0 );
	//itemFlexGridSizer4->Add(_drumControl[7]->_btnFx, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3 );

    _drumControl[7]->_chkOn = new wxCheckBox( itemDialog1, ID_SAMPLECHECK8, _T(""), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    _drumControl[7]->_chkOn->SetValue(true);
    itemFlexGridSizer4->Add(_drumControl[7]->_chkOn, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[7]->_sampleName = new wxTextCtrl( itemDialog1, ID_SAMPLE8, wxFileName(_filenames[7]).GetName(), wxDefaultPosition, filenameSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[7]->_sampleName, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _drumControl[7]->_btnBrowse = new wxButton( itemDialog1, ID_BROWSE8, _("Browse"), wxDefaultPosition, buttonSize, 0 );
    itemFlexGridSizer4->Add(_drumControl[7]->_btnBrowse, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

    wxBoxSizer* itemBoxSizer102 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer102, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer103 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer102->Add(itemBoxSizer103, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxBoxSizer* itemBoxSizer104 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer103->Add(itemBoxSizer104, 0, wxALIGN_LEFT|wxALL, 0);

    _chkKickFirstBeat = new wxCheckBox( itemDialog1, ID_KICKONE, _("Kick on First Beat"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    _chkKickFirstBeat->SetValue(false);
    itemBoxSizer104->Add(_chkKickFirstBeat, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    _chkSimilarMeasures = new wxCheckBox( itemDialog1, ID_SIMILARMEASURES, _("Similar Measures"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    _chkSimilarMeasures->SetValue(true);
    itemBoxSizer104->Add(_chkSimilarMeasures, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    _chkVaryVolume = new wxCheckBox( itemDialog1, ID_VARYVOLUME, _("Vary Volume"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    _chkVaryVolume->SetValue(false);
    itemBoxSizer104->Add(_chkVaryVolume, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    _chkHihatCancel = new wxCheckBox( itemDialog1, ID_CHECK_HIHAT_CANCEL, _("Hihat Cancellation"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    _chkHihatCancel->SetValue(false);
    itemBoxSizer104->Add(_chkHihatCancel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

	wxBoxSizer* itemBoxSizer108 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer103->Add(itemBoxSizer108, 0, wxALIGN_LEFT|wxALL, 0);

    wxStaticText* itemStaticText109 = new wxStaticText( itemDialog1, wxID_STATIC, _("BPM:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer108->Add(itemStaticText109, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    _txtBPM = new wxTextCtrl( itemDialog1, ID_BPM, _("130"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer108->Add(_txtBPM, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

	wxStaticText* itemStaticText110 = new wxStaticText( itemDialog1, wxID_STATIC, _("Swing"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer108->Add(itemStaticText110, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

	_swingSlider = new wxSlider( itemDialog1, ID_SWING_SLIDER, 100, 100, 150, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	itemBoxSizer108->Add(_swingSlider, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxStaticText* itemStaticText112 = new wxStaticText( itemDialog1, wxID_STATIC, _("Base Pattern"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer108->Add(itemStaticText112, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxString _basePatternStrings[] = {
        _("Random"),
		_("Clear"),
        _("Basic Rock" ),
		_("Basic Rock 2"),
		_("Basic Rock 3"),
		_("Basic Funk" ),
        _("Oontz"),
        _("Fibonacci"),
        _("Sierpinski"),
        _("Sierpinski Inverted")
    };
    _basePattern = new wxChoice( itemDialog1, ID_BASEPATTERN, wxDefaultPosition, wxSize( -1, -1 ), 10, _basePatternStrings, 0 );
    _basePattern->SetSelection(0);
    itemBoxSizer108->Add(_basePattern, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer114 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer103->Add(itemBoxSizer114, 0, wxALIGN_LEFT|wxALL, 0);

    wxStaticText* itemStaticText115 = new wxStaticText( itemDialog1, wxID_STATIC, _("MIDI Device"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer114->Add(itemStaticText115, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxString _midiDeviceStrings[] = {
		_("MIDI Mapper")
    };
    _midiDevice = new wxChoice( itemDialog1, ID_MIDIDEVICE, wxDefaultPosition, wxSize( -1, -1 ), 1, _midiDeviceStrings, 0 );
    _midiDevice->SetStringSelection(_("Disabled"));
    itemBoxSizer114->Add(_midiDevice, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText117 = new wxStaticText( itemDialog1, wxID_STATIC, _("Channel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer114->Add(itemStaticText117, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxString itemChoice118Strings[] = {
        _("1"),
        _("2"),
        _("3"),
        _("4"),
        _("5"),
        _("6"),
        _("7"),
        _("8"),
        _("9"),
        _("10"),
        _("11"),
        _("12"),
        _("13"),
        _("14"),
        _("15"),
        _("16")
    };
    _midiChannel = new wxChoice( itemDialog1, ID_MIDICHANNEL, wxDefaultPosition, wxSize(48, -1), 16, itemChoice118Strings, 0 );
    _midiChannel->SetStringSelection(_("10"));
    itemBoxSizer114->Add(_midiChannel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer119 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer103->Add(itemBoxSizer119, 0, wxALIGN_LEFT|wxALL, 0);

    _chkMidiOn = new wxCheckBox( itemDialog1, ID_CHECK_MIDION, _("On"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    _chkMidiOn->SetValue(false);
    itemBoxSizer114->Add(_chkMidiOn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    _chkMutate = new wxCheckBox( itemDialog1, ID_CHECKMUTATE, _("Mutate Every"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    _chkMutate->SetValue(false);
    itemBoxSizer119->Add(_chkMutate, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    _txtMutateMeasures = new wxTextCtrl( itemDialog1, ID_MUTATEMEASURES, _("8"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer119->Add(_txtMutateMeasures, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText122 = new wxStaticText( itemDialog1, wxID_STATIC, _("Measures"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer119->Add(itemStaticText122, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText123 = new wxStaticText( itemDialog1, wxID_STATIC, _("Mutation Rate (0 to 1)"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer119->Add(itemStaticText123, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    _txtMutateRate = new wxTextCtrl( itemDialog1, ID_MUTATERATE, _("0.06"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer119->Add(_txtMutateRate, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer124 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer103->Add(itemBoxSizer124, 0, wxALIGN_LEFT|wxALL, 0);

    _btnStart = new wxButton( itemDialog1, ID_START, _("Start"), wxDefaultPosition, wxSize( 84, -1 ), 0 );
    itemBoxSizer124->Add(_btnStart, 0, wxALIGN_CENTER_VERTICAL|wxALL, 2);

    _btnStop = new wxButton( itemDialog1, ID_STOP, _("Stop"), wxDefaultPosition, wxSize( 84, -1 ), 0 );
    itemBoxSizer124->Add(_btnStop, 0, wxALIGN_CENTER_VERTICAL|wxALL, 2);

    _btnEditDrumData = new wxButton( itemDialog1, ID_DRUM_DATA_EDIT, _("Edit Notes"), wxDefaultPosition, wxSize( 84, -1 ), 0 );
    itemBoxSizer124->Add(_btnEditDrumData, 0, wxALIGN_CENTER_VERTICAL|wxALL, 2);

#ifdef _DEMOVERSION
    _btnPurchase = new wxButton( itemDialog1, ID_PURCHASE, _("Purchase"), wxDefaultPosition, wxSize( 84, -1 ), 0 );
    itemBoxSizer124->Add(_btnPurchase, 0, wxALIGN_CENTER_VERTICAL|wxALL, 2 );
#endif

	wxBoxSizer* itemBoxSizer294 = new wxBoxSizer(wxVERTICAL);
	itemBoxSizer102->Add(itemBoxSizer294, 0, wxALIGN_LEFT|wxALL, 0);

    wxString radioMeasuresStrings[] = {
        _("&One"),
        _("&Two"),
        _("Th&ree"),
        _("&Four")
    };
    _radioMeasures = new wxRadioBox( itemDialog1, ID_MEASURES_RADIOBOX, _("Measures"), wxDefaultPosition, wxDefaultSize, 4, radioMeasuresStrings, 4, wxRA_SPECIFY_ROWS );
    itemBoxSizer294->Add(_radioMeasures, 0, wxALIGN_TOP|wxALL, 2);

    wxStaticText* itemStaticText315 = new wxStaticText( itemDialog1, wxID_STATIC, _("Division"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer294->Add(itemStaticText315, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 3);

	wxString divisionStrings[] = {
		_("Quarter"),
	    _("Eighth"),
		_("Sixteenth")
	};
	_chcDivision = new wxChoice( itemDialog1, ID_DIVISION, wxDefaultPosition, wxSize(84, -1), 3, divisionStrings, 0 );
	_chcDivision->SetSelection(1);
	itemBoxSizer294->Add(_chcDivision, 0, wxALIGN_TOP|wxALL, 2 );

    wxString _radioTimeSignatureStrings[] = {
        _("3/4"),
        _("4/4"),
        _("5/4"),
        _("7/8"),
        _("9/8"),
        _("11/8")
    };
    _radioTimeSignature = new wxRadioBox( itemDialog1, ID_SIGNATURE_RADIOBOX, _("Signature"), wxDefaultPosition, wxDefaultSize, 6, _radioTimeSignatureStrings, 6, wxRA_SPECIFY_ROWS );
	_radioTimeSignature->SetSelection( 1 );
    itemBoxSizer102->Add(_radioTimeSignature, 0, wxALIGN_TOP|wxALL, 2);

    wxBoxSizer* itemBoxSizer133 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer102->Add(itemBoxSizer133, 0, wxALIGN_TOP|wxALL, 0);

    _btnAbout = new wxButton( itemDialog1, ID_ABOUT, _("About"), wxDefaultPosition, wxSize( 96, -1 ), 0 );
    itemBoxSizer133->Add(_btnAbout, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    _btnRegenerate = new wxButton( itemDialog1, ID_CLEANSLATE, _("Regenerate"), wxDefaultPosition, wxSize( 96, -1 ), 0 );
    itemBoxSizer133->Add(_btnRegenerate, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    _btnSaveMidi = new wxButton( itemDialog1, ID_SAVEMIDI, _("Save MIDI"), wxDefaultPosition, wxSize( 96, -1 ), 0 );
    itemBoxSizer133->Add(_btnSaveMidi, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    _btnSavePattern = new wxButton( itemDialog1, ID_SAVE_PATTERN, _("Save Pattern"), wxDefaultPosition, wxSize( 96, -1 ), 0 );
    itemBoxSizer133->Add(_btnSavePattern, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    _btnLoadPattern = new wxButton( itemDialog1, ID_LOAD_PATTERN, _("Load Pattern"), wxDefaultPosition, wxSize( 96, -1 ), 0 );
    itemBoxSizer133->Add(_btnLoadPattern, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    _btnExit = new wxButton( itemDialog1, ID_EXIT, _("Exit"), wxDefaultPosition, wxSize( 96, -1 ), 0 );
    itemBoxSizer133->Add(_btnExit, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

	if( _icon.LoadFile(_T("algo.ico"), wxBITMAP_TYPE_ICO ))
	{
		SetIcon(_icon);
	}
}

AlgoRhythmia::AlgoRhythmia( )
{
}

AlgoRhythmia::~AlgoRhythmia()
{
	// Make sure all notes are off and close the MIDI device
#ifdef WIN32
	_mutex.Lock();
	if( _outHandle )
	{
		midiOutShortMsg(_outHandle, 0x00007BB0);	
		midiOutClose(_outHandle);
	}

	// Uninitialize XAudio2
	int count;
	for( count = 0; count < DRUM_MAX; count++ )
	{
		if( _sourceVoice[count] )
		{
			_sourceVoice[count]->DestroyVoice();
			_sourceVoice[count] = NULL;
		}
	}
    SAFE_RELEASE( _xaudio2 );
	CoUninitialize();

	_mutex.Unlock();
#endif

	// Give everything a chance to finish up.
	Sleep(20);
}

void AlgoRhythmia::MutateAllDrums( )
{
	int count;
	for( count = 0; count < DRUM_MAX; count++ )
	{
		MutateDrum( count );
	}
}

void AlgoRhythmia::MutateDrum(int drum)
{
	// Run our algorithm to mutate the drum int passed to us.
	// Read the mutation rate (and maybe average density) boxes to let
	// us know generally how to behave.
	int count;
	_mutex.Lock();
	_mutateRate = atof( _txtMutateRate->GetValue().mb_str() );
	if( _mutateRate >= 1.0 )
	{
		_mutateRate = 1.0;
	}
	else if( _mutateRate < 0.0 )
	{
		_mutateRate = 0.0;
	}

	float randomnumber;
	for( count = 0; count < MAX_PATTERN_SIZE; count++ )
	{
		randomnumber = (float)((float)rand() / (float)RAND_MAX);
		if( randomnumber < _mutateRate )
		{
			if( _drumControl[drum]->_noteData[count] )
			{
				_drumControl[drum]->_noteData[count] = false;
			}
			else
			{
				_drumControl[drum]->_noteData[count] = true;
			}
		}
	}
	if( _measureEditDlg != NULL )
	{
		_measureEditDlg->RefreshDrum(drum);
	}
	_mutex.Unlock();
}

void AlgoRhythmia::RegenerateDrum(int drum)
{
	// Run our algorithm to create the drum int passed to us.
	// Read the average density box to let us know generally how to behave.
	_mutex.Lock();
	double density = atof( _drumControl[drum]->_avgDensity->GetStringSelection().mb_str() );
	if( density == 0.0 )
	{
		density = 0.25;
	}

	float randomnumber;
	int count;
	int count2;
	// Check for similar.
	if( !_similarMeasures )
	{
		for( count = 0; count < MAX_MEASURES; count++ )
		{
			for( count2 = 0; count2 < MAX_MEASURE_LENGTH; count2++ )
			{
				randomnumber = (float)((float)rand() / (float)RAND_MAX);
				if( randomnumber < density )
				{
					_drumControl[drum]->_noteData[(count * MAX_MEASURE_LENGTH + count2)] = true;
				}
				else
				{
					_drumControl[drum]->_noteData[(count * MAX_MEASURE_LENGTH + count2)] = false;
				}
			}
		}
	}
	else
	{
		_mutateRate = atof( _txtMutateRate->GetValue().mb_str() );
		if( _mutateRate >= 1.0 )
		{
			_mutateRate = 1.0;
		}
		else if( _mutateRate < 0.0 )
		{
			_mutateRate = 0.0;
		}

		for( count = 0; count < MAX_MEASURE_LENGTH; count++ )
		{
			randomnumber = (float)((float)rand() / (float)RAND_MAX);
			if( randomnumber < density )
			{
				_drumControl[drum]->_noteData[count] = true;
			}
			else
			{
				_drumControl[drum]->_noteData[count] = false;
			}
		}
		for( count2 = 1; count2 < MAX_MEASURES; count2++ )
		{
			for( count = 0; count < MAX_MEASURE_LENGTH; count++ )
			{
				// Copy value from first measure into current measure position.
				_drumControl[drum]->_noteData[(count2 * MAX_MEASURE_LENGTH + count )] = _drumControl[drum]->_noteData[count];
				// Mutate as appropriate.
				randomnumber = (float)((float)rand() / (float)RAND_MAX);
				if( randomnumber < _mutateRate )
				{
					if( _drumControl[drum]->_noteData[(count2 * MAX_MEASURE_LENGTH + count )] )
					{
						_drumControl[drum]->_noteData[(count2 * MAX_MEASURE_LENGTH + count )] = false;
					}
					else
					{
						_drumControl[drum]->_noteData[(count2 * MAX_MEASURE_LENGTH + count )] = true;
					}
				}
			}
		}
	}
	_mutex.Unlock();
	if( _measureEditDlg != NULL )
	{
		_measureEditDlg->RefreshDrum(drum);
	}
}

void AlgoRhythmia::RegenerateAllDrums( void )
{
	int count;
	int selection = _basePattern->GetSelection();

	_mutex.Lock();
    for( count = 0; count < DRUM_MAX; count++ )
    {
        memset( _drumControl[count]->_noteData, 0, (sizeof(bool)*MAX_PATTERN_SIZE) );
    }
	_mutex.Unlock();

	switch( selection )
	{
	case STYLE_RANDOM: // Random
		for( count = 0; count < DRUM_MAX; count++ )
		{
			RegenerateDrum( count );
		}
		break;
	case STYLE_FIBONACCI: // Fibonacci
		{
			int drumNumber;
			_mutex.Lock();
			for( drumNumber = 0; drumNumber < DRUM_MAX; drumNumber++ )
			{
				for( count = 0; count < MAX_PATTERN_SIZE; count++ )
				{
					// Zero-based fibonacci sequence
					if( count == 0 || count == 1 || count == 2 || count == 4 ||
						count == 7 || count == 12 || count == 20 || count == 33 ||
						count == 54 )
					{
						_drumControl[drumNumber]->_noteData[count] = true;
					}
				}
			}
			_mutex.Unlock();
		}
		break;
	case STYLE_SIERPINSKI: // Sierpinski
		_mutex.Lock();
		for( count = 0; count < MAX_PATTERN_SIZE; count++ )
		{
			if( count % 27 == 0 )
			{
				_drumControl[2]->_noteData[count] = true;
			}
			if( count % 9 == 0 )
			{
				_drumControl[1]->_noteData[count] = true;
			}
			else if( count % 3 == 0 )
			{
				_drumControl[0]->_noteData[count] = true;
			}
			else
			{
				int countTwo;
				for( countTwo = 0; countTwo < DRUM_MAX; countTwo++ )
				{
					_drumControl[countTwo]->_noteData[count] = false;
				}
			}
		}
		_mutex.Unlock();
		break;
	case STYLE_SIERPINSKI_INV: // Sierpinski Inverted
		_mutex.Lock();
		for( count = 0; count < MAX_PATTERN_SIZE; count++ )
		{
			if( count % 27 == 0 )
			{
				_drumControl[0]->_noteData[count] = true;
			}
			if( count % 9 == 0 )
			{
				_drumControl[1]->_noteData[count] = true;
			}
			else if( count % 3 == 0 )
			{
				_drumControl[2]->_noteData[count] = true;
			}
			else
			{
				int countTwo;
				for( countTwo = 0; countTwo < DRUM_MAX; countTwo++ )
				{
					_drumControl[countTwo]->_noteData[count] = false;
				}
			}
		}
		_mutex.Unlock();
		break;
    case STYLE_ROCK1: // Basic Rock
		_mutex.Lock();
        for( count = 0; count < MAX_PATTERN_SIZE; count++ )
        {
            if( count % 8 != 7 )
            {
                _drumControl[2]->_noteData[count] = true;
            }
            else
            {
                _drumControl[3]->_noteData[count] = true;
            }
            if( count % 4 == 2 )
            {
                _drumControl[1]->_noteData[count] = true;
            }
            if( count % 4 == 0 )
            {
                _drumControl[0]->_noteData[count] = true;
            }
            if( count % 8 == 5 )
            {
                _drumControl[0]->_noteData[count] = true;
            }
        }
		_chcDivision->SetSelection( 1 );
		_division = 8;
		_mutex.Unlock();
        break;
    case STYLE_OONTZ: // Oontz
		_mutex.Lock();
        for( count = 0; count < MAX_PATTERN_SIZE; count++ )
        {
            if( count % 2 == 0 )
            {
                _drumControl[0]->_noteData[count] = true;
            }
            else
            {
                _drumControl[2]->_noteData[count] = true;
            }
		}
		_chcDivision->SetSelection( 1 );
		_division = 8;
		_mutex.Unlock();
	case STYLE_CLEAR: // Clear
		// Drums were already set to 0, so nothing to do.
		break;
	case STYLE_ROCK2: // Basic Rock 2
		_mutex.Lock();
        for( count = 0; count < MAX_PATTERN_SIZE; count++ )
        {
            if( count % 2 == 0 )
            {
                _drumControl[4]->_noteData[count] = true;
            }
            if( count % 4 == 2 )
            {
                _drumControl[1]->_noteData[count] = true;
            }
            if( count % 8 == 7 )
            {
                _drumControl[1]->_noteData[count] = true;
            }
            if( count % 4 == 0 )
            {
                _drumControl[0]->_noteData[count] = true;
            }
        }
		_chcDivision->SetSelection( 1 );
		_division = 8;
		_mutex.Unlock();
		break;
	case STYLE_ROCK3: // Basic Rock 3
		_mutex.Lock();
		for( count = 0; count < MAX_PATTERN_SIZE; count++ )
		{
			_drumControl[2]->_noteData[count] = true;
			if( count % 8 == 4 )
			{
				_drumControl[1]->_noteData[count] = true;
			}
			if( count % 8 == 0 || count % 8 == 2 || count % 8 == 5 || count % 8 == 7 )
			{
				_drumControl[0]->_noteData[count] = true;
			}
		}
		_chcDivision->SetSelection( 1 );
		_division = 8;
		_mutex.Unlock();
		break;
	case STYLE_FUNK1: // Basic Funk
		_mutex.Lock();
		for( count = 0; count < MAX_PATTERN_SIZE; count++ )
		{
			if( count % 2 == 0 )
			{
				_drumControl[2]->_noteData[count] = true;
			}
			if( (count % MAX_MEASURE_LENGTH) == 0 || (count % MAX_MEASURE_LENGTH) == 3 ||
                (count % MAX_MEASURE_LENGTH) == 10 || (count % MAX_MEASURE_LENGTH) == 13 ||
                (count % MAX_MEASURE_LENGTH) == 16 || (count % MAX_MEASURE_LENGTH) == 19 )
			{
				_drumControl[0]->_noteData[count] = true;
			}
			if( (count % MAX_MEASURE_LENGTH) == 4 || (count % MAX_MEASURE_LENGTH) == 12 ||
                (count % MAX_MEASURE_LENGTH) == 20 )
			{
				_drumControl[1]->_noteData[count] = true;
			}
			_chcDivision->SetSelection( 2 );
			_division = 16;
		}
		_mutex.Unlock();
	}
	if( _measureEditDlg != NULL )
	{
		_measureEditDlg->RefreshDrums();
	}
}

void AlgoRhythmia::InvertDrum( int drum )
{
	int count;
	_mutex.Lock();
	for( count = 0; count < MAX_PATTERN_SIZE; count++ )
	{
		_drumControl[drum]->_noteData[count] = !_drumControl[drum]->_noteData[count];
	}
	_mutex.Unlock();
	if( _measureEditDlg != NULL )
	{
		_measureEditDlg->RefreshDrum(drum);
	}
	return;
}

void AlgoRhythmia::SaveMIDI( void )
{
#ifdef _DEMOVERSION
    wxMessageBox( _("Save to MIDI is disabled in the demo version.") );
    return;
#endif
	wxFileDialog fdialog( NULL, _T("Choose a file to Save"), _T("."), _T("Save1"), _T("MIDI Files (*.mid) |*.mid||"), wxFD_SAVE|wxFD_CHANGE_DIR );

	wxString filename;

	if( fdialog.ShowModal() != wxID_OK )
	{
		return;
	}

    filename = fdialog.GetPath();
    FILE* fp;

	if( !( fp = fopen( filename.mb_str(), "wb" ) ) )
	{
		wxMessageBox( _("Could Not Save File"), _("Error"), wxOK );
		return;
	}

	// Write Header Information: MThd
	int ival = 0x6468544D;
	short sval;
	fwrite( &ival, 4, 1, fp );
	ival = 0x06000000;
	fwrite( &ival, 4, 1, fp );
	// Type 0 file: all on single track
	sval = 0x0000;
	fwrite( &sval, 2, 1, fp );
	// Single track.
	sval = 0x0100;
	fwrite( &sval, 2, 1, fp );
	// msec resolution
	//sval = 0x28E7;
    // 96 PPQN
    sval = 0x6000;
	fwrite( &sval, 2, 1, fp );

	// Write Track Information: MTrk
	ival = 0x6B72544D;
	fwrite( &ival, 4, 1, fp );

    char buffer[16384];
    memset( buffer, 0, 16384 );

    // Generate the MIDI data into the buffer so we can write it out.
    int bytes = PrepareMIDIBuffer( buffer, 16384 );

	// Luckily we have the size from our call to PrepareMIDIBuffer and can write this info after swapping it.
    // we make a copy because we still need this value for the last write.
    ival = bytes;
	Swap4Bytes(ival);
	fwrite( &ival, 4, 1, fp );

    // Dump the generated buffer to file.
    fwrite( buffer, bytes, 1, fp );

	// Cleanup and return.
	fclose( fp );

	return;
}

// Thread to play the beat - makes dialog independent of sound.
void* AlgoRhythmia::Entry( )
{
#ifdef WIN32
	DWORD fullWord;
	WORD hiWord;
	WORD loWord;
#endif
	// LARGE_INTEGER difference, sum;
	int counter = 0;
	static int mutateMeasure = 0;
	while( !TestDestroy())
	{
		_mutex.Lock();
		if( _playing == true )
		{
#ifdef WIN32
			QueryPerformanceCounter( &_currtime );
#endif
			// BPM / 60 = Beats per second.
			// Ticks per second / beats per second = ticks per beat.
			// 1 beat = quarter note.
			// We are treating each box as a beat, giving us 16 beats per pattern.  This makes
			// it easy because 1 box = 1 step = 1 beat.  We can change the ratio later if need be.
			//
			// difference.QuadPart = (currtime.QuadPart - lasttime.QuadPart);
			// sum.QuadPart = ((tickspersec.QuadPart * 60.0f ) / (float)bpm );
			// if( difference.QuadPart > sum.QuadPart )

			// Compensate for "swing" setting.
			double nextNoteTime;
			if( _step % 2 == 1 )
			{
				// Long note.
#ifdef WIN32
				nextNoteTime = ((_tickspersec.QuadPart * 60.0f ) / (float)_bpm) * _swingRatio;
#endif
				// Shorten time if we have eighth or sixteenth notes;
				if( _division == 16 )
				{
					nextNoteTime /= 4;
				}
				else if( _division == 8 )
				{
					nextNoteTime /= 2;
				}
			}
			else
			{
				// Short note.
#ifdef WIN32
				nextNoteTime = ((_tickspersec.QuadPart * 60.0f ) / (float)_bpm) * (2.0 - _swingRatio );
#endif
				// Shorten time if we have eighth or sixteenth notes;
				if( _division == 16 )
				{
					nextNoteTime /= 4;
				}
				else if( _division == 8 )
				{
					nextNoteTime /= 2;
				}
			}

#ifdef WIN32
			if( (_currtime.QuadPart - _lasttime.QuadPart) > nextNoteTime )
#else
            if( 1 )
#endif
			{
				// Increment the current step and wrap it at our max steps count.
				// We're using 0 to N-1 for our step count.  Increment post-beat.
				if( _step >= _timesignature )
				{
					_measure++;
					mutateMeasure++;
					if( _periodicmutate && ((mutateMeasure % _periodicmutatemeasures) == 0) )
					{
						MutateAllDrums();
					}
					_step = 0;
					if( _measure >= _measures )
					{
						_measure = 0;
					}
				}

				int note = _measure * MAX_MEASURE_LENGTH + _step;

				if( note > MAX_PATTERN_SIZE )
				{
                    wxMessageBox( _("We went past our maximum pattern length."), _("Programmer's a Retard"), wxOK );
				}

				// Now, play our sounds that are set to be on that beat.
				// This gets a little stupid because we have to know our checkbox names.
				if( _alwayskickone && _step == 0 )
				{
#ifdef WIN32
					if( _midiOn && _outHandle )
					{
						midiOutShortMsg(_outHandle, (0x007F2390 + _midichannel));
					}
					if( _drumControl[0]->_sampleOn )
					{
						_sourceVoice[0]->Stop(XAUDIO2_PLAY_TAILS, XAUDIO2_COMMIT_NOW);
						_sourceVoice[0]->SubmitSourceBuffer(_wave[0]->GetXAudio2Buffer());
						_sourceVoice[0]->Start(0, XAUDIO2_COMMIT_NOW);
					}
#endif
				}
				bool hihatEnabled = true;
				for( counter = 0; counter < DRUM_MAX; counter++ )
				{
					// Used for hihat cancellation checking.
					if( (_drumControl[counter]->_drumOn == true) && (_drumControl[counter]->_noteData[note] == true) )
					{
						// Check whether it's a hihat that we need to skip.
						if( _drumControl[counter]->_drumNote == 4 || // Closed Hi-hat
							_drumControl[counter]->_drumNote == 5 || // Pedal Hi-hat
							_drumControl[counter]->_drumNote == 6 )  // Open Hi-hat
						{
							if( hihatEnabled == false )
							{
								// Skip it.
								continue;
							}
							if( hihatEnabled == true && _hihatCancel == true )
							{
								// We'll play it, but we set enabled to false so we don't play it next time around.
								hihatEnabled = false;
							}
						}
#ifdef WIN32
						if( !_varyvolume )
						{
							loWord = MAKEWORD( _drumControl[counter]->_midiVolume, 0x00 );
						}
						else
						{
							if( _drumControl[counter]->_midiVolume > 15 )
							{
								loWord = MAKEWORD( ((rand() % 16) + (_drumControl[counter]->_midiVolume - 16)), 0x00 );
							}
							else
							{
								loWord = MAKEWORD( (rand() % 16), 0x00 );
							}
						}
						hiWord = MAKEWORD( (0x90 + _midichannel), midival[_drumControl[counter]->_drumNote] );
						fullWord = MAKELONG( hiWord, loWord );
						if( _midiOn && _outHandle )
						{
							midiOutShortMsg(_outHandle, fullWord );
						}
						if( _drumControl[counter]->_sampleOn && _sourceVoice[counter] != NULL )
						{
							_sourceVoice[counter]->Stop(XAUDIO2_PLAY_TAILS, XAUDIO2_COMMIT_NOW);
							XAUDIO2_BUFFER* buffer = _wave[counter]->GetXAudio2Buffer();
							_sourceVoice[counter]->SubmitSourceBuffer(buffer);
							_sourceVoice[counter]->Start(0, XAUDIO2_COMMIT_NOW);
						}
#endif
					}
				}
				// Set our time so we know when to play the next beat.
				// By not adding the time it took us to actually play the beat we maintain timing consistency.
#ifdef WIN32
				_lasttime = _currtime;
#endif
				++_step;
				_mutex.Unlock();
			}
			else
			{
				_mutex.Unlock();
				Sleep(1);
			}
		}
		else
		{
			_mutex.Unlock();
			Sleep(1);
		}
	}
	return 0;
}

void AlgoRhythmia::SampleBrowse( int drumNumber )
{
	// Make sure that we always default to ProgramDirectory\samples for browse.
	wxString pathName = wxStandardPaths::Get().GetDataDir() + _T("\\samples");
	wxFileDialog fdialog( NULL, _T("Choose a Sample"), pathName, _T(""), _T("Wave Files (*.wav) |*.wav||"), wxFD_OPEN );
	if( fdialog.ShowModal() != wxID_OK )
	{
		return;
	}

	// Free the old sample
#ifdef WIN32
	if( _sourceVoice[drumNumber] )
	{
		_sourceVoice[drumNumber]->DestroyVoice();
		_sourceVoice[drumNumber] = NULL;
	}
#endif

	_filenames[drumNumber] = fdialog.GetPath();

	_wave[drumNumber]->Load(_filenames[drumNumber].wchar_str());
	if( _wave[drumNumber] == NULL )
	{
		return;
		//wxMessageBox::Show(wxString::Format(_("Failed to load sample %s"), _filenames[drumNumber]), _("Sample Load Failed."));
	}

	_drumControl[drumNumber]->_sampleName->SetValue( wxFileName(_filenames[drumNumber]).GetName() );

	// Load the new sample.
#ifdef WIN32
	HRESULT hr;
	if( FAILED(hr = _xaudio2->CreateSourceVoice( &_sourceVoice[drumNumber], _wave[drumNumber]->GetWaveFormatEx(),
         0, XAUDIO2_DEFAULT_FREQ_RATIO, NULL, NULL, NULL ) ) )
	{
		return;
	}
#endif

	return;
}

void AlgoRhythmia::OnBrowse1Click( wxCommandEvent& event )
{
    SampleBrowse( 0 );
    event.Skip();
}

void AlgoRhythmia::OnBrowse2Click( wxCommandEvent& event )
{
    SampleBrowse( 1 );
    event.Skip();
}

void AlgoRhythmia::OnBrowse3Click( wxCommandEvent& event )
{
    SampleBrowse( 2 );
    event.Skip();
}

void AlgoRhythmia::OnBrowse4Click( wxCommandEvent& event )
{
    SampleBrowse( 3 );
    event.Skip();
}

void AlgoRhythmia::OnBrowse5Click( wxCommandEvent& event )
{
    SampleBrowse( 4 );
    event.Skip();
}

void AlgoRhythmia::OnBrowse6Click( wxCommandEvent& event )
{
    SampleBrowse( 5 );
    event.Skip();
}

void AlgoRhythmia::OnBrowse7Click( wxCommandEvent& event )
{
    SampleBrowse( 6 );
    event.Skip();
}

void AlgoRhythmia::OnBrowse8Click( wxCommandEvent& event )
{
    SampleBrowse( 7 );
    event.Skip();
}

void AlgoRhythmia::SetSampleState( int drumNumber, bool enable )
{
	_drumControl[drumNumber]->_chkOn->SetValue( enable );
	_drumControl[drumNumber]->_sampleOn = enable;
}

void AlgoRhythmia::OnSamplecheck1Click( wxCommandEvent& event )
{
	bool enable = ( event.IsChecked() );
    SetSampleState( 0, enable );
    event.Skip();
}

void AlgoRhythmia::OnSamplecheck2Click( wxCommandEvent& event )
{
	bool enable = ( event.IsChecked() );
    SetSampleState( 1, enable );
    event.Skip();
}

void AlgoRhythmia::OnSamplecheck3Click( wxCommandEvent& event )
{
	bool enable = ( event.IsChecked() );
    SetSampleState( 2, enable );
    event.Skip();
}

void AlgoRhythmia::OnSamplecheck4Click( wxCommandEvent& event )
{
	bool enable = ( event.IsChecked() );
    SetSampleState( 3, enable );
    event.Skip();
}

void AlgoRhythmia::OnSamplecheck5Click( wxCommandEvent& event )
{
	bool enable = ( event.IsChecked() );
    SetSampleState( 4, enable );
    event.Skip();
}

void AlgoRhythmia::OnSamplecheck6Click( wxCommandEvent& event )
{
	bool enable = ( event.IsChecked() );
    SetSampleState( 5, enable );
    event.Skip();
}

void AlgoRhythmia::OnSamplecheck7Click( wxCommandEvent& event )
{
	bool enable = ( event.IsChecked() );
    SetSampleState( 6, enable );
    event.Skip();
}

void AlgoRhythmia::OnSamplecheck8Click( wxCommandEvent& event )
{
	bool enable = ( event.IsChecked() );
    SetSampleState( 7, enable );
    event.Skip();
}

void AlgoRhythmia::OnSurvive1Click( wxCommandEvent& event )
{
	MutateDrum( 0 );
    event.Skip();
}

void AlgoRhythmia::OnDie1Click( wxCommandEvent& event )
{
	RegenerateDrum( 0 );
    event.Skip();
}

void AlgoRhythmia::OnInvert1Click( wxCommandEvent& event )
{
	InvertDrum( 0 );
    event.Skip();
}

void AlgoRhythmia::OnSurvive2Click( wxCommandEvent& event )
{
	MutateDrum( 1 );
    event.Skip();
}

void AlgoRhythmia::OnDie2Click( wxCommandEvent& event )
{
	RegenerateDrum( 1 );
    event.Skip();
}

void AlgoRhythmia::OnInvert2Click( wxCommandEvent& event )
{
	InvertDrum( 1 );
    event.Skip();
}

void AlgoRhythmia::OnSurvive3Click( wxCommandEvent& event )
{
	MutateDrum( 2 );
    event.Skip();
}

void AlgoRhythmia::OnDie3Click( wxCommandEvent& event )
{
	RegenerateDrum( 2 );
    event.Skip();
}

void AlgoRhythmia::OnInvert3Click( wxCommandEvent& event )
{
	InvertDrum( 2 );
    event.Skip();
}

void AlgoRhythmia::OnSurvive4Click( wxCommandEvent& event )
{
	MutateDrum( 3 );
    event.Skip();
}

void AlgoRhythmia::OnDie4Click( wxCommandEvent& event )
{
	RegenerateDrum( 3 );
    event.Skip();
}

void AlgoRhythmia::OnInvert4Click( wxCommandEvent& event )
{
	InvertDrum( 3 );
    event.Skip();
}

void AlgoRhythmia::OnSurvive5Click( wxCommandEvent& event )
{
	MutateDrum( 4 );
    event.Skip();
}

void AlgoRhythmia::OnDie5Click( wxCommandEvent& event )
{
	RegenerateDrum( 4 );
    event.Skip();
}

void AlgoRhythmia::OnInvert5Click( wxCommandEvent& event )
{
	InvertDrum( 4 );
    event.Skip();
}

void AlgoRhythmia::OnSurvive6Click( wxCommandEvent& event )
{
	MutateDrum( 5 );
    event.Skip();
}

void AlgoRhythmia::OnDie6Click( wxCommandEvent& event )
{
	RegenerateDrum( 5 );
    event.Skip();
}

void AlgoRhythmia::OnInvert6Click( wxCommandEvent& event )
{
	InvertDrum( 5 );
    event.Skip();
}

void AlgoRhythmia::OnSurvive7Click( wxCommandEvent& event )
{
	MutateDrum( 6 );
    event.Skip();
}

void AlgoRhythmia::OnDie7Click( wxCommandEvent& event )
{
	RegenerateDrum( 6 );
    event.Skip();
}

void AlgoRhythmia::OnInvert7Click( wxCommandEvent& event )
{
	InvertDrum( 6 );
    event.Skip();
}

void AlgoRhythmia::OnSurvive8Click( wxCommandEvent& event )
{
	MutateDrum( 7 );
    event.Skip();
}

void AlgoRhythmia::OnDie8Click( wxCommandEvent& event )
{
	RegenerateDrum( 7 );
    event.Skip();
}

void AlgoRhythmia::OnInvert8Click( wxCommandEvent& event )
{
	InvertDrum( 7 );
    event.Skip();
}

void AlgoRhythmia::OnDensity1Selected( wxCommandEvent& event )
{
    // Nothing to do here: Density is only used on a regenerate.
    event.Skip();
}

void AlgoRhythmia::OnDensity2Selected( wxCommandEvent& event )
{
    // Nothing to do here: Density is only used on a regenerate.
    event.Skip();
}

void AlgoRhythmia::OnDensity3Selected( wxCommandEvent& event )
{
    // Nothing to do here: Density is only used on a regenerate.
    event.Skip();
}

void AlgoRhythmia::OnDensity4Selected( wxCommandEvent& event )
{
    // Nothing to do here: Density is only used on a regenerate.
    event.Skip();
}

void AlgoRhythmia::OnDensity5Selected( wxCommandEvent& event )
{
    // Nothing to do here: Density is only used on a regenerate.
    event.Skip();
}

void AlgoRhythmia::OnDensity6Selected( wxCommandEvent& event )
{
    // Nothing to do here: Density is only used on a regenerate.
    event.Skip();
}

void AlgoRhythmia::OnDensity7Selected( wxCommandEvent& event )
{
    // Nothing to do here: Density is only used on a regenerate.
    event.Skip();
}

void AlgoRhythmia::OnDensity8Selected( wxCommandEvent& event )
{
    // Nothing to do here: Density is only used on a regenerate.
    event.Skip();
}

void AlgoRhythmia::OnDrumcombo1Selected( wxCommandEvent& event )
{
	_drumControl[0]->_drumNote = event.GetSelection();
    event.Skip();
}

void AlgoRhythmia::OnDrumcombo2Selected( wxCommandEvent& event )
{
	_drumControl[1]->_drumNote = event.GetSelection();
    event.Skip();
}

void AlgoRhythmia::OnDrumcombo3Selected( wxCommandEvent& event )
{
	_drumControl[2]->_drumNote = event.GetSelection();
    event.Skip();
}

void AlgoRhythmia::OnDrumcombo4Selected( wxCommandEvent& event )
{
	_drumControl[3]->_drumNote = event.GetSelection();
    event.Skip();
}

void AlgoRhythmia::OnDrumcombo5Selected( wxCommandEvent& event )
{
	_drumControl[4]->_drumNote = event.GetSelection();
    event.Skip();
}

void AlgoRhythmia::OnDrumcombo6Selected( wxCommandEvent& event )
{
	_drumControl[5]->_drumNote = event.GetSelection();
    event.Skip();
}

void AlgoRhythmia::OnDrumcombo7Selected( wxCommandEvent& event )
{
	_drumControl[6]->_drumNote = event.GetSelection();
    event.Skip();
}

void AlgoRhythmia::OnDrumcombo8Selected( wxCommandEvent& event )
{
	_drumControl[7]->_drumNote = event.GetSelection();
    event.Skip();
}

void AlgoRhythmia::OnAboutClick( wxCommandEvent& event )
{
	// Show about box.
    wxAboutDialogInfo info;
#ifdef _DEMOVERSION
	info.SetName(_("AlgoRhythmia Demo"));
    info.SetLicense(_("The demo version of AlgoRhythmia is free software and may be distributed freely.  The full version of AlgoRhythmia is copyrighted software and may not be used without a license."));
#else
	info.SetName(_("AlgoRhythmia"));
    info.SetLicense(_("AlgoRhythmia is copyrighted software and may not be distributed without a license."));
#endif
    info.SetVersion(_("4.1"));
    info.SetCopyright(_("(c) 2005-2016 Zeta Centauri"));
	info.AddDeveloper(_("Jason Champion"));
	info.SetIcon(_icon);
	info.SetLicense(_("AlgoRhythmia is copyrighted software and may not be distributed without a license."));
	info.SetWebSite(_("http://zetacentauri.com"));
	info.SetDescription(_("AlgoRhythmia uses the wxWidgets and libsndfile libraries."));

    wxAboutBox(info);

    event.Skip();
}

void AlgoRhythmia::OnCleanslateClick( wxCommandEvent& event )
{
	RegenerateAllDrums();
    event.Skip();
}

void AlgoRhythmia::OnSavemidiClick( wxCommandEvent& event )
{
	SaveMIDI();
    event.Skip();
}

void AlgoRhythmia::OnExitClick( wxCommandEvent& event )
{
	wxThread::Pause();
	Sleep(10);
	//Delete();
	//Wait();
    Destroy();
    event.Skip();
}

void AlgoRhythmia::OnKickoneClick( wxCommandEvent& event )
{
	_alwayskickone = event.IsChecked();
    event.Skip();
}

void AlgoRhythmia::OnSimilarmeasuresClick( wxCommandEvent& event )
{
    _similarMeasures = event.IsChecked();
    event.Skip();
}

void AlgoRhythmia::OnVaryvolumeClick( wxCommandEvent& event )
{
	_varyvolume = event.IsChecked();
    event.Skip();
}

void AlgoRhythmia::OnBasepatternSelected( wxCommandEvent& event )
{
    // Nothing to do here: This is only used on regenerate.
    event.Skip();
}

void AlgoRhythmia::OnMidideviceSelected( wxCommandEvent& event )
{
#ifdef WIN32
	if( _outHandle )
	{
		midiOutClose(_outHandle);
	}
	/* Open the MIDI Device */
    int selection = event.GetSelection();
	HRESULT result = midiOutOpen(&_outHandle, selection, 0, 0, CALLBACK_WINDOW);
	if (result)
	{
        wxMessageBox( _("There was an error opening the MIDI device!"), _("Device Error"), wxOK );
	}
#endif
	// MessageBox( NULL, "Midi device selected", "Midi", MB_OK );
    event.Skip();
}

void AlgoRhythmia::OnMidichannelSelected( wxCommandEvent& event )
{
    _midichannel = event.GetSelection();
    event.Skip();
}

void AlgoRhythmia::OnCheckmutateClick( wxCommandEvent& event )
{
	_periodicmutate = event.IsChecked();
	_txtMutateMeasures->Enable( _periodicmutate );
	_periodicmutatemeasures = atoi( _txtMutateMeasures->GetValue().mb_str() );
    event.Skip();
}

void AlgoRhythmia::OnMutatemeasuresUpdated( wxCommandEvent& event )
{
	if( _txtMutateMeasures != NULL )
	{
		_periodicmutatemeasures = atoi( _txtMutateMeasures->GetValue().mb_str() );
	}
    event.Skip();
}

void AlgoRhythmia::OnBpmUpdated( wxCommandEvent& event )
{
	if( _txtBPM != NULL )
	{
		_bpm = atoi( _txtBPM->GetValue().mb_str() );
	}
    event.Skip();
}

void AlgoRhythmia::OnStartClick( wxCommandEvent& event )
{
	_mutex.Lock();
	if( _bpm != 0 )
	{
		_playing = true;
		_step = 0;
		_measure = 0;
		_mutex.Unlock();
	}
	else
	{
		_mutex.Unlock();
		wxMessageBox( _("I refuse to play with 0 beats per minute."), _("Stupid Human"), wxOK );
        return;
	}

    event.Skip();
}

void AlgoRhythmia::OnStopClick( wxCommandEvent& event )
{
	_mutex.Lock();
	_playing = false;
#ifdef WIN32
	for( int i = 0; i < DRUM_MAX; i++ )
	{
		if( _sourceVoice[i] != NULL )
		{
			_sourceVoice[i]->Stop();
			_sourceVoice[i]->FlushSourceBuffers();
		}
	}
	// Make sure all notes are off.
	if( _outHandle != NULL )
	{
		midiOutShortMsg(_outHandle, 0x00007BB0);
	}
#endif
	_step = 0;
	_mutex.Unlock();
    event.Skip();
}

void AlgoRhythmia::OnEditNotesClick( wxCommandEvent& event )
{
    static bool state = _measureEditDlg->IsShown();
    _measureEditDlg->Show(!state);
    event.Skip();
}

void AlgoRhythmia::OnMeasuresRadioboxSelected( wxCommandEvent& event )
{
	_measures = _radioMeasures->GetSelection() + 1;
	_measureEditDlg->_numMeasures = _measures;
	_measureEditDlg->SetActiveRows();
    event.Skip();
}

void AlgoRhythmia::OnSignatureRadioboxSelected( wxCommandEvent& event )
{
	int selection = _radioTimeSignature->GetSelection();
	_mutex.Lock();
	switch( selection )
	{
	case 0: // 3-4
		_timesignature = 12;
		break;
	case 1: // 4-4
		_timesignature = 16;
		break;
	case 2: // 5-4
		_timesignature = 20;
		break;
	case 3: // 7-8
		_timesignature = 14;
		break;
	case 4: // 9-8
		_timesignature = 18;
		break;
	case 5: // 11-8
		_timesignature = 22;
		break;
	}
	_mutex.Unlock();
	_measureEditDlg->SetActiveColumns( _timesignature );
    event.Skip();
}

void AlgoRhythmia::SetDrumEnabled( bool enable, int drum )
{
	_drumControl[drum]->_drumOn = enable;
	_drumControl[drum]->_drumSelection->Enable(enable);
	_measureEditDlg->SetActiveRows();
}

void AlgoRhythmia::OnDrum8OffSelected( wxCommandEvent& event )
{
    SetDrumEnabled( false, 7 );
    event.Skip();
}

void AlgoRhythmia::OnDrum7OffSelected( wxCommandEvent& event )
{
    SetDrumEnabled( false, 6 );
    event.Skip();
}

void AlgoRhythmia::OnDrum6OffSelected( wxCommandEvent& event )
{
    SetDrumEnabled( false, 5 );
    event.Skip();
}

void AlgoRhythmia::OnDrum5OffSelected( wxCommandEvent& event )
{
    SetDrumEnabled( false, 4 );
    event.Skip();
}

void AlgoRhythmia::OnDrum4OffSelected( wxCommandEvent& event )
{
    SetDrumEnabled( false, 3 );
    event.Skip();
}

void AlgoRhythmia::OnDrum3OffSelected( wxCommandEvent& event )
{
    SetDrumEnabled( false, 2 );
    event.Skip();
}

void AlgoRhythmia::OnDrum2OffSelected( wxCommandEvent& event )
{
    SetDrumEnabled( false, 1 );
    event.Skip();
}

void AlgoRhythmia::OnDrum1OffSelected( wxCommandEvent& event )
{
    SetDrumEnabled( false, 0 );
    event.Skip();
}

void AlgoRhythmia::OnDrum1OnSelected( wxCommandEvent& event )
{
    SetDrumEnabled( true, 0 );
    event.Skip();
}

void AlgoRhythmia::OnDrum2OnSelected( wxCommandEvent& event )
{
    SetDrumEnabled( true, 1 );
    event.Skip();
}

void AlgoRhythmia::OnDrum3OnSelected( wxCommandEvent& event )
{
    SetDrumEnabled( true, 2 );
    event.Skip();
}

void AlgoRhythmia::OnDrum4OnSelected( wxCommandEvent& event )
{
    SetDrumEnabled( true, 3 );
    event.Skip();
}

void AlgoRhythmia::OnDrum5OnSelected( wxCommandEvent& event )
{
    SetDrumEnabled( true, 4 );
    event.Skip();
}

void AlgoRhythmia::OnDrum6OnSelected( wxCommandEvent& event )
{
    SetDrumEnabled( true, 5 );
    event.Skip();
}

void AlgoRhythmia::OnDrum7OnSelected( wxCommandEvent& event )
{
    SetDrumEnabled( true, 6 );
    event.Skip();
}

void AlgoRhythmia::OnDrum8OnSelected( wxCommandEvent& event )
{
    SetDrumEnabled( true, 7 );
    event.Skip();
}

void AlgoRhythmia::OnCloseWindow( wxCloseEvent& event )
{
	// Stop playback before exiting to prevent segfault.
	wxCommandEvent cevent;
	OnStopClick( cevent );
	// Let things clean up a bit (i.e. let last note finish playing).  Not
	// doing so will likely cause a segfault in threading.
	Sleep(40);
	wxThread::Pause();
	Sleep(10);
    Destroy();
    event.Skip();
}

void AlgoRhythmia::OnLoadPatternClick( wxCommandEvent& event )
{
#ifdef _DEMOVERSION
    wxMessageBox( "Pattern load is disabled in the demo version." );
    return;
#endif
	wxFileDialog fdialog( NULL, _T("Choose a file to Load"), _T("."), _T("Pattern"), _T("AlgoRhythmia Files (*.algo) |*.algo||"), wxFD_OPEN );

	wxString fileName;
	
	if( fdialog.ShowModal() == wxID_OK )
	{
		fileName = fdialog.GetPath();
		LoadPattern( fileName );
	}
	else
	{
		return;
	}
    event.Skip();
}

void AlgoRhythmia::LoadPattern( wxString& filename )
{
    if( !_configData->Load( filename ))
    {
        wxMessageBox( _("Error loading configuration file."), filename );
        return;
    }

    int value = 0;
	_mutex.Lock();
	_bpm = atoi(_configData->GetValue( _("bpm") ).mb_str());
	_txtBPM->SetValue( wxString::Format( _("%d"), _bpm ) );
	_periodicmutatemeasures = atoi(_configData->GetValue( _("mutatemeasures") ).mb_str());
	_txtMutateMeasures->SetValue( wxString::Format( _("%d"), _periodicmutatemeasures ) );
	_mutateRate = atof(_configData->GetValue( _("mutaterate") ).mb_str());
	_txtMutateRate->SetValue( wxString::Format( _("%f"), _mutateRate ));
	_timesignature = atoi(_configData->GetValue( _("timesignature") ).mb_str());
	// TODO: Set radio button
	_measures = atoi(_configData->GetValue( _("measures") ).mb_str());
	// TODO: Set radio button
	_alwayskickone = atoi(_configData->GetValue( _("alwayskickone") ).mb_str());
	_chkKickFirstBeat->SetValue( _alwayskickone );
	_varyvolume = atoi(_configData->GetValue( _("varyvolume") ).mb_str());
	_chkVaryVolume->SetValue( _varyvolume );
    _periodicmutate = atoi(_configData->GetValue( _("periodicmutate") ).mb_str());
	_chkMutate->SetValue( _periodicmutate );
	_midichannel = atoi(_configData->GetValue( _("midichannel") ).mb_str());
	_midiChannel->SetSelection( _midichannel );
	_similarMeasures = atoi(_configData->GetValue( _("similarmeasures") ).mb_str());
	_chkSimilarMeasures->SetValue( _similarMeasures );
	value = atoi(_configData->GetValue( _("basepattern") ).mb_str());
	_basePattern->SetSelection ( value );
	int count;
#ifdef WIN32
	HRESULT hr;
#endif
	for( count = 0; count < DRUM_MAX; count++ )
	{
		_drumControl[count]->_drumOn = atoi(_configData->GetValue( wxString::Format(_("drumcontrol%ddrumon"), count ) ).mb_str());
		_drumControl[count]->_onButton->SetValue( _drumControl[count]->_drumOn );
		_drumControl[count]->_offButton->SetValue( !_drumControl[count]->_drumOn );
		_drumControl[count]->_sampleOn = atoi(_configData->GetValue( wxString::Format(_("drumcontrol%dsampleon"), count ) ).mb_str());
		_drumControl[count]->_chkOn->SetValue( _drumControl[count]->_sampleOn );
		_drumControl[count]->_drumNote = atoi(_configData->GetValue( wxString::Format(_("drumcontrol%ddrumnote"), count ) ).mb_str());
		value = atoi(_configData->GetValue( wxString::Format(_("drumcontrol%ddrumselection"), count ) ).mb_str());
		_drumControl[count]->_drumSelection->SetSelection( value );
		// Set up sample.
		wxString name;
		name = _configData->GetValue( wxString::Format(_("drumcontrol%dsamplename"), count ) );
		_filenames[count] = name;
		_drumControl[count]->_sampleName->SetValue( wxFileName(_filenames[count]).GetName() );
		if( _sourceVoice[count] )
		{
#ifdef WIN32
			_sourceVoice[count]->DestroyVoice();
#else
                        delete _sourceVoice[count];
#endif
			_sourceVoice[count] = NULL;
		}
		_wave[count]->Load(_filenames[count].wchar_str());
#ifdef WIN32
		if( FAILED(hr = _xaudio2->CreateSourceVoice( &_sourceVoice[count], _wave[count]->GetWaveFormatEx(),
            0, XAUDIO2_DEFAULT_FREQ_RATIO, NULL, NULL, NULL ) ) )
		{
			wxMessageBox(wxString::Format(_("Could not load sample %s, CreateSourceVoice returned %d"), _wave[count], hr));
			return;
		}
#endif
		// End set up sample.
		name = _configData->GetValue( wxString::Format(_("drumcontrol%davgdensity"), count ) );
		_drumControl[count]->_avgDensity->SetStringSelection( name );
		value = atoi(_configData->GetValue( wxString::Format(_("drumcontrol%ddensityselection"), count ) ).mb_str());
		_drumControl[count]->_avgDensity->SetSelection( value );
		int note;
		for ( note = 0; note < MAX_PATTERN_SIZE; note++ )
		{
           bool state = atoi(_configData->GetValue( wxString::Format(_("drumcontrol%dnotedata%d"), count, note )).mb_str());
		   _drumControl[count]->_noteData[note] = state;
		}


	// Load the new sample.

		// Store effects settings.
		//_drumControl[count]->_fxManager->ReadConfigurationSettings( count, _configData );
		//int fxnum;
		//bool state;
		//for( fxnum = 0; fxnum < EFFECT_MAX; fxnum++ )
		//{
		//	state = atoi(_configData->getValue( wxString::Format( "/drumcontrol%d/fx%denabled", count, fxnum )));
		//	//_drumControl[count]->_fxDialog->EnableEffect( fxnum, state );
		//}
		//_drumControl[count]->_fxDialog->RefreshSettings();
	}
	_mutex.Unlock();
	if( _measureEditDlg != NULL )
	{
		_measureEditDlg->RefreshDrums();
	}
	wxMessageBox( _("Settings Loaded.") );
}

void AlgoRhythmia::OnSavePatternClick( wxCommandEvent& event )
{
#ifdef _DEMOVERSION
    wxMessageBox( _("Pattern save is disabled in the demo version.") );
    return;
#endif
	wxFileDialog fdialog( NULL, _T("Choose a file to Save"), _T("."), _T("Pattern"), _T("AlgoRhythmia Files (*.algo) |*.algo||"), wxFD_SAVE|wxFD_CHANGE_DIR );

	wxString fileName;

	if( fdialog.ShowModal() == wxID_OK )
	{
		fileName = fdialog.GetPath();
		SavePattern( fileName );
	}
	else
	{
		return;
	}
    event.Skip();
}

void AlgoRhythmia::SavePattern( wxString& filename )
{
	_mutex.Lock();
	_configData->SetValue( _("bpm"), _txtBPM->GetValue() );
	_configData->SetValue( _("mutatemeasures"), wxString::Format( _("%d"), _periodicmutatemeasures ));
	_configData->SetValue( _("mutaterate"), wxString::Format( _("%f"), _mutateRate ));
	_configData->SetValue( _("timesignature"), wxString::Format( _("%d"), _timesignature ));
	_configData->SetValue( _("measures"), wxString::Format( _("%d"), _measures ));
    _configData->SetValue( _("alwayskickone"), wxString::Format( _("%d"), _alwayskickone ));
	_configData->SetValue( _("varyvolume"), wxString::Format( _("%d"), _varyvolume ));
	_configData->SetValue( _("periodicmutate"), wxString::Format( _("%d"), _periodicmutate ));
	_configData->SetValue( _("midichannel"), wxString::Format( _("%d"), _midichannel ));
	_configData->SetValue( _("similarmeasures"), wxString::Format( _("%d"), _similarMeasures ));
	_configData->SetValue( _("basepattern"), wxString::Format( _("%d"), _basePattern->GetSelection() ));
	int count;
	for( count = 0; count < DRUM_MAX; count++ )
	{
		_configData->SetValue( wxString::Format(_("drumcontrol%ddrumon"), count ), wxString::Format( _("%d"), _drumControl[count]->_drumOn ));
		_configData->SetValue( wxString::Format(_("drumcontrol%dsampleon"), count ), wxString::Format( _("%d"), _drumControl[count]->_sampleOn )); 
		_configData->SetValue( wxString::Format(_("drumcontrol%ddrumnote"), count ), wxString::Format( _("%d"), _drumControl[count]->_drumNote ));
		_configData->SetValue( wxString::Format(_("drumcontrol%ddrumselection"), count ), wxString::Format( _("%d"), _drumControl[count]->_drumSelection->GetSelection() ));
		_configData->SetValue( wxString::Format(_("drumcontrol%dsamplename"), count ), _filenames[count] );
		_configData->SetValue( wxString::Format(_("drumcontrol%davgdensity"), count ), _drumControl[count]->_avgDensity->GetStringSelection() );
		_configData->SetValue( wxString::Format(_("drumcontrol%ddensityselection"), count ), wxString::Format( _("%d"), _drumControl[count]->_avgDensity->GetSelection() ));
		int note;
		for ( note = 0; note < MAX_PATTERN_SIZE; note++ )
		{
			_configData->SetValue( wxString::Format(_("drumcontrol%dnotedata%d"), count, note ),
				wxString::Format( _("%d"), _drumControl[count]->_noteData[note] ) );
		}
		// Store effects settings.
		//_drumControl[count]->_fxManager->WriteConfigurationSettings( count, _configData );
		//int fxnum;
		//for( fxnum = 0; fxnum < EFFECT_MAX; fxnum++ )
		//{
  //          bool effectState = false;
  //          //if( _drumControl[count]->_fxDialog != NULL )
  //          //{
  //          //    effectState = _drumControl[count]->_fxDialog->IsEffectEnabled(fxnum);
  //          //}
		//	_configData->setValue( wxString::Format( "/drumcontrol%d/fx%denabled", count, fxnum ), wxString::Format( "%d", effectState ));
		//}
	}
	_mutex.Unlock();
    if( !_configData->Save( filename.c_str() ))
    {
        wxMessageBox( _("Error saving configuration file."), filename );
        return;
    }
	wxMessageBox( _("Settings Saved.") );
}

void AlgoRhythmia::OnSwingSlider( wxScrollEvent& event )
{
	int value = _swingSlider->GetValue();
	_swingRatio = (double)value / 100;
    event.Skip();
}

void AlgoRhythmia::OnVolume1Change( wxCommandEvent& event )
{
    UpdateVolume(0);
    event.Skip();
}

void AlgoRhythmia::OnVolume2Change( wxCommandEvent& event )
{
    UpdateVolume(1);
    event.Skip();
}

void AlgoRhythmia::OnVolume3Change( wxCommandEvent& event )
{
    UpdateVolume(2);
    event.Skip();
}

void AlgoRhythmia::OnVolume4Change( wxCommandEvent& event )
{
    UpdateVolume(3);
    event.Skip();
}

void AlgoRhythmia::OnVolume5Change( wxCommandEvent& event )
{
    UpdateVolume(4);
    event.Skip();
}

void AlgoRhythmia::OnVolume6Change( wxCommandEvent& event )
{
    UpdateVolume(5);
    event.Skip();
}

void AlgoRhythmia::OnVolume7Change( wxCommandEvent& event )
{
    UpdateVolume(6);
    event.Skip();
}

void AlgoRhythmia::OnVolume8Change( wxCommandEvent& event )
{
    UpdateVolume(7);
    event.Skip();
}

void AlgoRhythmia::UpdateVolume( int channel )
{
    if( channel < 0 || channel >= 8 )
    {
        return;
    }
    int value = _drumControl[channel]->_volSlider->GetValue();
	float newValue = (float)value / 100.0;
#ifdef WIN32
    _sourceVoice[channel]->SetVolume( newValue, 0 );
#else
#pragma message ("TODO: Fix volume setting on non-Windows builds")
#endif
    // Convert range 0 to 200 range 0 to 127.
    _drumControl[channel]->_midiVolume = (value * 127 / 200);
}

void AlgoRhythmia::OnMidiOnheck( wxCommandEvent& event )
{
	_midiOn = _chkMidiOn->GetValue();
	event.Skip();
}

void AlgoRhythmia::OnHihatCancelCheck( wxCommandEvent& event )
{
	_hihatCancel = _chkHihatCancel->GetValue();
	event.Skip();
}

int WriteVarLen(register unsigned long value, char* output)
{
   int charsWritten = 0;
   register unsigned long buffer;
   buffer = value & 0x7F;

   while ( (value >>= 7) )
   {
     buffer <<= 8;
     buffer |= ((value & 0x7F) | 0x80);
   }

   while (TRUE)
   {
      output[charsWritten] = buffer;
      ++charsWritten;
      if (buffer & 0x80)
      {
          buffer >>= 8;
      }
      else
      {
          break;
      }
   }
   return charsWritten;
}

// Generates a stream of track data and returns the length.
int AlgoRhythmia::PrepareMIDIBuffer( char* buffer, int length )
{
	int step = 0;
    int measure = 0;
	int drum = 0;
	int laststepwritten = 0;
    int microsecondsPerQuarter = (int)(1000000.0 / ( (float)_bpm / 60.0 )); // Will be 5000000 (07 A1 20) for 120BPM.
    int bytesWritten = 0;
    // pulses per note.  will be 96 for quarter, 48 for eighth, and 24 for sixteenth.
	int pulse;
	switch( _division )
	{
	case 16:
		pulse = 24;
		break;
	case 8:
		pulse = 48;
		break;
	case 4:
		pulse = 96;
		break;
	default:
		pulse = 96; // This should actually throw an error.
	}

    // Write beats per minute.
    buffer[bytesWritten] = 0x00;
    bytesWritten++;
    buffer[bytesWritten] = 0xFF;
    bytesWritten++;
    buffer[bytesWritten] = 0x51;
    bytesWritten++;
    buffer[bytesWritten] = 0x03;
    bytesWritten++;
    buffer[bytesWritten] = microsecondsPerQuarter / 65536;
    bytesWritten++;
    buffer[bytesWritten] = microsecondsPerQuarter / 256;
    bytesWritten++;
    buffer[bytesWritten] = microsecondsPerQuarter % 256;
    bytesWritten++;

	_mutex.Lock();
    for( measure = 0; measure < _measures; measure++ )
    {
	    for( step = 0; step < _timesignature; step++ )
	    {
		    for( drum = 0; drum < DRUM_MAX; drum++ )
		    {
			    if( _drumControl[drum]->_drumOn && _drumControl[drum]->_noteData[(step + (MAX_MEASURE_LENGTH * measure))] )
			    {
				    if( step != laststepwritten )
				    {
					    //fwrite( &time, 4, 1, fp );
                        if( bytesWritten < length )
                        {
                            //int value = (step - laststepwritten) * millisecondsPerStep;
                            int value = ((step + (_timesignature * measure)) - laststepwritten) * pulse;
                            bytesWritten += WriteVarLen( value, (buffer+bytesWritten) );
                        }
				    }
				    else
				    {
					    // Same step: write a single zero value.
                        if( bytesWritten < length )
                        {
				    	    bytesWritten += WriteVarLen( 0, (buffer+bytesWritten) );
                        }
				    }
				    int volume;
				    if( !_varyvolume )
                    {
					    volume = _drumControl[drum]->_midiVolume;
                    }
				    else
                    {
					    if( _drumControl[drum]->_midiVolume > 15 )
					    {
						    volume = (rand() % 16) + _drumControl[drum]->_midiVolume - 16;
					    }
					    else
					    {
						    volume = rand() % 16;
					    }
						// Adjust sample volume too: 10% range.
						int value = _drumControl[drum]->_volSlider->GetValue();
						float newValue = (float)(value + rand() % 20) / 100.0;
#ifdef WIN32
						_sourceVoice[drum]->SetVolume( newValue, 0 );
#else
#pragma message ("TODO: Fix volume setting on non-Windows builds")
#endif
                    }
                    if( bytesWritten < length )
                    {
					    buffer[bytesWritten] = 0x90 + _midichannel;
					    ++bytesWritten;
                    }
                    if( bytesWritten < length )
                    {
					    buffer[bytesWritten] = midival[_drumControl[drum]->_drumNote];
					    ++bytesWritten;
                    }
                    if( bytesWritten < length )
                    {
					    buffer[bytesWritten] = volume;
					    ++bytesWritten;
                    }
				    //fwrite( &fullWord, 4, 1, fp );
				    laststepwritten = (step + (_timesignature * measure));
			    }
		    }
	    }
    }
	_mutex.Unlock();
    // Write track ending.
    if( bytesWritten < length )
    {
        buffer[bytesWritten] = 0;
        ++bytesWritten;
    }
    if( bytesWritten < length )
    {
        buffer[bytesWritten] = 0xff;
        ++bytesWritten;
    }
    if( bytesWritten < length )
    {
        buffer[bytesWritten] = 47;
        ++bytesWritten;
    }
    if( bytesWritten < length )
    {
        buffer[bytesWritten] = 0;
        ++bytesWritten;
    }
    return bytesWritten;
}

void AlgoRhythmia::OnDivisionSelected( wxCommandEvent& event )
{
	// Get division selection and populate member variable.
	int selection = _chcDivision->GetSelection();
	switch( selection )
	{
	case 0:
		_division = 4;
		break;
	case 1:
		_division = 8;
		break;
	case 2:
		_division = 16;
		break;
	}
	event.Skip();
}

void AlgoRhythmia::OnFx1Click( wxCommandEvent& event )
{
    ShowFxDialog(0);
	event.Skip();
}

void AlgoRhythmia::OnFx2Click( wxCommandEvent& event )
{
    ShowFxDialog(1);
	event.Skip();
}

void AlgoRhythmia::OnFx3Click( wxCommandEvent& event )
{
    ShowFxDialog(2);
	event.Skip();
}

void AlgoRhythmia::OnFx4Click( wxCommandEvent& event )
{
    ShowFxDialog(3);
	event.Skip();
}

void AlgoRhythmia::OnFx5Click( wxCommandEvent& event )
{
    ShowFxDialog(4);
	event.Skip();
}

void AlgoRhythmia::OnFx6Click( wxCommandEvent& event )
{
    ShowFxDialog(5);
	event.Skip();
}

void AlgoRhythmia::OnFx7Click( wxCommandEvent& event )
{
    ShowFxDialog(6);
	event.Skip();
}

void AlgoRhythmia::OnFx8Click( wxCommandEvent& event )
{
    ShowFxDialog(7);
	event.Skip();
}

void AlgoRhythmia::ShowFxDialog( int channel )
{
    if( channel < 0 || channel >= DRUM_MAX )
    {
        return;
    }
#ifdef _DEMOVERSION
    if( channel != 0 )
    {
        wxMessageBox( _("Effects are only available on drum channel 1 in the demo version.") );
        return;
    }
#endif
	//if( _drumControl[channel]->_fxDialog == NULL )
	//{
    //    _drumControl[channel]->_fxDialog = new EffectsDlg(this, _drumControl[channel]->_fxManager, ID_EFFECTSDIALOG, wxString::Format( "Edit Channel %d Effects", (channel + 1) ));
	//}
	//_drumControl[channel]->_fxDialog->Show();
}

// User has clicked the purchase button, start eSellerate transaction.
void AlgoRhythmia::OnPurchase( wxCommandEvent& event )
{
#ifdef WIN32
	system("start http://sites.fastspring.com/zetacentauri/product/algorhythmia");
#endif
	// Avoid linking in unnecessary libraries, even though this button is only shown in the demo version.
//#ifdef _DEMOVERSION
//	eSellerate_ResultData result = NULL;
//	// Use the preview certificate in debug version, use the real deal in release version.
//#ifdef _DEBUG
//	eSellerate_ErrorCode error = eSellerate_Purchase( "PUB2158959366", "ES8597071575", "PC8597071575-1062", NULL, NULL,
//		NULL, true, NULL, NULL, NULL, NULL, NULL, &result );
//#else
//	eSellerate_ErrorCode error = eSellerate_Purchase( "PUB2158959366", "ES8597071575", NULL, NULL, NULL, 
//		NULL, true, NULL, NULL, NULL, NULL, NULL, &result );
//#endif
//	eSellerate_DeleteResultData( result );
//#endif
    event.Skip();
}
