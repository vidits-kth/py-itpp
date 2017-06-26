# --------------------------------------------------------------------------
# Makefile for the src directory
# --------------------------------------------------------------------------

LOCAL_HOME        := $(shell pwd)/..

# All-----------------
all:  opt debug framepointer asan

include $(LOCAL_HOME)/makerules

# Get list of files in current directory
CSOURCES := $(shell find . \( -type d -a -name .svn -a -prune \) -o \( -type f -a -regex '.*\.c$$' -print \) | sed 's%^\./%%')
CPPSOURCES := $(shell find . \( -type d -a -name .svn -a -prune \) -o \( -type f -a -regex '.*\.cpp$$' -print \) | sed 's%^\./%%')
PYSOURCES := $(shell find . \( -type d -a -name .svn -a -prune \) -o \( -type f -a -regex '.*\.py$$' -print \) | sed 's%^\./%%')

# Include prerequisites
CDEPS := $(patsubst %.c,$(LOCAL_TARGET_DIR)/%.d,$(CSOURCES))
CPPDEPS := $(patsubst %.cpp,$(LOCAL_TARGET_DIR)/%.d,$(CPPSOURCES))

sinclude $(CDEPS) $(CPPDEPS)

#TARGET_LIB_OPT_S := $(subst /,\/,$(TARGET_LIB_OPT))
#TARGET_LIB_DEBUG_S := $(subst /,\/,$(TARGET_LIB_DEBUG))
#TARGET_LIB_PROF_S := $(subst /,\/,$(TARGET_LIB_PROF))

opt:  depend $(TARGET_LIB_OPT)

debug:  depend $(TARGET_LIB_DEBUG)

framepointer:  depend $(TARGET_LIB_FRAMEPOINTER)

asan:  depend $(TARGET_LIB_ASAN)

shared:  depend $(TARGET_LIB_SHARED)

pylib:  depend $(TARGET_LIB_PYTHON)

depend:  $(CDEPS) $(CPPDEPS)

# Suffix rules for archive files

#
# OPT
#

$(TARGET_LIB_OPT): $(patsubst %.cpp,$(LOCAL_TARGET_DIR)/%.o,$(CPPSOURCES)) $(patsubst %.c,$(LOCAL_TARGET_DIR)/%.o,$(CSOURCES))
	@echo "========================================================================="
	@echo Building archives for opt mode
	@echo "========================================================================="
	@$(AR) rc $@ $?

$(LOCAL_TARGET_DIR)/%.o: %.cpp
	@echo Compiling $< for opt mode
	@${CXX} $(FLAGS_OPT) $(INCLUDE_PATH) -c $< -o $@

$(LOCAL_TARGET_DIR)/%.o: %.c
	@echo Compiling $< for opt mode
	@$(CC) $(FLAGS_OPT) $(INCLUDE_PATH) -c $< -o $@

#
# Debug
#

$(TARGET_LIB_DEBUG): $(patsubst %.cpp,$(LOCAL_TARGET_DIR)/%_debug.o,$(CPPSOURCES)) $(patsubst %.c,$(LOCAL_TARGET_DIR)/%_debug.o,$(CSOURCES))
	@echo "========================================================================="
	@echo Building archives for debug mode
	@echo "========================================================================="
	@$(AR) rc $@ $?

$(LOCAL_TARGET_DIR)/%_debug.o: %.cpp
	@echo Compiling $< for debug mode
	@${CXX} $(FLAGS_DEBUG) $(INCLUDE_PATH) -c $< -o $@

$(LOCAL_TARGET_DIR)/%_debug.o: %.c
	@echo Compiling $< for debug mode
	@$(CC) $(FLAGS_DEBUG) $(INCLUDE_PATH) -c $< -o $@

#
# Framepointer
#

$(TARGET_LIB_FRAMEPOINTER): $(patsubst %.cpp,$(LOCAL_TARGET_DIR)/%_fp.o,$(CPPSOURCES)) $(patsubst %.c,$(LOCAL_TARGET_DIR)/%_fp.o,$(CSOURCES))
	@echo "========================================================================="
	@echo Building archives for framepointer mode
	@echo "========================================================================="
	@$(AR) rc $@ $?

$(LOCAL_TARGET_DIR)/%_fp.o: %.cpp
	@echo Compiling $< for framepointer mode
	@${CXX} $(FLAGS_FRAMEPOINTER) $(INCLUDE_PATH) -c $< -o $@

$(LOCAL_TARGET_DIR)/%_fp.o: %.c
	@echo Compiling $< for framepointer mode
	@$(CC) $(FLAGS_FRAMEPOINTER) $(INCLUDE_PATH) -c $< -o $@

#
# Asan (adress sanitizer)
#

$(TARGET_LIB_ASAN): $(patsubst %.cpp,$(LOCAL_TARGET_DIR)/%_asan.o,$(CPPSOURCES)) $(patsubst %.c,$(LOCAL_TARGET_DIR)/%_asan.o,$(CSOURCES))
	@echo "========================================================================="
	@echo Building archives for asan mode
	@echo "========================================================================="
	@$(AR) rc $@ $?

$(LOCAL_TARGET_DIR)/%_asan.o: %.cpp
	@echo Compiling $< for asan mode
	@${CXX} $(FLAGS_ASAN) $(INCLUDE_PATH) -c $< -o $@

$(LOCAL_TARGET_DIR)/%_asan.o: %.c
	@echo Compiling $< for asan mode
	@$(CC) $(FLAGS_ASAN) $(INCLUDE_PATH) -c $< -o $@

#
# Shared
#

$(TARGET_LIB_SHARED): $(patsubst %.cpp,$(LOCAL_TARGET_DIR)/%_pic.so,$(CPPSOURCES)) $(patsubst %.c,$(LOCAL_TARGET_DIR)/%_pic.so,$(CSOURCES)) 
	@echo "========================================================================="
	@echo Linking for shared mode
	@echo "========================================================================="
	#@$(CC) -shared $? -o $(TARGET_LIB_SHARED)
	#@echo $(CXX) -shared $(LIB_PATH) -o $@ $< $(LIBS)
	#@$(CXX) -shared $< -o $@

$(LOCAL_TARGET_DIR)/%_pic.so: %.cpp
	@echo Compiling $< for shared mode
	@echo ${CXX} $(FLAGS_SHARED) $(INCLUDE_PATH) -c $< -o $@
	@${CXX} $(FLAGS_SHARED) $(INCLUDE_PATH) -c $< -o $@
	@echo Linking $< for shared mode \(move to a separate rule\)
	@$(CXX) -shared $(LIB_PATH) -o $(patsubst %_pic.o,%.so,$@) $@ $(LIBS)

$(LOCAL_TARGET_DIR)/%_pic.so: %.c
	@echo Compiling $< for shared mode
	@$(CC) $(FLAGS_SHARED) $(INCLUDE_PATH) -c $< -o $@
	
#
# Python Module
#

$(TARGET_LIB_PYTHON): $(patsubst %.cpp,$(LOCAL_TARGET_DIR)/%.so,$(CPPSOURCES)) $(patsubst %.c,$(LOCAL_TARGET_DIR)/%.so,$(CSOURCES)) $(patsubst %.py,$(LOCAL_TARGET_DIR)/%.py,$(PYSOURCES)) 

$(LOCAL_TARGET_DIR)/%.so: %.cpp
	@echo Compiling $< to Python module
#	@echo LIBS_SHARED $(LIBS_SHARED)
	@${CXX} $(FLAGS_PYTHON) $(INCLUDE_PATH) $(LIB_PATH) $< -o $@ $(LIBS_SHARED)

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
	@set -e; $(CC) $(ARCH_FLAGS) -MM -MT '$*.o' $(INCLUDE_PATH_system) $(INCLUDE_PATH) $< \
		| sed 's|$*.o:|$(LOCAL_TARGET_DIR)/$*.o  $(LOCAL_TARGET_DIR)/$*_debug.o  $(LOCAL_TARGET_DIR)/$*_fp.o  $(LOCAL_TARGET_DIR)/$*_asan.o  $(LOCAL_TARGET_DIR)/$*_pic.o $@:|g' > $@

$(LOCAL_TARGET_DIR)/%.d: %.cpp
	@echo Create prerequisites for $<
	@echo $@ | sed 's|/[^/]*$$||' | while read path; do \
		( mkdir -p "$$path" )\
		done
	@set -e; ${CXX} ${FLAGS_COMMON} $(ARCH_FLAGS) -MM -MT '$*.o' $(INCLUDE_PATH_system) $(INCLUDE_PATH) $< \
		| sed 's|$*.o:|$(LOCAL_TARGET_DIR)/$*.o  $(LOCAL_TARGET_DIR)/$*_debug.o  $(LOCAL_TARGET_DIR)/$*_fp.o $(LOCAL_TARGET_DIR)/$*_asan.o  $(LOCAL_TARGET_DIR)/$*_pic.o $@:|g' > $@
