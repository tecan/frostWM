NULL=

libbrl_LTLIBRARIES = libbrl.la

INCLUDES = -I$(top_builddir)			\
	   -I$(top_srcdir)/srutil		\
	   -I$(top_srcdir)/srconf/libsrconf 	\
	   -DBRAILLE_TRANS_TABLES_DIR=\"$(gnopernicusconfdir)/translation_tables/\" \
	   $(BRLTTY_ACTIVE)			\
	   $(LIBBRL_CFLAGS) 			\
	   $(BRLTTY_INCLUDE)			\
	   -DG_LOG_DOMAIN=\"gnopernicus\"

AM_LDFLAGS = $(LIBBRL_LIBS) @LT_VERSION_INFO@

LDADD = ../../srconf/libsrconf/libsrconf.la	\
	../../srutil/srutil.la 			\
	$(LIBBRL_LIBS)				\
	$(BRLTTY_LIBRARY)

libbrlincludedir =$(includedir)/gnopernicus-1.0/libbrl
libbrldir=$(libdir)/gnopernicus-1.0

libbrlinclude_HEADERS = brlxmlapi.h  

libbrl_la_SOURCES = baumbrl.h	 \
		    alvabrl.h	 \
		    braille.h    \
		    ecobrl.h	 \
		    brlxmlapi.h  \
		    brlxml.h     \
		    sercomm.h    \
		    handybrl.h	 \
		    sercomm.c    \
		    baumbrl.c    \
		    alvabrl.c	 \
		    braille.c    \
		    brlxml.c     \
		    handybrl.c	 \
		    ecobrl.c	 \
		    $(EXTRA_libbrl_la_SOURCES)

if BUILD_BRLTTY_SUPPORT
EXTRA_libbrl_la_SOURCES = ttybrl.c 	 \
			 ttybrl.h
endif

EXTRA_DIST = ttybrl.c 	 \
	    ttybrl.h
