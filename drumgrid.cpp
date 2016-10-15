/////////////////////////////////////////////////////////////////////////////
// Name:        drumgrid.cpp
// Purpose:     
// Author:      Jason Champion
// Modified by: 
// Created:     01/08/2006 16:56:38
// RCS-ID:      
// Copyright:   (c) 2006
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "drumgrid.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#include "wx/wx.h"
#include "wx/event.h"

#include "drumgrid.h"

IMPLEMENT_DYNAMIC_CLASS( DrumDialog, wxDialog )

BEGIN_EVENT_TABLE( DrumDialog, wxDialog )
    EVT_GRID_CELL_LEFT_CLICK( DrumDialog::OnCellLeftClick )
END_EVENT_TABLE()

DrumDialog::DrumDialog( )
{
}

DrumDialog::DrumDialog( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);
}

bool DrumDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    m_drumGrid[0] = NULL;
	m_drumGrid[1] = NULL;
	m_drumGrid[2] = NULL;
	m_drumGrid[3] = NULL;
	int count;
	for( count = 0; count < DRUM_MAX; count++ )
	{
		_drumControl[count] = NULL;
	}
	_numMeasures = 1;
    SetExtraStyle(GetExtraStyle()|wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );
    CreateControls();
    wxIcon _icon;

#ifndef __APPLE__
    wxString filepath = _("algo.ico");
#else
    wxString filepath = wxString::Format(_("%s//%s"), wxStandardPaths::Get().GetResourcesDir(), _("algo.ico"));
#endif
    if( _icon.LoadFile(filepath, wxBITMAP_TYPE_ICO ))
    {
        SetIcon(_icon);
    }

    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();
    return true;
}

/*!
 * Control creation for DrumDialog
 */

void DrumDialog::CreateControls()
{    
    DrumDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

	wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);

    m_drumGrid[0] = new wxGrid( itemDialog1, ID_DRUMGRID_1, wxDefaultPosition, wxSize(498, 194), wxSUNKEN_BORDER/*|wxHSCROLL|wxVSCROLL*/ );
    m_drumGrid[1] = new wxGrid( itemDialog1, ID_DRUMGRID_2, wxDefaultPosition, wxSize(498, 194), wxSUNKEN_BORDER/*|wxHSCROLL|wxVSCROLL*/ );
    m_drumGrid[2] = new wxGrid( itemDialog1, ID_DRUMGRID_3, wxDefaultPosition, wxSize(498, 194), wxSUNKEN_BORDER/*|wxHSCROLL|wxVSCROLL*/ );
    m_drumGrid[3] = new wxGrid( itemDialog1, ID_DRUMGRID_4, wxDefaultPosition, wxSize(498, 194), wxSUNKEN_BORDER/*|wxHSCROLL|wxVSCROLL*/ );
	int count = 0;
	for( count = 0; count < 4; count++ )
	{
		m_drumGrid[count]->SetDefaultColSize(21);
		m_drumGrid[count]->SetDefaultRowSize(19);
		m_drumGrid[count]->SetColLabelSize(21);
		m_drumGrid[count]->SetRowLabelSize(30);
		m_drumGrid[count]->CreateGrid(DRUM_MAX, MAX_MEASURE_LENGTH, wxGrid::wxGridSelectCells);
		m_drumGrid[count]->EnableEditing(false);
		m_drumGrid[count]->HideCellEditControl();
		m_drumGrid[count]->EnableDragGridSize(false);
		m_drumGrid[count]->EnableGridLines(false);
		int column;
		int row;
		_numBeatsPerMeasure = 16;
		for( column = 0; column < MAX_MEASURE_LENGTH; column++ )
		{
			m_drumGrid[count]->SetColFormatBool(column);
			m_drumGrid[count]->SetColLabelValue( column, wxString::Format( _("%d"), column+1 ));
			for( row = 0; row < DRUM_MAX; row++ )
			{
				m_drumGrid[count]->SetCellValue( row, column, _("0") );
				if( column >= _numBeatsPerMeasure )
				{
					m_drumGrid[count]->SetCellBackgroundColour(row, column, *wxLIGHT_GREY );
				}
			}
		}
		//m_drumGrid[count]->Fit();
	}
    itemBoxSizer3->Add(m_drumGrid[0], 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);
    itemBoxSizer3->Add(m_drumGrid[1], 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);
    itemBoxSizer4->Add(m_drumGrid[2], 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);
    itemBoxSizer4->Add(m_drumGrid[3], 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);
	itemBoxSizer2->Add(itemBoxSizer3, 0, 0, 0);
	itemBoxSizer2->Add(itemBoxSizer4, 0, 0, 0);
	Fit();

}

void DrumDialog::OnCellLeftClick( wxGridEvent& event )
{
	int row = event.GetRow();
	int column = event.GetCol();
#ifdef _DEMOVERSION
    if( row != 0 )
    {
        wxMessageBox( "Pattern editing is only enabled for drum channel 1 in the demo version." );
        return;
    }
#endif
    wxGrid* grid = (wxGrid*)event.GetEventObject();
	int id = event.GetId();
	bool state;
	if( grid == NULL )
	{
		return;
	}
	wxString value = grid->GetCellValue( row, column );
	if( value == _("0") )
	{
		state = true;
		grid->SetCellValue( row, column, _("1") );
	}
	else
	{
		state = false;
		grid->SetCellValue( row, column, _("0") );
	}
	int offset = 0;
	switch( id )
	{
		case ID_DRUMGRID_1:
			offset = 0;
			break;
		case ID_DRUMGRID_2:
			offset = MAX_MEASURE_LENGTH;
			break;
		case ID_DRUMGRID_3:
			offset = MAX_MEASURE_LENGTH * 2;
			break;
		case ID_DRUMGRID_4:
			offset = MAX_MEASURE_LENGTH * 3;
			break;
	}
	_drumControl[row]->_noteData[column+offset] = state;
    event.Skip();
}

bool DrumDialog::ShowToolTips()
{
    return true;
}

wxBitmap DrumDialog::GetBitmapResource( const wxString& name )
{
    wxUnusedVar(name);
    return wxNullBitmap;
}

wxIcon DrumDialog::GetIconResource( const wxString& name )
{
    wxUnusedVar(name);
    return wxNullIcon;
}

void DrumDialog::SetDrumControls( int number, DrumControl * control )
{
	_drumControl[number] = control;
	int count;
	for( count = 0; count < MAX_MEASURE_LENGTH; count++ )
	{
		m_drumGrid[0]->SetCellValue( number, count, wxString::Format( _("%d"), _drumControl[number]->_noteData[count] ));
		m_drumGrid[1]->SetCellValue( number, count, wxString::Format( _("%d"), _drumControl[number]->_noteData[count+MAX_MEASURE_LENGTH] ));
		m_drumGrid[2]->SetCellValue( number, count, wxString::Format( _("%d"), _drumControl[number]->_noteData[count+(MAX_MEASURE_LENGTH*2)] ));
		m_drumGrid[3]->SetCellValue( number, count, wxString::Format( _("%d"), _drumControl[number]->_noteData[count+(MAX_MEASURE_LENGTH*3)] ));
	}
	SetActiveRows();
}

void DrumDialog::SetActiveColumns( int columns )
{
	_numBeatsPerMeasure = columns;
	int count;
	for( count = 0; count < MAX_MEASURES; count++ )
	{
		int column;
		for( column = 0; column < MAX_MEASURE_LENGTH; column++ )
		{
			int row;
			for( row = 0; row < DRUM_MAX; row ++ )
			{
				if( column >= _numBeatsPerMeasure || !_drumControl[row]->_drumOn || count >= _numMeasures )
				{
					m_drumGrid[count]->SetCellBackgroundColour(row, column, *wxLIGHT_GREY );
				}
				else
				{
					m_drumGrid[count]->SetCellBackgroundColour(row, column, *wxWHITE );
				}
			}
		}
	}
	Refresh();
}

void DrumDialog::SetActiveRows()
{
	int count;
	for( count = 0; count < MAX_MEASURES; count++ )
	{
		int column;
		for( column = 0; column < MAX_MEASURE_LENGTH; column++ )
		{
			int row;
			for( row = 0; row < DRUM_MAX; row ++ )
			{
				bool on = true;
				if( _drumControl[row] != NULL )
				{
					on = _drumControl[row]->_drumOn;
				}
				if( column >= _numBeatsPerMeasure || !on || count >= _numMeasures )
				{
					m_drumGrid[count]->SetCellBackgroundColour(row, column, *wxLIGHT_GREY );
				}
				else
				{
					m_drumGrid[count]->SetCellBackgroundColour(row, column, *wxWHITE );
				}
			}
		}
	}
	Refresh();
}

void DrumDialog::RefreshDrums()
{
	int count;
	for( count = 0; count < DRUM_MAX; count++ )
	{
		RefreshDrum( count );
	}
}

void DrumDialog::RefreshDrum( int drum )
{
	if( drum < 0 || drum >= DRUM_MAX )
	{
		return;
	}
	int column;
	int grid;
	for( grid = 0; grid < MAX_MEASURES; grid++ )
	{
		for( column = 0; column < MAX_MEASURE_LENGTH; column++ )
		{
			m_drumGrid[grid]->SetCellValue( drum, column, wxString::Format( _("%d"), _drumControl[drum]->_noteData[((grid * MAX_MEASURE_LENGTH) + column)] ));
		}
	}
}
