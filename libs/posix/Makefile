# submodule posix

TOP_DIR = ../

include $(TOP_DIR)/build/define.mk

VERSION = 0.1

POSIX_SONAME = $(call mksoname,posix,$(VERSION))

TEST = test_thread

OBJS = \
	   thread.o \
	   condition.o \
	   mutex.o \

SRCS = $(OBJS:.o=.cpp)

TARGETS = $(POSIX_SONAME)

include $(TOP_DIR)/build/rules.mk

CPPFLAGS := -I. -fPIC $(CPPFLAGS)

$(POSIX_SONAME): $(OBJS)
	rm -rf $@
	$(call mkshlib,$@,$(POSIX_SONAME),$(OBJS))

#mkshlib      = $(CXX) -shared $(LDFLAGS) -o $(1) -Wl,-h,$(2) $(3) $(4) -lpthread -lrt

#$(TEST): $(TEST_OBJS)
#	rm -rf $@
#	$(CXX) $(LDFLAGS) $(TEST_OBJS) -o $@ $(CXXFLAGS) $(CPPFLAGS)
