# submodule posix

TOP_DIR = ../

include $(TOP_DIR)/build/define.mk

POSIX_SONAME = $(call mksoname, posix)

TEST = test_thread

OBJS = \
	   thread.o \
	   condition.o \
	   mutex.o \
	   main.o

SRCS = $(OBJS:.o=.cpp)

TARGETS = $(TEST)
#$(POSIX_SONMAE)

include $(TOP_DIR)/build/rules.mk

CPPFLAGS := -I. $(CPPFLAGS)

$(POSIX_SONMAE): $(OBJS)
	rm -rf $@
	$(call mkshlib, $@, $(POSIX_SONMAE), $(OBJS))

$(TEST): $(OBJS)
	rm -rf $@
	$(CXX) $(LDFLAGS) $(OBJS) -o $@ $(CXXFLAGS) $(CPPFLAGS)
