## Makefile.am - procress this file with automake to produce Makefile.in
lib_LTLIBRARIES = libobstack.la
libobstack_la_SOURCES = obstack.c obstack_printf.c
libobstack_la_HEADERS = obstack.h
libobstack_la_LDFLAGS = -version-info 1
libobstack_ladir = $(includedir)
ACLOCAL_AMFLAGS = -Im4

pkgconfig_DATA = musl-obstack.pc
