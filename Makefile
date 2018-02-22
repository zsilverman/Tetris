# Zack Silverman 913618592

all: fill

CXXFLAGS=-g -Wall

Shape.o: Shape.cpp Shape.h
fill.o: fill.cpp Shape.h
Domain.o: Domain.cpp Domain.h

fill: fill.o Shape.o Domain.o
	$(CXX) -o $@ $^  $(LDFLAGS)

clean:
	rm -f *.o fill
