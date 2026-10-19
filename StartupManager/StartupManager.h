// StartupManager.h - Stand-alone Startup Manager utility: view, add, delete
// and enable/disable the programs Windows starts at logon (HKCU/HKLM Run and
// RunOnce). Split out of DiskForge, and kept separate from Registry Cleaner.
#pragma once

class CStartupManagerApp : public CWinApp
{
public:
    virtual BOOL InitInstance();
};

extern CStartupManagerApp theApp;
