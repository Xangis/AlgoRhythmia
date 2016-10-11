# Sigmatizm makefile.  Requires wxWidgets.
# Uses wxWidgets 3.0
# wx-config must be on the path. If it's not, change wx-config to wherever it is,
# such as /usr/local/wx/wx-config
WX_CONFIG := wx-config

# Main executable file
PROGRAM = AlgoRhythmia

# Directory containing library portions of code.
INCLUDEDIR = ../../lib/libsndfile-1.0.27/include/
INCLUDEDIR2 = ../AudioFile
INCLUDEDIR3 = rtmidi-2.1.0

# Object files
OBJECTS = AboutDlg.o DrumControl.o EffectsDlg.o PresetDrumPattern.o SoundFxManager.o ../AudioFile/wavefile.o ../wxAudioControls/wxSettingsFile.o AlgoRhythmiaApp.o drumgrid.o AlgoRhythmia.o

CXX = $(shell $(WX_CONFIG) --cxx) -g -ggdb
#CXX = $(shell $(WX_CONFIG) --cxx) -O3

.SUFFIXES:	.o .cpp

.cpp.o :
#	$(CXX) -c -D__MACOSX_CORE__ -I$(INCLUDEDIR) -I$(INCLUDEDIR2) -I$(INCLUDEDIR3) `$(WX_CONFIG) --cxxflags` -o $@ $<
	$(CXX) -c -D__MACOSX_CORE__ -I$(INCLUDEDIR) -I$(INCLUDEDIR2) -I$(INCLUDEDIR3) `$(WX_CONFIG) --cxxflags` -o $@ $<

all:    $(PROGRAM)

$(PROGRAM):	$(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) `$(WX_CONFIG) --libs` -lportaudio -lasound -lpthread -lsndfile

clean: 
	rm -f *.o $(PROGRAM)
