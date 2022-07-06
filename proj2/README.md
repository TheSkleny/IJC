# Project 2

evaulation: 13.5/15

## Build
```bash
make
```
This command should build both A and B tasks

# Task A

Write program that print last 10 (or any user inputed number) lines from given file.

## Run
```bash
tail {file}

tail -n [number of lines] [file]

tail -n [number of lines] < [file]
```

# Task B

Rewrite C++ program (wordcount.cc) to C (wordcount.c) using hash table functions as a substitute for unordered_map in C++.

## Windows run

### Static library
```bash
wordcount.exe < [file]
```

### Dynamic library
```bash
wordcount-dynamic.exe < [file]
```

## Linux run

### Static library
```bash
./wordcount < [file]
```

### Dynamic library
```bash
./wordcount-dynamic < [file]
```

# Utilities

## Cleaning on Windows
```bash
make win-clear
```
deletes all .o files

```bash
make win-delete
```
deletes all compiled files, useful for testing

## Cleaning on Linux
```bash
make clear
```
deletes all .o files

```bash
make delete
```
deletes all compiled files, useful for testing

