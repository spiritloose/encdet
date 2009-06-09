noinst_PROGRAMS = encdet
encdet_SOURCES = encdet.c
INCLUDES = -I$(top_builddir)/src
LIBS = $(top_builddir)/src/libencdet.la
EXTRA_DIST = EUC-JP.txt ISO-2022-JP.txt Shift_JIS.txt UTF-16.txt UTF-8.txt test.sh
TESTS = test.sh

test: encdet
	prove=`which prove || echo ""`; $$prove ./test.sh
.PHONY: test
