#!/bin/bash
install_name_tool -change /usr/local/lib/libportaudio.2.dylib @executable_path/../Frameworks/libportaudio.2.dylib AlgoRhythmia.app/Contents/MacOS/AlgoRhythmia
install_name_tool -change /usr/local/lib/libsndfile.1.dylib @executable_path/../Frameworks/libsndfile.1.dylib AlgoRhythmia.app/Contents/MacOS/AlgoRhythmia
otool -L AlgoRhythmia.app/Contents/MacOS/AlgoRhythmia
