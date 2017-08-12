EXTRA_DIST = README.md
include_HEADERS =
lib_LIBRARIES =
TESTS =
check_PROGRAMS =

include_HEADERS += src/file-get-contents.h
lib_LIBRARIES += libfile-get-contents.a
libfile_get_contents_a_SOURCES = \
	src/file-get-contents.h \
	src/file-get-contents.c

TESTS += tests/read-file
check_PROGRAMS += tests/read-file
tests_read_file_SOURCES = src/tests/read-file.c
tests_read_file_LDADD = libfile-get-contents.a

TESTS += tests/read-empty-file
check_PROGRAMS += tests/read-empty-file
tests_read_empty_file_SOURCES = src/tests/read-empty-file.c
tests_read_empty_file_LDADD = libfile-get-contents.a

TESTS += tests/file-not-found
check_PROGRAMS += tests/file-not-found
tests_file_not_found_SOURCES = src/tests/file-not-found.c
tests_file_not_found_LDADD = libfile-get-contents.a
