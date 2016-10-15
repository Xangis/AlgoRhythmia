#!/bin/bash
#cp -R ../Release/Patches Sigmatizm.app/Contents/Resources/
codesign -f --deep -s "3rd Party Mac Developer Application: Jason Champion (G6PFF85X2R)" AlgoRhythmia.app --entitlements AlgoRhythmia.app/Contents/Resources/Entitlements.plist
productbuild --sign "3rd Party Mac Developer Installer: Jason Champion (G6PFF85X2R)" --component AlgoRhythmia.app /Applications AlgoRhythmia.pkg
