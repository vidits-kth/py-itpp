# --------------------------------------------------------------------------
# Makefile for py-itpp
# --------------------------------------------------------------------------

#Define the home direcory of the local version of this library

LOCAL_HOME        := $(shell pwd)
LIB_NAME          := itpp

# Run the make command serially within this makefile
.NOTPARALLEL:

install: create_pylib

PLAIN_LIB_PATHS := $(subst -L,,$(LIB_PATH))
LIB_FILES := $(foreach dir,$(PLAIN_LIB_PATHS),$(wildcard $(dir)/*))

create_pylib: lib_dir
	@echo "------------------------------------"
	@echo Compiling py-itpp
	@echo "------------------------------------"
	@cd src && $(MAKE) -i install MAKE=$(MAKE) CXX="${CXX}" LOCAL_HOME="$(LOCAL_HOME)"

clean: clean_local 

clean_local:
	-rm -rf $(LOCAL_HOME)/lib/

lib_dir:
	@mkdir -p $(LOCAL_HOME)/lib/$(LIB_NAME)/

