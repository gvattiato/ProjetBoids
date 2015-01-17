test.out: main.o bwindow.o
	g++ -o test.out main.o bwindow.o -lX11 -L/usr/X11/lib
main.o: main.cpp
	g++ -c main.cpp -I/usr/X11/include
bwindow.o: bwindow.cpp bwindow.h 
	g++ -c bwindow.cpp -I/usr/X11/include
clean :
	rm *.o *.out