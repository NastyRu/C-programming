CC := gcc

CFLAGS := -g3 -std=c99 -Wall -Werror -pedantic

app.exe: tree.o struct.o main.o
	$(CC) -g3 $^ -o $@

test.exe: tree.o struct.o test.o
	$(CC) $^ -o $@

%.o: %.c tree.h struct.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.exe

