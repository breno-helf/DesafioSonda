FLAGS = -Wall -Wshadow -std=c++11

OBJS = sonda.o robot.o grid.o

all: sonda test

.PHONY: clean

sonda: $(OBJS)
	g++ $(FLAGS) $^ -o $@
	make clean

test: test.o robot.o grid.o
	g++ $(FLAGS) $^ -o $@
	make clean

%.o: %.cpp %.hpp
	g++ $(FLAGS) -c $< -o $@

%.o: %.cpp
	g++ $(CFLAGS) -c $< -o $@

clean:
	-rm -f *.o *~
