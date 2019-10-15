/*
    Copyright (c) 2015 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include "WxFilePickerCtrl1Frame.h"
#include "WindowIDs.h"
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/sizer.h>

WxFilePickerCtrl1Frame::WxFilePickerCtrl1Frame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title), m_textCtrl(0)
{
    // Create a top-level panel to hold all the contents of the frame
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Create a wxFilePickerCtrl control
    wxFilePickerCtrl* filePickerCtrl = new wxFilePickerCtrl(panel, FilePickerID,
        wxEmptyString, wxFileSelectorPromptStr, wxFileSelectorDefaultWildcardStr,
        wxDefaultPosition, wxSize(350, wxDefaultCoord));

    // We add a wxTextCtrl that will contain the same path as
    // the wxFilePickerCtrl. This is done by using the event
    // generated by the wxFilePickerCtrl when the path changes.
    wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "Selected Path:");
    m_textCtrl = new wxTextCtrl(panel, wxID_ANY);

    // Set up the sizer for the panel
    wxBoxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
    panelSizer->Add(filePickerCtrl, 0, wxEXPAND | wxALL, 5);
    panelSizer->AddSpacer(15);
    panelSizer->Add(staticText, 0, wxEXPAND | wxLEFT, 5);
    panelSizer->Add(m_textCtrl, 0, wxEXPAND | wxALL, 5);
    panel->SetSizer(panelSizer);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}

// This event handler will be called when the path
// of the wxFilePickerCtrl has changed
void WxFilePickerCtrl1Frame::OnPathChanged(wxFileDirPickerEvent& evt)
{
    if (m_textCtrl)
    {
        m_textCtrl->SetValue(evt.GetPath());
    }
}

// Add the event handler to the event table. As you can see we use the
// window ID to link the event handler to the wxFilePickerCtrl we created.
wxBEGIN_EVENT_TABLE(WxFilePickerCtrl1Frame, wxFrame)
    EVT_FILEPICKER_CHANGED(FilePickerID, WxFilePickerCtrl1Frame::OnPathChanged)
wxEND_EVENT_TABLE()