# --------------------------------------------------------------------------
# Makefile for SimCLibs projects
# --------------------------------------------------------------------------

#Define the home direcory of the local version of this library

LOCAL_HOME        := $(shell pwd)

# Don't use clearmake configuration record lookup for
# readme files, it breaks compatibility
# with GNU make
ifeq ($(MAKE),clearmake)
.NO_CONFIG_REC: readme.txt
endif

# Run the make command serially within this makefile
.NOTPARALLEL:

all: lib_dir version_control_report create_opt create_debug create_framepointer create_asan check_version_control_report

opt: lib_dir version_control_report create_opt check_version_control_report
debug: lib_dir version_control_report create_debug check_version_control_report
framepointer: lib_dir version_control_report create_framepointer check_version_control_report
asan: lib_dir version_control_report create_asan check_version_control_report
cpuprof: lib_dir version_control_report create_cpuprof check_version_control_report
heapprof: lib_dir version_control_report create_heapprof check_version_control_report
shared: lib_dir version_control_report create_shared check_version_control_report
pylib: lib_dir version_control_report create_pylib check_version_control_report

include $(LOCAL_HOME)/makerules

PLAIN_LIB_PATHS := $(subst -L,,$(LIB_PATH))
LIB_FILES := $(foreach dir,$(PLAIN_LIB_PATHS),$(wildcard $(dir)/*))

VERSION_CONTROL_REPORT_OK := $(shell $(SIMCLIBS_HOME)/bin/check_version_control_report.sh $(LOCAL_TARGET_DIR)/version_control_report.txt | grep -c 'WARNING')
version_control_report:
	@echo "========================================================================="
	@echo "Building version control report"
	@echo $(LIB_BASE_NAME): `echo "$(WC_AND_LIB_VERSION_INFO)" | sed -e 's%$(SIMLIBS_REPO)%SIMLIBS_REPO%' -e 's/SIMLIBS_REPO/$$SIMLIBS_REPO/'` > $(LOCAL_TARGET_DIR)/version_control_report.txt
	@for path in $(PLAIN_LIB_PATHS); do $(SIMCLIBS_HOME)/bin/print_version_control_report.sh $$path/version_control_report.txt >> $(LOCAL_TARGET_DIR)/version_control_report.txt; done;
	@cat $(LOCAL_TARGET_DIR)/version_control_report.txt | sed -e 's/\(cat: cannot open\)\(.*\)/(\1\2)/' > $(LOCAL_TARGET_DIR)/version_control_report.tmp
	@mv $(LOCAL_TARGET_DIR)/version_control_report.tmp $(LOCAL_TARGET_DIR)/version_control_report.txt
	@echo '#ifndef __version_control_report_h' > src/version_control_report.tmp
	@echo '#define __version_control_report_h' >> src/version_control_report.tmp
	@echo >> src/version_control_report.tmp
	@echo 'namespace lstools {' >> src/version_control_report.tmp
	@echo >> src/version_control_report.tmp
	@echo '  inline const char *' >> src/version_control_report.tmp
	@echo '  get_version_control_report()' >> src/version_control_report.tmp
	@echo '  {' >> src/version_control_report.tmp
	@echo '    static const char version_control_report[] =' >> src/version_control_report.tmp
	@cat $(LOCAL_TARGET_DIR)/version_control_report.txt | sed 's/\(^.*$$\)/      \"\1\\n\"/' >> src/version_control_report.tmp
	@echo '      "";' >> src/version_control_report.tmp
	@echo '    return version_control_report;' >> src/version_control_report.tmp
	@echo '  }' >> src/version_control_report.tmp
	@echo >> src/version_control_report.tmp
	@echo '  inline bool' >> src/version_control_report.tmp
	@echo '  get_version_control_report_status()' >> src/version_control_report.tmp
	@echo '  {' >> src/version_control_report.tmp
	@echo '    const int nrof_warning_texts_in_report =' `$(SIMCLIBS_HOME)/bin/check_version_control_report.sh $(LOCAL_TARGET_DIR)/version_control_report.txt | grep -c 'WARNING'`';' >> src/version_control_report.tmp
	@echo "    return nrof_warning_texts_in_report == 0;" >> src/version_control_report.tmp
	@echo '  }' >> src/version_control_report.tmp
	@echo >> src/version_control_report.tmp
	@echo '}' >> src/version_control_report.tmp
	@echo '#endif' >> src/version_control_report.tmp
	@if [ ! -r "src/version_control_report.h" ]; then cp src/version_control_report.tmp src/version_control_report.h; fi
	@diff src/version_control_report.tmp src/version_control_report.h > /dev/null; if [ "$$?" -eq 1 ]; then cp src/version_control_report.tmp src/version_control_report.h; fi
	@rm src/version_control_report.tmp


check_version_control_report:
	@$(SIMCLIBS_HOME)/bin/check_version_control_report.sh $(LOCAL_TARGET_DIR)/version_control_report.txt

create_opt: readme.txt lib_dir
	@echo "========================================================================="
	@echo Compiling for opt mode
	@echo "-------------------------------------------------------------------------"
	@echo "FLAGS = $(FLAGS_OPT)"
	@echo "INCLUDE_PATH =  $(INCLUDE_PATH)"
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB = $(MATLAB)"; fi
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB_ARCH = $(MATLAB_ARCH)"; fi
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB_FNAME_EXTENSION = $(MATLAB_MEX_FNAME_EXTENSION)"; fi
	@if test -n "$(LOCAL_SOURCE_SUBDIRS)" ; then echo "LOCAL_SOURCE_SUBDIRS = $(LOCAL_SOURCE_SUBDIRS)"; fi
	@echo "========================================================================="
	@cd src && $(MAKE) -i opt MAKE=$(MAKE) CXX="${CXX}" LOCAL_HOME="$(LOCAL_HOME)"

create_debug: readme.txt lib_dir
	@echo "========================================================================="
	@echo Compiling for debug mode
	@echo "-------------------------------------------------------------------------"
	@echo "FLAGS = $(FLAGS_DEBUG)"
	@echo "INCLUDE_PATH =  $(INCLUDE_PATH)"
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB = $(MATLAB)"; fi
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB_ARCH = $(MATLAB_ARCH)"; fi
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB_FNAME_EXTENSION = $(MATLAB_MEX_FNAME_EXTENSION)"; fi
	@if test -n "$(LOCAL_SOURCE_SUBDIRS)" ; then echo "LOCAL_SOURCE_SUBDIRS = $(LOCAL_SOURCE_SUBDIRS)"; fi
	@echo "========================================================================="
	@cd src && $(MAKE) -i debug MAKE=$(MAKE) CXX="${CXX}" LOCAL_HOME="$(LOCAL_HOME)"

create_framepointer: readme.txt lib_dir
	@echo "========================================================================="
	@echo Compiling for framepointer mode
	@echo "-------------------------------------------------------------------------"
	@echo "FLAGS = $(FLAGS_FRAMEPOINTER)"
	@echo "INCLUDE_PATH =  $(INCLUDE_PATH)"
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB = $(MATLAB)"; fi
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB_ARCH = $(MATLAB_ARCH)"; fi
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB_FNAME_EXTENSION = $(MATLAB_MEX_FNAME_EXTENSION)"; fi
	@if test -n "$(LOCAL_SOURCE_SUBDIRS)" ; then echo "LOCAL_SOURCE_SUBDIRS = $(LOCAL_SOURCE_SUBDIRS)"; fi
	@echo "========================================================================="
	@cd src && $(MAKE) -i framepointer MAKE=$(MAKE) CXX="${CXX}" LOCAL_HOME="$(LOCAL_HOME)"

create_asan: readme.txt lib_dir
	@echo "========================================================================="
	@echo Compiling for asan mode
	@echo "-------------------------------------------------------------------------"
	@echo "FLAGS = $(FLAGS_ASAN)"
	@echo "INCLUDE_PATH =  $(INCLUDE_PATH)"
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB = $(MATLAB)"; fi
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB_ARCH = $(MATLAB_ARCH)"; fi
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB_FNAME_EXTENSION = $(MATLAB_MEX_FNAME_EXTENSION)"; fi
	@if test -n "$(LOCAL_SOURCE_SUBDIRS)" ; then echo "LOCAL_SOURCE_SUBDIRS = $(LOCAL_SOURCE_SUBDIRS)"; fi
	@echo "========================================================================="
	@cd src && $(MAKE) -i asan MAKE=$(MAKE) CXX="${CXX}" LOCAL_HOME="$(LOCAL_HOME)"

create_cpuprof: readme.txt lib_dir
	@echo "========================================================================="
	@echo Compiling for cpuprof mode
	@echo "-------------------------------------------------------------------------"
	@echo "FLAGS = $(FLAGS_CPUPROF)"
	@echo "INCLUDE_PATH =  $(INCLUDE_PATH)"
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB = $(MATLAB)"; fi
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB_ARCH = $(MATLAB_ARCH)"; fi
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB_FNAME_EXTENSION = $(MATLAB_MEX_FNAME_EXTENSION)"; fi
	@if test -n "$(LOCAL_SOURCE_SUBDIRS)" ; then echo "LOCAL_SOURCE_SUBDIRS = $(LOCAL_SOURCE_SUBDIRS)"; fi
	@echo "========================================================================="
	@cd src && $(MAKE) -i framepointer MAKE=$(MAKE) CXX="${CXX}" LOCAL_HOME="$(LOCAL_HOME)"

create_heapprof: readme.txt lib_dir
	@echo "========================================================================="
	@echo Compiling for heapprof mode
	@echo "-------------------------------------------------------------------------"
	@echo "FLAGS = $(FLAGS_HEAPPROF)"
	@echo "INCLUDE_PATH =  $(INCLUDE_PATH)"
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB = $(MATLAB)"; fi
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB_ARCH = $(MATLAB_ARCH)"; fi
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB_FNAME_EXTENSION = $(MATLAB_MEX_FNAME_EXTENSION)"; fi
	@if test -n "$(LOCAL_SOURCE_SUBDIRS)" ; then echo "LOCAL_SOURCE_SUBDIRS = $(LOCAL_SOURCE_SUBDIRS)"; fi
	@echo "========================================================================="
	@cd src && $(MAKE) -i framepointer MAKE=$(MAKE) CXX="${CXX}" LOCAL_HOME="$(LOCAL_HOME)"

create_shared: readme.txt lib_dir
	@echo "========================================================================="
	@echo Compiling for shared mode
	@echo "-------------------------------------------------------------------------"
	@echo "FLAGS = $(FLAGS_SHARED)"
	@echo "INCLUDE_PATH =  $(INCLUDE_PATH)"
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB = $(MATLAB)"; fi
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB_ARCH = $(MATLAB_ARCH)"; fi
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB_FNAME_EXTENSION = $(MATLAB_MEX_FNAME_EXTENSION)"; fi
	@if test -n "$(LOCAL_SOURCE_SUBDIRS)" ; then echo "LOCAL_SOURCE_SUBDIRS = $(LOCAL_SOURCE_SUBDIRS)"; fi
	@echo "========================================================================="
	@cd src && $(MAKE) -i shared MAKE=$(MAKE) CXX="${CXX}" LOCAL_HOME="$(LOCAL_HOME)"

create_pylib: readme.txt lib_dir
	@echo "========================================================================="
	@echo Compiling to Python module
	@echo "-------------------------------------------------------------------------"
	@echo "FLAGS = $(FLAGS_PYTHON)"
	@echo "INCLUDE_PATH =  $(INCLUDE_PATH)"
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB = $(MATLAB)"; fi
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB_ARCH = $(MATLAB_ARCH)"; fi
	@if test -n "$(MATLAB_MEX)"; then echo "MATLAB_FNAME_EXTENSION = $(MATLAB_MEX_FNAME_EXTENSION)"; fi
	@if test -n "$(LOCAL_SOURCE_SUBDIRS)" ; then echo "LOCAL_SOURCE_SUBDIRS = $(LOCAL_SOURCE_SUBDIRS)"; fi
	@echo "========================================================================="
	@cd src && $(MAKE) -i pylib MAKE=$(MAKE) CXX="${CXX}" LOCAL_HOME="$(LOCAL_HOME)"


check: readme.txt
	@cd test && $(MAKE) -i check MAKE=$(MAKE) CXX="${CXX}"

cleancheck: readme.txt
	@cd test && $(MAKE) -i cleancheck MAKE=$(MAKE) CXX="${CXX}"


examples: readme.txt
	@cd examples && $(MAKE) -i  all MAKE=$(MAKE) CXX="${CXX}"

apps: readme.txt
	@cd apps && $(MAKE) -i  all MAKE=$(MAKE) CXX="${CXX}"

doc:  doxy svnlog

doxy:  doxy_html doxy_latex

doxy_multilib_html: readme.txt
	cat doc/doxygen_multilib_html_config | sed 's/PROJECT_NAME_TAG/$(LIB_BASE_NAME)/' > doc/doxygen_multilib_html_config.tmp
	doxygen doc/doxygen_multilib_html_config.tmp > doc/doxygen_multilib_html_config.log

doxy_html: readme.txt
	cat doc/doxygen_html_config | sed 's/PROJECT_NAME_TAG/$(LIB_BASE_NAME)/' > doc/doxygen_html_config.tmp
	doxygen doc/doxygen_html_config.tmp > doc/doxygen_html_config.log

doxy_latex: readme.txt
	@cat doc/doxygen_latex_config | sed 's/PROJECT_NAME_TAG/$(LIB_BASE_NAME)/' > doc/doxygen_latex_config.tmp
	doxygen doc/doxygen_latex_config.tmp > doc/doxygen_latex_config.log

	@sed -n -e '/\\documentclass/,/\\pagenumbering{arabic}/p' doc/latex/refman.tex > .base
	@sed -n -e '/\\pagenumbering{arabic}/,/\\input{index}/p' doc/latex/refman.tex |  sed 's/\\pagenumbering{arabic}//' > .index
	@sed -n -e '/\\chapter{.* Page Documentation}/,//p' doc/latex/refman.tex | sed 's/\\end{document}//' |  sed 's/\\printindex//' > .page
	@sed -n -e '/\\chapter{.* Module Index}/,/\\input{modules}/p' doc/latex/refman.tex  > .mindex
	@sed -n -e '/\\chapter{.* Compound Index}/,/\\input{annotated}/p' doc/latex/refman.tex > .cindex
	@sed -n -e '/\\chapter{.* Hierarchical Index}/,/\\input{hierarchy}/p' doc/latex/refman.tex > .hindex
	@sed -n -e '/\\chapter{.* Class Documentation}/,/\\chapter{.* File Documentation}/p' doc/latex/refman.tex | sed 's/\\chapter{.* File Documentation}//' > .class
	@sed -n -e '/\\chapter{.* Module Documentation}/,/\\chapter{.* Class Documentation}/p' doc/latex/refman.tex | sed 's/\\chapter{.* Class Documentation}//' > .module


	@cat .base .index .page .class .module .cindex .mindex .hindex > doc/latex/refman.tex
	@echo '\printindex' >> doc/latex/refman.tex
	@echo '\end{document}' >> doc/latex/refman.tex
	-rm .base .class .page .index .cindex .hindex .mindex .module

	@cd doc/latex && $(MAKE) -i ps MAKE=$(MAKE) CXX="${CXX}"

.PHONY: svnlog
svnlog:
	cd doc; svn --verbose --xml log `svn info | grep 'URL: ' | sed 's/URL: //g' | sed 's/\/doc//g'` | xsltproc --stringparam strip-prefix `basename $(pwd)` --stringparam groupbyday yes svn2html.xsl - > changelog.html; \
	rm -rf svnlog; \
	mkdir svnlog; \
	mv changelog.html svnlog/changelog.html; \
	cp svn2html.css svnlog

veryclean:  clean_local
	-rm -fR `ls  -d lib/*`
	-rm -f `ls  -d doc/html/*`
	-rm -f `ls  -d doc/man/man3/*`
	-rm -f `ls  -d doc/latex/*`
	-rm -fR doc/svnlog
	@cd examples && $(MAKE) -i veryclean MAKE=$(MAKE) CXX="${CXX}"
	@cd test && $(MAKE) -i veryclean MAKE=$(MAKE) CXX="${CXX}"
	@cd apps && $(MAKE) -i veryclean MAKE=$(MAKE) CXX="${CXX}"
	@cd mex && $(MAKE) -i veryclean MAKE=$(MAKE) CXX="${CXX}" MATLAB_MEX=
	-rm -f /tmp/matlab_out.txt
	-rm -f /tmp/matlab_info.txt
	-rm -f /tmp/matlab_out_$(LOGNAME).txt
	-rm -f /tmp/matlab_info*_$(LOGNAME).txt

clean:  clean_local
	@cd examples && $(MAKE) -i clean MAKE=$(MAKE) CXX="${CXX}"
	@cd test && $(MAKE) -i clean MAKE=$(MAKE) CXX="${CXX}"
	@cd apps && $(MAKE) -i clean MAKE=$(MAKE) CXX="${CXX}"
	@cd mex && $(MAKE) -i clean MAKE=$(MAKE) CXX="${CXX}" MATLAB_MEX=

clean_local:
	-rm -f *% *~ *~~ *.orig *$$ core #*
	-rm -f *.log
	-rm -f */*% */*~ */*~~ */*.orig */*$$ */core */#*
	-rm -f */*/*% */*/*~ */*/*~~ */*/*.orig */*/*$$ */*/core */*/#*
	-rm -f lib/*/*/*.o lib/*/*/*.d
	-find lib -mindepth 3 -type d -print0 | xargs -i -0 rm -rf {}
	-rm -f doc/*.log doc/*.tmp
	-rm -f src/version_control_report.h
	-rm -f `ls  -d doc/latex/* | grep -v refman.ps`

lib_dir: $(LOCAL_HOME)/lib/$(TARGET_MACHINE)/gcc$(COMPILER_VERSION)

$(LOCAL_HOME)/lib/$(TARGET_MACHINE)/gcc$(COMPILER_VERSION):
	@mkdir -p $(LOCAL_HOME)/lib/$(TARGET_MACHINE)/gcc$(COMPILER_VERSION)


readme.txt:
	@echo "Warning: No readme.txt file, readme.txt file added, please enter readme information in readme.txt file"
	@echo "Welcome to the $(LIB_BASE_NAME) library." > readme.txt
	@echo " " >> readme.txt
	@echo "More information in this library is found by running: " >> readme.txt
	@echo "> make doc " >> readme.txt
	@echo "and then " >> readme.txt
	@echo "open the file doc/html/index.html in a web browser" >> readme.txt
	@echo "or " >> readme.txt
	@echo "open the postscript file doc/latex/refman.ps " >> readme.txt
	@echo " " >> readme.txt
	@echo "If this does not work try open the files " >> readme.txt
	@echo "   doc/local/installation.doc" >> readme.txt
	@echo "in your favourite editor to find what may be the problem." >> readme.txt
	@echo " " >> readme.txt
	@echo "You may also be able to find more information in files named" >> readme.txt
	@echo "   doc/local/*.doc" >> readme.txt
	@echo "" >> readme.txt
	@echo "Enjoy //" >> readme.txt

# MAKEFILES_VERSION: $HeadURL: https://openalm.lmera.ericsson.se/svnplugin/simlibs/simlibs/projects/proj2017/evidsax_py_itpp/trunk/makefile $
version_makefiles:
	@echo "========================================================================="
	@echo Using makefiles version stemming from:
	@cat makefile | grep '^# MAKEFILES_VERSION:' | sed -e 's/^# MAKEFILES_VERSION:[ ]*//' -e 's/^\$$HeadURL:[ ]*//' -e 's%/makerules.base%%' -e 's/[ ]*\$$//'
	@echo "========================================================================="
