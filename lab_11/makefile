CC := gcc

CFLAGS := -std=c99 -Wall -Werror

test.exe: my_snprintf.o string.o test.o
	$(CC) $^ -o $@

%.o: %.c string.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.exe
