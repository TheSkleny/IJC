CC=gcc
CFLAGS=-g -std=c11 -pedantic -Wall -Wextra
MODULES=htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o htab_free.o htab_hash_function.o htab_init.o htab_insert_item.o htab_item_init.o htab_lookup_add.o htab_resize.o htab_size.o htab.h htab_structs.h

#all: htab_bucket_count.c htab_clear.c htab_erase.c htab_free.c htab_hash_function.c htab_init.c htab_insert_item.c htab_item_init.c htab_resize.c htab_size.c htab_find.c htab_lookup_add.c htab_for_each.c io.c testing.c
#	$(CC) $(CFLAGS) htab_bucket_count.c htab_clear.c htab_erase.c htab_free.c htab_hash_function.c htab_init.c htab_insert_item.c htab_item_init.c htab_resize.c htab_size.c htab_find.c htab_lookup_add.c htab_for_each.c io.c testing.c -o testing

#all: htab_bucket_count.c htab_clear.c htab_erase.c htab_free.c htab_hash_function.c htab_init.c htab_insert_item.c htab_item_init.c htab_resize.c htab_size.c htab_find.c htab_lookup_add.c htab_for_each.c io.c wordcount.c
#	$(CC) $(CFLAGS) htab_bucket_count.c htab_clear.c htab_erase.c htab_free.c htab_hash_function.c htab_init.c htab_insert_item.c htab_item_init.c htab_resize.c htab_size.c htab_find.c htab_lookup_add.c htab_for_each.c io.c wordcount.c -o wordcount

all: tail libhtab.a libhtab.so wordcount-dynamic wordcount


# TASK A

tail: tail.o
	$(CC) $(CFLAGS) $< -o $@

tail.o: tail.c
	$(CC) $(CFLAGS) $< -c -o $@

# TASK B

# o-files

# parts of library
htab_bucket_count.o: htab_bucket_count.c
	$(CC) $(CFLAGS) -fPIC $< -c -o $@

htab_clear.o: htab_clear.c
	$(CC) $(CFLAGS) -fPIC $< -c -o $@

htab_erase.o: htab_erase.c
	$(CC) $(CFLAGS) -fPIC $< -c -o $@

htab_find.o: htab_find.c
	$(CC) $(CFLAGS) -fPIC $< -c -o $@

htab_for_each.o: htab_for_each.c
	$(CC) $(CFLAGS) -fPIC $< -c -o $@

htab_free.o: htab_free.c
	$(CC) $(CFLAGS) -fPIC $< -c -o $@

htab_hash_function.o: htab_hash_function.c
	$(CC) $(CFLAGS) -fPIC $< -c -o $@

htab_init.o: htab_init.c
	$(CC) $(CFLAGS) -fPIC $< -c -o $@

htab_insert_item.o: htab_insert_item.c
	$(CC) $(CFLAGS) -fPIC $< -c -o $@

htab_item_init.o: htab_item_init.c
	$(CC) $(CFLAGS) -fPIC $< -c -o $@

htab_lookup_add.o: htab_lookup_add.c
	$(CC) $(CFLAGS) -fPIC $< -c -o $@

htab_resize.o: htab_resize.c
	$(CC) $(CFLAGS) -fPIC $< -c -o $@

htab_size.o: htab_size.c
	$(CC) $(CFLAGS) -fPIC $< -c -o $@

# wordcount and io

io.o: io.c
	$(CC) $(CFLAGS) $< -c -o $@

io: io.o
	$(CC) $(CFLAGS) $< -o $@

wordcount.o: wordcount.c
	$(CC) $(CFLAGS) $< -c -o $@

wordcount: wordcount.o io.o libhtab.a
	$(CC) $(CFLAGS) $^ -o $@

wordcount-dynamic: wordcount.o io.o libhtab.so
	$(CC) $(CFLAGS) $^ -o $@


# Static library

libhtab.a: $(MODULES)
	ar rcs libhtab.a $^


# Dynamic library

libhtab.so: $(MODULES)
	$(CC) $(CFLAGS) -fPIC -shared $^ -o $@


# Cleaning

clear:
	rm *.o

win-clear:
	del *.o

win-delete:
	del tail.exe libhtab.a libhtab.so wordcount-dynamic.exe wordcount.exe

delete:
	rm tail libhtab.a libhtab.so wordcount-dynamic wordcount