# Sigmatizm makefile.  Requires wxWidgets.
# Uses wxWidgets 3.0
# wx-config must be on the path. If it's not, change wx-config to wherever it is,
# such as /usr/local/wx/wx-config
WX_CONFIG := wx-config

# Main executable file
PROGRAM = installer/AlgoRhythmia.app/Contents/MacOS/AlgoRhythmia

# Directory containing library portions of code.
INCLUDEDIR = ../../lib/libsndfile-1.0.28/src/
INCLUDEDIR2 = ../AudioFile
INCLUDEDIR3 = ../../lib/rtmidi-4.0.0
INCLUDEDIR4 = ../../lib/SDL2-2.0.9/include
INCLUDEDIR5 = ../../lib/SDL2_mixer-2.0.4
LIBDIR = ../../lib/libsndfile-1.0.28/lib/

# Object files
OBJECTS = AboutDlg.o DrumControl.o EffectsDlg.o PresetDrumPattern.o SoundFxManager.o ../AudioFile/wavefile.o ../wxAudioControls/wxSettingsFile.o AlgoRhythmiaApp.o drumgrid.o AlgoRhythmia.o $(INCLUDEDIR3)/RtMidi.o

#CXX = $(shell $(WX_CONFIG) --cxx) -g -ggdb
CXX = $(shell $(WX_CONFIG) --cxx) -O3

.SUFFIXES:	.o .cpp

.cpp.o :
#	$(CXX) -c -g -ggdb -D__MACOSX_CORE__ -I$(INCLUDEDIR) -I$(INCLUDEDIR2) -I$(INCLUDEDIR3) -I$(INCLUDEDIR4) -I$(INCLUDEDIR5) `$(WX_CONFIG) --cxxflags` -o $@ $<
	$(CXX) -c -D__MACOSX_CORE__ -I$(INCLUDEDIR) -I$(INCLUDEDIR2) -I$(INCLUDEDIR3) -I$(INCLUDEDIR4) -I$(INCLUDEDIR5) `$(WX_CONFIG) --cxxflags` -o $@ $<

all:    $(PROGRAM)

$(PROGRAM):	$(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) -L$(LIBDIR) `$(WX_CONFIG) --libs` -lportaudio -lpthread -lsndfile -lSDL2 -lSDL2_mixer -framework CoreMidi -framework CoreAudio -framework CoreFoundation

clean: 
	rm -f *.o ../wxAudioControls/*.o $(PROGRAM)
