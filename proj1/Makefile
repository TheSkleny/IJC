CC=gcc
CFLAGS=-g -std=c11 -pedantic -Wall -Wextra

all: primes primes-i steg-decode

run: primes primes-i
	./primes
	./primes-i

run-win: primes primes-i
	primes.exe
	primes-i.exe


#if used on windows machine, add to compilation     -Wl,--stack,38000000      to increase stack size
primes: eratosthenes.o bitset.o primes.o error.o
	$(CC) $(CFLAGS) eratosthenes.o bitset.o primes.o error.o -o primes -lm

primes-i: eratosthenes-i.o bitset-i.o primes-i.o error-i.o
	$(CC) $(CFLAGS) -DUSE_INLINE eratosthenes-i.o bitset-i.o primes-i.o error-i.o -o primes-i -lm



eratosthenes.o: eratosthenes.c
	$(CC) $(CFLAGS) -O2 eratosthenes.c -c -o eratosthenes.o

bitset.o: bitset.c
	$(CC) $(CFLAGS) -O2 bitset.c -c -o bitset.o

primes.o: primes.c
	$(CC) $(CFLAGS) -O2 primes.c -c -o primes.o

error.o: error.c
	$(CC) $(CFLAGS) -O2 error.c -c -o error.o



eratosthenes-i.o: eratosthenes.c
	$(CC) $(CFLAGS) -O2 -DUSE_INLINE eratosthenes.c -c -o eratosthenes-i.o

bitset-i.o: bitset.c
	$(CC) $(CFLAGS) -O2 -DUSE_INLINE bitset.c -c -o bitset-i.o

primes-i.o: primes.c
	$(CC) $(CFLAGS) -O2 -DUSE_INLINE primes.c -c -o primes-i.o

error-i.o: error.c
	$(CC) $(CFLAGS) -O2 -DUSE_INLINE error.c -c -o error-i.o



steg-decode: steg-decode.o ppm.o error.o eratosthenes.o
	$(CC) $(CFLAGS) steg-decode.o ppm.o eratosthenes.o error.o -o steg-decode -lm


steg-decode.o: steg-decode.c
	$(CC) $(CFLAGS) steg-decode.c -c -o steg-decode.o

ppm.o: ppm.c
	$(CC) $(CFLAGS) ppm.c -c -o ppm.o




clear-win:
	del *.o

clear:
	rm *.o