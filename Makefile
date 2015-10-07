# Sigmatizm makefile.  Requires wxWidgets.
# Uses wxWidgets 2.8, non-unicode build. (--disable-unicode)
WX_CONFIG := /usr/bin/wx-config

# Main executable file
PROGRAM = AlgoRhythmia

# Directory containing library portions of code.
INCLUDEDIR3 = rtmidi-2.1.0

# Object files
OBJECTS = AboutDlg.o DrumControl.o EffectsDlg.o PresetDrumPattern.o SoundFxManager.o wavefile.o wxSettingsFile.o AlgoRhythmiaApp.o AlgoRhythmia.o drumgrid.o

CXX = $(shell $(WX_CONFIG) --cxx -ggdb)

.SUFFIXES:	.o .cpp

.cpp.o :
	$(CXX) -c -D__LINUX_ALSASEQ__ -I$(INCLUDEDIR3) `$(WX_CONFIG) --cxxflags` -o $@ $<

all:    $(PROGRAM)

$(PROGRAM):	$(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) `$(WX_CONFIG) --libs` -lportaudio -lasound -lpthread -lsndfile

clean: 
	rm -f *.o $(PROGRAM)
