# Startup Manager

A small Windows MFC utility to view, add, delete and enable/disable the programs Windows starts at logon.

Split out of DiskForge, where it used to be one of the built-in tools.

## Features

- Reads all four startup locations: `HKCU\...\Run`, `HKLM\...\Run`, `HKCU\...\RunOnce` and `HKLM\...\RunOnce`
- Shows each entry's name, command, enabled/disabled status, registry hive (HKCU/HKLM) and key type
  (Run/RunOnce) in a sortable list
- **Enable/Disable** toggles the entry's `Explorer\StartupApproved\Run` binary flag (byte `0x02` = enabled,
  `0x03` = disabled) - the same mechanism Task Manager uses - so the entry stays in the registry and can be
  re-enabled
- **Add Entry...** opens a sub-dialog to create a new startup entry: name, command (with a file browser),
  Current User (HKCU) or All Users (HKLM), and an optional Run Once flag
- **Delete** removes the value from the Run/RunOnce key and clears any leftover `StartupApproved` entry,
  after confirmation
- RunOnce entries cannot be enabled/disabled (they delete themselves on first run, so there is nothing to
  toggle) and the button is greyed accordingly
- Runs as Administrator (the manifest requests elevation) so HKLM entries can be changed

## Requirements

- **OS:** Windows 10 / Windows 11 x64
- **Runtime:** Microsoft Visual C++ Redistributable 2022 (x64) - https://aka.ms/vs/17/release/vc_redist.x64.exe
- **Build:** Visual Studio 2022 with the "Desktop development with C++" workload and MFC

## How to Build

Open `StartupManager.sln` in Visual Studio 2022, select **Release | x64** and build, or:

```powershell
msbuild StartupManager.sln /p:Configuration=Release /p:Platform=x64
```

The exe is written to `x64\Release\StartupManager.exe`.

## Continuous Integration

`.github/workflows/build.yml` builds Debug and Release x64 on every push and pull request and uploads
`StartupManager.exe` as an artifact. Every successful push to the default branch is released automatically as
`v1.0.<run number>` (pushing a `v*.*.*` tag releases exactly that tag) with `StartupManager-<tag>-x64.zip`
attached, after checking the exe only depends on Windows and VC++ 2015-2022 runtime DLLs.

## Project Structure

| File | Description |
|------|-------------|
| `StartupManager.sln` | Visual Studio 2022 solution |
| `StartupManager/StartupManager.vcxproj` | MSBuild project (x64, v143, MFC as shared DLL, `requireAdministrator`) |
| `StartupManager/StartupManager.cpp/h` | Application entry point; the Startup Manager dialog is the main window |
| `StartupManager/StartupManagerDialog.cpp/h` | Main `CStartupManagerDialog` and the `CAddStartupEntryDialog` sub-dialog |
| `StartupManager/StartupManager.rc`, `resource.h` | Dialogs, icon, strings, version info |
| `StartupManager/StartupManager.manifest` | DPI awareness, Windows 10/11 compatibility, Common Controls 6 |
| `StartupManager/StartupManager.ico` | Application icon |
