
# $(call mksoname, soname, version)
mksoname    = $(if $(2),lib$(1).so.$(2),lib$(1).so)
# $(call mkshlib, $@, $(SONMAE), $(OBJS), $(LINKWITH))
mkshlib      = $(CXX) -shared $(LDFLAGS) -o $(1) -Wl,-h,$(2) $(3) $(4) -lpthread -lrt

# $(call mklibname, name)
mklibname = lib$(1).a
# $(call mklib, $@, $(OBJS))
mklib        = ar cr $(1) $(2)
