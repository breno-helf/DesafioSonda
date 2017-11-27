all: sonda

sonda: Sonda.cpp
	g++ -Wall -Wshadow Sonda.cpp -o sonda
	make clean

clean:
	-rm -f *.o *~
