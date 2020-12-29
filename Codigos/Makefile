all: Mastermind

Mastermind: Implement.o Mastermind.o
	g++ -o Mastermind Mastermind.o Implement.o
 
Mastermind.o: Mastermind.cpp Implement.h
	g++ -o Mastermind.o Mastermind.cpp -c -Wall

Implement.o: Implement.cpp Implement.o
	g++ -o Implement.o Implement.cpp -c -Wall
 
clean:
	rm -rf *.o *~ Mastermind
