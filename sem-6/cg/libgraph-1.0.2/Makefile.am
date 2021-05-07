INCLUDES = -I$(top_srcdir)

SUBDIRS = doc

AM_CFLAGS = $(CFLAGS) -DFONTDIR=\""$(libgraphfontdir)/"\"

EXTRA_DIST = sample.c



lib_LTLIBRARIES = libgraph.la 

libgraph_la_SOURCES = libgraph.c text.c shapes.c polygon.c

include_HEADERS = graphics.h shapes.h grtext.h polygon.h

libgraph_la_LDFLAGS = -version-info 1:2:0 -export-dynamic

## C compilation script
dist_bin_SCRIPTS = grc


libgraphdir = $(pkgdatadir)
libgraphfontdir = $(libgraphdir)/Font
dist_libgraph_DATA = doc/*.html
dist_libgraphfont_DATA = Font/*






#	if test "x$enable_guile" = "xyes" ; then
if GUILE 
libguiledir = $(libdir)
## Guile-loadable module
libguile_LTLIBRARIES =  libguile-libgraph.la 

BUILT_SOURCES = libgraph.scm

libguile_libgraph_la_SOURCES = $(BUILT_SOURCES) guile-libgraph.c

libguile_libgraph_la_LDFLAGS = -version-info 0:2:0 -export-dynamic $(GUILE_LDFLAGS) 

libguile_libgraph_la_LIBADD = -lgraph

libguile_libgraphdir = $(GUILE_DATADIR)/libgraph

dist_libguile_libgraph_DATA = libgraph.scm
endif 


if PKGCONFIG
##	Check whether to compile pkg-config support
##	if test "x$enable_pkgconfig" = "xyes" ; then
## pkgconfig .pc file

libgraphpkgdir = $(libdir)/pkgconfig
libgraphpkg_PROGRAMS = libgraph.pc
libgraph_pc_SOURCES = pcgen.sh

$(libgraphpkg_PROGRAMS): $(libgraph_pc_SOURCES)
	./$< $(prefix) $(libdir) $(bindir) $(includedir) $(PACKAGE) $(VERSION) > $@; 

CLEANFILES = *.pc
endif 
