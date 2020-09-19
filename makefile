pham_p1:	pham_p1.o
	g++ pham_p1.o -o pham_p1.exe

pham_p1.o:	pham_p1.cpp
	g++ -c pham_p1.cpp

clean:	
	rm -f *.o pham_p1.exe
