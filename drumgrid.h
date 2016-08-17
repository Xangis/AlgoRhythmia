/////////////////////////////////////////////////////////////////////////////
// Name:        drumgrid.h
// Purpose:     
// Author:      Jason Champion
// Modified by: 
// Created:     01/08/2006 16:56:38
// RCS-ID:      
// Copyright:   (c) 2006
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _DRUMGRID_H_
#define _DRUMGRID_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "drumgrid.h"
#endif

#include "wx/wx.h"
#include "wx/grid.h"
#include "AlgoRhythmia.h"

#define ID_DRUMDIALOG 20000
#define SYMBOL_DRUMDIALOG_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_DRUMDIALOG_TITLE _("Drum Grid")
#define SYMBOL_DRUMDIALOG_IDNAME ID_DRUMDIALOG
#define SYMBOL_DRUMDIALOG_SIZE wxSize(400, 300)
#define SYMBOL_DRUMDIALOG_POSITION wxDefaultPosition
#define ID_DRUMGRID_1 20001
#define ID_DRUMGRID_2 20002
#define ID_DRUMGRID_3 20003
#define ID_DRUMGRID_4 20004

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

class DrumDialog: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( DrumDialog )
    DECLARE_EVENT_TABLE()

public:
    DrumDialog( );
    DrumDialog( wxWindow* parent, wxWindowID id = SYMBOL_DRUMDIALOG_IDNAME, const wxString& caption = SYMBOL_DRUMDIALOG_TITLE, const wxPoint& pos = SYMBOL_DRUMDIALOG_POSITION, const wxSize& size = SYMBOL_DRUMDIALOG_SIZE, long style = SYMBOL_DRUMDIALOG_STYLE );
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_DRUMDIALOG_IDNAME, const wxString& caption = SYMBOL_DRUMDIALOG_TITLE, const wxPoint& pos = SYMBOL_DRUMDIALOG_POSITION, const wxSize& size = SYMBOL_DRUMDIALOG_SIZE, long style = SYMBOL_DRUMDIALOG_STYLE );
    void CreateControls();
    void OnCellLeftClick( wxGridEvent& event );
	void SetActiveColumns( int columns );
	void SetActiveRows( void );
	void RefreshDrums( void );
	void RefreshDrum( int drum );
    wxBitmap GetBitmapResource( const wxString& name );
    wxIcon GetIconResource( const wxString& name );
    static bool ShowToolTips();
    wxGrid* m_drumGrid[MAX_MEASURES];
	void SetDrumControls( int number, DrumControl * control );
	DrumControl* _drumControl[DRUM_MAX];
	int _numBeatsPerMeasure;
	int _numMeasures;
};

#endif
