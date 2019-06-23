CC := gcc

CFLAGS := -std=c99 -Wall -Werror -pedantic

app.exe: other_functions.o str_replace.o my_getline.o main.o
	$(CC) $^ -o $@

test.exe: other_functions.o str_replace.o my_getline.o test.o
	$(CC) $^ -o $@

%.o: %.c my_string.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.exe
