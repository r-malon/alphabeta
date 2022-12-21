PROG = alphabeta
SRCS = interpreter.c ipow.c
OBJS = ${SRCS:.c=.o}
FLAGS = -ansi -Wall -Wextra -pedantic -O2 -fwrapv

all: ${PROG}

interpreter.o: ipow.h
ipow.o: ipow.h

.c.o:
	${CC} ${FLAGS} ${CFLAGS} -c $<

${PROG}: ${OBJS}
	${CC} -o $@ ${OBJS} ${LDFLAGS}

clean:
	-rm -f ${OBJS} ${PROG} ${PROG:=.exe} ${PROG:=.core}

.PHONY: all clean
