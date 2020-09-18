all:	main

main:	main.o
	g++ main.o -o main.exe

main.o: main.cpp
	g++ -c main.cpp

clean:	
	rm -f *.o main.exe
