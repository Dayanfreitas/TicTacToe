all: display.o evaluator.o
	gcc display.o evaluator.o main.c -o tictactoe

display.o: 
	gcc -c display.c

evaluator.o: 
	gcc -c src/evaluator.c

run-test:
	make -C test

clean:
	rm -rf *.o

run:
	./tictactoe
