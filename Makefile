all: demo_comb_fastswap demo_comb_natural demo_comb_shift

clean:
	rm demo_comb_fastswap
	rm demo_comb_natural
	rm demo_comb_shift

# Might map to gcc or clang
# Or if you have a specific version of GCC installed
#CC=/usr/local/bin/gcc
CC=gcc

# Optionally:
#   GCC    -stdc=c99
#   Clang  -std=c99
# See: http://clang.llvm.org/docs/UsersManual.html
CFLAGS= -Wall -Wextra -Wpedantic

demo_comb_fastswap: comb_fastswap.cpp
	$(CC) $(CFLAGS) $< -o $@

demo_comb_natural: comb_natural.cpp
	$(CC) $(CFLAGS) $< -o $@

demo_comb_shift: comb_shift.cpp
	$(CC) $(CFLAGS) $< -o $@

