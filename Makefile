all: demo_comb_fastswap

clean:
	rm demo_comb_fastswap

# Might map to gcc or clang
CC=gcc

# Of if you have a specific version of GCC installed
#CC=/usr/local/bin/gcc

# Optionally:
#   GCC    -stdc=c99
#   Clang  -std=c99
# See: http://clang.llvm.org/docs/UsersManual.html
demo_comb_fastswap: comb_fastswap.cpp
	$(CC) $< -o $@ -Wall -Wextra -Wpedantic
