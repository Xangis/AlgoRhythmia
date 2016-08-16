//#ifndef _SOUNDFXMANAGER_H_
//#define _SOUNDFXMANAGER_H_
//
//#include <windows.h>
//#include <basetsd.h>
//#include <mmsystem.h>
//#include <mmreg.h>
//#include <dxerr.h>
//#include <dsound.h>
//#include <cguid.h>
//#include <commctrl.h>
//#include <commdlg.h>
//#include <stdio.h>
//#include "Configuration.h"
//
//#ifndef SAFE_RELEASE
//#define SAFE_RELEASE(x) \
//   if(x != NULL)        \
//   {                    \
//      x->Release();     \
//      x = NULL;         \
//   }
//#endif
//
////-----------------------------------------------------------------------------
//// Name: enum ESFXType
//// Desc: each is a unique identifier mapped to a DirectSoundFX
////-----------------------------------------------------------------------------
//enum ESFXType
//{
//    eSFX_chorus = 0,
//    eSFX_compressor,
//    eSFX_distortion,
//    eSFX_echo,
//    eSFX_flanger,
//    eSFX_gargle,
//    eSFX_parameq,
//    eSFX_reverb,
//
//    // number of enumerated effects
//    eNUM_SFX
//};
//
////-----------------------------------------------------------------------------
//// Name: class SoundFxManager
//// Desc: Takes care of effects for one DirectSoundBuffer
////-----------------------------------------------------------------------------
//class SoundFxManager
//{
//public:
//    SoundFxManager();
//    ~SoundFxManager();
//
//public: // interface
//    HRESULT Initialize ( IDirectMusicAudioPath * pAudioPath8, BOOL bLoadDefaultParamValues );
//    HRESULT UnInitialize ();
//
//    HRESULT SetFXEnable( DWORD esfxType );
//    HRESULT ActivateFX();
//    HRESULT DisableAllFX();
//    HRESULT LoadCurrentFXParameters();
//
//public: // members
//    LPDIRECTSOUNDFXCHORUS8      _lpChorus;
//    LPDIRECTSOUNDFXCOMPRESSOR8  _lpCompressor;
//    LPDIRECTSOUNDFXDISTORTION8  _lpDistortion;
//    LPDIRECTSOUNDFXECHO8        _lpEcho;
//    LPDIRECTSOUNDFXFLANGER8     _lpFlanger;
//    LPDIRECTSOUNDFXGARGLE8      _lpGargle;
//    LPDIRECTSOUNDFXPARAMEQ8     _lpParamEq;
//    LPDIRECTSOUNDFXWAVESREVERB8 _lpReverb;
//
//    DSFXChorus                  _paramsChorus;
//    DSFXCompressor              _paramsCompressor;
//    DSFXDistortion              _paramsDistortion;
//    DSFXEcho                    _paramsEcho;
//    DSFXFlanger                 _paramsFlanger;
//    DSFXGargle                  _paramsGargle;
//    DSFXParamEq                 _paramsParamEq;
//    DSFXWavesReverb             _paramsReverb;
//
//    LPDIRECTSOUNDBUFFER8        _lpDSB8;
//    IDirectMusicAudioPath *    _pAudioPath;
//
//	bool WriteConfigurationSettings( int channel, ConfigurationSettings* settings );
//	bool ReadConfigurationSettings( int channel, ConfigurationSettings* settings );
//
//protected:
//    DSEFFECTDESC                _rgFxDesc[eNUM_SFX];
//    const GUID *                _rgRefGuids[eNUM_SFX];
//    LPVOID *                    _rgPtrs[eNUM_SFX];
//    BOOL                        _rgLoaded[eNUM_SFX];
//    DWORD                       _dwNumFX;
//
//    HRESULT EnableGenericFX( GUID guidSFXClass, REFGUID rguidInterface, LPVOID * ppObj );
//    HRESULT LoadDefaultParamValues();
//};
//
//#endif