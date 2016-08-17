#ifndef _EFFECTSDLG_H_
#define _EFFECTSDLG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "EffectsDlg.h"
#endif

#define ID_EFFECTSDIALOG 27000
#define SYMBOL_EFFECTSDLG_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_EFFECTSDLG_TITLE _("Edit Effects")
#define SYMBOL_EFFECTSDLG_IDNAME ID_EFFECTSDIALOG
#define SYMBOL_EFFECTSDLG_SIZE wxSize(400, 300)
#define SYMBOL_EFFECTSDLG_POSITION wxDefaultPosition
#define ID_EFFECTS 27001
#define ID_ENABLED 27002
#define ID_PARAMNAME1 27003
#define ID_PARAMNAME2 27004
#define ID_PARAMNAME3 27005
#define ID_PARAMNAME4 27006
#define ID_PARAMNAME5 27007
#define ID_PARAMNAME6 27018
#define ID_PARAMSLIDER1 27008
#define ID_PARAMSLIDER2 27009
#define ID_PARAMSLIDER3 27010
#define ID_PARAMSLIDER4 27011
#define ID_PARAMSLIDER5 27012
#define ID_PARAMSLIDER6 27019
#define ID_VALUE1 27013
#define ID_VALUE2 27014
#define ID_VALUE3 27015
#define ID_VALUE4 27016
#define ID_VALUE5 27017
#define ID_VALUE6 27020
#define ID_WAVEFORM 27021
#define ID_PHASE 27022

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

#define EFFECT_MAX 8

#include "wx/wx.h"
//#include "SoundFxManager.h"
//
//class EffectsDlg : public wxDialog
//{
//    DECLARE_DYNAMIC_CLASS( EffectsDlg )
//    DECLARE_EVENT_TABLE()
//
//public:
//    /// Constructors
//    EffectsDlg( );
//    EffectsDlg( wxWindow* parent, SoundFxManager* fxManager, wxWindowID id = SYMBOL_EFFECTSDLG_IDNAME, const wxString& caption = SYMBOL_EFFECTSDLG_TITLE, const wxPoint& pos = SYMBOL_EFFECTSDLG_POSITION, const wxSize& size = SYMBOL_EFFECTSDLG_SIZE, long style = SYMBOL_EFFECTSDLG_STYLE );
//
//    /// Creation
//    bool Create( wxWindow* parent, SoundFxManager* fxManager, wxWindowID id = SYMBOL_EFFECTSDLG_IDNAME, const wxString& caption = SYMBOL_EFFECTSDLG_TITLE, const wxPoint& pos = SYMBOL_EFFECTSDLG_POSITION, const wxSize& size = SYMBOL_EFFECTSDLG_SIZE, long style = SYMBOL_EFFECTSDLG_STYLE );
//
//    /// Creates the controls and sizers
//    void CreateControls();
//
//    /// Retrieves bitmap resources
//    wxBitmap GetBitmapResource( const wxString& name );
//
//    /// Retrieves icon resources
//    wxIcon GetIconResource( const wxString& name );
//
//    void OnEnabledCheck( wxCommandEvent &event );
//    void OnEffectChoice( wxCommandEvent &event );
//    void OnSlider1( wxCommandEvent &event );
//    void OnSlider2( wxCommandEvent &event );
//    void OnSlider3( wxCommandEvent &event );
//    void OnSlider4( wxCommandEvent &event );
//    void OnSlider5( wxCommandEvent &event );
//	void OnSlider6( wxCommandEvent &event );
//    void OnPhaseSelected( wxCommandEvent &event );
//    void OnWaveformSelected( wxCommandEvent &event );
//	bool IsEffectEnabled( int effectNum );
//	void EnableEffect( int effectNum, bool state );
//
//    /// Should we show tooltips?
//    static bool ShowToolTips();
//	void RefreshSettings();
//private:
//    wxChoice* _chcEffect;
//    wxCheckBox* _chkEnabled;
//    wxStaticText* _txtParamName1;
//    wxStaticText* _txtParamName2;
//    wxStaticText* _txtParamName3;
//    wxStaticText* _txtParamName4;
//    wxStaticText* _txtParamName5;
//	wxStaticText* _txtParamName6;
//    wxSlider* _slParam1;
//    wxSlider* _slParam2;
//    wxSlider* _slParam3;
//    wxSlider* _slParam4;
//    wxSlider* _slParam5;
//	wxSlider* _slParam6;
//    wxStaticText* _txtValue1;
//    wxStaticText* _txtValue2;
//    wxStaticText* _txtValue3;
//    wxStaticText* _txtValue4;
//    wxStaticText* _txtValue5;
//	wxStaticText* _txtValue6;
//    wxRadioBox* _radWaveform;
//    wxRadioBox* _radPhase;
//    bool _enabled[EFFECT_MAX];
//    SoundFxManager* _fxManager;
//};
//
//
#endif