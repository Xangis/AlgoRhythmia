echo This program runs the desktop app packager command to create a Windows 10 store package from an existing installer.
pause
DesktopAppConverter.exe -Installer "C:\Users\Xangis\code\AlgoRhythmia\installer\AlgoRhythmia4.1Setup.exe" -PackageName "AlgoRhythmia" -Version 4.1.0.0 -Makeappx -Destination "C:\Users\Xangis\code\AlgoRhythmia\installer" -InstallerArguments "/VERYSILENT" -Publisher "CN=Jason Champion" -Sign
Certutil -addStore TrustedPeople AlgoRhythmia\auto-generated.cer



