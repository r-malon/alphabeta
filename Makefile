PROG = alphabeta
SRCS = interpreter.c ipow.c
OBJS = ${SRCS:.c=.o}
CFLAGS = -ansi -Wall -Wextra -pedantic -O2 -fwrapv
LDFLAGS = -s

all: ${PROG}

interpreter.o: ipow.h
ipow.o: ipow.h

.c.o:
	${CC} ${CFLAGS} -c $<

${PROG}: ${OBJS}
	${CC} -o $@ ${OBJS} ${LDFLAGS}

clean:
	-rm -f ${OBJS} ${PROG} ${PROG:=.core}

.PHONY: all clean
