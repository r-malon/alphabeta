VERSION = 1.0.0

PREFIX = /usr/local
MANPREFIX = $(PREFIX)/share/man
MANSECTION = 1

CC = cc
CFLAGS = -ansi -Wall -Wextra -pedantic -O2 -fwrapv
CPPFLAGS = -DMEMSIZE=1024 # -DMORE_INSTR
LDFLAGS = -s
