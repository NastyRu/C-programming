CC := gcc

CFLAGS := -std=c99 -Wall -Werror

app.exe: work_with_file.o filter.o bubble_sort.o main.o
	$(CC) $^ -o $@

test.exe: work_with_file.o filter.o test_filter.o bubble_sort.o test_bubble_sort.o test.o
	$(CC) $^ -o $@

time.exe: work_with_file.o bubble_sort.o time.o
	$(CC) $^ -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.exe
