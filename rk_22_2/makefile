app.exe: main.o stepen.o
	gcc -o app.exe stepen.c main.c

stepen.o: stepen.c
	gcc -c stepen.c

main.o: main.c
	gcc -c main.c

clean:
	rm *.o *.exe
