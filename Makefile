.PHONY: all clean info install
CXXFLAGS = -Wall -o2
CXXFLAGS+= $(shell root-config --cflags)

LIBS = $(shell root-config --libs)
SRC = $(wildcard *.cc)
EXE = $(SRC:.cc=.exe)
all: $(EXE)

%.exe: %.cc
	$(CXX) $(CXXFLAGS) $(LIBS) $< -o $@

info: 
	@echo $(SRC)
	@echo $(EXE)
	@echo $(CXXFLAGS)
	@echo $(LIBS)
clean: 
	$(RM) *.exe
