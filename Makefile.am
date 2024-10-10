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

stdtests_SOURCES = $(top_srcdir)/src/stdtests.c $(top_srcdir)/include/settings.h \
		$(top_srcdir)/include/compiler.h  $(top_builddir)/lastbuild.h \
		$(top_srcdir)/Makefile.am  $(top_srcdir)/Makefile.in $(top_builddir)/Makefile \
		$(top_srcdir)/configure.ac  $(top_srcdir)/configure


# Helper tool for MAINTAINER_MODE
generator_SOURCES = $(top_srcdir)/template/generator.c $(top_srcdir)/include/settings.h \
		$(top_srcdir)/include/fix_non_posix_systems.h $(top_builddir)/lastbuild.h \
		$(top_srcdir)/Makefile.am  $(top_srcdir)/Makefile.in $(top_builddir)/Makefile \
		$(top_srcdir)/configure.ac  $(top_srcdir)/configure


# timestamp for this build
$(top_builddir)/lastbuild.h: $(top_srcdir)/Makefile.am  $(top_srcdir)/Makefile.in $(top_builddir)/Makefile \
        $(top_srcdir)/configure.ac $(top_srcdir)/configure
		date  >lastbuild.h "+#define  LASTBUILD %s"
		echo >>lastbuild.h "/* automatic created from Makefile */"


#config.h: configure $(top_srcdir)/Makefile.in $(top_srcdir)/Makefile.am
#		$(top_srcdir)/configure


EXTRA_DIST = $(top_srcdir)/bootstrap $(top_srcdir)/tools/header2line.sh \
		$(top_srcdir)/template/c_header.txt $(top_srcdir)/template/cxx_header.txt \
		$(top_srcdir)/template/posix_header.txt

dist-hook:
		rm -f $(distdir)/configure $(distdir)/config.h.in
		rm -f $(distdir)/Makefile  $(distdir)/Makefile.in
		rm -f $(distdir)/aclocal.m4 $(distdir)/lastbuild.h
		rm -f $(distdir)/tools/install-sh $(distdir)/tools/depcomp
		touch $(distdir)/tools/install-sh $(distdir)/tools/depcomp


CLEANFILES = *.o  *.obj \
		$(top_builddir)/lastbuild.h $(top_builddir)/stamp-h1 \
		$(top_builddir)/c_header_names_ac.txt $(top_builddir)/cxx_header_names_ac.txt \
		$(top_builddir)/posix_header_names_ac.txt \
		$(top_builddir)/config.h $(top_builddir)/config.log


MOSTLYCLEANFILES = *.d *.Po $(top_builddir)/src/.deps/* $(top_builddir)/template/.deps/*


DISTCLEANFILES = $(top_srcdir)/Makefile.in $(top_builddir)/Makefile \
		$(top_srcdir)/configure $(top_srcdir)/config.h.in \
		$(top_srcdir)/aclocal.m4 $(top_srcdir)/autom4te.cache/* \
		$(top_builddir)/config.status


update: $(top_srcdir)/configure.ac $(top_srcdir)/Makefile.in $(top_srcdir)/bootstrap
		cd '$(top_srcdir)' && ./bootstrap -v


init: $(top_srcdir)/configure.ac $(top_srcdir)/Makefile.in
		cd '$(top_srcdir)' && ./bootstrap -v


.PHONY: all clean distclean init update

### the end
