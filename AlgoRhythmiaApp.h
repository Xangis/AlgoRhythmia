#ifndef _DIRECTNOISE_H_
#define _DIRECTNOISE_H_

//#include "resource.h"
#include "wx/wx.h"

#include "wx/grid.h"
#include "AlgoRhythmia.h"

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

class AlgoRhythmiaApp : public wxApp
{
    DECLARE_CLASS( AlgoRhythmiaApp )
    DECLARE_EVENT_TABLE()

public:
	AlgoRhythmiaApp();
#ifdef WIN32
	AlgoRhythmiaApp( HINSTANCE hInst, int nCmd );
#endif
	~AlgoRhythmiaApp();
    // Initialises the application
    virtual bool OnInit();

    // Called on exit
    virtual int OnExit();
};

DECLARE_APP(AlgoRhythmiaApp)

#endif
