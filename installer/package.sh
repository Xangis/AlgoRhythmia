#!/bin/bash
cp "../Release/AlgoRhythmia Manual.pdf" AlgoRhythmia.app/Contents/Resources/AlgoRhythmia_Manual.pdf
codesign -f --deep -s "3rd Party Mac Developer Application: Jason Champion (G6PFF85X2R)" AlgoRhythmia.app --entitlements AlgoRhythmia.app/Contents/Resources/Entitlements.plist
productbuild --sign "3rd Party Mac Developer Installer: Jason Champion (G6PFF85X2R)" --component AlgoRhythmia.app /Applications AlgoRhythmia.pkg
