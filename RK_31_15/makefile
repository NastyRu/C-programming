CC := gcc

CFLAGS := -std=c99 -Wall -Werror -pedantic

build: main.o work_with_matrix.o
	$(CC) $^ -o app.exe

run:
	./app.exe in.txt

%.o: %.c include.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.exe
