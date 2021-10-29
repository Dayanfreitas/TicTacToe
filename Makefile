all: display.o
	gcc display.o main.c -o tictactoe

display.o: 
	gcc -c display.c

test:
	make -C test

clean:
	rm -rf *.o

run:
	./tictactoe
