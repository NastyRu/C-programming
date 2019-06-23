CC := gcc

CFLAGS := -std=c99 -Wall -Werror

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

app.exe: max.o read_array.o main.o
	$(CC) -o app.exe max.o read_array.o main.o

max.o: max.c
	$(CC) $(CFLAGS) -c max.c

read_array.o: read_array.c
	$(CC) $(CFLAGS) -c read_array.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm *.o *.exe
