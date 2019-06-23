CC := gcc

CFLAGS := -std=c99 -Wall -Werror -pedantic

build: work_with_file.o main.o
	$(CC) $^ -o app.exe

run: build
	./app.exe -i SPB.csv

%.o: %.c list.h work_with_file.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.exe
