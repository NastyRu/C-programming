CC := gcc

CFLAGS := -std=c99 -Wall -Werror -pedantic

app.exe: work_with_file.o action_with_matrix.o main.o
	$(CC) $^ -o $@

test.exe: work_with_file.o action_with_matrix.o test.o
	$(CC) $^ -o $@

rand.exe: rand_matrix.o
	$(CC) $^ -o $@
	chmod +x revert.py	

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.exe
