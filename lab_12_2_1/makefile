CC := gcc

CFLAGS := -std=c99 -Wall -Werror -pedantic

libarray.dll: array.o
	$(CC) -shared $^ -Wl -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

test: libarray.dll
	python test.py
	
clean:
	rm *.dll *.a *.o *.exe
