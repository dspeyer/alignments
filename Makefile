CC=g++
CFLAGS=-c --std=c++11
SOURCES=compare.cc main.cc plain.cc RCA.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=alignment

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

$(OBJECTS): common.h

.cc.o:
	$(CC) $(CFLAGS) $< -o $@