CXX = $(shell wx-config --cxx)
PROGRAM = tetris
# wx-config --libs
WX_LIBS = $(shell wx-config --libs)
# wx-config --cxxflags
WX_CXXFLAGS = $(shell wx-config --cxxflags)

OBJECTS = $(patsubst %.cpp,%.o, $(wildcard *.cpp))

# implementation

.SUFFIXES:  .o .cpp

.cpp.o :
	$(CXX) $(WX_CXXFLAGS) -c  -o $@ $<

all:	$(PROGRAM)

$(PROGRAM):$(OBJECTS)
	$(CXX) $(WX_LIBS) -o $(PROGRAM) $(OBJECTS)


clean:
	rm *~
	rm *.o
	rm -rf bin
	rm -rf obj
