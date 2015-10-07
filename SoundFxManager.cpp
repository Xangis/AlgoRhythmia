//#include "SoundFxManager.h"
//
////-----------------------------------------------------------------------------
//// Name: SoundFxManager()
//// Desc: constructor
////-----------------------------------------------------------------------------
//SoundFxManager::SoundFxManager()
//{
//    _lpChorus = NULL;
//    _lpCompressor = NULL;
//    _lpDistortion = NULL;
//    _lpEcho = NULL;
//    _lpFlanger = NULL;
//    _lpGargle = NULL;
//    _lpParamEq = NULL;
//    _lpReverb = NULL;
//
//    ZeroMemory( &_paramsChorus, sizeof( DSFXChorus ) );
//    ZeroMemory( &_paramsCompressor, sizeof( DSFXCompressor ) );
//    ZeroMemory( &_paramsDistortion, sizeof( DSFXDistortion ) );
//    ZeroMemory( &_paramsFlanger, sizeof( DSFXFlanger ) );
//    ZeroMemory( &_paramsEcho, sizeof( DSFXEcho ) );
//    ZeroMemory( &_paramsGargle, sizeof( DSFXGargle ) );
//    ZeroMemory( &_paramsParamEq, sizeof( DSFXParamEq ) );
//    ZeroMemory( &_paramsReverb, sizeof( DSFXWavesReverb ) );
//
//    _dwNumFX = 0;
//    ZeroMemory( _rgFxDesc, sizeof( DSEFFECTDESC ) * eNUM_SFX );
//    ZeroMemory( _rgRefGuids, sizeof( GUID * ) * eNUM_SFX );
//    ZeroMemory( _rgPtrs, sizeof(LPVOID*) * eNUM_SFX );
//    ZeroMemory( _rgLoaded, sizeof( BOOL ) * eNUM_SFX );
//
//    _lpDSB8 = NULL;
//    _pAudioPath = NULL;
//}
//
////-----------------------------------------------------------------------------
//// Name: ~SoundFxManager()
//// Desc: destructor
////-----------------------------------------------------------------------------
//SoundFxManager::~SoundFxManager()
//{
//    // free any effects
//    DisableAllFX();
//    SAFE_RELEASE( _lpDSB8 );
//    SAFE_RELEASE( _pAudioPath );
//}
//
////-----------------------------------------------------------------------------
//// Name: Initialize()
//// Desc: associates a DirectSoundBuffer with the manager, any effects
////       enabled in the old DirectSoundBuffer will be disabled, 
////       and the effect objects released
////-----------------------------------------------------------------------------
//HRESULT SoundFxManager::Initialize( IDirectMusicAudioPath* pAudioPath, BOOL bLoadDefaultParamValues )
//{
//    HRESULT hr;
//
//    if( _lpDSB8 )
//    {
//        // release the effect for the previously associated sound buffers
//        DisableAllFX();
//        SAFE_RELEASE( _lpDSB8 );
//        SAFE_RELEASE( _pAudioPath );
//    }
//
//    if( NULL == pAudioPath )
//        return S_OK;
//    
//    if( FAILED( hr = pAudioPath->GetObjectInPath( DMUS_PCHANNEL_ALL,
//                DMUS_PATH_BUFFER, 0, GUID_NULL, 0, IID_IDirectSoundBuffer8, 
//                (LPVOID*) &_lpDSB8 )))
//        return hr;
//
//    _pAudioPath = pAudioPath;
// 
//    if( bLoadDefaultParamValues )
//        LoadDefaultParamValues();
//
//    return S_OK;
//}
//
////-----------------------------------------------------------------------------
//// Name: UnInitialize()
//// Desc: the manager goes back to default state, the effects params, however
////       will not be reset
////-----------------------------------------------------------------------------
//HRESULT SoundFxManager::UnInitialize()
//{
//    Initialize( NULL, FALSE );
//
//    return S_OK;
//}
//
////-----------------------------------------------------------------------------
//// Name: LoadDefaultParamValues()
//// Desc: loads the default param value for each effect
////-----------------------------------------------------------------------------
//HRESULT SoundFxManager::LoadDefaultParamValues()
//{
//    DWORD i;
//
//    if( NULL == _lpDSB8 )
//        return E_FAIL;
//
//    for( i = eSFX_chorus; i < eNUM_SFX; i++ )
//        SetFXEnable( i );
//    
//    ActivateFX();
//
//    if( _lpChorus )
//        _lpChorus->GetAllParameters( &_paramsChorus );
//
//    if( _lpCompressor )
//        _lpCompressor->GetAllParameters( &_paramsCompressor );
//    
//    if( _lpDistortion )
//        _lpDistortion->GetAllParameters( &_paramsDistortion );
//
//    if( _lpEcho )
//        _lpEcho->GetAllParameters( &_paramsEcho );
//
//    if( _lpFlanger )
//        _lpFlanger->GetAllParameters( &_paramsFlanger );
//
//    if( _lpGargle )
//        _lpGargle->GetAllParameters( &_paramsGargle );
//
//    if( _lpParamEq )
//        _lpParamEq->GetAllParameters( &_paramsParamEq );
//
//    if( _lpReverb )
//        _lpReverb->GetAllParameters( &_paramsReverb );
//
//    DisableAllFX();
//
//    return S_OK;
//}
//
////-----------------------------------------------------------------------------
//// Name: LoadCurrentFXParameters
//// Desc: loads the default param value for each effect
////-----------------------------------------------------------------------------
//HRESULT SoundFxManager::LoadCurrentFXParameters()
//{
//    if( _lpChorus )
//        _lpChorus->SetAllParameters( &_paramsChorus );
//
//    if( _lpCompressor )
//        _lpCompressor->SetAllParameters( &_paramsCompressor );
//    
//    if( _lpDistortion )
//        _lpDistortion->SetAllParameters( &_paramsDistortion );
//
//    if( _lpEcho )
//        _lpEcho->SetAllParameters( &_paramsEcho );
//
//    if( _lpFlanger )
//        _lpFlanger->SetAllParameters( &_paramsFlanger );
//
//    if( _lpGargle )
//        _lpGargle->SetAllParameters( &_paramsGargle );
//
//    if( _lpParamEq )
//        _lpParamEq->SetAllParameters( &_paramsParamEq );
//
//    if( _lpReverb )
//        _lpReverb->SetAllParameters( &_paramsReverb );
//
//    return S_OK;
//}
//
////-----------------------------------------------------------------------------
//// Name: SetFXEnable()
//// Desc: enables a sound effect for the sound buffer associated with this
////-----------------------------------------------------------------------------
//HRESULT SoundFxManager::SetFXEnable( DWORD esfxType )
//{
//    HRESULT hr;
//
//    if( esfxType >= eNUM_SFX )
//        return E_FAIL;
//
//    if( _rgLoaded[esfxType] )
//        return S_FALSE;
//    else
//        _rgLoaded[esfxType] = TRUE;
//
//    switch ( esfxType )
//    {
//    case eSFX_chorus:
//        hr = EnableGenericFX( GUID_DSFX_STANDARD_CHORUS,     IID_IDirectSoundFXChorus8,      
//                              (LPVOID*) &_lpChorus );
//        break;
//    case eSFX_compressor:
//        hr = EnableGenericFX( GUID_DSFX_STANDARD_COMPRESSOR, IID_IDirectSoundFXCompressor8,  
//                              (LPVOID*) &_lpCompressor );
//        break;
//    case eSFX_distortion:
//        hr = EnableGenericFX( GUID_DSFX_STANDARD_DISTORTION, IID_IDirectSoundFXDistortion8,  
//                              (LPVOID*) &_lpDistortion );
//        break;
//    case eSFX_echo:
//        hr = EnableGenericFX( GUID_DSFX_STANDARD_ECHO,       IID_IDirectSoundFXEcho8,        
//                              (LPVOID*) &_lpEcho );
//        break;
//    case eSFX_flanger:
//        hr = EnableGenericFX( GUID_DSFX_STANDARD_FLANGER,    IID_IDirectSoundFXFlanger8,     
//                              (LPVOID*) &_lpFlanger );
//        break;
//    case eSFX_gargle:
//        hr = EnableGenericFX( GUID_DSFX_STANDARD_GARGLE,     IID_IDirectSoundFXGargle8,      
//                              (LPVOID*) &_lpGargle );
//        break;
//    case eSFX_parameq:
//        hr = EnableGenericFX( GUID_DSFX_STANDARD_PARAMEQ,    IID_IDirectSoundFXParamEq8,     
//                              (LPVOID*) &_lpParamEq );
//        break;
//    case eSFX_reverb:
//        hr = EnableGenericFX( GUID_DSFX_WAVES_REVERB,        IID_IDirectSoundFXWavesReverb8, 
//                              (LPVOID*) &_lpReverb );
//        break;
//    default:
//        hr = E_FAIL;
//        break;
//    }
//
//    return hr;
//}
//
////-----------------------------------------------------------------------------
//// Name: DisableAllFX()
//// Desc: disables all effect in the DirectSoundBuffer, and releases all effect
////       object.
////-----------------------------------------------------------------------------
//HRESULT SoundFxManager::DisableAllFX()
//{
//    HRESULT hr;
//
//    // release all effect interfaces created with this manager so far
//    SAFE_RELEASE( _lpChorus );
//    SAFE_RELEASE( _lpCompressor );
//    SAFE_RELEASE( _lpDistortion );
//    SAFE_RELEASE( _lpEcho );
//    SAFE_RELEASE( _lpFlanger );
//    SAFE_RELEASE( _lpGargle );
//    SAFE_RELEASE( _lpParamEq );
//    SAFE_RELEASE( _lpReverb );
//    
//    _dwNumFX = 0;
//    ZeroMemory( _rgFxDesc, sizeof( DSEFFECTDESC ) * eNUM_SFX );
//    ZeroMemory( _rgRefGuids, sizeof( GUID * ) * eNUM_SFX );
//    ZeroMemory( _rgPtrs, sizeof(LPVOID*) * eNUM_SFX );
//    ZeroMemory( _rgLoaded, sizeof( BOOL ) * eNUM_SFX );
//
//    if( NULL == _lpDSB8 )
//        return E_FAIL;
//
//    if( _pAudioPath )
//        _pAudioPath->Activate( FALSE );
//    
//    // this removes all fx from the buffer
//    if( FAILED( hr = _lpDSB8->SetFX( 0, NULL, NULL ) ) )
//        //return DXTRACE_ERR_MSGBOX( TEXT("SetFX"), hr );
//        return 0;
//
//    if( _pAudioPath )
//        _pAudioPath->Activate( TRUE );
//    
//    return S_OK;
//}
//
////-----------------------------------------------------------------------------
//// Name: ActivateFX()
//// Desc: activate the effects enabled from EnableFX()
////-----------------------------------------------------------------------------
//HRESULT SoundFxManager::ActivateFX()
//{
//    DWORD dwResults[eNUM_SFX];
//    HRESULT hr;
//    DWORD i;
//
//    if( NULL == _lpDSB8 )
//        return E_FAIL;
//
//    if( _dwNumFX == 0 )
//        return S_FALSE;
//
//    if( _pAudioPath )
//        _pAudioPath->Activate( FALSE );
//
//    if( FAILED( hr = _lpDSB8->SetFX( _dwNumFX, _rgFxDesc, dwResults ) ) )
//        //return DXTRACE_ERR_MSGBOX( TEXT("SetFX"), hr );
//        return 0;
//
//    // get reference to the effect object
//    for( i = 0; i < _dwNumFX; i++ )
//        if( FAILED( hr = _lpDSB8->GetObjectInPath( _rgFxDesc[i].guidDSFXClass, 0, *_rgRefGuids[i], _rgPtrs[i] ) ) )
//            return hr;
//
//    if( _pAudioPath )
//        _pAudioPath->Activate( TRUE );
//
//    return S_OK;
//}
//
////-----------------------------------------------------------------------------
//// Name: EnableGenericFX()
//// Desc: given information, tries to enable an effect in a DirectSoundBuffer8,
////       and tries obtain reference to effect interface
////-----------------------------------------------------------------------------
//HRESULT SoundFxManager::EnableGenericFX( GUID guidSFXClass, REFGUID rguidInterface, LPVOID * ppObj )
//{
//    // if an effect already allocated
//    if( *ppObj )
//        return S_FALSE;
//
//    if( _dwNumFX >= eNUM_SFX )
//        return E_FAIL;
//
//    // set the effect to be enabled
//    ZeroMemory( &_rgFxDesc[_dwNumFX], sizeof(DSEFFECTDESC) );
//    _rgFxDesc[_dwNumFX].dwSize         = sizeof(DSEFFECTDESC);
//    _rgFxDesc[_dwNumFX].dwFlags        = 0;
//    CopyMemory( &_rgFxDesc[_dwNumFX].guidDSFXClass, &guidSFXClass, sizeof(GUID) );
//
//    _rgRefGuids[_dwNumFX] = &rguidInterface;
//    _rgPtrs[_dwNumFX] = ppObj;
//
//    _dwNumFX++;
//
//    return S_OK;
//}
//
//bool SoundFxManager::ReadConfigurationSettings( int channel, ConfigurationSettings* settings )
//{
//	if( settings == NULL )
//	{
//		return false;
//	}
//	// Read Chorus
//	_paramsChorus.fWetDryMix = atof(settings->getValue( wxString::Format("/fxchannel%d/chorus/wetdrymix", channel )) );
//	_paramsChorus.fDepth = atof(settings->getValue( wxString::Format("/fxchannel%d/chorus/depth", channel )) ); 
//	_paramsChorus.fFeedback = atof(settings->getValue( wxString::Format("/fxchannel%d/chorus/feedback", channel )) );
//	_paramsChorus.fFrequency = atof(settings->getValue( wxString::Format("/fxchannel%d/chorus/frequency", channel )) );
//	_paramsChorus.fDelay = atof(settings->getValue( wxString::Format("/fxchannel%d/chorus/delay", channel )) );
//	_paramsChorus.lPhase = atoi(settings->getValue( wxString::Format("/fxchannel%d/chorus/phase", channel )) );
//	_paramsChorus.lWaveform = atoi(settings->getValue( wxString::Format("/fxchannel%d/chorus/waveform", channel )) );
//	// Read Compression
//	_paramsCompressor.fGain = atof(settings->getValue( wxString::Format("/fxchannel%d/compression/gain", channel )) );
//	_paramsCompressor.fAttack = atof(settings->getValue( wxString::Format("/fxchannel%d/compression/attack", channel )) ); 
//	_paramsCompressor.fRelease = atof(settings->getValue( wxString::Format("/fxchannel%d/compression/release", channel )) );
//	_paramsCompressor.fThreshold = atof(settings->getValue( wxString::Format("/fxchannel%d/compression/threshold", channel )) );
//	_paramsCompressor.fRatio = atof(settings->getValue( wxString::Format("/fxchannel%d/compression/ratio", channel )) );
//	_paramsCompressor.fPredelay = atof(settings->getValue( wxString::Format("/fxchannel%d/compression/predelay", channel )) );
//	// Read Distortion
//	_paramsDistortion.fGain = atof(settings->getValue( wxString::Format("/fxchannel%d/distortion/gain", channel )) );
//	_paramsDistortion.fEdge = atof(settings->getValue( wxString::Format("/fxchannel%d/distortion/edge", channel )) ); 
//	_paramsDistortion.fPostEQCenterFrequency = atof(settings->getValue( wxString::Format("/fxchannel%d/distortion/posteqcenterfreq", channel )) );
//	_paramsDistortion.fPostEQBandwidth = atof(settings->getValue( wxString::Format("/fxchannel%d/distortion/posteqbandwidth", channel )) );
//	_paramsDistortion.fPreLowpassCutoff = atof(settings->getValue( wxString::Format("/fxchannel%d/distortion/prelowpasscutoff", channel )) );
//	// Read Echo
//	_paramsEcho.fWetDryMix = atof(settings->getValue( wxString::Format("/fxchannel%d/echo/gain", channel )) );
//	_paramsEcho.fFeedback = atof(settings->getValue( wxString::Format("/fxchannel%d/echo/edge", channel )) ); 
//	_paramsEcho.fLeftDelay = atof(settings->getValue( wxString::Format("/fxchannel%d/echo/posteqcenterfreq", channel )) );
//	_paramsEcho.fRightDelay = atof(settings->getValue( wxString::Format("/fxchannel%d/echo/posteqbandwidth", channel )) );
//	_paramsEcho.lPanDelay = atoi(settings->getValue( wxString::Format("/fxchannel%d/echo/prelowpasscutoff", channel )) );
//	// Read Flanger
//	_paramsFlanger.fWetDryMix = atof(settings->getValue( wxString::Format("/fxchannel%d/flanger/wetdrymix", channel )) );
//	_paramsFlanger.fDepth = atof(settings->getValue( wxString::Format("/fxchannel%d/flanger/depth", channel )) ); 
//	_paramsFlanger.fFeedback = atof(settings->getValue( wxString::Format("/fxchannel%d/flanger/feedback", channel )) );
//	_paramsFlanger.fFrequency = atof(settings->getValue( wxString::Format("/fxchannel%d/flanger/frequency", channel )) );
//	_paramsFlanger.fDelay = atof(settings->getValue( wxString::Format("/fxchannel%d/flanger/delay", channel )) );
//	_paramsFlanger.lPhase = atoi(settings->getValue( wxString::Format("/fxchannel%d/flanger/phase", channel )) );
//	_paramsFlanger.lWaveform = atoi(settings->getValue( wxString::Format("/fxchannel%d/flanger/waveform", channel )) );
//	// Read Gargle
//	_paramsGargle.dwRateHz = atoi(settings->getValue( wxString::Format("/fxchannel%d/gargle/rate", channel )) );
//	_paramsGargle.dwWaveShape = atoi(settings->getValue( wxString::Format("/fxchannel%d/gargle/waveshape", channel )) ); 
//	// Read Parametric EQ
//	_paramsParamEq.fCenter = atof(settings->getValue( wxString::Format("/fxchannel%d/parameq/center", channel )) ); 
//	_paramsParamEq.fBandwidth = atof(settings->getValue( wxString::Format("/fxchannel%d/parameq/bandwidth", channel )) ); 
//	_paramsParamEq.fGain = atof(settings->getValue( wxString::Format("/fxchannel%d/parameq/gain", channel )) ); 
//	// Read Reverb
//	_paramsReverb.fInGain = atof(settings->getValue( wxString::Format("/fxchannel%d/reverb/ingain", channel )) ); 
//	_paramsReverb.fReverbMix = atof(settings->getValue( wxString::Format("/fxchannel%d/reverb/reverbmix", channel )) ); 
//	_paramsReverb.fReverbTime = atof(settings->getValue( wxString::Format("/fxchannel%d/reverb/reverbtime", channel )) ); 
//	_paramsReverb.fHighFreqRTRatio = atof(settings->getValue( wxString::Format("/fxchannel%d/reverb/highfreqrtratio", channel )) ); 
//
//	// Now that we've set our parameters, send them to the actual effects.
//	LoadCurrentFXParameters();
//	return true;
//}
//
//bool SoundFxManager::WriteConfigurationSettings( int channel, ConfigurationSettings* settings )
//{
//	if( settings == NULL )
//	{
//		return false;
//	}
//	// Write Chorus
//	settings->setValue( wxString::Format("/fxchannel%d/chorus/wetdrymix", channel ), wxString::Format( "%f", _paramsChorus.fWetDryMix ));
//	settings->setValue( wxString::Format("/fxchannel%d/chorus/depth", channel ), wxString::Format( "%f", _paramsChorus.fDepth )); 
//	settings->setValue( wxString::Format("/fxchannel%d/chorus/feedback", channel ), wxString::Format( "%f", _paramsChorus.fFeedback ));
//	settings->setValue( wxString::Format("/fxchannel%d/chorus/frequency", channel ), wxString::Format( "%f", _paramsChorus.fFrequency ));
//	settings->setValue( wxString::Format("/fxchannel%d/chorus/delay", channel ), wxString::Format( "%f", _paramsChorus.fDelay ));
//	settings->setValue( wxString::Format("/fxchannel%d/chorus/phase", channel ), wxString::Format( "%d", _paramsChorus.lPhase ));
//	settings->setValue( wxString::Format("/fxchannel%d/chorus/waveform", channel ), wxString::Format( "%d", _paramsChorus.lWaveform ));
//	// Write Compression
//	settings->setValue( wxString::Format("/fxchannel%d/compression/gain", channel ), wxString::Format( "%f", _paramsCompressor.fGain ));
//	settings->setValue( wxString::Format("/fxchannel%d/compression/attack", channel ), wxString::Format( "%f", _paramsCompressor.fAttack )); 
//	settings->setValue( wxString::Format("/fxchannel%d/compression/release", channel ), wxString::Format( "%f", _paramsCompressor.fRelease ));
//	settings->setValue( wxString::Format("/fxchannel%d/compression/threshold", channel ), wxString::Format( "%f", _paramsCompressor.fThreshold ));
//	settings->setValue( wxString::Format("/fxchannel%d/compression/ratio", channel ), wxString::Format( "%f", _paramsCompressor.fRatio ));
//	settings->setValue( wxString::Format("/fxchannel%d/compression/predelay", channel ), wxString::Format( "%f", _paramsCompressor.fPredelay ));
//	// Write Distortion
//	settings->setValue( wxString::Format("/fxchannel%d/distortion/gain", channel ), wxString::Format( "%f", _paramsDistortion.fGain ));
//	settings->setValue( wxString::Format("/fxchannel%d/distortion/edge", channel ), wxString::Format( "%f", _paramsDistortion.fEdge )); 
//	settings->setValue( wxString::Format("/fxchannel%d/distortion/posteqcenterfreq", channel ), wxString::Format( "%f", _paramsDistortion.fPostEQCenterFrequency ));
//	settings->setValue( wxString::Format("/fxchannel%d/distortion/posteqbandwidth", channel ), wxString::Format( "%f", _paramsDistortion.fPostEQBandwidth ));
//	settings->setValue( wxString::Format("/fxchannel%d/distortion/prelowpasscutoff", channel ), wxString::Format( "%f", _paramsDistortion.fPreLowpassCutoff ));
//	// Write Echo
//	settings->setValue( wxString::Format("/fxchannel%d/echo/gain", channel ), wxString::Format( "%f", _paramsEcho.fWetDryMix ));
//	settings->setValue( wxString::Format("/fxchannel%d/echo/edge", channel ), wxString::Format( "%f", _paramsEcho.fFeedback )); 
//	settings->setValue( wxString::Format("/fxchannel%d/echo/posteqcenterfreq", channel ), wxString::Format( "%f", _paramsEcho.fLeftDelay ));
//	settings->setValue( wxString::Format("/fxchannel%d/echo/posteqbandwidth", channel ), wxString::Format( "%f", _paramsEcho.fRightDelay ));
//	settings->setValue( wxString::Format("/fxchannel%d/echo/prelowpasscutoff", channel ), wxString::Format( "%d", _paramsEcho.lPanDelay ));
//	// Write Flanger
//	settings->setValue( wxString::Format("/fxchannel%d/flanger/wetdrymix", channel ), wxString::Format( "%f", _paramsFlanger.fWetDryMix ));
//	settings->setValue( wxString::Format("/fxchannel%d/flanger/depth", channel ), wxString::Format( "%f", _paramsFlanger.fDepth )); 
//	settings->setValue( wxString::Format("/fxchannel%d/flanger/feedback", channel ), wxString::Format( "%f", _paramsFlanger.fFeedback ));
//	settings->setValue( wxString::Format("/fxchannel%d/flanger/frequency", channel ), wxString::Format( "%f", _paramsFlanger.fFrequency ));
//	settings->setValue( wxString::Format("/fxchannel%d/flanger/delay", channel ), wxString::Format( "%f", _paramsFlanger.fDelay ));
//	settings->setValue( wxString::Format("/fxchannel%d/flanger/phase", channel ), wxString::Format( "%d", _paramsFlanger.lPhase ));
//	settings->setValue( wxString::Format("/fxchannel%d/flanger/waveform", channel ), wxString::Format( "%d", _paramsFlanger.lWaveform ));
//	// Write Gargle
//	settings->setValue( wxString::Format("/fxchannel%d/gargle/rate", channel ), wxString::Format( "%d", _paramsGargle.dwRateHz ));
//	settings->setValue( wxString::Format("/fxchannel%d/gargle/waveshape", channel ), wxString::Format( "%d", _paramsGargle.dwWaveShape )); 
//	// Write Parametric EQ
//	settings->setValue( wxString::Format("/fxchannel%d/parameq/center", channel ), wxString::Format( "%f", _paramsParamEq.fCenter )); 
//	settings->setValue( wxString::Format("/fxchannel%d/parameq/bandwidth", channel ), wxString::Format( "%f", _paramsParamEq.fBandwidth )); 
//	settings->setValue( wxString::Format("/fxchannel%d/parameq/gain", channel ), wxString::Format( "%f", _paramsParamEq.fGain )); 
//	// Write Reverb
//	settings->setValue( wxString::Format("/fxchannel%d/reverb/ingain", channel ), wxString::Format( "%f", _paramsReverb.fInGain )); 
//	settings->setValue( wxString::Format("/fxchannel%d/reverb/reverbmix", channel ), wxString::Format( "%f", _paramsReverb.fReverbMix )); 
//	settings->setValue( wxString::Format("/fxchannel%d/reverb/reverbtime", channel ), wxString::Format( "%f", _paramsReverb.fReverbTime )); 
//	settings->setValue( wxString::Format("/fxchannel%d/reverb/highfreqrtratio", channel ), wxString::Format( "%f", _paramsReverb.fHighFreqRTRatio )); 
//	return true;
//}