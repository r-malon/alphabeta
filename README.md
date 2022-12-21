# AlphaBeta
AlphaBeta is an interpreted recreational programming language.\
Source code is identified by the `.abc` file extension.

There are 52 instructions (cf. instructions.txt), each being a upper or lower-case alphabet letter, and 5 registers available.\
Register 1 and 2 (R1, R2) are data registers, register 3 (R3) is the accumulator, P0 stores a pointer to one of the 1024 words of memory and P1 stores a position indicator for jumping around the currently opened source code stream.

Whitespace is ignored, if a character doesn't match `/[a-zA-Z]/`, `Invalid instruction` is thrown.

**See**:\
[Esolang page](https://esolangs.org/wiki/AlphaBeta)\
[Original C++ implementation](https://github.com/TryItOnline/alphabeta)
