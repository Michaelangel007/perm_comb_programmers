all: demo_comb_fastswap

clean:
	rm demo_comb_fastswap

demo_comb_fastswap: comb_fastswap.cpp
	$(CC) $< -o $@ -Wall -Wextra -Wpedantic
