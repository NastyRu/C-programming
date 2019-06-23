CC := gcc

CFLAGS := -std=c99 -Wall -Werror -pedantic

test.exe: function.o test.o
	$(CC) $^ -o $@

rand.exe: function.o rand.o
	$(CC) $^ -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.exe
