VERSION = 0.0.1

PREFIX = /usr/local
MANPREFIX = $(PREFIX)/share/man
MANSECTION = 1

CC = cc
CFLAGS = -ansi -Wall -Wextra -pedantic -O2 -fwrapv
CPPFLAGS = # -DMORE_INSTR
LDFLAGS = -s
