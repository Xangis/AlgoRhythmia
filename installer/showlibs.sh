#!/bin/bash
otool -L *.app/Contents/Frameworks/*.dylib|grep -v /System/Library/Frameworks|grep -v libSystem|grep -v libtiff|grep -v libpng|grep -v libjpeg|grep -v libz|grep -v libiconv|grep -v liblzma|grep -v executable_path|grep -v libobjc|grep -v libc++|grep -v libgcc|grep -v libbz|grep -v libexpat
DYLD_PRINT_LIBRARIES=1 ./AlgoRhythmia.app/Contents/MacOS/AlgoRhythmia
