//-----------------------------------------------------------------------------
// wx.NET - contextmenuevent.cxx
// 
// The wxContextMenuEvent proxy interface.
//
// Written by Alexander Olk (xenomorph2@onlinehome.de)
// (C) 2004 by Alexander Olk
// Licensed under the wxWidgets license, see LICENSE.txt for details.
//
// $Id$
//-----------------------------------------------------------------------------

#include <wx/wx.h>

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxContextMenuEvent* wxContextMenuEvent_ctor(wxEventType type)
{
    return new wxContextMenuEvent(type);
}

extern "C" WXEXPORT
void wxContextMenuEvent_GetPosition(wxContextMenuEvent* self, wxPoint* inp)
{
	*inp = self->GetPosition();
}

extern "C" WXEXPORT
void wxContextMenuEvent_SetPosition(wxContextMenuEvent* self, wxPoint* inp)
{
	self->SetPosition(*inp);
}
