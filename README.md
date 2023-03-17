# alphabeta
**alphabeta** is an interpreted recreational programming language.\
Source code is identified by the `.abc` file extension.

There are 52 instructions (cf. instructions.txt), each being a upper or
 lower-case alphabet letter, and 5 registers available.\
Add `CPPFLAGS='-DMORE_INSTR'` to compile 12 more instructions.\
Register 1 and 2 (R1, R2) are data registers, register 3 (R3) is the
 accumulator, P0 stores a pointer to one of the 1024 words of memory and
 P1 stores a position indicator for jumping around the currently opened
 source code stream.

Whitespace is ignored, any other character that doesn't match `a-zA-Z`
 (or `a-zA-Z0-9+/` if compiled with MORE_INSTR)
 throws `Invalid instruction`.

## Installation
Edit `config.mk` to match your local setup (alphabeta is installed into the
`/usr/local` namespace by default), then simply enter the following command to
install (if necessary as root):
```
make clean install
```

**See**:\
[Esolang page](https://esolangs.org/wiki/AlphaBeta)\
[Original C++ implementation](https://github.com/TryItOnline/alphabeta)
