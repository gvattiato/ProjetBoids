
all: main

main: main.cpp Vector.o Agent.o Prey.o Sky.o bwindow.o
	g++ -Wall -o main main.cpp Vector.o Agent.o Prey.o Sky.o bwindow.o -lX11 -L/usr/X11/lib

Vector.o: Vector.cpp Vector.h
	g++ -Wall -c -o Vector.o Vector.cpp

Agent.o: Agent.cpp Agent.h
	g++ -Wall -c -o Agent.o Agent.cpp

Prey.o: Prey.cpp Prey.h 
	g++ -Wall -c -o Prey.o Prey.cpp 

Sky.o: Sky.cpp Sky.h
	g++ -Wall -c -o Sky.o Sky.cpp

bwindow.o: bwindow.cpp bwindow.h 
	g++ -c bwindow.cpp -I/usr/X11/include

clean:
	rm *.o

mrproper: clean
	rm main
