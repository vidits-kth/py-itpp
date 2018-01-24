# --------------------------------------------------------------------------
# Makefile for py-itpp
# --------------------------------------------------------------------------

#Define the home direcory of the local version of this library

LOCAL_HOME        := $(shell pwd)

# Run the make command serially within this makefile
.NOTPARALLEL:

install: lib_dir create_pylib

PLAIN_LIB_PATHS := $(subst -L,,$(LIB_PATH))
LIB_FILES := $(foreach dir,$(PLAIN_LIB_PATHS),$(wildcard $(dir)/*))

create_pylib: lib_dir
	@echo "------------------------------------"
	@echo Compiling py-itpp
	@echo "------------------------------------"
	@cd src && $(MAKE) -i install MAKE=$(MAKE) CXX="${CXX}" LOCAL_HOME="$(LOCAL_HOME)"

clean: clean_local 

clean_local:
	-rm -rf lib/
#	-rm -f *% *~ *~~ *.orig *$$ core #*
#	-rm -f *.log
#	-rm -f */*% */*~ */*~~ */*.orig */*$$ */core */#*
#	-rm -f */*/*% */*/*~ */*/*~~ */*/*.orig */*/*$$ */*/core */*/#*
#	-rm -f lib/*/*/*.o lib/*/*/*.d
#	-find lib -mindepth 3 -type d -print0 | xargs -i -0 rm -rf {}

lib_dir: $(LOCAL_HOME)/lib/$(TARGET_MACHINE)/gcc$(COMPILER_VERSION)

$(LOCAL_HOME)/lib/$(TARGET_MACHINE)/gcc$(COMPILER_VERSION):
	@mkdir -p $(LOCAL_HOME)/lib/$(TARGET_MACHINE)/gcc$(COMPILER_VERSION)

