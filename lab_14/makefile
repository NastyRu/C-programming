CC := gcc

CFLAGS := -std=c99 -Wall -Werror -pedantic

test_massiv.exe: queue_massiv.o test_massiv.o
	$(CC) $^ -o $@

test_list.exe: queue_list.o test_list.o
	$(CC) $^ -o $@

%.o: %.c queue_list.h queue_massiv.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.exe
