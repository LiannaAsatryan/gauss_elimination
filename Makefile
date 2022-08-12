main: a
	./a

a: Rational.o Rmatrix.o gauss.o
	g++ main.cpp Rational.o Rmatrix.o gauss.o -o a

all: test clean

test: target
	./target

target: Rational.o Rmatrix.o gauss.o
	g++ gauss_test.cpp Rational.o Rmatrix.o gauss.o -o target

Rational.o:
	g++ -c Rational.cpp -o Rational.o

Rmatrix.o: Rmatrix.cpp
	g++ -c Rmatrix.cpp -o Rmatrix.o

gauss.o: gauss.cpp
	g++ -c gauss.cpp -o gauss.o
clean: 
	 rm -f a target output.txt result.txt *.o

