# Makefile.in generated by automake 1.13.1 from Makefile.am.
# lib/tgdb/annotate-two/Makefile.  Generated from Makefile.in by configure.

# Copyright (C) 1994-2012 Free Software Foundation, Inc.

# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.




am__make_dryrun = \
  { \
    am__dry=no; \
    case $$MAKEFLAGS in \
      *\\[\ \	]*) \
        echo 'am--echo: ; @echo "AM"  OK' | $(MAKE) -f - 2>/dev/null \
          | grep '^AM OK$$' >/dev/null || am__dry=yes;; \
      *) \
        for am__flg in $$MAKEFLAGS; do \
          case $$am__flg in \
            *=*|--*) ;; \
            *n*) am__dry=yes; break;; \
          esac; \
        done;; \
    esac; \
    test $$am__dry = yes; \
  }
pkgdatadir = $(datadir)/cgdb
pkgincludedir = $(includedir)/cgdb
pkglibdir = $(libdir)/cgdb
pkglibexecdir = $(libexecdir)/cgdb
am__cd = CDPATH="$${ZSH_VERSION+.}$(PATH_SEPARATOR)" && cd
install_sh_DATA = $(install_sh) -c -m 644
install_sh_PROGRAM = $(install_sh) -c
install_sh_SCRIPT = $(install_sh) -c
INSTALL_HEADER = $(INSTALL_DATA)
transform = $(program_transform_name)
NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
build_triplet = i686-pc-linux-gnu
host_triplet = i686-pc-linux-gnu
subdir = lib/tgdb/annotate-two
DIST_COMMON = $(srcdir)/Makefile.in $(srcdir)/Makefile.am \
	$(top_srcdir)/config/depcomp
ACLOCAL_M4 = $(top_srcdir)/aclocal.m4
am__aclocal_m4_deps = $(top_srcdir)/config/readline_check_version.m4 \
	$(top_srcdir)/configure.in
am__configure_deps = $(am__aclocal_m4_deps) $(CONFIGURE_DEPENDENCIES) \
	$(ACLOCAL_M4)
mkinstalldirs = $(install_sh) -d
CONFIG_HEADER = $(top_builddir)/config.h
CONFIG_CLEAN_FILES =
CONFIG_CLEAN_VPATH_FILES =
LIBRARIES = $(noinst_LIBRARIES)
AR = ar
ARFLAGS = cru
AM_V_AR = $(am__v_AR_$(V))
am__v_AR_ = $(am__v_AR_$(AM_DEFAULT_VERBOSITY))
am__v_AR_0 = @echo "  AR      " $@;
am__v_AR_1 = 
libtgdb_a2_a_AR = $(AR) $(ARFLAGS)
libtgdb_a2_a_LIBADD =
am_libtgdb_a2_a_OBJECTS = libtgdb_a2_a-a2-tgdb.$(OBJEXT) \
	libtgdb_a2_a-annotate.$(OBJEXT) \
	libtgdb_a2_a-commands.$(OBJEXT) libtgdb_a2_a-data.$(OBJEXT) \
	libtgdb_a2_a-globals.$(OBJEXT) \
	libtgdb_a2_a-state_machine.$(OBJEXT)
libtgdb_a2_a_OBJECTS = $(am_libtgdb_a2_a_OBJECTS)
AM_V_P = $(am__v_P_$(V))
am__v_P_ = $(am__v_P_$(AM_DEFAULT_VERBOSITY))
am__v_P_0 = false
am__v_P_1 = :
AM_V_GEN = $(am__v_GEN_$(V))
am__v_GEN_ = $(am__v_GEN_$(AM_DEFAULT_VERBOSITY))
am__v_GEN_0 = @echo "  GEN     " $@;
am__v_GEN_1 = 
AM_V_at = $(am__v_at_$(V))
am__v_at_ = $(am__v_at_$(AM_DEFAULT_VERBOSITY))
am__v_at_0 = @
am__v_at_1 = 
DEFAULT_INCLUDES = -I. -I$(top_builddir)
depcomp = $(SHELL) $(top_srcdir)/config/depcomp
am__depfiles_maybe = depfiles
am__mv = mv -f
AM_V_lt = $(am__v_lt_$(V))
am__v_lt_ = $(am__v_lt_$(AM_DEFAULT_VERBOSITY))
am__v_lt_0 = --silent
am__v_lt_1 = 
COMPILE = $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	$(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
AM_V_CC = $(am__v_CC_$(V))
am__v_CC_ = $(am__v_CC_$(AM_DEFAULT_VERBOSITY))
am__v_CC_0 = @echo "  CC      " $@;
am__v_CC_1 = 
CCLD = $(CC)
LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(AM_LDFLAGS) $(LDFLAGS) -o $@
AM_V_CCLD = $(am__v_CCLD_$(V))
am__v_CCLD_ = $(am__v_CCLD_$(AM_DEFAULT_VERBOSITY))
am__v_CCLD_0 = @echo "  CCLD    " $@;
am__v_CCLD_1 = 
SOURCES = $(libtgdb_a2_a_SOURCES)
DIST_SOURCES = $(libtgdb_a2_a_SOURCES)
am__can_run_installinfo = \
  case $$AM_UPDATE_INFO_DIR in \
    n|no|NO) false;; \
    *) (install-info --version) >/dev/null 2>&1;; \
  esac
am__tagged_files = $(HEADERS) $(SOURCES) $(TAGS_FILES) $(LISP)
# Read a list of newline-separated strings from the standard input,
# and print each of them once, without duplicates.  Input order is
# *not* preserved.
am__uniquify_input = $(AWK) '\
  BEGIN { nonempty = 0; } \
  { items[$$0] = 1; nonempty = 1; } \
  END { if (nonempty) { for (i in items) print i; }; } \
'
# Make sure the list of sources is unique.  This is necessary because,
# e.g., the same source file might be shared among _SOURCES variables
# for different programs/libraries.
am__define_uniq_tagged_files = \
  list='$(am__tagged_files)'; \
  unique=`for i in $$list; do \
    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
  done | $(am__uniquify_input)`
ETAGS = etags
CTAGS = ctags
DISTFILES = $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST)
ACLOCAL = ${SHELL} /home/l/cgdb-0.6.7/config/missing aclocal-1.13
AMTAR = $${TAR-tar}
AM_DEFAULT_VERBOSITY = 1
AUTOCONF = ${SHELL} /home/l/cgdb-0.6.7/config/missing autoconf
AUTOHEADER = ${SHELL} /home/l/cgdb-0.6.7/config/missing autoheader
AUTOMAKE = ${SHELL} /home/l/cgdb-0.6.7/config/missing automake-1.13
AWK = gawk
CC = gcc
CCDEPMODE = depmode=gcc3
CFLAGS = -g -O2
CPP = gcc -E
CPPFLAGS = 
CYGPATH_W = echo
DEFS = -DHAVE_CONFIG_H
DEPDIR = .deps
ECHO_C = 
ECHO_N = -n
ECHO_T = 
EGREP = /usr/bin/grep -E
EXEEXT = 
GREP = /usr/bin/grep
INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_STRIP_PROGRAM = $(install_sh) -c -s
LDFLAGS = 
LEX = flex
LEXLIB = 
LEX_OUTPUT_ROOT = lex.yy
LIBOBJS = 
LIBS = -lreadline -lncurses -lm 
LTLIBOBJS = 
MAKEINFO = ${SHELL} /home/l/cgdb-0.6.7/config/missing makeinfo
MKDIR_P = /usr/bin/mkdir -p
OBJEXT = o
PACKAGE = cgdb
PACKAGE_BUGREPORT = 
PACKAGE_NAME = cgdb
PACKAGE_STRING = cgdb 0.6.7
PACKAGE_TARNAME = cgdb
PACKAGE_URL = 
PACKAGE_VERSION = 0.6.7
PATH_SEPARATOR = :
RANLIB = ranlib
RL_MAJOR = 6
RL_MINOR = 2
RL_VERSION = 0x0602
SET_MAKE = 
SHELL = /bin/sh
STRIP = 
VERSION = 0.6.7
YACC = yacc
YFLAGS = 
abs_builddir = /home/l/cgdb-0.6.7/lib/tgdb/annotate-two
abs_srcdir = /home/l/cgdb-0.6.7/lib/tgdb/annotate-two
abs_top_builddir = /home/l/cgdb-0.6.7
abs_top_srcdir = /home/l/cgdb-0.6.7
ac_ct_CC = gcc
am__include = include
am__leading_dot = .
am__quote = 
am__tar = $${TAR-tar} chof - "$$tardir"
am__untar = $${TAR-tar} xf -
bindir = ${exec_prefix}/bin
build = i686-pc-linux-gnu
build_alias = 
build_cpu = i686
build_os = linux-gnu
build_vendor = pc
builddir = .
datadir = ${datarootdir}
datarootdir = ${prefix}/share
docdir = ${datarootdir}/doc/${PACKAGE_TARNAME}
dvidir = ${docdir}
exec_prefix = ${prefix}
host = i686-pc-linux-gnu
host_alias = 
host_cpu = i686
host_os = linux-gnu
host_vendor = pc
htmldir = ${docdir}
includedir = ${prefix}/include
infodir = ${datarootdir}/info
install_sh = ${SHELL} /home/l/cgdb-0.6.7/config/install-sh
libdir = ${exec_prefix}/lib
libexecdir = ${exec_prefix}/libexec
localedir = ${datarootdir}/locale
localstatedir = ${prefix}/var
mandir = ${datarootdir}/man
mkdir_p = $(MKDIR_P)
oldincludedir = /usr/include
pdfdir = ${docdir}
prefix = /usr/local
program_transform_name = s,x,x,
psdir = ${docdir}
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
srcdir = .
sysconfdir = ${prefix}/etc
target_alias = 
top_build_prefix = ../../../
top_builddir = ../../..
top_srcdir = ../../..
libtgdb_a2_a_CFLAGS = \
    -I$(top_srcdir)/lib/adt \
    -I$(top_srcdir)/lib/util \
    -I$(top_srcdir)/lib/tgdb/tgdb-base


# create the input library
# This depends on input
noinst_LIBRARIES = libtgdb_a2.a
libtgdb_a2_a_SOURCES = \
    a2-tgdb.c \
    a2-tgdb.h \
    annotate.c \
    annotate.h \
    annotate_two.h \
    commands.c \
    commands.h \
    data.c \
    data.h \
    globals.c \
    globals.h \
    state_machine.c \
    state_machine.h

all: all-am

.SUFFIXES:
.SUFFIXES: .c .o .obj
$(srcdir)/Makefile.in:  $(srcdir)/Makefile.am  $(am__configure_deps)
	@for dep in $?; do \
	  case '$(am__configure_deps)' in \
	    *$$dep*) \
	      ( cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh ) \
	        && { if test -f $@; then exit 0; else break; fi; }; \
	      exit 1;; \
	  esac; \
	done; \
	echo ' cd $(top_srcdir) && $(AUTOMAKE) --gnu lib/tgdb/annotate-two/Makefile'; \
	$(am__cd) $(top_srcdir) && \
	  $(AUTOMAKE) --gnu lib/tgdb/annotate-two/Makefile
.PRECIOUS: Makefile
Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@case '$?' in \
	  *config.status*) \
	    cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh;; \
	  *) \
	    echo ' cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__depfiles_maybe)'; \
	    cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__depfiles_maybe);; \
	esac;

$(top_builddir)/config.status: $(top_srcdir)/configure $(CONFIG_STATUS_DEPENDENCIES)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh

$(top_srcdir)/configure:  $(am__configure_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(ACLOCAL_M4):  $(am__aclocal_m4_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(am__aclocal_m4_deps):

clean-noinstLIBRARIES:
	-test -z "$(noinst_LIBRARIES)" || rm -f $(noinst_LIBRARIES)
libtgdb_a2.a: $(libtgdb_a2_a_OBJECTS) $(libtgdb_a2_a_DEPENDENCIES) $(EXTRA_libtgdb_a2_a_DEPENDENCIES) 
	$(AM_V_at)-rm -f libtgdb_a2.a
	$(AM_V_AR)$(libtgdb_a2_a_AR) libtgdb_a2.a $(libtgdb_a2_a_OBJECTS) $(libtgdb_a2_a_LIBADD)
	$(AM_V_at)$(RANLIB) libtgdb_a2.a

mostlyclean-compile:
	-rm -f *.$(OBJEXT)

distclean-compile:
	-rm -f *.tab.c

include ./$(DEPDIR)/libtgdb_a2_a-a2-tgdb.Po
include ./$(DEPDIR)/libtgdb_a2_a-annotate.Po
include ./$(DEPDIR)/libtgdb_a2_a-commands.Po
include ./$(DEPDIR)/libtgdb_a2_a-data.Po
include ./$(DEPDIR)/libtgdb_a2_a-globals.Po
include ./$(DEPDIR)/libtgdb_a2_a-state_machine.Po

.c.o:
	$(AM_V_CC)$(COMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $<
	$(AM_V_at)$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po
#	$(AM_V_CC)source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(COMPILE) -c $<

.c.obj:
	$(AM_V_CC)$(COMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ `$(CYGPATH_W) '$<'`
	$(AM_V_at)$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po
#	$(AM_V_CC)source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(COMPILE) -c `$(CYGPATH_W) '$<'`

libtgdb_a2_a-a2-tgdb.o: a2-tgdb.c
	$(AM_V_CC)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -MT libtgdb_a2_a-a2-tgdb.o -MD -MP -MF $(DEPDIR)/libtgdb_a2_a-a2-tgdb.Tpo -c -o libtgdb_a2_a-a2-tgdb.o `test -f 'a2-tgdb.c' || echo '$(srcdir)/'`a2-tgdb.c
	$(AM_V_at)$(am__mv) $(DEPDIR)/libtgdb_a2_a-a2-tgdb.Tpo $(DEPDIR)/libtgdb_a2_a-a2-tgdb.Po
#	$(AM_V_CC)source='a2-tgdb.c' object='libtgdb_a2_a-a2-tgdb.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -c -o libtgdb_a2_a-a2-tgdb.o `test -f 'a2-tgdb.c' || echo '$(srcdir)/'`a2-tgdb.c

libtgdb_a2_a-a2-tgdb.obj: a2-tgdb.c
	$(AM_V_CC)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -MT libtgdb_a2_a-a2-tgdb.obj -MD -MP -MF $(DEPDIR)/libtgdb_a2_a-a2-tgdb.Tpo -c -o libtgdb_a2_a-a2-tgdb.obj `if test -f 'a2-tgdb.c'; then $(CYGPATH_W) 'a2-tgdb.c'; else $(CYGPATH_W) '$(srcdir)/a2-tgdb.c'; fi`
	$(AM_V_at)$(am__mv) $(DEPDIR)/libtgdb_a2_a-a2-tgdb.Tpo $(DEPDIR)/libtgdb_a2_a-a2-tgdb.Po
#	$(AM_V_CC)source='a2-tgdb.c' object='libtgdb_a2_a-a2-tgdb.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -c -o libtgdb_a2_a-a2-tgdb.obj `if test -f 'a2-tgdb.c'; then $(CYGPATH_W) 'a2-tgdb.c'; else $(CYGPATH_W) '$(srcdir)/a2-tgdb.c'; fi`

libtgdb_a2_a-annotate.o: annotate.c
	$(AM_V_CC)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -MT libtgdb_a2_a-annotate.o -MD -MP -MF $(DEPDIR)/libtgdb_a2_a-annotate.Tpo -c -o libtgdb_a2_a-annotate.o `test -f 'annotate.c' || echo '$(srcdir)/'`annotate.c
	$(AM_V_at)$(am__mv) $(DEPDIR)/libtgdb_a2_a-annotate.Tpo $(DEPDIR)/libtgdb_a2_a-annotate.Po
#	$(AM_V_CC)source='annotate.c' object='libtgdb_a2_a-annotate.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -c -o libtgdb_a2_a-annotate.o `test -f 'annotate.c' || echo '$(srcdir)/'`annotate.c

libtgdb_a2_a-annotate.obj: annotate.c
	$(AM_V_CC)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -MT libtgdb_a2_a-annotate.obj -MD -MP -MF $(DEPDIR)/libtgdb_a2_a-annotate.Tpo -c -o libtgdb_a2_a-annotate.obj `if test -f 'annotate.c'; then $(CYGPATH_W) 'annotate.c'; else $(CYGPATH_W) '$(srcdir)/annotate.c'; fi`
	$(AM_V_at)$(am__mv) $(DEPDIR)/libtgdb_a2_a-annotate.Tpo $(DEPDIR)/libtgdb_a2_a-annotate.Po
#	$(AM_V_CC)source='annotate.c' object='libtgdb_a2_a-annotate.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -c -o libtgdb_a2_a-annotate.obj `if test -f 'annotate.c'; then $(CYGPATH_W) 'annotate.c'; else $(CYGPATH_W) '$(srcdir)/annotate.c'; fi`

libtgdb_a2_a-commands.o: commands.c
	$(AM_V_CC)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -MT libtgdb_a2_a-commands.o -MD -MP -MF $(DEPDIR)/libtgdb_a2_a-commands.Tpo -c -o libtgdb_a2_a-commands.o `test -f 'commands.c' || echo '$(srcdir)/'`commands.c
	$(AM_V_at)$(am__mv) $(DEPDIR)/libtgdb_a2_a-commands.Tpo $(DEPDIR)/libtgdb_a2_a-commands.Po
#	$(AM_V_CC)source='commands.c' object='libtgdb_a2_a-commands.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -c -o libtgdb_a2_a-commands.o `test -f 'commands.c' || echo '$(srcdir)/'`commands.c

libtgdb_a2_a-commands.obj: commands.c
	$(AM_V_CC)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -MT libtgdb_a2_a-commands.obj -MD -MP -MF $(DEPDIR)/libtgdb_a2_a-commands.Tpo -c -o libtgdb_a2_a-commands.obj `if test -f 'commands.c'; then $(CYGPATH_W) 'commands.c'; else $(CYGPATH_W) '$(srcdir)/commands.c'; fi`
	$(AM_V_at)$(am__mv) $(DEPDIR)/libtgdb_a2_a-commands.Tpo $(DEPDIR)/libtgdb_a2_a-commands.Po
#	$(AM_V_CC)source='commands.c' object='libtgdb_a2_a-commands.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -c -o libtgdb_a2_a-commands.obj `if test -f 'commands.c'; then $(CYGPATH_W) 'commands.c'; else $(CYGPATH_W) '$(srcdir)/commands.c'; fi`

libtgdb_a2_a-data.o: data.c
	$(AM_V_CC)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -MT libtgdb_a2_a-data.o -MD -MP -MF $(DEPDIR)/libtgdb_a2_a-data.Tpo -c -o libtgdb_a2_a-data.o `test -f 'data.c' || echo '$(srcdir)/'`data.c
	$(AM_V_at)$(am__mv) $(DEPDIR)/libtgdb_a2_a-data.Tpo $(DEPDIR)/libtgdb_a2_a-data.Po
#	$(AM_V_CC)source='data.c' object='libtgdb_a2_a-data.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -c -o libtgdb_a2_a-data.o `test -f 'data.c' || echo '$(srcdir)/'`data.c

libtgdb_a2_a-data.obj: data.c
	$(AM_V_CC)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -MT libtgdb_a2_a-data.obj -MD -MP -MF $(DEPDIR)/libtgdb_a2_a-data.Tpo -c -o libtgdb_a2_a-data.obj `if test -f 'data.c'; then $(CYGPATH_W) 'data.c'; else $(CYGPATH_W) '$(srcdir)/data.c'; fi`
	$(AM_V_at)$(am__mv) $(DEPDIR)/libtgdb_a2_a-data.Tpo $(DEPDIR)/libtgdb_a2_a-data.Po
#	$(AM_V_CC)source='data.c' object='libtgdb_a2_a-data.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -c -o libtgdb_a2_a-data.obj `if test -f 'data.c'; then $(CYGPATH_W) 'data.c'; else $(CYGPATH_W) '$(srcdir)/data.c'; fi`

libtgdb_a2_a-globals.o: globals.c
	$(AM_V_CC)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -MT libtgdb_a2_a-globals.o -MD -MP -MF $(DEPDIR)/libtgdb_a2_a-globals.Tpo -c -o libtgdb_a2_a-globals.o `test -f 'globals.c' || echo '$(srcdir)/'`globals.c
	$(AM_V_at)$(am__mv) $(DEPDIR)/libtgdb_a2_a-globals.Tpo $(DEPDIR)/libtgdb_a2_a-globals.Po
#	$(AM_V_CC)source='globals.c' object='libtgdb_a2_a-globals.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -c -o libtgdb_a2_a-globals.o `test -f 'globals.c' || echo '$(srcdir)/'`globals.c

libtgdb_a2_a-globals.obj: globals.c
	$(AM_V_CC)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -MT libtgdb_a2_a-globals.obj -MD -MP -MF $(DEPDIR)/libtgdb_a2_a-globals.Tpo -c -o libtgdb_a2_a-globals.obj `if test -f 'globals.c'; then $(CYGPATH_W) 'globals.c'; else $(CYGPATH_W) '$(srcdir)/globals.c'; fi`
	$(AM_V_at)$(am__mv) $(DEPDIR)/libtgdb_a2_a-globals.Tpo $(DEPDIR)/libtgdb_a2_a-globals.Po
#	$(AM_V_CC)source='globals.c' object='libtgdb_a2_a-globals.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -c -o libtgdb_a2_a-globals.obj `if test -f 'globals.c'; then $(CYGPATH_W) 'globals.c'; else $(CYGPATH_W) '$(srcdir)/globals.c'; fi`

libtgdb_a2_a-state_machine.o: state_machine.c
	$(AM_V_CC)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -MT libtgdb_a2_a-state_machine.o -MD -MP -MF $(DEPDIR)/libtgdb_a2_a-state_machine.Tpo -c -o libtgdb_a2_a-state_machine.o `test -f 'state_machine.c' || echo '$(srcdir)/'`state_machine.c
	$(AM_V_at)$(am__mv) $(DEPDIR)/libtgdb_a2_a-state_machine.Tpo $(DEPDIR)/libtgdb_a2_a-state_machine.Po
#	$(AM_V_CC)source='state_machine.c' object='libtgdb_a2_a-state_machine.o' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -c -o libtgdb_a2_a-state_machine.o `test -f 'state_machine.c' || echo '$(srcdir)/'`state_machine.c

libtgdb_a2_a-state_machine.obj: state_machine.c
	$(AM_V_CC)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -MT libtgdb_a2_a-state_machine.obj -MD -MP -MF $(DEPDIR)/libtgdb_a2_a-state_machine.Tpo -c -o libtgdb_a2_a-state_machine.obj `if test -f 'state_machine.c'; then $(CYGPATH_W) 'state_machine.c'; else $(CYGPATH_W) '$(srcdir)/state_machine.c'; fi`
	$(AM_V_at)$(am__mv) $(DEPDIR)/libtgdb_a2_a-state_machine.Tpo $(DEPDIR)/libtgdb_a2_a-state_machine.Po
#	$(AM_V_CC)source='state_machine.c' object='libtgdb_a2_a-state_machine.obj' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libtgdb_a2_a_CFLAGS) $(CFLAGS) -c -o libtgdb_a2_a-state_machine.obj `if test -f 'state_machine.c'; then $(CYGPATH_W) 'state_machine.c'; else $(CYGPATH_W) '$(srcdir)/state_machine.c'; fi`

ID: $(am__tagged_files)
	$(am__define_uniq_tagged_files); mkid -fID $$unique
tags: tags-am
TAGS: tags

tags-am: $(TAGS_DEPENDENCIES) $(am__tagged_files)
	set x; \
	here=`pwd`; \
	$(am__define_uniq_tagged_files); \
	shift; \
	if test -z "$(ETAGS_ARGS)$$*$$unique"; then :; else \
	  test -n "$$unique" || unique=$$empty_fix; \
	  if test $$# -gt 0; then \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      "$$@" $$unique; \
	  else \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      $$unique; \
	  fi; \
	fi
ctags: ctags-am

CTAGS: ctags
ctags-am: $(TAGS_DEPENDENCIES) $(am__tagged_files)
	$(am__define_uniq_tagged_files); \
	test -z "$(CTAGS_ARGS)$$unique" \
	  || $(CTAGS) $(CTAGSFLAGS) $(AM_CTAGSFLAGS) $(CTAGS_ARGS) \
	     $$unique

GTAGS:
	here=`$(am__cd) $(top_builddir) && pwd` \
	  && $(am__cd) $(top_srcdir) \
	  && gtags -i $(GTAGS_ARGS) "$$here"
cscopelist: cscopelist-am

cscopelist-am: $(am__tagged_files)
	list='$(am__tagged_files)'; \
	case "$(srcdir)" in \
	  [\\/]* | ?:[\\/]*) sdir="$(srcdir)" ;; \
	  *) sdir=$(subdir)/$(srcdir) ;; \
	esac; \
	for i in $$list; do \
	  if test -f "$$i"; then \
	    echo "$(subdir)/$$i"; \
	  else \
	    echo "$$sdir/$$i"; \
	  fi; \
	done >> $(top_builddir)/cscope.files

distclean-tags:
	-rm -f TAGS ID GTAGS GRTAGS GSYMS GPATH tags

distdir: $(DISTFILES)
	@srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	topsrcdirstrip=`echo "$(top_srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	list='$(DISTFILES)'; \
	  dist_files=`for file in $$list; do echo $$file; done | \
	  sed -e "s|^$$srcdirstrip/||;t" \
	      -e "s|^$$topsrcdirstrip/|$(top_builddir)/|;t"`; \
	case $$dist_files in \
	  */*) $(MKDIR_P) `echo "$$dist_files" | \
			   sed '/\//!d;s|^|$(distdir)/|;s,/[^/]*$$,,' | \
			   sort -u` ;; \
	esac; \
	for file in $$dist_files; do \
	  if test -f $$file || test -d $$file; then d=.; else d=$(srcdir); fi; \
	  if test -d $$d/$$file; then \
	    dir=`echo "/$$file" | sed -e 's,/[^/]*$$,,'`; \
	    if test -d "$(distdir)/$$file"; then \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    if test -d $(srcdir)/$$file && test $$d != $(srcdir); then \
	      cp -fpR $(srcdir)/$$file "$(distdir)$$dir" || exit 1; \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    cp -fpR $$d/$$file "$(distdir)$$dir" || exit 1; \
	  else \
	    test -f "$(distdir)/$$file" \
	    || cp -p $$d/$$file "$(distdir)/$$file" \
	    || exit 1; \
	  fi; \
	done
check-am: all-am
check: check-am
all-am: Makefile $(LIBRARIES)
installdirs:
install: install-am
install-exec: install-exec-am
install-data: install-data-am
uninstall: uninstall-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am

installcheck: installcheck-am
install-strip:
	if test -z '$(STRIP)'; then \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	      install; \
	else \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	    "INSTALL_PROGRAM_ENV=STRIPPROG='$(STRIP)'" install; \
	fi
mostlyclean-generic:

clean-generic:

distclean-generic:
	-test -z "$(CONFIG_CLEAN_FILES)" || rm -f $(CONFIG_CLEAN_FILES)
	-test . = "$(srcdir)" || test -z "$(CONFIG_CLEAN_VPATH_FILES)" || rm -f $(CONFIG_CLEAN_VPATH_FILES)

maintainer-clean-generic:
	@echo "This command is intended for maintainers to use"
	@echo "it deletes files that may require special tools to rebuild."
clean: clean-am

clean-am: clean-generic clean-noinstLIBRARIES mostlyclean-am

distclean: distclean-am
	-rm -rf ./$(DEPDIR)
	-rm -f Makefile
distclean-am: clean-am distclean-compile distclean-generic \
	distclean-tags

dvi: dvi-am

dvi-am:

html: html-am

html-am:

info: info-am

info-am:

install-data-am:

install-dvi: install-dvi-am

install-dvi-am:

install-exec-am:

install-html: install-html-am

install-html-am:

install-info: install-info-am

install-info-am:

install-man:

install-pdf: install-pdf-am

install-pdf-am:

install-ps: install-ps-am

install-ps-am:

installcheck-am:

maintainer-clean: maintainer-clean-am
	-rm -rf ./$(DEPDIR)
	-rm -f Makefile
maintainer-clean-am: distclean-am maintainer-clean-generic

mostlyclean: mostlyclean-am

mostlyclean-am: mostlyclean-compile mostlyclean-generic

pdf: pdf-am

pdf-am:

ps: ps-am

ps-am:

uninstall-am:

.MAKE: install-am install-strip

.PHONY: CTAGS GTAGS TAGS all all-am check check-am clean clean-generic \
	clean-noinstLIBRARIES cscopelist-am ctags ctags-am distclean \
	distclean-compile distclean-generic distclean-tags distdir dvi \
	dvi-am html html-am info info-am install install-am \
	install-data install-data-am install-dvi install-dvi-am \
	install-exec install-exec-am install-html install-html-am \
	install-info install-info-am install-man install-pdf \
	install-pdf-am install-ps install-ps-am install-strip \
	installcheck installcheck-am installdirs maintainer-clean \
	maintainer-clean-generic mostlyclean mostlyclean-compile \
	mostlyclean-generic pdf pdf-am ps ps-am tags tags-am uninstall \
	uninstall-am


# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
