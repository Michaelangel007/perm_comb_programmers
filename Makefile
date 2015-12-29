all: demo_perm_almost demo_perm_fastswap demo_perm_natural demo_perm_shift print_perm_comb

clean:
	rm demo_perm_almost
	rm demo_perm_fastswap
	rm demo_perm_natural
	rm demo_perm_shift
	rm print_perm_comb

# Might map to gcc or clang
# Or if you have a specific version of GCC installed
#CC=/usr/local/bin/gcc
CC=gcc

# Optionally:
#   GCC    -stdc=c99
#   Clang  -std=c99
# See: http://clang.llvm.org/docs/UsersManual.html
CFLAGS= -Wall -Wextra -Wpedantic

demo_perm_almost:   demo_perm_almost.cpp
	$(CC) $(CFLAGS) $< -o $@

demo_perm_fastswap: demo_perm_fastswap.cpp
	$(CC) $(CFLAGS) $< -o $@

demo_perm_natural:  demo_perm_natural.cpp
	$(CC) $(CFLAGS) $< -o $@

demo_perm_shift:    demo_perm_shift.cpp
	$(CC) $(CFLAGS) $< -o $@

print_perm_comb: print_perm_comb.cpp
	$(CC) $(CFLAGS) $< -o $@

