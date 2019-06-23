CC := gcc

CFLAGS := -std=c99 -Wall -Werror

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

app.exe: max.o read_array.o main.o
	$(CC) -o app.exe max.o read_array.o main.o

test_max.exe: test_max.o max.o
	$(CC) -o test_max.exe test_max.o max.o

test_read_array.exe: test_read_array.o read_array.o
	$(CC) -o test_read_array.exe test_read_array.o read_array.o

max.o: max.c max.h
	$(CC) $(CFLAGS) -c max.c

read_array.o: read_array.c read_array.h
	$(CC) $(CFLAGS) -c read_array.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

test_max.o: test_max.c
	$(CC) $(CFLAGS) -c test_max.c

test_read_array.o: test_read_array.c
	$(CC) $(CFLAGS) -c test_read_array.c

clean:
	rm *.o *.exe
