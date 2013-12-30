
include $(TOP_DIR)/build/define.mk

CXX = g++
LDFLAGS = -lpthread
MAKE = make

CPPFLAGS =  -Wall
CXXFLAGS = 

EVERYTHING = all

.SUFFIXES:
.SUFFIXES:      .cpp .c .o
.cpp.o:
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< 

.c.o:
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $<


all:: $(SRCS) $(TARGETS)
