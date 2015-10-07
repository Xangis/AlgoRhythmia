#include "wx/wx.h"
#include "wx/image.h"
#include "AlgoRhythmiaApp.h"

IMPLEMENT_APP( AlgoRhythmiaApp )
IMPLEMENT_CLASS( AlgoRhythmiaApp, wxApp )

BEGIN_EVENT_TABLE( AlgoRhythmiaApp, wxApp )
END_EVENT_TABLE()

AlgoRhythmiaApp::AlgoRhythmiaApp()
{
}

AlgoRhythmiaApp::~AlgoRhythmiaApp()
{
}

bool AlgoRhythmiaApp::OnInit()
{
    wxInitAllImageHandlers();

    AlgoRhythmia* algoRhythmia = new AlgoRhythmia(NULL);
    algoRhythmia->Show(true);
	SetTopWindow( algoRhythmia );

    return true;
}

/*!
 * Cleanup for BoolGridApp
 */
int AlgoRhythmiaApp::OnExit()
{
    return wxApp::OnExit();
}

