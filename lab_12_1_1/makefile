CC := gcc

CFLAGS := -std=c99

test.exe: test.c libarray.a
	$(CC) $^ -o $@

libarray.a: array_lib.o
	ar rc $@ $^
	ranlib $@

array_lib.o: array_lib.c
	$(CC) -fPIC -c array_lib.c

%.o: %.c
	$(CC) $(CFLAGS) -c $<

test_dyn_comp.exe: test.c libarray.dll
	$(CC) $^ -o $@

libarray.dll: array_lib.o
	$(CC) -shared $^ -Wl -o $@

test_dyn_load.exe: test_dyn.o libarray.dll
	$(CC) $< -o $@

clean:
	rm *.dll *.a *.o *.exe
