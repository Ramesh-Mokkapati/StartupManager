// StartupManager.cpp - Application entry point. The Startup Manager dialog
// is the main window.
#include "pch.h"
#include "StartupManager.h"
#include "StartupManagerDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CStartupManagerApp theApp;

BOOL CStartupManagerApp::InitInstance()
{
    INITCOMMONCONTROLSEX InitCtrls;
    InitCtrls.dwSize = sizeof(InitCtrls);
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&InitCtrls);

    CWinApp::InitInstance();
    SetRegistryKey(_T("DiskForge"));

    CStartupManagerDialog dlg;
    m_pMainWnd = &dlg;
    dlg.DoModal();
    return FALSE; // dialog closed - exit instead of starting the message pump
}
