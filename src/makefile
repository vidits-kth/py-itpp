# --------------------------------------------------------------------------
# Makefile for the src directory
# --------------------------------------------------------------------------

LOCAL_HOME        := $(shell pwd)/..

include $(LOCAL_HOME)/makerules

# Get list of files in current directory
CSOURCES := $(shell find . \( -type d -a -name .svn -a -prune \) -o \( -type f -a -regex '.*\.c$$' -print \) | sed 's%^\./%%')
CPPSOURCES := $(shell find . \( -type d -a -name .svn -a -prune \) -o \( -type f -a -regex '.*\.cpp$$' -print \) | sed 's%^\./%%')
PYSOURCES := $(shell find . \( -type d -a -name .svn -a -prune \) -o \( -type f -a -regex '.*\.py$$' -print \) | sed 's%^\./%%')

# Include prerequisites
CDEPS := $(patsubst %.c,$(LOCAL_TARGET_DIR)/%.d,$(CSOURCES))
CPPDEPS := $(patsubst %.cpp,$(LOCAL_TARGET_DIR)/%.d,$(CPPSOURCES))

sinclude $(CDEPS) $(CPPDEPS)

#pylib:  depend $(TARGET_LIB_PYTHON)
pylib:  $(TARGET_LIB_PYTHON)

depend:  $(CDEPS) $(CPPDEPS)

# Suffix rules for archive files

#
# Python Module
#

$(TARGET_LIB_PYTHON): $(patsubst %.cpp,$(LOCAL_TARGET_DIR)/%.so,$(CPPSOURCES)) $(patsubst %.c,$(LOCAL_TARGET_DIR)/%.so,$(CSOURCES)) $(patsubst %.py,$(LOCAL_TARGET_DIR)/%.py,$(PYSOURCES)) 

$(LOCAL_TARGET_DIR)/%.so: %.cpp
	@echo Compiling $< to Python module
#	@echo LIBS_SHARED $(LIBS_SHARED)
	@echo g++ ${CXX} $(FLAGS_PYTHON) $(INCLUDE_PATH) $(LIB_PATH) $< -o $@ $(LIBS_SHARED)
	@g++ ${CXX} $(FLAGS_PYTHON) $(INCLUDE_PATH) $(LIB_PATH) $< -o $@ $(LIBS_SHARED)

$(LOCAL_TARGET_DIR)/%.so: %.c
	@echo Compiling $< to Python module
	@$(CC) $(FLAGS_PYTHON) $(INCLUDE_PATH) $< -o $@

$(LOCAL_TARGET_DIR)/%.py: %.py
	@echo Copying $< to Python module
	@if [ -d $(LOCAL_TARGET_DIR)/py_itpp/utils ]; then continue; else mkdir -p $(LOCAL_TARGET_DIR)/py_itpp/utils; fi
	@cp -p $< $@
	
#
# Automatically generate prerequisites
#

$(LOCAL_TARGET_DIR)/%.d: %.c
	@echo Create prerequisites for $<
	@echo $@ | sed 's|/[^/]*$$||' | while read path; do \
		( mkdir -p "$$path" )\
		done
	@set -e; cc $(CC) $(ARCH_FLAGS) -MM -MT '$*.o' $(INCLUDE_PATH_system) $(INCLUDE_PATH) $< \
		| sed 's|$*.o:|$(LOCAL_TARGET_DIR)/$*.o  $(LOCAL_TARGET_DIR)/$*_debug.o  $(LOCAL_TARGET_DIR)/$*_fp.o  $(LOCAL_TARGET_DIR)/$*_asan.o  $(LOCAL_TARGET_DIR)/$*_pic.o $@:|g' > $@

$(LOCAL_TARGET_DIR)/%.d: %.cpp
	@echo Create prerequisites for $<
	@echo $@ | sed 's|/[^/]*$$||' | while read path; do \
		( mkdir -p "$$path" )\
		done
	@set -e; ${CXX} ${FLAGS_COMMON} $(ARCH_FLAGS) -MM -MT '$*.o' $(INCLUDE_PATH_system) $(INCLUDE_PATH) $< \
		| sed 's|$*.o:|$(LOCAL_TARGET_DIR)/$*.o  $(LOCAL_TARGET_DIR)/$*_debug.o  $(LOCAL_TARGET_DIR)/$*_fp.o $(LOCAL_TARGET_DIR)/$*_asan.o  $(LOCAL_TARGET_DIR)/$*_pic.o $@:|g' > $@
