; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{10BE0872-DCBB-4680-AD19-F270B41D33B7}
AppName=AlgoRhythmia
AppVerName=AlgoRhythmia 4.21
AppPublisher=Jason Champion
AppPublisherURL=http://zetacentauri.com
AppSupportURL=http://zetacentauri.com
AppUpdatesURL=http://zetacentauri.com
DefaultDirName={pf}\AlgoRhythmia
DefaultGroupName=AlgoRhythmia
LicenseFile=C:\Users\Xangis\code\AlgoRhythmia\LICENSE
OutputDir=C:\Users\Xangis\code\AlgoRhythmia\installer
OutputBaseFilename=AlgoRhythmia4.21Setup
Compression=lzma
SolidCompression=yes
SetupIconFile=C:\Users\Xangis\code\AlgoRhythmia\Release\algo.ico
UninstallDisplayIcon={app}\algo.ico

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Files]
Source: "C:\Users\Xangis\code\AlgoRhythmia\Release\AlgoRhythmia.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\AlgoRhythmia\Release\AlgoRhythmia Manual.pdf"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\AlgoRhythmia\Release\algo.ico"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\AlgoRhythmia\LICENSE"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\AlgoRhythmia\Release\libsndfile-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\AlgoRhythmia\Release\SDL2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\AlgoRhythmia\Release\SDL2_mixer.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\AlgoRhythmia\samples\*"; DestDir: "{app}\Samples"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Users\Xangis\code\AlgoRhythmia\installer\vcredist2010_x86.exe"; DestDir: "{app}"; Flags: ignoreversion deleteafterinstall

[Icons]
Name: "{group}\AlgoRhythmia"; Filename: "{app}\AlgoRhythmia.exe"; WorkingDir: "{app}"
Name: "{group}\AlgoRhythmia Manual"; Filename: "{app}\AlgoRhythmia Manual.pdf"; WorkingDir: "{app}"
Name: "{group}\Free Wave Samples Website"; Filename: "http://freewavesamples.com"
Name: "{group}\{cm:ProgramOnTheWeb,AlgoRhythmia}"; Filename: "http://zetacentauri.com/software_algorhythmia.htm"
Name: "{commondesktop}\AlgoRhythmia"; Filename: "{app}\AlgoRhythmia.exe"; Tasks: desktopicon; WorkingDir: "{app}"
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\AlgoRhythmia"; Filename: "{app}\AlgoRhythmia.exe"; Tasks: quicklaunchicon; WorkingDir: "{app}"

[Run]
Filename: "{app}\vcredist2010_x86.exe"; Parameters: "/q"; WorkingDir: "{app}";  StatusMsg: "Installing Visual C++ 2010 Redistributable..."; Flags: waituntilterminated
Filename: "{app}\AlgoRhythmia.exe"; Description: "{cm:LaunchProgram,AlgoRhythmia}"; Flags: nowait postinstall skipifsilent
