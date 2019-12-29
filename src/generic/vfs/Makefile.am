
AUTOMAKE_OPTIONS = subdir-objects

AM_CFLAGS = -imacros ${top_builddir}/src/config.h
AM_CCASFLAGS = -imacros ${top_builddir}/srcinclude/config.h

bin_PROGRAMS = vfs.elf
vfs_elf_SOURCES = \
  fs.h \
  fs.c \
  main.c
