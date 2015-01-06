
all: main

main: main.cpp Vector.o Agent.o Prey.o
	g++ -Wall -o main main.cpp Vector.o Agent.o Prey.o

Vector.o: Vector.cpp Vector.h
	g++ -Wall -c -o Vector.o Vector.cpp

Agent.o: Agent.cpp Agent.h
	g++ -Wall -c -o Agent.o Agent.cpp

Prey.o: Prey.cpp Prey.h 
	g++ -Wall -c -o Prey.o Prey.cpp 

clean:
	rm *.o

mrproper: clean
	rm main
