## Process this file with automake to produce Makefile.in

# ###################
# debug this makefile

# Debug building the project using GNU Make extensions
# Must me deactivated during autoreconf
# OLD_SHELL := $(SHELL)
# SHELL = $(info Building $@ $(if $<, (from $<))$(if $?, ($? newer)))$(OLD_SHELL)

#$(info OLD_SHELL: $(OLD_SHELL))
#$(info SHELL:     $(SHELL))

#$(info .CURDIR:   $(.CURDIR))
#$(info CURDIR:    $(CURDIR))


#$(info MAKEFLAGS = $(MAKEFLAGS))


# #####################
# MAKE rules start here

bin_PROGRAMS = stdtests$(EXEEXT) generator$(EXEEXT)

stdtests_SOURCES = $(top_srcdir)/src/stdtests.c $(top_builddir)/lastbuild.h \
		$(top_srcdir)/Makefile.am  $(top_srcdir)/configure.ac  configure


stdtests.$(OBJEXT): $(top_srcdir)/src/stdtests.c  $(top_builddir)/lastbuild.h  \
		 $(top_srcdir)/Makefile.am $(top_srcdir)/configure.ac


# Helper tool for MAINTAINER_MODE
generator_SOURCES = $(top_srcdir)/tools/generator.c $(top_builddir)/lastbuild.h \
		$(top_srcdir)/Makefile.am  $(top_srcdir)/configure.ac  configure

generator.$(OBJEXT): $(top_srcdir)/tools/generator.c  $(top_builddir)/lastbuild.h \
		 $(top_srcdir)/Makefile.am $(top_srcdir)/configure.ac


# timestamp for this build
$(top_builddir)/lastbuild.h: $(top_srcdir)/Makefile.am  $(top_srcdir)/configure.ac
		date  >lastbuild.h "+#define  LASTBUILD %s"
		echo >>lastbuild.h "/* automatic created from Makefile */"


#config.h: configure $(top_srcdir)/Makefile.in $(top_srcdir)/Makefile.am
#		$(top_srcdir)/configure  



MOSTLYCLEANFILES = *.o  *.obj

CLEANFILES = *.o  *.obj $(bin_PROGRAMS) lastbuild.h

DISTCLEANFILES = $(top_srcdir)/Makefile.in \
		 $(top_srcdir)/configure $(top_srcdir)/config.in config.h


update: $(top_srcdir)/configure.ac $(top_srcdir)/Makefile.in
		cd '$(top_srcdir)' && autogen.sh -v


init: $(top_srcdir)/configure.ac $(top_srcdir)/Makefile.in
		cd '$(top_srcdir)' && autogen.sh -v



.PHONY: init, update

### the end

