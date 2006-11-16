//-----------------------------------------------------------------------------
// wx.NET - image.cxx
//
// The wxImage proxy interface.
//
// Written by Jason Perkins (jason@379.com)
// (C) 2003 by 379, Inc.
// Licensed under the wxWidgets license, see LICENSE.txt for details.
//
// $Id$
//-----------------------------------------------------------------------------

#include <wx/wx.h>
#include <wx/image.h>

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxImage* wxImage_ctor()
{
	return new wxImage();
}

extern "C" WXEXPORT
wxImage* wxImage_ctorByName(const char* name, int type)
{
	return new wxImage(wxString(name, wxConvUTF8), type);
}

extern "C" WXEXPORT
wxImage* wxImage_ctorintintbool(int width, int height, bool clear)
{
	return new wxImage(width, height, clear);
}

extern "C" WXEXPORT
wxImage* wxImage_ctorByImage(wxImage* image)
{
	return new wxImage(image);
}

extern "C" WXEXPORT
void wxImage_dtor(wxImage* self)
{
	if (self != NULL)
		delete self;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImage_Destroy(wxImage* self)
{
	self->Destroy();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxImage_GetHeight(wxImage* self)
{
	return self->GetHeight();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxImage_GetWidth(wxImage* self)
{
	return self->GetWidth();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImage_InitAllHandlers()
{
	wxInitAllImageHandlers();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
bool wxImage_LoadFileByTypeId(wxImage* self, const char* name, int type, int index)
{
	return self->LoadFile(wxString(name, wxConvUTF8), type, index)?1:0;
}

extern "C" WXEXPORT
bool wxImage_LoadFileByMimeTypeId(wxImage* self, const char* name, const char* mimetype, int index)
{
	return self->LoadFile(wxString(name, wxConvUTF8), wxString(mimetype, wxConvUTF8), index)?1:0;
}


extern "C" WXEXPORT
bool wxImage_SaveFileByType(wxImage* self, const char* name, int type)
{
    return self->SaveFile(wxString(name, wxConvUTF8), type)?1:0;
}

extern "C" WXEXPORT
bool wxImage_SaveFileByMimeType(wxImage* self, const char* name, const char* mimetype)
{
    return self->SaveFile(wxString(name, wxConvUTF8), wxString(mimetype, wxConvUTF8))?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxImage* wxImage_Rescale(wxImage* self, int width, int height)
{
	return new wxImage(self->Rescale(width, height));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxImage* wxImage_Scale(wxImage* self, int width, int height)
{
	return new wxImage(self->Scale(width, height));

}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImage_SetMaskColour(wxImage* self, unsigned char r, unsigned char g, unsigned char b)
{
    self->SetMaskColour(r, g, b);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImage_SetMask(wxImage* self, bool mask)
{
    self->SetMask(mask);
}

extern "C" WXEXPORT
bool wxImage_HasMask(wxImage* self)
{
    return self->HasMask()?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxImage* wxImage_Copy(wxImage* self)
{
	return new wxImage(self->Copy());
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxImage* wxImage_GetSubImage(wxImage* self, wxRect* rect)
{
	return new wxImage(self->GetSubImage(*rect));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImage_Paste(wxImage* self, wxImage* image, int x, int y)
{
	self->Paste(*image, x, y);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxImage* wxImage_ShrinkBy(wxImage* self, int xFactor, int yFactor)
{
	return new wxImage(self->ShrinkBy(xFactor, yFactor));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxImage* wxImage_Rotate(wxImage* self, double angle, wxPoint* centre_of_rotation, bool interpolating, wxPoint* offset_after_rotation)
{
	return new wxImage(self->Rotate(angle, *centre_of_rotation, interpolating, offset_after_rotation));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxImage* wxImage_Rotate90(wxImage* self, bool clockwise)
{
	return new wxImage(self->Rotate90(clockwise));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxImage* wxImage_Mirror(wxImage* self, bool horizontally)
{
	return new wxImage(self->Mirror(horizontally));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImage_Replace(wxImage* self, unsigned char r1, unsigned char g1, unsigned char b1, unsigned char r2, unsigned char g2, unsigned char b2)
{
	self->Replace(r1, g1, b1, r2, g2, b2);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxImage* wxImage_ConvertToMono(wxImage* self, unsigned char r, unsigned char g, unsigned char b)
{
	return new wxImage(self->ConvertToMono(r, g, b));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImage_SetRGB(wxImage* self, int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
	self->SetRGB(x, y, r, g, b);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
unsigned char wxImage_GetRed(wxImage* self, int x, int y)
{
	return self->GetRed(x, y);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
unsigned char wxImage_GetGreen(wxImage* self, int x, int y)
{
	return self->GetGreen(x, y);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
unsigned char wxImage_GetBlue(wxImage* self, int x, int y)
{
	return self->GetBlue(x, y);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImage_SetAlpha(wxImage* self, int x, int y, unsigned char alpha)
{
	self->SetAlpha(x, y, alpha);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
unsigned char wxImage_GetAlpha(wxImage* self, int x, int y)
{
	return self->GetAlpha(x, y);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
bool wxImage_FindFirstUnusedColour(wxImage* self, unsigned char* r, unsigned char* g, unsigned char* b, unsigned char startR, unsigned char startG, unsigned char startB)
{
	return self->FindFirstUnusedColour(r, g, b, startR, startG, startB)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
bool wxImage_SetMaskFromImage(wxImage* self, wxImage* mask, unsigned char mr, unsigned char mg, unsigned char mb)
{
	return self->SetMaskFromImage(*mask, mr, mg, mb)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
bool wxImage_ConvertAlphaToMask(wxImage* self, unsigned char threshold)
{
	return self->ConvertAlphaToMask(threshold)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
bool wxImage_CanRead(const char* name)
{
	return wxImage::CanRead(wxString(name, wxConvUTF8))?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxImage_GetImageCount(const char* name, int type)
{
	return wxImage::GetImageCount(wxString(name, wxConvUTF8), type);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
bool wxImage_Ok(wxImage* self)
{
	return self->Ok()?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
unsigned char wxImage_GetMaskRed(wxImage* self)
{
	return self->GetMaskRed();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
unsigned char wxImage_GetMaskGreen(wxImage* self)
{
	return self->GetMaskGreen();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
unsigned char wxImage_GetMaskBlue(wxImage* self)
{
	return self->GetMaskBlue();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
bool wxImage_HasPalette(wxImage* self)
{
	return self->HasPalette()?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxPalette* wxImage_GetPalette(wxImage* self)
{
	return new wxPalette(self->GetPalette());
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImage_SetPalette(wxImage* self, wxPalette* palette)
{
	self->SetPalette(*palette);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImage_SetOption(wxImage* self, const char* name, const char* value)
{
	self->SetOption(wxString(name, wxConvUTF8), wxString(value, wxConvUTF8));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImage_SetOption2(wxImage* self, const char* name, int value)
{
	self->SetOption(wxString(name, wxConvUTF8), value);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxString* wxImage_GetOption(wxImage* self, const char* name)
{
	return new wxString(self->GetOption(wxString(name, wxConvUTF8)));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxImage_GetOptionInt(wxImage* self, const char* name)
{
	return self->GetOptionInt(wxString(name, wxConvUTF8));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
bool wxImage_HasOption(wxImage* self, const char* name)
{
	return self->HasOption(wxString(name, wxConvUTF8))?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
unsigned long wxImage_CountColours(wxImage* self, unsigned long stopafter)
{
	return self->CountColours(stopafter);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
unsigned long wxImage_ComputeHistogram(wxImage* self, wxImageHistogram* h)
{
	return self->ComputeHistogram(*h);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxList* wxImage_GetHandlers()
{
	return new wxList(wxImage::GetHandlers());
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImage_AddHandler(wxImageHandler* handler)
{
	wxImage::AddHandler(handler);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImage_InsertHandler(wxImageHandler* handler)
{
	wxImage::InsertHandler(handler);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
bool wxImage_RemoveHandler(const char* name)
{
	return wxImage::RemoveHandler(wxString(name,wxConvUTF8))?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxImageHandler* wxImage_FindHandler(const char* name)
{
	return wxImage::FindHandler(wxString(name, wxConvUTF8));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxImageHandler* wxImage_FindHandler2(const char* name, long imageType)
{
	return wxImage::FindHandler(wxString(name, wxConvUTF8), imageType);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxImageHandler* wxImage_FindHandler3(long imageType)
{
	return wxImage::FindHandler(imageType);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxImageHandler* wxImage_FindHandlerMime(const char* mimetype)
{
	return wxImage::FindHandlerMime(wxString(mimetype, wxConvUTF8));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxString* wxImage_GetImageExtWildcard()
{
	return new wxString(wxImage::GetImageExtWildcard());
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImage_CleanUpHandlers()
{
	wxImage::CleanUpHandlers();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImage_InitStandardHandlers()
{
	wxImage::InitStandardHandlers();
}

//-----------------------------------------------------------------------------
// wxImageHandler


extern "C" WXEXPORT
void wxImageHandler_SetName(wxImageHandler* self, const char* name)
{
	self->SetName(wxString(name, wxConvUTF8));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImageHandler_SetExtension(wxImageHandler* self, const char* ext)
{
	self->SetExtension(wxString(ext, wxConvUTF8));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImageHandler_SetType(wxImageHandler* self, long type)
{
	self->SetType(type);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImageHandler_SetMimeType(wxImageHandler* self, const char* type)
{
	self->SetMimeType(wxString(type, wxConvUTF8));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxString* wxImageHandler_GetName(wxImageHandler* self)
{
	return new wxString(self->GetName());
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxString* wxImageHandler_GetExtension(wxImageHandler* self)
{
	return new wxString(self->GetExtension());
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
long wxImageHandler_GetType(wxImageHandler* self)
{
	return self->GetType();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxString* wxImageHandler_GetMimeType(wxImageHandler* self)
{
	return new wxString(self->GetMimeType());
}

//-----------------------------------------------------------------------------
// wxImageHistogramEntry

extern "C" WXEXPORT
wxImageHistogramEntry* wxImageHistogramEntry_ctor()
{
	return new wxImageHistogramEntry();
}

extern "C" WXEXPORT
void wxImageHistogramEntry_dtor(wxImageHistogramEntry* self)
{
	if (self != NULL)
		delete self;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
unsigned long wxImageHistogramEntry_index(wxImageHistogramEntry* self)
{
	return self->index;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImageHistogramEntry_Setindex(wxImageHistogramEntry* self, unsigned long v)
{
	self->index=v;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
unsigned long wxImageHistogramEntry_value(wxImageHistogramEntry* self)
{
	return self->value;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxImageHistogramEntry_Setvalue(wxImageHistogramEntry* self, unsigned long v)
{
	self->value=v;
}

//-----------------------------------------------------------------------------
// wxImageHistogram

extern "C" WXEXPORT
wxImageHistogram* wxImageHistogram_ctor()
{
	return new wxImageHistogram();
}

extern "C" WXEXPORT
void wxImageHistogram_dtor(wxImageHistogram* self)
{
	if (self != NULL)
		delete self;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
unsigned long wxImageHistogram_MakeKey(unsigned char r, unsigned char g, unsigned char b)
{
		return wxImageHistogram::MakeKey(r, g, b);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
bool wxImageHistogram_FindFirstUnusedColour(wxImageHistogram* self, unsigned char* r, unsigned char* g, unsigned char*b, unsigned char startR, unsigned char startG, unsigned char startB)
{
	return self->FindFirstUnusedColour(r, g, b, startR, startG, startB)?1:0;
}
