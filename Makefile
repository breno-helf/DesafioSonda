FLAGS = -Wall -Wshadow

OBJS = sonda.o robot.o grid.o

all: sonda

.PHONY: clean

sonda: $(OBJS)
	g++ $(FLAGS) $^ -o $@
	make clean

%.o: %.cpp %.hpp
	g++ $(FLAGS) -c $< -o $@

%.o: %.cpp
	g++ $(CFLAGS) -c $< -o $@

clean:
	-rm -f *.o *~
