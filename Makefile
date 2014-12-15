
all: main

main: main.cpp Agent.o Prey.o
	g++ -Wall -o main main.cpp Agent.o Prey.o

Agent.o: Agent.cpp Agent.h
	g++ -Wall -c -o Agent.o Agent.cpp

Prey.o: Prey.cpp Prey.h 
	g++ -Wall -c -o Prey.o Prey.cpp 

clean:
	rm *.o

mrproper: clean
	rm main
