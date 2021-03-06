/***************************************************************
 * Name:      SourceCounterMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    boomworks.net (boomworks@gmail.com)
 * Created:   2008-10-09
 * Copyright: boomworks.net (http://www.boomworks.net)
 * License:
 **************************************************************/

//(*InternalHeaders(SourceCounterDialog)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include <wx/tokenzr.h>
#include <wx/msgdlg.h>
#include <wx/mimetype.h>
#include <wx/config.h>

#include "wx_pch.h"

#include "SourceCounterMain.h"
#include "aboutdlg.h"
#include "CntSettingDlg.h"
#include "SrcTypeSelDlg.h"
#include "chooselang.h"

///////////////////////////////////////////////////////////////////////

const wxString CSZ_STATUS[] =
{
    _("Ready."),
    _("Counting..."),
    _("Completed."),
    _("Canceled."),
};

const wxString CSZ_DIALOG_CAPTIOM = _("SourceCounter");

///////////////////////////////////////////////////////////////////////

//(*IdInit(SourceCounterDialog)
const long SourceCounterDialog::ID_STATICTEXT2 = wxNewId();
const long SourceCounterDialog::ID_CHECKLISTBOX1 = wxNewId();
const long SourceCounterDialog::ID_BUTTON3 = wxNewId();
const long SourceCounterDialog::ID_BUTTON9 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT1 = wxNewId();
const long SourceCounterDialog::ID_COMBOBOX1 = wxNewId();
const long SourceCounterDialog::ID_BUTTON8 = wxNewId();
const long SourceCounterDialog::ID_CHECKBOX1 = wxNewId();
const long SourceCounterDialog::ID_BUTTON4 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT9 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT10 = wxNewId();
const long SourceCounterDialog::ID_BUTTON5 = wxNewId();
const long SourceCounterDialog::ID_BUTTON6 = wxNewId();
const long SourceCounterDialog::ID_LISTCTRL1 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT12 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT4 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT22 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT21 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT3 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT11 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT13 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT6 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT23 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT26 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT5 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT14 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT16 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT8 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT27 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT24 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT18 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT20 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT29 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT30 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT25 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT28 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT19 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT17 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT7 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT15 = wxNewId();
const long SourceCounterDialog::ID_BUTTON7 = wxNewId();
const long SourceCounterDialog::ID_BUTTON11 = wxNewId();
const long SourceCounterDialog::ID_BUTTON10 = wxNewId();
const long SourceCounterDialog::ID_MENU_ITEM_OPEN = wxNewId();
const long SourceCounterDialog::ID_MENU_ITEM_OPENDIR = wxNewId();
//*)

BEGIN_EVENT_TABLE(SourceCounterDialog,wxDialog)
    //(*EventTable(SourceCounterDialog)
    //*)
END_EVENT_TABLE()

SourceCounterDialog::SourceCounterDialog(wxWindow* parent,wxWindowID id):
        m_pCountingMgr(0)
{
    //(*Initialize(SourceCounterDialog)
    wxBoxSizer* BoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxBoxSizer* BoxSizer6;
    wxMenuItem* m_menuItemOpen;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxBoxSizer* BoxSizer13;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer11;
    wxBoxSizer* BoxSizer16;
    wxBoxSizer* BoxSizer12;
    wxBoxSizer* BoxSizer14;
    wxBoxSizer* BoxSizer17;
    wxBoxSizer* BoxSizer9;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxBoxSizer* BoxSizer3;
    wxMenuItem* m_menuItemOpenDir;
    
    Create(parent, wxID_ANY, _("SourceCounter"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Options"));
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Source code &folder:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer4->Add(StaticText2, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
    m_lbxSrcFolder = new wxCheckListBox(this, ID_CHECKLISTBOX1, wxDefaultPosition, wxSize(387,80), 0, 0, wxLB_SINGLE, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
    BoxSizer14->Add(m_lbxSrcFolder, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer14, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer13 = new wxBoxSizer(wxVERTICAL);
    m_btnAdd = new wxButton(this, ID_BUTTON3, _("&Add..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer13->Add(m_btnAdd, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnDelete = new wxButton(this, ID_BUTTON9, _("&Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
    m_btnDelete->Disable();
    BoxSizer13->Add(m_btnDelete, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer13, 0, wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    BoxSizer4->Add(BoxSizer2, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer4, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Source &type:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer3->Add(StaticText1, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_cmbSrcTypes = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX1"));
    BoxSizer3->Add(m_cmbSrcTypes, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnSelSrcType = new wxButton(this, ID_BUTTON8, _("S&elect..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    BoxSizer3->Add(m_btnSelSrcType, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer3, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    m_chbRecursiveCouting = new wxCheckBox(this, ID_CHECKBOX1, _("&Recursive file counting"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    m_chbRecursiveCouting->SetValue(true);
    m_chbRecursiveCouting->SetToolTip(_("Check this box if you wish to count all files that located in the subfolders of source code folder."));
    BoxSizer5->Add(m_chbRecursiveCouting, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnMoreSetting = new wxButton(this, ID_BUTTON4, _("&More settings..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer5->Add(m_btnMoreSetting, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer5, 1, wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(StaticBoxSizer1, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Counting status:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    BoxSizer11->Add(StaticText9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblStatus = new wxStaticText(this, ID_STATICTEXT10, _("Ready."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    BoxSizer11->Add(m_lblStatus, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnStart = new wxButton(this, ID_BUTTON5, _("&Start"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    BoxSizer11->Add(m_btnStart, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnStop = new wxButton(this, ID_BUTTON6, _("Sto&p"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    m_btnStop->Disable();
    BoxSizer11->Add(m_btnStop, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer11, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("Counting result"));
    BoxSizer6 = new wxBoxSizer(wxVERTICAL);
    m_lstResult = new wxListCtrl(this, ID_LISTCTRL1, wxDefaultPosition, wxSize(500,180), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES|wxLC_VRULES, wxDefaultValidator, _T("ID_LISTCTRL1"));
    BoxSizer6->Add(m_lstResult, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer6, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("Code lines:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    BoxSizer7->Add(StaticText12, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblCodeLines = new wxStaticText(this, ID_STATICTEXT4, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT4"));
    m_lblCodeLines->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    BoxSizer7->Add(m_lblCodeLines, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText10 = new wxStaticText(this, ID_STATICTEXT22, _("Total UT Cases:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    BoxSizer7->Add(StaticText10, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblUtCases = new wxStaticText(this, ID_STATICTEXT21, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT21"));
    m_lblUtCases->SetForegroundColour(wxColour(0,128,0));
    BoxSizer7->Add(m_lblUtCases, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Total files:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer7->Add(StaticText3, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblTotalFiles = new wxStaticText(this, ID_STATICTEXT11, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT11"));
    m_lblTotalFiles->SetForegroundColour(wxColour(128,0,64));
    BoxSizer7->Add(m_lblTotalFiles, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer7, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("Comment lines:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    BoxSizer8->Add(StaticText13, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblCommentLines = new wxStaticText(this, ID_STATICTEXT6, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT6"));
    m_lblCommentLines->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    BoxSizer8->Add(m_lblCommentLines, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText11 = new wxStaticText(this, ID_STATICTEXT23, _("Total UT Defects:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    BoxSizer8->Add(StaticText11, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblUtDefects = new wxStaticText(this, ID_STATICTEXT26, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT26"));
    m_lblUtDefects->SetForegroundColour(wxColour(255,0,0));
    BoxSizer8->Add(m_lblUtDefects, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Total size (KB):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    BoxSizer8->Add(StaticText5, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblTotalSize = new wxStaticText(this, ID_STATICTEXT14, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT14"));
    m_lblTotalSize->SetForegroundColour(wxColour(128,0,64));
    BoxSizer8->Add(m_lblTotalSize, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer8, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    StaticText16 = new wxStaticText(this, ID_STATICTEXT16, _("Blank lines:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    BoxSizer9->Add(StaticText16, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblBlankLines = new wxStaticText(this, ID_STATICTEXT8, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT8"));
    m_lblBlankLines->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    BoxSizer9->Add(m_lblBlankLines, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText18 = new wxStaticText(this, ID_STATICTEXT27, _("Total IT Cases:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT27"));
    BoxSizer9->Add(StaticText18, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblItCases = new wxStaticText(this, ID_STATICTEXT24, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT24"));
    m_lblItCases->SetForegroundColour(wxColour(0,128,0));
    BoxSizer9->Add(m_lblItCases, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT18, _("Total man-month:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    BoxSizer9->Add(StaticText6, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblTotalMM = new wxStaticText(this, ID_STATICTEXT20, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT20"));
    m_lblTotalMM->SetForegroundColour(wxColour(255,0,255));
    BoxSizer9->Add(m_lblTotalMM, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer9, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer16 = new wxBoxSizer(wxHORIZONTAL);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT29, _("Code// Comment:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT29"));
    BoxSizer16->Add(StaticText4, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblCodeCommentLines = new wxStaticText(this, ID_STATICTEXT30, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT30"));
    m_lblCodeCommentLines->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    BoxSizer16->Add(m_lblCodeCommentLines, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText15 = new wxStaticText(this, ID_STATICTEXT25, _("Total IT Defects:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    BoxSizer16->Add(StaticText15, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblItDefects = new wxStaticText(this, ID_STATICTEXT28, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT28"));
    m_lblItDefects->SetForegroundColour(wxColour(255,0,0));
    BoxSizer16->Add(m_lblItDefects, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(this, ID_STATICTEXT19, _("Total cost($):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    BoxSizer16->Add(StaticText8, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblTotalCost = new wxStaticText(this, ID_STATICTEXT17, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT17"));
    m_lblTotalCost->SetForegroundColour(wxColour(255,0,255));
    BoxSizer16->Add(m_lblTotalCost, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer16, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer17 = new wxBoxSizer(wxHORIZONTAL);
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Total lines:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    BoxSizer17->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblTotalLines = new wxStaticText(this, ID_STATICTEXT15, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT15"));
    m_lblTotalLines->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    BoxSizer17->Add(m_lblTotalLines, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer17->Add(-1,-1,3, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnSave = new wxButton(this, ID_BUTTON7, _("Sa&ve..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    m_btnSave->Disable();
    BoxSizer17->Add(m_btnSave, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer17, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(StaticBoxSizer2, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
    m_btnCheckUpdate = new wxButton(this, ID_BUTTON11, _("&Check for updates..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON11"));
    m_btnCheckUpdate->SetToolTip(_("Get the latest version from http://down.boomworks.org"));
    BoxSizer12->Add(m_btnCheckUpdate, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnUiLang = new wxButton(this, ID_BUTTON10, _("U&I Language..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON10"));
    BoxSizer12->Add(m_btnUiLang, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, wxID_ABOUT, _("A&bout..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_ABOUT"));
    BoxSizer12->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    Button2 = new wxButton(this, wxID_EXIT, _("&Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_EXIT"));
    BoxSizer12->Add(Button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer12->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer12, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    m_dlgAddDir = new wxDirDialog(this, _("Select directory"), wxEmptyString, wxDD_DIR_MUST_EXIST, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));
    m_dlgFile = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("CSV files (*.csv)|*.csv"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    m_menuItemOpen = new wxMenuItem((&m_pMenu), ID_MENU_ITEM_OPEN, _("Open file"), wxEmptyString, wxITEM_NORMAL);
    m_pMenu.Append(m_menuItemOpen);
    m_menuItemOpenDir = new wxMenuItem((&m_pMenu), ID_MENU_ITEM_OPENDIR, _("Open directory"), wxEmptyString, wxITEM_NORMAL);
    m_pMenu.Append(m_menuItemOpenDir);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();
    
    Connect(ID_CHECKLISTBOX1,wxEVT_COMMAND_CHECKLISTBOX_TOGGLED,(wxObjectEventFunction)&SourceCounterDialog::OnLbxSrcFolderCheck);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnBtnAddDirClick);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnBtnDeleteClick);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnBtnSelSrcTypeClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnBtnMoreSettingsClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnBtnStartClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnBtnStopClick);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK,(wxObjectEventFunction)&SourceCounterDialog::OnLstResultItemRClick);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnBtnSaveClick);
    Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnBtnCheckUpdateClick);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnBtnUiLangClick);
    Connect(wxID_ABOUT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnAbout);
    Connect(wxID_EXIT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnQuit);
    Connect(ID_MENU_ITEM_OPEN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SourceCounterDialog::OnMenuItemOpenSelected);
    Connect(ID_MENU_ITEM_OPENDIR,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SourceCounterDialog::OnMenuItemOpenDirSelected);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&SourceCounterDialog::OnInit);
    //*)

    //
    Connect(ID_CHECKLISTBOX1, wxEVT_COMMAND_LISTBOX_SELECTED, (wxObjectEventFunction)&SourceCounterDialog::OnLbxSrcFolderItemSelect);

}

SourceCounterDialog::~SourceCounterDialog()
{
    //(*Destroy(SourceCounterDialog)
    //*)

    if (m_pCountingMgr->GetStatus() == NManagerStatusRunning)
    {
        m_pCountingMgr->SetStatus(NManagerStatusStop);
    }

    //
    // Save source folder path and source types to registy
    //

    wxConfigBase* pConf = wxConfig::Get();
    pConf->SetPath(wxT("/"));

// TODO: The code of below doesnt work, because the source file types is not selected
//		 from dialog
//    wxString strSrcTypes = m_cmbSrcTypes->GetValue();
//    pConf->Write(wxT("SrcTypes"), strSrcTypes);

    // Get current source folder number
    int nSrcFolderNum = m_lbxSrcFolder->GetCount();

    // Write source folder number to Registry
    pConf->Write(wxT("SrcFolderNum"), (long)nSrcFolderNum);

    // Source folder exists, write path to Registry
    if (nSrcFolderNum)
    {
        pConf->SetPath(wxT("SrcFolderHistory"));

        wxString strTemp;
        for (int i=0; i<nSrcFolderNum; i++)
        {
            strTemp.Printf(wxT("%d"), i);
            pConf->Write(strTemp, m_lbxSrcFolder->GetString(i));
        }
    }

    // finally set path to root
    pConf->SetPath(wxT("/"));

	//
	//
	//

    if (m_pCountingMgr)
    {
        delete m_pCountingMgr;
        m_pCountingMgr = 0;
    }
}

void SourceCounterDialog::OnQuit(wxCommandEvent& event)
{
    if (m_pCountingMgr->GetStatus() == NManagerStatusRunning)
    {
        m_pCountingMgr->SetStatus(NManagerStatusStop);
    }

    //
    // Close dialog
    //
    Close();
}

void SourceCounterDialog::OnAbout(wxCommandEvent& event)
{
    AboutDlg dlg(this);
    dlg.ShowModal();
}

/**
 * More counting param setting
 */
void SourceCounterDialog::OnBtnMoreSettingsClick(wxCommandEvent& event)
{
    CountingParam* pCountingParam = m_pCountingMgr->GetCountingParam();
    SettingParam* pParam = &(pCountingParam->m_settingParam);

    CntSettingDlg dlg(this);
    dlg.SetSettingParam(pParam);

    if (wxID_OK == dlg.ShowModal())
    {
        dlg.GetSettingParam(pCountingParam->m_settingParam);
    }
}

void SourceCounterDialog::OnBtnAddDirClick(wxCommandEvent& event)
{
//    try
//    {
    if ( wxID_OK == m_dlgAddDir->ShowModal())
    {
        //
        wxString strPath = m_dlgAddDir->GetPath();
        int nIndex = m_lbxSrcFolder->Append(strPath);
        m_lbxSrcFolder->Check(nIndex, true);
    }
//    }
//    catch (...)
//    {
//        wxMessageBox(_T("Unknown error!"));
//    }
}

void SourceCounterDialog::OnBtnDeleteClick(wxCommandEvent& event)
{
    // Confirm when the delete button be clicked - Boom 20090821
    int nRet = wxMessageBox(_("Do you want to delete it?"), _("Confirm"),
                            wxYES_NO, this);
    if (nRet == wxYES)
    {
        // Get selection
        int nIndex = -1;
        nIndex = m_lbxSrcFolder->GetSelection();
        if (-1 == nIndex)
            return;

        // Delete item
        m_lbxSrcFolder->Delete(nIndex);

        updateOptionsCtrls();
    }
}

void SourceCounterDialog::OnBtnSelSrcTypeClick(wxCommandEvent& event)
{
    //
    SrcTypeSelDlg dlg(this);
    dlg.SetMapData(m_pCountingMgr->GetCounterRules(), m_pCountingMgr->GetFileExtensions());

    if (wxID_OK == dlg.ShowModal())
    {
        wxString strSrcTypes;
        dlg.GetSrcTypes(strSrcTypes);
        //wxMessageBox(strSrcTypes);
        m_cmbSrcTypes->Append(strSrcTypes);
        m_cmbSrcTypes->SetValue(strSrcTypes);
    }
}

void SourceCounterDialog::OnLbxSrcFolderCheck(wxCommandEvent& event)
{
//    int nIndex = -1;
//    nIndex = m_lbxSrcFolder->GetSelection();
//
//    wxString strTemp;
//    strTemp.Printf(_T("%d"), nIndex);
//
//    wxMessageBox(strTemp);
}

void SourceCounterDialog::OnLbxSrcFolderItemSelect(wxCommandEvent& evt)
{
    if ( wxNOT_FOUND != m_lbxSrcFolder->GetSelection())
    {
        m_btnDelete->Enable();
    }
}

void SourceCounterDialog::OnBtnStartClick(wxCommandEvent& event)
{
    //
    // Check counting parameter
    //

    // Check source folder exist
    int nCount = m_lbxSrcFolder->GetCount();
    if (0 == nCount)
    {
        wxMessageBox(_("Please add source folder."), CSZ_DIALOG_CAPTIOM, wxOK, this);
        return;
    }

    // Check source folder have been checked
    bool bHasChecked = false;
    for (int i = 0; i < nCount; i++)
    {
        bHasChecked = m_lbxSrcFolder->IsChecked(i);
        if (bHasChecked)
        {
            break;
        }
    }

    if (!bHasChecked)
    {
        wxMessageBox(_("Please check counting folder."), CSZ_DIALOG_CAPTIOM);
        return;
    }

    // Check source types
    wxString strSrcTypes;
    strSrcTypes.Empty();
    strSrcTypes = m_cmbSrcTypes->GetValue();
    if (strSrcTypes.IsEmpty())
    {
        wxMessageBox(_("Please select source types."), CSZ_DIALOG_CAPTIOM);
        return;
    }

    //
    // Prepare counting
    //

    m_pCountingMgr->Clear();	    // Clear prev counting info

    m_pCountingMgr->SetStatus(NManagerStatusRunning);

    // Update options ctrls and Initial counting ctrls
    updateOptionsCtrls();
    initCountingCtrls();

    //
    // Collection of counting parameter information
    //

    CountingParam countingParam;

    // Collect source folder path for counting
    for (int i = 0; i < nCount; i++)
    {
        if (m_lbxSrcFolder->IsChecked(i))
        {
            countingParam.m_arrSrcFolderPath.Add(m_lbxSrcFolder->GetString(i));
        }
    }

    // Collect source types
    wxStringTokenizer tkz(strSrcTypes, _T(";"));
    while ( tkz.HasMoreTokens() )
    {
        wxString token = tkz.GetNextToken();
        countingParam.m_arrSrcType.Add(token);
    }

    // Collect recursive counting
    countingParam.m_bRecursiveCounting = m_chbRecursiveCouting->GetValue();

    // Set counting parameter to CountingManager
    m_pCountingMgr->SetCountingParam( &countingParam );

    //
    // Start counting by call CountingManager
    //

    // Attach observer
    m_pCountingMgr->AttachObserver(this);

    // Set wait cursor
    wxCursor cursor1(wxCURSOR_WAIT);
    this->SetCursor(cursor1);

    m_lblStatus->SetLabel(CSZ_STATUS[1]); // Counting

//    try
//    {
    // Start counting
    m_pCountingMgr->StartCounting();
//    }
//    catch (...)
//    {
//        wxMessageBox(_T("Unknown error occured! Please start counting again."));
//    }

    // Reset cursor
    wxCursor cursor2(wxCURSOR_ARROW);
    this->SetCursor(cursor2);

    //
    // finally
    //

    switch ( m_pCountingMgr->GetStatus())
    {
    case NManagerStatusComplete:
        m_lblStatus->SetLabel(CSZ_STATUS[2]); // Completed
        break;

    case NManagerStatusStop:
        m_lblStatus->SetLabel(CSZ_STATUS[3]);  // Canceled
        break;

    default:
        break;
    }

    updateOptionsCtrls();
}

void SourceCounterDialog::updateOptionsCtrls()
{
    //
    NManagerStatus nStatus = m_pCountingMgr->GetStatus();

    m_lbxSrcFolder->Enable(nStatus == NManagerStatusRunning ? false : true );
    m_btnAdd->Enable(nStatus == NManagerStatusRunning ? false : true );

    if (nStatus == NManagerStatusRunning || m_lbxSrcFolder->GetSelection() == wxNOT_FOUND)
    {
        m_btnDelete->Enable(false);
    }

    m_cmbSrcTypes->Enable(nStatus == NManagerStatusRunning ? false : true );
    m_btnSelSrcType->Enable(nStatus == NManagerStatusRunning ? false : true );

    m_chbRecursiveCouting->Enable(nStatus == NManagerStatusRunning ? false : true);
    m_btnMoreSetting->Enable(nStatus == NManagerStatusRunning ? false : true);

    m_btnStart->Enable(nStatus == NManagerStatusRunning ? false : true);
    m_btnStop->Enable(nStatus == NManagerStatusRunning ? true : false);

    //
    m_lstResult->Enable(nStatus == NManagerStatusRunning? false : true);

    // Save btn
    bool bEnableBtnSave = false;
    if (m_lstResult->GetItemCount() >0 && nStatus != NManagerStatusRunning)
    {
        bEnableBtnSave = true;
    }
    m_btnSave->Enable( bEnableBtnSave );
}

void SourceCounterDialog::initCountingCtrls()
{
    // Delete all listctrl items, if exist.
    m_lstResult->DeleteAllItems();

    // Initial labels
    wxString strTemp(_T("0"));
    m_lblTotalFiles->SetLabel(strTemp);
    m_lblTotalSize->SetLabel(strTemp);
    m_lblTotalLines->SetLabel(strTemp);
    m_lblCodeLines->SetLabel(strTemp);
    m_lblCommentLines->SetLabel(strTemp);
    m_lblBlankLines->SetLabel(strTemp);
    m_lblTotalMM->SetLabel(strTemp);
    m_lblTotalCost->SetLabel(strTemp);

    m_lblStatus->SetLabel(CSZ_STATUS[0]); // Ready
}

void SourceCounterDialog::UpdateCountingInfoCtrls()
{
    // Get countingInfo
    CountingInfo* pCountingInfo = m_pCountingMgr->GetCountingInfo();
    CountingFileInfo* pCountingFileInfo = pCountingInfo->GetLastCountingFileInfo();

    //
    // Insert item to resutl listctrl
    //
    long nIndex = m_lstResult->InsertItem(m_lstResult->GetItemCount(), pCountingFileInfo->m_strFileName);
    m_lstResult->SetItem(nIndex, 1, pCountingFileInfo->m_strFileExtName);
    m_lstResult->SetItem(nIndex, 2, pCountingFileInfo->m_strFolderPath);

    wxString strTemp;

    strTemp.Printf(_T("%d"), pCountingFileInfo->m_nTotalStatement);
    m_lstResult->SetItem(nIndex, 3, strTemp);

    strTemp.Printf(_T("%d"), pCountingFileInfo->m_nCodeStatement);
    m_lstResult->SetItem(nIndex, 4, strTemp);

    strTemp.Printf(_T("%d"), pCountingFileInfo->m_nCodeCommentStatement);
    m_lstResult->SetItem(nIndex, 5, strTemp);

    strTemp.Printf(_T("%d"), pCountingFileInfo->m_nCommentStatement);
    m_lstResult->SetItem(nIndex, 6, strTemp);

    strTemp.Printf(_T("%d"), pCountingFileInfo->m_nBlankStatement);
    m_lstResult->SetItem(nIndex, 7, strTemp);

    strTemp.Printf(_T("%d"), pCountingFileInfo->m_nSize);
    m_lstResult->SetItem(nIndex, 8, strTemp);

    strTemp.Printf(_T("%2.2f"), pCountingFileInfo->m_nManDay);
    m_lstResult->SetItem(nIndex, 9, strTemp);

    strTemp.Printf(_T("%2.2f"), pCountingFileInfo->m_nCost);
    m_lstResult->SetItem(nIndex, 10, strTemp);

    // Boom: add UT and IT counting information on 2009-3-3
    strTemp.Printf(_T("%2.2f"), pCountingFileInfo->m_fUtCase);
    m_lstResult->SetItem(nIndex, 11, strTemp);
    strTemp.Printf(_T("%2.2f"), pCountingFileInfo->m_fUtDefect);
    m_lstResult->SetItem(nIndex, 12, strTemp);
    strTemp.Printf(_T("%2.2f"), pCountingFileInfo->m_fItCase);
    m_lstResult->SetItem(nIndex, 13, strTemp);
    strTemp.Printf(_T("%2.2f"), pCountingFileInfo->m_fItDefect);
    m_lstResult->SetItem(nIndex, 14, strTemp);

    // Set data to item
    m_lstResult->SetItemData(nIndex, (long)pCountingFileInfo);

    // Ensure visible
    if (nIndex % 3 == 0)
        m_lstResult->EnsureVisible(nIndex);

    ///////////////////////////////////////////////////////////////////
    // Update labels
    strTemp.Printf(_T("%d"), pCountingInfo->m_nTotalFile);
    m_lblTotalFiles->SetLabel(strTemp);

    strTemp.Printf(_T("%d"), pCountingInfo->m_nTotalSize);
    m_lblTotalSize->SetLabel(strTemp);

    strTemp.Printf(_T("%d"), pCountingInfo->m_nTotalStatement);
    m_lblTotalLines->SetLabel(strTemp);

    strTemp.Printf(_T("%d"), pCountingInfo->m_nTotalCodeStatement);
    m_lblCodeLines->SetLabel(strTemp);

    strTemp.Printf(_T("%d"), pCountingInfo->m_nTotalCommentStatement);
    m_lblCommentLines->SetLabel(strTemp);

    // Add : COde + Comment lines - 2009-3-22
    strTemp.Printf(_T("%d"), pCountingInfo->m_nTotalCodeCommentStatement);
    m_lblCodeCommentLines->SetLabel(strTemp);

    strTemp.Printf(_T("%d"), pCountingInfo->m_nTotalBlankStatement);
    m_lblBlankLines->SetLabel(strTemp);

    strTemp.Printf(_T("%2.2f"), pCountingInfo->m_fTotalManMonth);
    m_lblTotalMM->SetLabel(strTemp);

    strTemp.Printf(_T("%2.2f"), pCountingInfo->m_fTotalCost);
    m_lblTotalCost->SetLabel(strTemp);

    // Boom 2009-3-3: add UT and IT counting info
    strTemp.Printf(_T("%2.2f"), pCountingInfo->m_fTotalUtCases);
    m_lblUtCases->SetLabel(strTemp);
    strTemp.Printf(_T("%2.2f"), pCountingInfo->m_fTotalUtDefects);
    m_lblUtDefects->SetLabel(strTemp);
    strTemp.Printf(_T("%2.2f"), pCountingInfo->m_fTotalItCases);
    m_lblItCases->SetLabel(strTemp);
    strTemp.Printf(_T("%2.2f"), pCountingInfo->m_fTotalItDefects);
    m_lblItDefects->SetLabel(strTemp);

//    wxMessageBox(pCountingFileInfo->m_strFileFullPath);
//    wxMessageBox(pCountingFileInfo->m_strFileName);
//    if (nIndex % 11 == 0)
    m_lblStatus->SetLabel(pCountingFileInfo->m_strFileFullPath);

}

void SourceCounterDialog::OnInit(wxInitDialogEvent& event)
{
    if (!m_pCountingMgr)
        m_pCountingMgr = new CountingManager();

    // Load rule xml file date etc.
    m_pCountingMgr->Init();

    for (int i=0; i<N_COLUMN_NUM; i++)
    {
        m_lstResult->InsertColumn(i, CSZ_COLUMN_NAMES[i]);
    }

    //
    // Initial source folders and source file types from registry
    //

    wxConfigBase* pConf = wxConfig::Get();

// TODO: The code of below doesnt work
    // Source file types
//    wxString strSrcTypes = pConf->Read(wxT("SrcTypes"));
//    m_cmbSrcTypes->Append(strSrcTypes);
//    m_cmbSrcTypes->SetValue(strSrcTypes);

    // Source folders
    int nSrcFolderNum = pConf->Read(wxT("SrcFolderNum"), 0l); // 0L

    wxString strTemp, strPathTemp;
    pConf->SetPath(wxT("SrcFolderHistory"));
    int nIdx = 0;
    for (int i=0; i< nSrcFolderNum; i++ )
    {
        strTemp.Printf(wxT("%d"), i);
        strPathTemp = pConf->Read(strTemp);

        if (!strPathTemp.IsEmpty())
        {
            nIdx = m_lbxSrcFolder->Append(strPathTemp);
            m_lbxSrcFolder->Check(nIdx, true);
        }
    }

    // finally set path to root
    pConf->SetPath(wxT("/"));

#ifdef __WXDEBUG__
    int nIndex = m_lbxSrcFolder->Append(_T("W:\\boomworks\\SrcCounter\\testcase\\"));
    m_lbxSrcFolder->Check(nIndex, true);

    m_cmbSrcTypes->Append(_T(".php"));
    m_cmbSrcTypes->SetValue(_T(".php"));

#endif

}

void SourceCounterDialog::OnBtnStopClick(wxCommandEvent& event)
{
    m_pCountingMgr->StopCounting();
}

void SourceCounterDialog::OnBtnSaveClick(wxCommandEvent& event)
{
    if ( 0 == m_lstResult->GetItemCount())
    {
        return;
    }

    if ( wxID_CANCEL == m_dlgFile->ShowModal() )
    {
        return;
    }

    wxString strPath = m_dlgFile->GetPath();
    m_pCountingMgr->SaveCountingResultToCSV(strPath);

    wxMessageBox(CSZ_STATUS[2]); // Completed
}

void SourceCounterDialog::OnBtnUiLangClick(wxCommandEvent& event)
{
    ChangeUILanguage();
}

void SourceCounterDialog::OnBtnCheckUpdateClick(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser(_T("http://down.boomworks.org/"), wxBROWSER_NEW_WINDOW);
}

void SourceCounterDialog::OnLstResultItemRClick(wxListEvent& event)
{
    PopupMenu(&m_pMenu);
}

void SourceCounterDialog::OnMenuItemOpenSelected(wxCommandEvent& event)
{
    wxListItem listitem;
    getSelectedItem(listitem);

    CountingFileInfo* pFileInfo = (CountingFileInfo*)listitem.GetData();

    ///////////////////////////////////////////////////////////////////

    if (pFileInfo)
    {
        wxString strCmd;
        strCmd = _T("notepad \"");
        strCmd += pFileInfo->m_strFileFullPath;
        strCmd += _T("\"");

        wxExecute(strCmd, wxEXEC_ASYNC);
    }
    else
    {
        wxMessageBox(wxT("No selected item!"), CSZ_DIALOG_CAPTIOM);
    }

    ///////////////////////////////////////////////////////////////////
    /*
        wxString strCmd;
        strCmd = _T("notepad \"");
        strCmd += pFileInfo->m_strFileFullPath;
        strCmd += _T("\"");

        try
        {

            wxExecute(strCmd, wxEXEC_ASYNC);
        }
        catch (...)
        {
            wxMessageBox(_T("Unknown error occured!"));
        }
    */
    ///////////////////////////////////////////////////////////////////
    /*
            wxString strCmd;
            bool isOK = false;
            wxFileType *ft = wxTheMimeTypesManager->GetFileTypeFromExtension(pFileInfo->m_strFileExtName.AfterLast('.'));
            if (!ft)
            {
                strCmd = _T("notepad \"");
                strCmd += pFileInfo->m_strFileFullPath;
                strCmd += _T("\"");
                isOK = true;
            }
            else
            {
                isOK = ft->GetOpenCommand (&strCmd, wxFileType::MessageParameters(pFileInfo->m_strFileFullPath,  wxEmptyString));
                delete ft;
            }

            // Execute command
            if (isOK)
            {
                wxExecute(strCmd, wxEXEC_ASYNC);
                // wxExecute(strCmd, wxEXEC_SYNC);
            }
    */
    ///////////////////////////////////////////////////////////////////
}

void SourceCounterDialog::OnMenuItemOpenDirSelected(wxCommandEvent& event)
{
    wxListItem listitem;
    getSelectedItem(listitem);

    CountingFileInfo* pFileInfo = (CountingFileInfo*)listitem.GetData();

    wxString strCmd;
    strCmd = _T("explorer /select,") + pFileInfo->m_strFileFullPath;

#ifdef __WXMSW__
    wxExecute(strCmd);
#endif

}

void SourceCounterDialog::getSelectedItem(wxListItem& listitem)
{
    listitem.SetMask(wxLIST_MASK_TEXT |  wxLIST_MASK_DATA);
    int nLast = -1, nLastSelected = -1;
    while ((nLast = m_lstResult->GetNextItem(nLast, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED)) != -1)
    {
        listitem.SetId(nLast);
        m_lstResult->GetItem(listitem);
        if ((listitem.GetState() & wxLIST_STATE_FOCUSED) )
            break;
        nLastSelected = nLast;
    }

    if (nLast == -1 && nLastSelected == -1)
    {
        return;
    }

    listitem.SetId(nLastSelected == -1 ? nLast : nLastSelected);
    m_lstResult->GetItem(listitem);
}
