#
#
TOP_DIR = .

SUBDIRS = posix

include $(TOP_DIR)/build/rules.mk

# make all
$(EVERYTHING)::
	@for subdir in $(SUBDIRS); \
		do \
		echo "making $@ in $$subdir"; \
		( cd $$subdir && $(MAKE) $@ ) || exit 1; \
	done

