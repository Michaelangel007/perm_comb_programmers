all: demo_perm_almost demo_perm_fastswap demo_perm_natural demo_perm_shift \
     meta_perm_ordering \
     print_perm_comb

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

DEP_H := $(wildcard *.h)

demo_perm_almost:   demo_perm_almost.cpp   util.h perm_norep_almost.h
	$(CC) $(CFLAGS) $< -o $@

demo_perm_fastswap: demo_perm_fastswap.cpp util.h perm_norep_fastswap.h
	$(CC) $(CFLAGS) $< -o $@

demo_perm_natural:  demo_perm_natural.cpp  util.h perm_norep_natural.h
	$(CC) $(CFLAGS) $< -o $@

demo_perm_shift:    demo_perm_shift.cpp    util.h perm_norep_shift.h
	$(CC) $(CFLAGS) $< -o $@

meta_perm_ordering: meta_perm_ordering.cpp $(DEP_H)
	$(CC) $(CFLAGS) $< -o $@

print_perm_comb: print_perm_comb.cpp       $(DEP_H)
	$(CC) $(CFLAGS) $< -o $@

