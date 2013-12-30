# submodule posix

TOP_DIR = ../

POSIX_SONAME = $(call mksoname, posix)

OBJS = \
	   thread.o \
	   condition.o \
	   mutex.o 

SRCS = $(OBJS:.o=.cpp)

TARGETS = $(POSIX_SONMAE)

include $(TOP_DIR)/build/rules.mk

CPPFLAGS := -I. $(CPPFLAGS)

$(POSIX_SONMAE): $(OBJS)
	rm -rf $@
	$(call mkshlib, $@, $(POSIX_SONMAE), $(OBJS))
