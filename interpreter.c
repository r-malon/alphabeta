#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iso646.h>
#include "ipow.h"

#ifndef MEMSIZE
#define MEMSIZE 1024
#endif

#define ERROR(msg) do { fputs(msg, stderr); exit(EXIT_FAILURE); } while (0)
#define CHECKMEM(addr, errmsg) do {		\
	if (addr < 0 or addr >= MEMSIZE)	\
		ERROR(errmsg);					\
} while (0)


int R1 = 0;
int R2 = 0;
int R3 = 0;	/* Accumulator */
int P[] = {
	0,	/* Memory pointer */
	0	/* Position pointer */
};
int mode = 0;
int mem[MEMSIZE];
int tmp;


int
main(int argc, char *argv[])
{
	int c;
	FILE *fp;

	if (argc > 1) {
		fp = fopen(argv[1], "r");
		if (fp == NULL) {
			fprintf(stderr, "Could not open file '%s'.\n", argv[1]);
			return EXIT_FAILURE;
		}
	} else {
		fp = stdin;
	}

	while ((c = getc(fp)) != EOF) {	/* TODO: block input */
		if (isspace(c))
			continue;

		switch (c) {
		case 'a': R1 += 1; break;
		case 'b': R1 -= 1; break;
		case 'c': R1 += 10; break;
		case 'd': R1 -= 10; break;
		case 'e': R1 += 100; break;
		case 'f': R1 -= 100; break;
		case 'g': R2 += 1; break;
		case 'h': R2 -= 1; break;
		case 'i': R2 += 10; break;
		case 'j': R2 -= 10; break;
		case 'k': R2 += 100; break;
		case 'l': R2 -= 100; break;
		case 'm': R3 = not R1; break;
		case 'n': R3 = not R2; break;
		case 'o': R3 = R1 and R2; break;
		case 'p': R3 = R1 or R2; break;
		case 'q': R3 = not R1 != not R2; break;
		case 'r': R3 = R1 + R2; break;
		case 's': R3 = R1 - R2; break;
		case 't': R3 = R1 * R2; break;
		case 'u':
			if (R2 == 0)
				ERROR("u: division by zero");
			R3 = R1 / R2;
			break;
		case 'v':
			if (R2 == 0)
				ERROR("v: division by zero");
			R3 = R1 % R2;
			break;
		case 'w': R3 = ipow(R1, R2); break;
		case 'x': R1 = 0; break;
		case 'y': R2 = 0; break;
		case 'z': R3 = 0; break;
		case 'A': R2 = R1; break;
		case 'B': R1 = R2; break;
		case 'C': R3 = R1; break;
		case 'D': R3 = R2; break;
		case 'E': R1 = R3; break;
		case 'F': R2 = R3; break;
		case 'G':
			CHECKMEM(P[0], "G: invalid memory address");
			R1 = mem[P[0]];
			break;
		case 'H':
			CHECKMEM(P[0], "H: invalid memory address");
			R2 = mem[P[0]];
			break;
		case 'I':
			CHECKMEM(P[0], "I: invalid memory address");
			mem[P[0]] = R3;
			break;
		case 'J': if ((tmp = getchar()) != EOF) R1 = tmp; break;
		case 'K': if ((tmp = getchar()) != EOF) R2 = tmp; break;
		case 'L': putchar(R3); break;
		case 'M': printf("%d", R3); break;
		case 'N': if (R1 == R2) fseek(fp, P[1], SEEK_SET); break;
		case 'O': if (R1 != R2) fseek(fp, P[1], SEEK_SET); break;
		case 'P': if (R1 >= R2) fseek(fp, P[1], SEEK_SET); break;
		case 'Q': if (R1 <= R2) fseek(fp, P[1], SEEK_SET); break;
		case 'R': if (R3 == 0) fseek(fp, P[1] - 1, SEEK_SET); break;
		case 'S': P[mode] += 1; break;
		case 'T': P[mode] -= 1; break;
		case 'U': P[mode] += 10; break;
		case 'V': P[mode] -= 10; break;
		case 'W': P[mode] += 100; break;
		case 'X': P[mode] -= 100; break;
		case 'Y': P[mode] = 0; break;
		case 'Z': mode = not mode; break;
	#if MORE_INSTR
		case '0': goto exit;
		case '1': R3 = ~R3; break;
		case '2': R3 = R1 & R2; break;
		case '3': R3 = R1 | R2; break;
		case '4': R3 = R1 ^ R2; break;
		case '5': R3 |= 1UL << R1; break;
		case '6': R3 &= ~(1UL << R1); break;
		case '7': R3 ^= 1UL << R1; break;
		case '8': R3 = (R1 >> R2) & 1UL; break;
		case '9': tmp = R1; R1 = R2; R2 = tmp; break;
		case '+': R3 = R1 << R2; break;
		case '/': R3 = R1 >> R2; break;
	#endif
		default: ERROR("Invalid instruction");
		}
	}
#if MORE_INSTR
exit:
#endif
	if (fp != stdin)
		fclose(fp);

	return 0;
}
