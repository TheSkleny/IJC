# Project 1
evaulation: 15/15

Print the last 10 prime numbers from 300 milion number range using bit field to use minimal amount of memory

# Task A

## Task A build on Windows

Automated build and run for both versions of primes.c file (with macros / with inline functions)

```bash
make run-win
```

OR

```bash
make
primes.exe
primes-i.exe
```
for automated build and manual run

## Task A build on Linux

Automated build and run for both versions of primes.c file (with macros / with inline functions)

```bash
make run
```

OR

```bash
make
./primes
./primes-i
```
for automated build and manual run

# Task B
Decode a secret message from the .ppm file using Eratosthenes algorithm from task A

#### Task B secret message
Obrázek "Lenna" (zdroj: Wikipedie).

Používáme metodu podobnou steganografii - viz

http://en.wikipedia.org/wiki/Steganography

## Task B build on Windows

```bash
make
steg-decode.exe {filename}.ppm
```

## Task B build on Linux

```bash
make
./steg-decode {filename}.ppm
```