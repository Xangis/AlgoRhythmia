//#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
//#pragma implementation "EffectsDlg.h"
//#endif
//
//// For compilers that support precompilation, includes "wx/wx.h".
//#include "wx/wxprec.h"
//
//#ifdef __BORLANDC__
//#pragma hdrstop
//#endif
//
//#ifndef WX_PRECOMP
//#include "wx/wx.h"
//#endif
//
//#include "EffectsDlg.h"
//
///*!
// * EffectsDlg type definition
// */
//IMPLEMENT_DYNAMIC_CLASS( EffectsDlg, wxDialog )
//
///*!
// * EffectsDlg event table definition
// */
//BEGIN_EVENT_TABLE( EffectsDlg, wxDialog )
//    EVT_CHOICE( ID_EFFECTS, EffectsDlg::OnEffectChoice )
//    EVT_CHECKBOX( ID_ENABLED, EffectsDlg::OnEnabledCheck )
//    EVT_SLIDER( ID_PARAMSLIDER1, EffectsDlg::OnSlider1 )
//    EVT_SLIDER( ID_PARAMSLIDER2, EffectsDlg::OnSlider2 )
//    EVT_SLIDER( ID_PARAMSLIDER3, EffectsDlg::OnSlider3 )
//    EVT_SLIDER( ID_PARAMSLIDER4, EffectsDlg::OnSlider4 )
//    EVT_SLIDER( ID_PARAMSLIDER5, EffectsDlg::OnSlider5 )
//	EVT_SLIDER( ID_PARAMSLIDER6, EffectsDlg::OnSlider6 )
//    EVT_RADIOBOX( ID_WAVEFORM, EffectsDlg::OnPhaseSelected )
//    EVT_RADIOBOX( ID_PHASE, EffectsDlg::OnWaveformSelected )
//END_EVENT_TABLE()
//
///*!
// * EffectsDlg constructors
// */
//EffectsDlg::EffectsDlg( )
//{
//}
//
//EffectsDlg::EffectsDlg( wxWindow* parent, SoundFxManager* fxManager, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
//{
//    int count;
//    for( count = 0; count < EFFECT_MAX; count++ )
//    {
//        _enabled[count] = false;
//    }
//    Create(parent, fxManager, id, caption, pos, size, style);
//}
//
///*!
// * EffectsDlg creator
// */
//bool EffectsDlg::Create( wxWindow* parent, SoundFxManager* fxManager, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
//{
//    //if( _fxManager == NULL )
//    //{
//    //    wxMessageBox( "Error: Effects dialog created with null Effects Manager" );
//    //    return false;
//    //}
//    _fxManager = fxManager;
//    SetExtraStyle(GetExtraStyle()|wxWS_EX_BLOCK_EVENTS);
//    wxDialog::Create( parent, id, caption, pos, size, style );
//    CreateControls();
//    GetSizer()->Fit(this);
//    GetSizer()->SetSizeHints(this);
//    Centre();
//	RefreshSettings();
//    return true;
//}
//
///*!
// * Control creation for EffectsDlg
// */
//void EffectsDlg::CreateControls()
//{    
//    EffectsDlg* itemDialog1 = this;
//
//    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
//    itemDialog1->SetSizer(itemBoxSizer2);
//
//    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
//    itemBoxSizer2->Add(itemBoxSizer3, 0, 0, 7);
//
//    wxString itemEffectStrings[] = {
//        _("Chorus"),
//        _("Compressor"),
//        _("Distortion"),
//        _("Echo"),
//        _("Flanger"),
//        _("Gargle"),
//        _("Parametric Eq"),
//        _("Reverb")
//    };
//    _chcEffect = new wxChoice( itemDialog1, ID_EFFECTS, wxDefaultPosition, wxSize( 110, 20 ), EFFECT_MAX, itemEffectStrings, 0 );
//    itemBoxSizer3->Add( _chcEffect, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 3 );
//    _chcEffect->SetSelection(0);
//
//    _chkEnabled = new wxCheckBox( itemDialog1, ID_ENABLED, _T("Effect Enabled"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
//    itemBoxSizer3->Add( _chkEnabled, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 3 );
//
//    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
//    itemBoxSizer2->Add(itemBoxSizer4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1 );
//
//    _txtParamName1 = new wxStaticText( itemDialog1, ID_PARAMNAME1, _T("Wet/Dry Mix (%)" ), wxDefaultPosition, wxSize( 116, -1 ) );
//    itemBoxSizer4->Add(_txtParamName1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 4 );
//
//    _slParam1 = new wxSlider( itemDialog1, ID_PARAMSLIDER1, 50, 0, 100, wxDefaultPosition, wxSize( 136, 22 ), wxNO_BORDER );
//    itemBoxSizer4->Add(_slParam1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1 );
//
//    _txtValue1 = new wxStaticText( itemDialog1, ID_VALUE1, _T("0.0"), wxDefaultPosition, wxSize( 32, -1 ) );
//    itemBoxSizer4->Add(_txtValue1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 2 );
//
//    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
//    itemBoxSizer2->Add(itemBoxSizer5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1 );
//
//    _txtParamName2 = new wxStaticText( itemDialog1, ID_PARAMNAME2, _T("Depth (%)" ), wxDefaultPosition, wxSize( 116, -1 ) );
//    itemBoxSizer5->Add(_txtParamName2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 4 );
//
//    _slParam2 = new wxSlider( itemDialog1, ID_PARAMSLIDER2, 50, 0, 100, wxDefaultPosition, wxSize( 136, 22 ), wxNO_BORDER );
//    itemBoxSizer5->Add(_slParam2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1 );
//
//    _txtValue2 = new wxStaticText( itemDialog1, ID_VALUE2, _T("0.0"), wxDefaultPosition, wxSize( 32, -1 ) );
//    itemBoxSizer5->Add(_txtValue2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 2 );
//
//    wxBoxSizer* itemBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
//    itemBoxSizer2->Add(itemBoxSizer6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1 );
//
//    _txtParamName3 = new wxStaticText( itemDialog1, ID_PARAMNAME3, _T("Feedback (%)" ), wxDefaultPosition, wxSize( 116, -1 ) );
//    itemBoxSizer6->Add(_txtParamName3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 4 );
//
//    _slParam3 = new wxSlider( itemDialog1, ID_PARAMSLIDER3, 50, 0, 100, wxDefaultPosition, wxSize( 136, 22 ), wxNO_BORDER );
//    itemBoxSizer6->Add(_slParam3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1 );
//
//    _txtValue3 = new wxStaticText( itemDialog1, ID_VALUE3, _T("0.0"), wxDefaultPosition, wxSize( 32, -1 ) );
//    itemBoxSizer6->Add(_txtValue3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 2 );
//
//    wxBoxSizer* itemBoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
//    itemBoxSizer2->Add(itemBoxSizer7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1 );
//
//    _txtParamName4 = new wxStaticText( itemDialog1, ID_PARAMNAME4, _T("Frequency (Hz)" ), wxDefaultPosition, wxSize( 116, -1 ) );
//    itemBoxSizer7->Add(_txtParamName4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 4 );
//
//    _slParam4 = new wxSlider( itemDialog1, ID_PARAMSLIDER4, 50, 0, 100, wxDefaultPosition, wxSize( 136, 22 ), wxNO_BORDER );
//    itemBoxSizer7->Add(_slParam4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1 );
//
//    _txtValue4 = new wxStaticText( itemDialog1, ID_VALUE4, _T("0.0"), wxDefaultPosition, wxSize( 32, -1 ) );
//    itemBoxSizer7->Add(_txtValue4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 2 );
//
//    wxBoxSizer* itemBoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
//    itemBoxSizer2->Add(itemBoxSizer8, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1 );
//
//    _txtParamName5 = new wxStaticText( itemDialog1, ID_PARAMNAME5, _T("Delay (ms)" ), wxDefaultPosition, wxSize( 116, -1 ) );
//    itemBoxSizer8->Add(_txtParamName5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 4 );
//
//    _slParam5 = new wxSlider( itemDialog1, ID_PARAMSLIDER5, 50, 0, 100, wxDefaultPosition, wxSize( 136, 22 ), wxNO_BORDER );
//    itemBoxSizer8->Add(_slParam5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1 );
//
//    _txtValue5 = new wxStaticText( itemDialog1, ID_VALUE5, _T("0.0"), wxDefaultPosition, wxSize( 32, -1 ) );
//    itemBoxSizer8->Add(_txtValue5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 2 );
//
//    wxBoxSizer* itemBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
//    itemBoxSizer2->Add(itemBoxSizer9, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1 );
//
//    _txtParamName6 = new wxStaticText( itemDialog1, ID_PARAMNAME6, _T("" ), wxDefaultPosition, wxSize( 116, -1 ) );
//    itemBoxSizer9->Add(_txtParamName6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 4 );
//
//    _slParam6 = new wxSlider( itemDialog1, ID_PARAMSLIDER6, 50, 0, 100, wxDefaultPosition, wxSize( 136, 22 ), wxNO_BORDER );
//    itemBoxSizer9->Add(_slParam6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1 );
//
//    _txtValue6 = new wxStaticText( itemDialog1, ID_VALUE6, _T("0.0"), wxDefaultPosition, wxSize( 32, -1 ) );
//    itemBoxSizer9->Add(_txtValue6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 2 );
//
//    //wxBoxSizer* itemBoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
//    //itemBoxSizer2->Add(itemBoxSizer11, 0, wxALIGN_CENTER_VERTICAL|wxALL, 4 );
//
//    wxString radioWaveformStrings[] = {
//        _("&Triangle"),
//        _("&Sine"),
//        _("S&quare")
//    };
//    _radWaveform = new wxRadioBox( itemDialog1, ID_WAVEFORM, _("Waveform"), wxDefaultPosition, wxDefaultSize, 3, radioWaveformStrings, 1, wxRA_SPECIFY_ROWS );
//    itemBoxSizer2->Add(_radWaveform, 1, wxALIGN_TOP|wxALL|wxGROW, 2);
//    // 2 not available for chorus (initial effect)
//
//    wxString radioPhaseStrings[] = {
//        _("-180°"),
//        _("-90°"),
//        _("0°"),
//        _("90°"),
//        _("180°")
//    };
//    _radPhase = new wxRadioBox( itemDialog1, ID_PHASE, _("Phase"), wxDefaultPosition, wxDefaultSize, 5, radioPhaseStrings, 1, wxRA_SPECIFY_ROWS );
//    itemBoxSizer2->Add(_radPhase, 1, wxALIGN_TOP|wxALL|wxGROW, 2);
//}
//
///*!
// * Should we show tooltips?
// */
//bool EffectsDlg::ShowToolTips()
//{
//    return true;
//}
//
///*!
// * Get bitmap resources
// */
//wxBitmap EffectsDlg::GetBitmapResource( const wxString& name )
//{
//    // Bitmap retrieval
//    wxUnusedVar(name);
//    return wxNullBitmap;
//}
//
///*!
// * Get icon resources
// */
//wxIcon EffectsDlg::GetIconResource( const wxString& name )
//{
//    // Icon retrieval
//    wxUnusedVar(name);
//    return wxNullIcon;
//}
//
//void EffectsDlg::RefreshSettings( void )
//{
//    // Send a null event just to get the window to refresh with the default effect's settings.
//    wxCommandEvent event;
//    OnEffectChoice( event );
//}
//
//void EffectsDlg::OnEffectChoice( wxCommandEvent& event )
//{
//    int selection = _chcEffect->GetSelection();
//    if( selection < 0 || selection >= EFFECT_MAX )
//    {
//        return;
//    }
//    // Set checkbox based on enabled/disabled state.
//    _chkEnabled->SetValue( _enabled[selection] );
//    // TODO: Load and display parameters and ranges based on selection.
//    switch( selection )
//    {
//        case eSFX_chorus:
//        {
//            _txtParamName1->SetLabel( "Wet/Dry Mix (%)" );
//            _slParam1->SetRange( DSFXCHORUS_WETDRYMIX_MIN, DSFXCHORUS_WETDRYMIX_MAX );
//            _slParam1->SetValue( _fxManager->_paramsChorus.fWetDryMix );
//            _txtParamName2->SetLabel( "Depth (%)" );
//            _slParam2->SetRange( DSFXCHORUS_DEPTH_MIN, DSFXCHORUS_DEPTH_MAX );
//            _slParam2->SetValue( _fxManager->_paramsChorus.fDepth );
//            _txtParamName3->SetLabel( "Feedback (%)" );
//            _slParam3->SetRange( DSFXCHORUS_FEEDBACK_MIN, DSFXCHORUS_FEEDBACK_MAX );
//            _slParam3->SetValue( _fxManager->_paramsChorus.fFeedback );
//            _txtParamName4->SetLabel( "Frequency (Hz)" );
//            _slParam4->SetRange( DSFXCHORUS_FREQUENCY_MIN, DSFXCHORUS_FREQUENCY_MAX );
//            _slParam4->SetValue( _fxManager->_paramsChorus.fFrequency );
//            _txtParamName5->SetLabel( "Delay (ms)" );
//            _slParam5->SetRange( DSFXCHORUS_DELAY_MIN, DSFXCHORUS_DELAY_MAX );
//            _slParam5->SetValue( _fxManager->_paramsChorus.fDelay );
//            _txtParamName6->SetLabel( "" );
//            _slParam6->SetRange( 0, 100 );
//            _slParam6->SetValue( 0 );
//            _radPhase->Enable(true);
//            _radPhase->SetSelection( _fxManager->_paramsChorus.lPhase );
//            _radWaveform->Enable( 0, true );
//            _radWaveform->Enable( 1, true );
//            _radWaveform->Enable( 2, false );
//            _radWaveform->SetSelection( _fxManager->_paramsChorus.lWaveform );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME1, TEXT( "Wet/Dry Mix (%)" ), g_lpFXManager->m_paramsChorus.fWetDryMix, DSFXCHORUS_WETDRYMIX_MIN, DSFXCHORUS_WETDRYMIX_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME2, TEXT( "Depth (%)" ), g_lpFXManager->m_paramsChorus.fDepth, DSFXCHORUS_DEPTH_MIN, DSFXCHORUS_DEPTH_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME3, TEXT( "Feedback (%)" ), g_lpFXManager->m_paramsChorus.fFeedback, DSFXCHORUS_FEEDBACK_MIN, DSFXCHORUS_FEEDBACK_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME4, TEXT( "Frequency (Hz)" ), g_lpFXManager->m_paramsChorus.fFrequency, DSFXCHORUS_FREQUENCY_MIN, DSFXCHORUS_FREQUENCY_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME5, TEXT( "Delay (ms)" ), g_lpFXManager->m_paramsChorus.fDelay, DSFXCHORUS_DELAY_MIN, DSFXCHORUS_DELAY_MAX );
//            //LoadWaveformRadio( hwndDlg, g_lpFXManager->m_paramsChorus.lWaveform, DSFXCHORUS_WAVE_TRIANGLE, -1, DSFXCHORUS_WAVE_SIN );
//            //LoadPhaseRadio( hwndDlg, g_lpFXManager->m_paramsChorus.lPhase, DSFXCHORUS_PHASE_NEG_180, DSFXCHORUS_PHASE_NEG_90, DSFXCHORUS_PHASE_ZERO, DSFXCHORUS_PHASE_90, DSFXCHORUS_PHASE_180 );
//            break;
//        }
//
//        case eSFX_compressor:
//        {
//            _txtParamName1->SetLabel( "Gain (dB)" );
//            _slParam1->SetRange( DSFXCOMPRESSOR_GAIN_MIN, DSFXCOMPRESSOR_GAIN_MAX );
//            _slParam1->SetValue( _fxManager->_paramsCompressor.fGain );
//            _txtParamName2->SetLabel( "Attack (ms)" );
//            _slParam2->SetRange( DSFXCOMPRESSOR_ATTACK_MIN, DSFXCOMPRESSOR_ATTACK_MAX );
//            _slParam2->SetValue( _fxManager->_paramsCompressor.fAttack );
//            _txtParamName3->SetLabel( "Release (ms)" );
//            _slParam3->SetRange( DSFXCOMPRESSOR_ATTACK_MIN, DSFXCOMPRESSOR_ATTACK_MAX );
//            _slParam3->SetValue( _fxManager->_paramsCompressor.fRelease );
//            _txtParamName4->SetLabel( "Threshold (dB)" );
//            _slParam4->SetRange( DSFXCOMPRESSOR_THRESHOLD_MIN, DSFXCOMPRESSOR_THRESHOLD_MAX );
//            _slParam4->SetValue( _fxManager->_paramsCompressor.fThreshold );
//            _txtParamName5->SetLabel( "Ratio (x:1)" );
//            _slParam5->SetRange( DSFXCOMPRESSOR_RATIO_MIN, DSFXCOMPRESSOR_RATIO_MAX );
//            _slParam5->SetValue( _fxManager->_paramsCompressor.fRatio );
//            _txtParamName6->SetLabel( "Predelay (ms)" );
//            _slParam6->SetRange( DSFXCOMPRESSOR_PREDELAY_MIN, DSFXCOMPRESSOR_PREDELAY_MAX );
//            _slParam6->SetValue( _fxManager->_paramsCompressor.fPredelay );
//            _radPhase->Enable(false);
//            _radWaveform->Enable( 0, false );
//            _radWaveform->Enable( 1, false );
//            _radWaveform->Enable( 2, false );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME1, TEXT( "Gain (dB)" ), g_lpFXManager->m_paramsCompressor.fGain, DSFXCOMPRESSOR_GAIN_MIN, DSFXCOMPRESSOR_GAIN_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME2, TEXT( "Attack (ms)" ), g_lpFXManager->m_paramsCompressor.fAttack, DSFXCOMPRESSOR_ATTACK_MIN, DSFXCOMPRESSOR_ATTACK_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME3, TEXT( "Release (ms)" ), g_lpFXManager->m_paramsCompressor.fRelease, DSFXCOMPRESSOR_RELEASE_MIN, DSFXCOMPRESSOR_RELEASE_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME4, TEXT( "Threshold (dB)" ), g_lpFXManager->m_paramsCompressor.fThreshold, DSFXCOMPRESSOR_THRESHOLD_MIN, DSFXCOMPRESSOR_THRESHOLD_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME5, TEXT( "Ratio (x:1)" ), g_lpFXManager->m_paramsCompressor.fRatio, DSFXCOMPRESSOR_RATIO_MIN, DSFXCOMPRESSOR_RATIO_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME6, TEXT( "Predelay (ms)" ), g_lpFXManager->m_paramsCompressor.fPredelay, DSFXCOMPRESSOR_PREDELAY_MIN, DSFXCOMPRESSOR_PREDELAY_MAX, 0.05f, 2 );
//            break;
//        }
//
//        case eSFX_distortion:
//        {
//            _txtParamName1->SetLabel( "Gain (dB)" );
//            _slParam1->SetRange( DSFXDISTORTION_GAIN_MIN, DSFXDISTORTION_GAIN_MAX );
//            _slParam1->SetValue( _fxManager->_paramsDistortion.fGain );
//            _txtParamName2->SetLabel( "Edge (%)" );
//            _slParam2->SetRange( DSFXDISTORTION_EDGE_MIN, DSFXDISTORTION_EDGE_MAX );
//            _slParam2->SetValue( _fxManager->_paramsDistortion.fEdge );
//            _txtParamName3->SetLabel( "PostEQ Center Freq (Hz)" );
//            _slParam3->SetRange( DSFXDISTORTION_POSTEQCENTERFREQUENCY_MIN, DSFXDISTORTION_POSTEQCENTERFREQUENCY_MAX );
//            _slParam3->SetValue( _fxManager->_paramsDistortion.fPostEQCenterFrequency );
//            _txtParamName4->SetLabel( "PostEQ Bandwidth (Hz)" );
//            _slParam4->SetRange( DSFXDISTORTION_POSTEQBANDWIDTH_MIN, DSFXDISTORTION_POSTEQBANDWIDTH_MAX );
//            _slParam4->SetValue( _fxManager->_paramsDistortion.fPostEQBandwidth );
//            _txtParamName5->SetLabel( "PreLowpass Cutoff (Hz)" );
//            _slParam5->SetRange( DSFXDISTORTION_PRELOWPASSCUTOFF_MIN, DSFXDISTORTION_PRELOWPASSCUTOFF_MAX );
//            _slParam5->SetValue( _fxManager->_paramsDistortion.fPreLowpassCutoff );
//            _txtParamName6->SetLabel( "" );
//            _slParam6->SetRange( 0, 100 );
//            _slParam6->SetValue( 0 );
//            _radPhase->Enable(false);
//            _radWaveform->Enable( 0, false );
//            _radWaveform->Enable( 1, false );
//            _radWaveform->Enable( 2, false );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME1, TEXT( "Gain (dB)" ), g_lpFXManager->m_paramsDistortion.fGain, DSFXDISTORTION_GAIN_MIN, DSFXDISTORTION_GAIN_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME2, TEXT( "Edge (%)" ), g_lpFXManager->m_paramsDistortion.fEdge, DSFXDISTORTION_EDGE_MIN, DSFXDISTORTION_EDGE_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME3, TEXT( "PostEQ Center Freq (Hz)" ), g_lpFXManager->m_paramsDistortion.fPostEQCenterFrequency, DSFXDISTORTION_POSTEQCENTERFREQUENCY_MIN, DSFXDISTORTION_POSTEQCENTERFREQUENCY_MAX, 1.0f, 0 );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME4, TEXT( "PostEQ Bandwidth (Hz)" ), g_lpFXManager->m_paramsDistortion.fPostEQBandwidth, DSFXDISTORTION_POSTEQBANDWIDTH_MIN, DSFXDISTORTION_POSTEQBANDWIDTH_MAX, 1.0f, 0 );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME5, TEXT( "PreLowpass Cutoff (Hz)" ), g_lpFXManager->m_paramsDistortion.fPreLowpassCutoff, DSFXDISTORTION_PRELOWPASSCUTOFF_MIN, DSFXDISTORTION_PRELOWPASSCUTOFF_MAX, 1.0f, 0 );
//            break;
//        }
//
//        case eSFX_echo:
//        {
//            _txtParamName1->SetLabel( "Wet/Dry Mix (%)" );
//            _slParam1->SetRange( DSFXECHO_WETDRYMIX_MIN, DSFXECHO_WETDRYMIX_MAX );
//            _slParam1->SetValue( _fxManager->_paramsEcho.fWetDryMix );
//            _txtParamName2->SetLabel( "Feedback (%)" );
//            _slParam2->SetRange( DSFXECHO_FEEDBACK_MIN, DSFXECHO_FEEDBACK_MAX );
//            _slParam2->SetValue( _fxManager->_paramsEcho.fFeedback );
//            _txtParamName3->SetLabel( "Left Delay (ms)" );
//            _slParam3->SetRange( DSFXECHO_LEFTDELAY_MIN, DSFXECHO_LEFTDELAY_MAX );
//            _slParam3->SetValue( _fxManager->_paramsEcho.fLeftDelay );
//            _txtParamName4->SetLabel( "Right Delay (ms)" );
//            _slParam4->SetRange( DSFXECHO_RIGHTDELAY_MIN, DSFXECHO_RIGHTDELAY_MAX );
//            _slParam4->SetValue( _fxManager->_paramsEcho.fRightDelay );
//            _txtParamName5->SetLabel( "Pan Delay (bool)" );
//            _slParam5->SetRange( DSFXECHO_PANDELAY_MIN, DSFXECHO_PANDELAY_MAX );
//            _slParam5->SetValue( _fxManager->_paramsEcho.lPanDelay );
//            _txtParamName6->SetLabel( "" );
//            _slParam6->SetRange( 0, 100 );
//            _slParam6->SetValue( 0 );
//            _radWaveform->Enable( 0, false );
//            _radWaveform->Enable( 1, false );
//            _radWaveform->Enable( 2, false );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME1, TEXT( "Wet/Dry Mix (%)" ), g_lpFXManager->m_paramsEcho.fWetDryMix, DSFXECHO_WETDRYMIX_MIN, DSFXECHO_WETDRYMIX_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME2, TEXT( "Feedback (%)" ), g_lpFXManager->m_paramsEcho.fFeedback, DSFXECHO_FEEDBACK_MIN, DSFXECHO_FEEDBACK_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME3, TEXT( "Left Delay (ms)" ), g_lpFXManager->m_paramsEcho.fLeftDelay, DSFXECHO_LEFTDELAY_MIN, DSFXECHO_LEFTDELAY_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME4, TEXT( "Right Delay (ms)" ), g_lpFXManager->m_paramsEcho.fRightDelay, DSFXECHO_RIGHTDELAY_MIN, DSFXECHO_RIGHTDELAY_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME5, TEXT( "Pan Delay (bool)" ), (float) g_lpFXManager->m_paramsEcho.lPanDelay, DSFXECHO_PANDELAY_MIN, DSFXECHO_PANDELAY_MAX );
//            break;
//        }
//
//        case eSFX_flanger:
//        {
//            _txtParamName1->SetLabel( "Wet/Dry Mix (%)" );
//            _slParam1->SetRange( DSFXFLANGER_WETDRYMIX_MIN, DSFXFLANGER_WETDRYMIX_MAX );
//            _slParam1->SetValue( _fxManager->_paramsFlanger.fWetDryMix );
//            _txtParamName2->SetLabel( "Depth (%)" );
//            _slParam2->SetRange( DSFXFLANGER_DEPTH_MIN, DSFXFLANGER_DEPTH_MAX );
//            _slParam2->SetValue( _fxManager->_paramsFlanger.fDepth );
//            _txtParamName3->SetLabel( "Feedback (%)" );
//            _slParam3->SetRange( DSFXFLANGER_FEEDBACK_MIN, DSFXFLANGER_FEEDBACK_MAX );
//            _slParam3->SetValue( _fxManager->_paramsFlanger.fFeedback );
//            _txtParamName4->SetLabel( "Frequency (Hz)" );
//            _slParam4->SetRange( DSFXFLANGER_FREQUENCY_MIN, DSFXFLANGER_FREQUENCY_MAX );
//            _slParam4->SetValue( _fxManager->_paramsFlanger.fFrequency );
//            _txtParamName5->SetLabel( "Delay (ms)" );
//            _slParam5->SetRange( DSFXFLANGER_DELAY_MIN, DSFXFLANGER_DELAY_MAX );
//            _slParam5->SetValue( _fxManager->_paramsFlanger.fDelay );
//            _txtParamName6->SetLabel( "" );
//            _slParam6->SetRange( 0, 100 );
//            _slParam6->SetValue( 0 );
//            _radPhase->Enable(true);
//            _radPhase->SetSelection( _fxManager->_paramsFlanger.lPhase );
//            _radWaveform->Enable( 0, true );
//            _radWaveform->Enable( 1, true );
//            _radWaveform->Enable( 2, false );
//            _radWaveform->SetSelection( _fxManager->_paramsFlanger.lWaveform );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME1, TEXT( "Wet/Dry Mix (%)" ), g_lpFXManager->m_paramsFlanger.fWetDryMix, DSFXFLANGER_WETDRYMIX_MIN, DSFXFLANGER_WETDRYMIX_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME2, TEXT( "Depth (%)" ), g_lpFXManager->m_paramsFlanger.fDepth, DSFXFLANGER_DEPTH_MIN, DSFXFLANGER_DEPTH_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME3, TEXT( "Feedback (%)" ), g_lpFXManager->m_paramsFlanger.fFeedback, DSFXFLANGER_FEEDBACK_MIN, DSFXFLANGER_FEEDBACK_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME4, TEXT( "Frequency (Hz)" ), g_lpFXManager->m_paramsFlanger.fFrequency, DSFXFLANGER_FREQUENCY_MIN, DSFXFLANGER_FREQUENCY_MAX, 0.01f, 2 );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME5, TEXT( "Delay (ms)" ), g_lpFXManager->m_paramsFlanger.fDelay, DSFXFLANGER_DELAY_MIN, DSFXFLANGER_DELAY_MAX, 0.01f, 2 );
//            //LoadWaveformRadio( hwndDlg, g_lpFXManager->m_paramsFlanger.lWaveform, DSFXFLANGER_WAVE_TRIANGLE, -1, DSFXFLANGER_WAVE_SIN );
//            //LoadPhaseRadio( hwndDlg, g_lpFXManager->m_paramsFlanger.lPhase, DSFXFLANGER_PHASE_NEG_180, DSFXFLANGER_PHASE_NEG_90, DSFXFLANGER_PHASE_ZERO, DSFXFLANGER_PHASE_90, DSFXFLANGER_PHASE_180 );
//            break;
//        }
//
//        case eSFX_gargle:
//        {
//            _txtParamName1->SetLabel( "Rate (Hz)" );
//            _slParam1->SetRange( (FLOAT)DSFXGARGLE_RATEHZ_MIN, (FLOAT)DSFXGARGLE_RATEHZ_MAX );
//            _slParam1->SetValue( _fxManager->_paramsGargle.dwRateHz );
//            _txtParamName2->SetLabel( "" );
//            _slParam2->SetRange( 0, 100 );
//            _slParam2->SetValue( 0 );
//            _txtParamName3->SetLabel( "" );
//            _slParam3->SetRange( 0, 100 );
//            _slParam3->SetValue( 0 );
//            _txtParamName4->SetLabel( "" );
//            _slParam4->SetRange( 0, 100 );
//            _slParam4->SetValue( 0 );
//            _txtParamName5->SetLabel( "" );
//            _slParam5->SetRange( 0, 100 );
//            _slParam5->SetValue( 0 );
//            _txtParamName6->SetLabel( "" );
//            _slParam6->SetRange( 0, 100 );
//            _slParam6->SetValue( 0 );
//            _radPhase->Enable(false);
//            _radWaveform->Enable( 0, true );
//            _radWaveform->Enable( 1, false );
//            _radWaveform->Enable( 2, true );
//            int waveShape = _fxManager->_paramsGargle.dwWaveShape;
//            // Convert enum because it doesn't match chorus and flange.
//            if( waveShape == DSFXGARGLE_WAVE_SQUARE ) waveShape = 2;
//            _radWaveform->SetSelection( waveShape );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME1, TEXT( "Rate (Hz)" ), ( FLOAT ) g_lpFXManager->m_paramsGargle.dwRateHz, ( FLOAT ) DSFXGARGLE_RATEHZ_MIN, ( FLOAT ) DSFXGARGLE_RATEHZ_MAX );
//            //LoadWaveformRadio( hwndDlg, g_lpFXManager->m_paramsGargle.dwWaveShape, DSFXGARGLE_WAVE_TRIANGLE, DSFXGARGLE_WAVE_SQUARE, -1 );
//            break;
//        }
//
//        case eSFX_parameq:
//        {
//            _txtParamName1->SetLabel( "Center Freq (Hz)" );
//            _slParam1->SetRange( DSFXPARAMEQ_CENTER_MIN, DSFXPARAMEQ_CENTER_MAX );
//            _slParam1->SetValue( _fxManager->_paramsParamEq.fCenter );
//            _txtParamName2->SetLabel( "Bandwidth" );
//            _slParam2->SetRange( DSFXPARAMEQ_BANDWIDTH_MIN, DSFXPARAMEQ_BANDWIDTH_MAX );
//            _slParam2->SetValue( _fxManager->_paramsParamEq.fBandwidth );
//            _txtParamName3->SetLabel( "Gain (dB)" );
//            _slParam3->SetRange( DSFXPARAMEQ_GAIN_MIN, DSFXPARAMEQ_GAIN_MAX );
//            _slParam3->SetValue( _fxManager->_paramsParamEq.fGain );
//            _txtParamName4->SetLabel( "" );
//            _slParam4->SetRange( 0, 100 );
//            _slParam4->SetValue( 0 );
//            _txtParamName5->SetLabel( "" );
//            _slParam5->SetRange( 0, 100 );
//            _slParam5->SetValue( 0 );
//            _txtParamName6->SetLabel( "" );
//            _slParam6->SetRange( 0, 100 );
//            _slParam6->SetValue( 0 );
//            _radPhase->Enable(false);
//            _radWaveform->Enable( 0, false );
//            _radWaveform->Enable( 1, false );
//            _radWaveform->Enable( 2, false );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME1, TEXT( "Center Freq (Hz)" ), g_lpFXManager->m_paramsParamEq.fCenter, DSFXPARAMEQ_CENTER_MIN, DSFXPARAMEQ_CENTER_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME2, TEXT( "Bandwidth (Hz)" ), g_lpFXManager->m_paramsParamEq.fBandwidth, DSFXPARAMEQ_BANDWIDTH_MIN, DSFXPARAMEQ_BANDWIDTH_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME3, TEXT( "Gain (dB)" ), g_lpFXManager->m_paramsParamEq.fGain, DSFXPARAMEQ_GAIN_MIN, DSFXPARAMEQ_GAIN_MAX );
//            break;
//        }
//
//        case eSFX_reverb:
//        {
//            _txtParamName1->SetLabel( "In Gain (dB)" );
//            _slParam1->SetRange( DSFX_WAVESREVERB_INGAIN_MIN, DSFX_WAVESREVERB_INGAIN_MAX );
//            _slParam1->SetValue( _fxManager->_paramsReverb.fInGain );
//            _txtParamName2->SetLabel( "Reverb Mix (dB)" );
//            _slParam2->SetRange( DSFX_WAVESREVERB_REVERBMIX_MIN, DSFX_WAVESREVERB_REVERBMIX_MAX );
//            _slParam2->SetValue( _fxManager->_paramsReverb.fReverbMix );
//            _txtParamName3->SetLabel( "Reverb Time (ms)" );
//            _slParam3->SetRange( DSFX_WAVESREVERB_REVERBTIME_MIN, DSFX_WAVESREVERB_REVERBTIME_MAX );
//            _slParam3->SetValue( _fxManager->_paramsReverb.fReverbTime );
//            _txtParamName4->SetLabel( "HighFreq RT Ratio (x:1)" );
//            _slParam4->SetRange( DSFX_WAVESREVERB_HIGHFREQRTRATIO_MIN, DSFX_WAVESREVERB_HIGHFREQRTRATIO_MAX );
//            _slParam4->SetValue( _fxManager->_paramsReverb.fHighFreqRTRatio );
//            _txtParamName5->SetLabel( "" );
//            _slParam5->SetRange( 0, 100 );
//            _slParam5->SetValue( 0 );
//            _txtParamName6->SetLabel( "" );
//            _slParam6->SetRange( 0, 100 );
//            _slParam6->SetValue( 0 );
//            _radPhase->Enable(false);
//            _radWaveform->Enable( 0, false );
//            _radWaveform->Enable( 1, false );
//            _radWaveform->Enable( 2, false );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME1, TEXT( "In Gain (dB)" ), g_lpFXManager->m_paramsReverb.fInGain, DSFX_WAVESREVERB_INGAIN_MIN, DSFX_WAVESREVERB_INGAIN_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME2, TEXT( "Reverb Mix (dB)" ), g_lpFXManager->m_paramsReverb.fReverbMix, DSFX_WAVESREVERB_REVERBMIX_MIN, DSFX_WAVESREVERB_REVERBMIX_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME3, TEXT( "Reverb Time (ms)" ), g_lpFXManager->m_paramsReverb.fReverbTime, DSFX_WAVESREVERB_REVERBTIME_MIN, DSFX_WAVESREVERB_REVERBTIME_MAX );
//            //LoadSingleParameter( hwndDlg, IDC_PARAM_NAME4, TEXT( "HighFreq RT Ratio (x:1)" ), g_lpFXManager->m_paramsReverb.fHighFreqRTRatio, DSFX_WAVESREVERB_HIGHFREQRTRATIO_MIN, DSFX_WAVESREVERB_HIGHFREQRTRATIO_MAX, 0.01f, 2 );
//            break;
//        }
//    }
//    _txtValue1->SetLabel( wxString::Format( "%d", _slParam1->GetValue() ));
//    _txtValue2->SetLabel( wxString::Format( "%d", _slParam2->GetValue() ));
//    _txtValue3->SetLabel( wxString::Format( "%d", _slParam3->GetValue() ));
//    _txtValue4->SetLabel( wxString::Format( "%d", _slParam4->GetValue() ));
//    _txtValue5->SetLabel( wxString::Format( "%d", _slParam5->GetValue() ));
//	_txtValue6->SetLabel( wxString::Format( "%d", _slParam6->GetValue() ));
//    Refresh();
//    event.Skip();
//}
//
//void EffectsDlg::OnEnabledCheck( wxCommandEvent& event )
//{
//    int selection = _chcEffect->GetSelection();
//    if( selection < 0 || selection >= EFFECT_MAX )
//    {
//        return;
//    }
//    _enabled[selection] = _chkEnabled->GetValue();
//    // To enable an effect, we first turn them all off and then enable only
//    // those that are set to on.
//    _fxManager->DisableAllFX();
//    int count;
//    for( count = 0; count < eNUM_SFX; count++ )
//    {
//        if( _enabled[count] == true )
//        {
//            _fxManager->SetFXEnable(count);
//        }
//    }
//	_fxManager->ActivateFX();
//    event.Skip();
//}
//
//void EffectsDlg::OnSlider1( wxCommandEvent& event )
//{
//    int selection = _chcEffect->GetSelection();
//    if( selection < 0 || selection >= EFFECT_MAX )
//    {
//        return;
//    }
//    _txtValue1->SetLabel( wxString::Format( "%d", _slParam1->GetValue() ));
//    switch( selection )
//    {
//    case eSFX_chorus:
//        _fxManager->_paramsChorus.fWetDryMix = _slParam1->GetValue();
//		if( _fxManager->_lpChorus != NULL )
//		{
//			_fxManager->_lpChorus->SetAllParameters( &_fxManager->_paramsChorus );
//		}
//        break;
//    case eSFX_compressor:
//        _fxManager->_paramsCompressor.fGain = _slParam1->GetValue();
//		if( _fxManager->_lpCompressor != NULL )
//		{
//			_fxManager->_lpCompressor->SetAllParameters( &_fxManager->_paramsCompressor );
//		}
//        break;
//    case eSFX_distortion:
//        _fxManager->_paramsDistortion.fGain = _slParam1->GetValue();
//		if( _fxManager->_lpDistortion != NULL )
//		{
//			_fxManager->_lpDistortion->SetAllParameters( &_fxManager->_paramsDistortion );
//		}
//        break;
//    case eSFX_echo:
//        _fxManager->_paramsEcho.fWetDryMix = _slParam1->GetValue();
//		if( _fxManager->_lpEcho != NULL )
//		{
//			_fxManager->_lpEcho->SetAllParameters( &_fxManager->_paramsEcho );
//		}
//        break;
//    case eSFX_flanger:
//        _fxManager->_paramsFlanger.fWetDryMix = _slParam1->GetValue();
//		if( _fxManager->_lpFlanger != NULL )
//		{
//			_fxManager->_lpFlanger->SetAllParameters( &_fxManager->_paramsFlanger );
//		}
//        break;
//    case eSFX_gargle:
//        _fxManager->_paramsGargle.dwRateHz = _slParam1->GetValue();
//		if( _fxManager->_lpGargle != NULL )
//		{
//			_fxManager->_lpGargle->SetAllParameters( &_fxManager->_paramsGargle );
//		}
//        break;
//    case eSFX_parameq:
//        _fxManager->_paramsParamEq.fCenter = _slParam1->GetValue();
//		if( _fxManager->_lpParamEq != NULL )
//		{
//			_fxManager->_lpParamEq->SetAllParameters( &_fxManager->_paramsParamEq );
//		}
//        break;
//    case eSFX_reverb:
//        _fxManager->_paramsReverb.fInGain = _slParam1->GetValue();
//		if( _fxManager->_lpReverb != NULL )
//		{
//			_fxManager->_lpReverb->SetAllParameters( &_fxManager->_paramsReverb );
//		}
//        break;
//    default:
//        break;
//    }
//    event.Skip();
//}
//
//void EffectsDlg::OnSlider2( wxCommandEvent& event )
//{
//    int selection = _chcEffect->GetSelection();
//    if( selection < 0 || selection >= EFFECT_MAX )
//    {
//        return;
//    }
//    _txtValue2->SetLabel( wxString::Format( "%d", _slParam2->GetValue() ));
//    switch( selection )
//    {
//    case eSFX_chorus:
//        _fxManager->_paramsChorus.fDepth = _slParam2->GetValue();
//		if( _fxManager->_lpChorus != NULL )
//		{
//			_fxManager->_lpChorus->SetAllParameters( &_fxManager->_paramsChorus );
//		}
//        break;
//    case eSFX_compressor:
//        _fxManager->_paramsCompressor.fAttack = _slParam2->GetValue();
//		if( _fxManager->_lpCompressor != NULL )
//		{
//			_fxManager->_lpCompressor->SetAllParameters( &_fxManager->_paramsCompressor );
//		}
//        break;
//    case eSFX_distortion:
//        _fxManager->_paramsDistortion.fEdge = _slParam2->GetValue();
//		if( _fxManager->_lpDistortion != NULL )
//		{
//			_fxManager->_lpDistortion->SetAllParameters( &_fxManager->_paramsDistortion );
//		}
//        break;
//    case eSFX_echo:
//        _fxManager->_paramsEcho.fFeedback = _slParam2->GetValue();
//		if( _fxManager->_lpEcho != NULL )
//		{
//			_fxManager->_lpEcho->SetAllParameters( &_fxManager->_paramsEcho );
//		}
//        break;
//    case eSFX_flanger:
//        _fxManager->_paramsFlanger.fDepth = _slParam2->GetValue();
//		if( _fxManager->_lpFlanger != NULL )
//		{
//			_fxManager->_lpFlanger->SetAllParameters( &_fxManager->_paramsFlanger );
//		}
//        break;
//    case eSFX_gargle:
//        // No parameter.
//        break;
//    case eSFX_parameq:
//        _fxManager->_paramsParamEq.fBandwidth = _slParam2->GetValue();
//		if( _fxManager->_lpParamEq != NULL )
//		{
//			_fxManager->_lpParamEq->SetAllParameters( &_fxManager->_paramsParamEq );
//		}
//        break;
//    case eSFX_reverb:
//        _fxManager->_paramsReverb.fReverbMix = _slParam2->GetValue();
//		if( _fxManager->_lpReverb != NULL )
//		{
//			_fxManager->_lpReverb->SetAllParameters( &_fxManager->_paramsReverb );
//		}
//        break;
//    default:
//        break;
//    }
//    event.Skip();
//}
//
//void EffectsDlg::OnSlider3( wxCommandEvent& event )
//{
//    int selection = _chcEffect->GetSelection();
//    if( selection < 0 || selection >= EFFECT_MAX )
//    {
//        return;
//    }
//    _txtValue3->SetLabel( wxString::Format( "%d", _slParam3->GetValue() ));
//    switch( selection )
//    {
//    case eSFX_chorus:
//        _fxManager->_paramsChorus.fFeedback = _slParam3->GetValue();
//		if( _fxManager->_lpChorus != NULL )
//		{
//			_fxManager->_lpChorus->SetAllParameters( &_fxManager->_paramsChorus );
//		}
//        break;
//    case eSFX_compressor:
//        _fxManager->_paramsCompressor.fRelease = _slParam3->GetValue();
//		if( _fxManager->_lpCompressor != NULL )
//		{
//			_fxManager->_lpCompressor->SetAllParameters( &_fxManager->_paramsCompressor );
//		}
//        break;
//    case eSFX_distortion:
//        _fxManager->_paramsDistortion.fPostEQCenterFrequency = _slParam3->GetValue();
//		if( _fxManager->_lpDistortion != NULL )
//		{
//			_fxManager->_lpDistortion->SetAllParameters( &_fxManager->_paramsDistortion );
//		}
//        break;
//    case eSFX_echo:
//        _fxManager->_paramsEcho.fLeftDelay = _slParam3->GetValue();
//		if( _fxManager->_lpEcho != NULL )
//		{
//			_fxManager->_lpEcho->SetAllParameters( &_fxManager->_paramsEcho );
//		}
//        break;
//    case eSFX_flanger:
//        _fxManager->_paramsFlanger.fFeedback = _slParam3->GetValue();
//		if( _fxManager->_lpFlanger != NULL )
//		{
//			_fxManager->_lpFlanger->SetAllParameters( &_fxManager->_paramsFlanger );
//		}
//        break;
//    case eSFX_gargle:
//        // No parameter.
//        break;
//    case eSFX_parameq:
//        _fxManager->_paramsParamEq.fGain = _slParam3->GetValue();
//		if( _fxManager->_lpParamEq != NULL )
//		{
//			_fxManager->_lpParamEq->SetAllParameters( &_fxManager->_paramsParamEq );
//		}
//        break;
//    case eSFX_reverb:
//        _fxManager->_paramsReverb.fReverbTime = _slParam3->GetValue();
//		if( _fxManager->_lpReverb != NULL )
//		{
//			_fxManager->_lpReverb->SetAllParameters( &_fxManager->_paramsReverb );
//		}
//        break;
//    default:
//        break;
//    }
//    event.Skip();
//}
//
//void EffectsDlg::OnSlider4( wxCommandEvent& event )
//{
//    int selection = _chcEffect->GetSelection();
//    if( selection < 0 || selection >= EFFECT_MAX )
//    {
//        return;
//    }
//    _txtValue4->SetLabel( wxString::Format( "%d", _slParam4->GetValue() ));
//    switch( selection )
//    {
//    case eSFX_chorus:
//        _fxManager->_paramsChorus.fFrequency = _slParam4->GetValue();
//		if( _fxManager->_lpChorus != NULL )
//		{
//			_fxManager->_lpChorus->SetAllParameters( &_fxManager->_paramsChorus );
//		}
//        break;
//    case eSFX_compressor:
//        _fxManager->_paramsCompressor.fThreshold = _slParam4->GetValue();
//		if( _fxManager->_lpCompressor != NULL )
//		{
//			_fxManager->_lpCompressor->SetAllParameters( &_fxManager->_paramsCompressor );
//		}
//        break;
//    case eSFX_distortion:
//        _fxManager->_paramsDistortion.fPostEQBandwidth = _slParam4->GetValue();
//		if( _fxManager->_lpDistortion )
//		{
//			_fxManager->_lpDistortion->SetAllParameters( &_fxManager->_paramsDistortion );
//		}
//        break;
//    case eSFX_echo:
//        _fxManager->_paramsEcho.fRightDelay = _slParam4->GetValue();
//		if( _fxManager->_lpEcho != NULL )
//		{
//			_fxManager->_lpEcho->SetAllParameters( &_fxManager->_paramsEcho );
//		}
//        break;
//    case eSFX_flanger:
//        _fxManager->_paramsFlanger.fFrequency = _slParam4->GetValue();
//		if( _fxManager->_lpFlanger != NULL )
//		{
//			_fxManager->_lpFlanger->SetAllParameters( &_fxManager->_paramsFlanger );
//		}
//        break;
//    case eSFX_gargle:
//        // No parameter.
//        break;
//    case eSFX_parameq:
//        // No parameter.
//        break;
//    case eSFX_reverb:
//        _fxManager->_paramsReverb.fHighFreqRTRatio = _slParam4->GetValue();
//		if( _fxManager->_lpReverb != NULL )
//		{
//			_fxManager->_lpReverb->SetAllParameters( &_fxManager->_paramsReverb );
//		}
//        break;
//    default:
//        break;
//    }
//    event.Skip();
//}
//
//void EffectsDlg::OnSlider5( wxCommandEvent& event )
//{
//    int selection = _chcEffect->GetSelection();
//    if( selection < 0 || selection >= EFFECT_MAX )
//    {
//        return;
//    }
//    _txtValue5->SetLabel( wxString::Format( "%d", _slParam5->GetValue() ));
//    switch( selection )
//    {
//    case eSFX_chorus:
//        _fxManager->_paramsChorus.fDelay = _slParam5->GetValue();
//		if( _fxManager->_lpChorus != NULL )
//		{
//			_fxManager->_lpChorus->SetAllParameters( &_fxManager->_paramsChorus );
//		}
//        break;
//    case eSFX_compressor:
//        _fxManager->_paramsCompressor.fRatio = _slParam5->GetValue();
//		if( _fxManager->_lpCompressor != NULL )
//		{
//			_fxManager->_lpCompressor->SetAllParameters( &_fxManager->_paramsCompressor );
//		}
//        break;
//    case eSFX_distortion:
//        _fxManager->_paramsDistortion.fPreLowpassCutoff = _slParam5->GetValue();
//		if( _fxManager->_lpDistortion != NULL )
//		{
//			_fxManager->_lpDistortion->SetAllParameters( &_fxManager->_paramsDistortion );
//		}
//        break;
//    case eSFX_echo:
//        _fxManager->_paramsEcho.lPanDelay = _slParam5->GetValue();
//		if( _fxManager->_lpEcho != NULL )
//		{
//			_fxManager->_lpEcho->SetAllParameters( &_fxManager->_paramsEcho );
//		}
//        break;
//    case eSFX_flanger:
//        _fxManager->_paramsFlanger.fDelay = _slParam5->GetValue();
//		if( _fxManager->_lpFlanger != NULL )
//		{
//			_fxManager->_lpFlanger->SetAllParameters( &_fxManager->_paramsFlanger );
//		}
//        break;
//    case eSFX_gargle:
//        // No parameter.
//        break;
//    case eSFX_parameq:
//        // No parameter.
//        break;
//    case eSFX_reverb:
//        // No parameter.
//        break;
//    default:
//        break;
//    }
//    event.Skip();
//}
//
//void EffectsDlg::OnSlider6( wxCommandEvent& event )
//{
//    int selection = _chcEffect->GetSelection();
//    if( selection < 0 || selection >= EFFECT_MAX )
//    {
//        return;
//    }
//    _txtValue6->SetLabel( wxString::Format( "%d", _slParam6->GetValue() ));
//    switch( selection )
//    {
//    case eSFX_chorus:
//        // No parameter.
//        break;
//    case eSFX_compressor:
//        _fxManager->_paramsCompressor.fPredelay = _slParam6->GetValue();
//		if( _fxManager->_lpCompressor != NULL )
//		{
//			_fxManager->_lpCompressor->SetAllParameters( &_fxManager->_paramsCompressor );
//		}
//        break;
//    case eSFX_distortion:
//        // No parameter.
//        break;
//    case eSFX_echo:
//        // No parameter.
//        break;
//    case eSFX_flanger:
//        // No parameter.
//        break;
//    case eSFX_gargle:
//        // No parameter.
//        break;
//    case eSFX_parameq:
//        // No parameter.
//        break;
//    case eSFX_reverb:
//        // No parameter.
//        break;
//    default:
//        break;
//    }
//    event.Skip();
//}
//
//void EffectsDlg::OnWaveformSelected( wxCommandEvent& event )
//{
//    int selection = _chcEffect->GetSelection();
//    if( selection < 0 || selection >= EFFECT_MAX )
//    {
//        return;
//    }
//    switch( selection )
//    {
//    case eSFX_chorus:
//        // Triangle and Sine allowed.
//        _fxManager->_paramsChorus.lWaveform = _radWaveform->GetSelection();
//		if( _fxManager->_lpChorus != NULL )
//		{
//			_fxManager->_lpChorus->SetAllParameters( &_fxManager->_paramsChorus );
//		}
//        break;
//    case eSFX_compressor:
//        // No parameter.
//        break;
//    case eSFX_distortion:
//        // No parameter.
//        break;
//    case eSFX_echo:
//        // No parameter.
//        break;
//    case eSFX_flanger:
//        // Triangle and sine allowed.
//        _fxManager->_paramsFlanger.lWaveform = _radWaveform->GetSelection();
//		if( _fxManager->_lpFlanger != NULL )
//		{
//			_fxManager->_lpFlanger->SetAllParameters( &_fxManager->_paramsFlanger );
//		}
//        break;
//    case eSFX_gargle:
//        // Triangle and square allowed.
//        // Convert enum because it doesn't match chorus and flange.  Triangle does match.
//        {
//            int waveShape = _radWaveform->GetSelection();
//            if( waveShape == 2 ) waveShape = DSFXGARGLE_WAVE_SQUARE;
//            _fxManager->_paramsGargle.dwWaveShape = waveShape;
//		    if( _fxManager->_lpGargle != NULL )
//		    {
//			    _fxManager->_lpGargle->SetAllParameters( &_fxManager->_paramsGargle );
//		    }
//        }
//        break;
//    case eSFX_parameq:
//        // No parameter.
//        break;
//    case eSFX_reverb:
//        // No parameter.
//        break;
//    default:
//        break;
//    }
//    event.Skip();
//}
//
//void EffectsDlg::OnPhaseSelected( wxCommandEvent& event )
//{
//    int selection = _chcEffect->GetSelection();
//    if( selection < 0 || selection >= EFFECT_MAX )
//    {
//        return;
//    }
//    switch( selection )
//    {
//    case eSFX_chorus:
//        // Phase settings used.
//        _fxManager->_paramsChorus.lPhase = _radPhase->GetSelection();
//		if( _fxManager->_lpChorus != NULL )
//		{
//			_fxManager->_lpChorus->SetAllParameters( &_fxManager->_paramsChorus );
//		}
//        break;
//    case eSFX_compressor:
//        // No parameter.
//        break;
//    case eSFX_distortion:
//        // No parameter.
//        break;
//    case eSFX_echo:
//        // No parameter.
//        break;
//    case eSFX_flanger:
//        // Phase settings used.
//        _fxManager->_paramsFlanger.lPhase = _radPhase->GetSelection();
//		if( _fxManager->_lpFlanger != NULL )
//		{
//			_fxManager->_lpFlanger->SetAllParameters( &_fxManager->_paramsFlanger );
//		}
//        break;
//    case eSFX_gargle:
//        // No parameter.
//        break;
//    case eSFX_parameq:
//        // No parameter.
//        break;
//    case eSFX_reverb:
//        // No parameter.
//        break;
//    default:
//        break;
//    }
//    event.Skip();
//}
//
//bool EffectsDlg::IsEffectEnabled( int effectNum )
//{
//	if( effectNum < 0 || effectNum >= EFFECT_MAX )
//	{
//		return false;
//	}
//	return _enabled[effectNum];
//}
//
//void EffectsDlg::EnableEffect( int effectNum, bool state )
//{
//	if( effectNum < 0 || effectNum >= EFFECT_MAX )
//	{
//		return;
//	}
//	_enabled[effectNum] = state;
//    _fxManager->DisableAllFX();
//    int count;
//    for( count = 0; count < eNUM_SFX; count++ )
//    {
//        if( _enabled[count] == true )
//        {
//            _fxManager->SetFXEnable(count);
//        }
//    }
//	_fxManager->ActivateFX();
//}