
include $(TOP_DIR)/build/define.mk

CXX = g++
CC = g++
LDFLAGS = -lpthread
MAKE = make

CPPFLAGS =  -Wall
CXXFLAGS = 
CFLAGS = 

EVERYTHING = all clean

.SUFFIXES:
.SUFFIXES:      .cpp .c .o

.cpp.o:
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< 

.c.o:
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $<


all:: $(SRCS) $(TARGETS)

clean::
	-rm -f $(TARGETS)
	-rm -f *.o
