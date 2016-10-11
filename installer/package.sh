#!/bin/bash
#cp -R ../Release/Patches Sigmatizm.app/Contents/Resources/
codesign -f -s "3rd Party Mac Developer Application: Jason Champion (G6PFF85X2R)" AlgoRhythmia.app/Contents/Frameworks/libportaudio.2.dylib --entitlements AlgoRhythmia.app/Contents/Resources/Entitlements.plist
codesign -f -s "3rd Party Mac Developer Application: Jason Champion (G6PFF85X2R)" AlgoRhythmia.app/Contents/Frameworks/libsndfile.1.dylib --entitlements AlgoRhythmia.app/Contents/Resources/Entitlements.plist
codesign -f -s "3rd Party Mac Developer Application: Jason Champion (G6PFF85X2R)" AlgoRhythmia.app --entitlements AlgoRhythmia.app/Contents/Resources/Entitlements.plist
productbuild --sign "3rd Party Mac Developer Installer: Jason Champion (G6PFF85X2R)" --component AlgoRhythmia.app /Applications AlgoRhythmia.pkg
