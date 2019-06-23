CC := gcc

CFLAGS := -std=c99 -Wall -Werror -pedantic

app.exe: work_with_table.o main.o
	$(CC) $^ -o $@

test.exe: work_with_table.o test.o
	$(CC) $^ -o $@

ftest: test.exe
	sh ftest.sh

graph:
	python graph.py

%.o: %.c list.h work_with_table.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.exe
