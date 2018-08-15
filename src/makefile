# --------------------------------------------------------------------------
# Makefile for the src directory
# --------------------------------------------------------------------------

LOCAL_HOME        := $(shell pwd)/..
LIB_NAME          := itpp

include $(LOCAL_HOME)/makerules

LIBS_SHARED := $(LIBS_SHARED) -litpp -lboost_python3 -lboost_numpy3
INCLUDE_PATH := $(INCLUDE_PATH) -I/usr/include/python3.5 -I/usr/include/python3.6

# Get list of files in current directory
CPPSOURCES := $(shell find . \( -type d -a -name .svn -a -prune \) -o \( -type f -a -regex '.*\.cpp$$' -print \) | sed 's%^\./%%')
PYSOURCES := $(shell find . \( -type d -a -name .svn -a -prune \) -o \( -type f -a -regex '.*\.py$$' -print \) | sed 's%^\./%%')

include $(CPPDEPS)

# Include prerequisites
CPPDEPS := $(patsubst %.cpp,$(LOCAL_TARGET_DIR)/%.d,$(CPPSOURCES))

install: depend $(TARGET_LIB_PYTHON)

depend: $(CPPDEPS)

# Python Module
$(TARGET_LIB_PYTHON): $(patsubst %.cpp,$(LOCAL_TARGET_DIR)/%.so,$(CPPSOURCES))  $(patsubst %.py,$(LOCAL_TARGET_DIR)/%.py,$(PYSOURCES)) 

$(LOCAL_TARGET_DIR)/%.so: %.cpp
	@echo Compiling $< to Python module
	@${CXX} $(FLAGS_PYTHON) $(INCLUDE_PATH) $(LIB_PATH) $< -o $@ $(LIBS_SHARED)

$(LOCAL_TARGET_DIR)/%.py: %.py
	@echo Copying $< to Python package
	@cp -p $< $@
	
# Automatically generate prerequisites
$(LOCAL_TARGET_DIR)/%.d: %.cpp
	@echo Create prerequisites for $<
	@echo $@ | sed 's|/[^/]*$$||' | while read path; do \
		( mkdir -p "$$path" )\
		done
	@set -e; ${CXX} ${FLAGS_COMMON} $(ARCH_FLAGS) -MM -MT '$*.o' $(INCLUDE_PATH_system) $(INCLUDE_PATH) $< \
		| sed 's|$*.o:|$(LOCAL_TARGET_DIR)/$*.o  $(LOCAL_TARGET_DIR)/$*_debug.o  $(LOCAL_TARGET_DIR)/$*_fp.o $(LOCAL_TARGET_DIR)/$*_asan.o  $(LOCAL_TARGET_DIR)/$*_pic.o $@:|g' > $@
