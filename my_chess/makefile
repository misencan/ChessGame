GCC = g++
all: test
test: testing.o Piece.o Board.o
	$(GCC) testing.o Piece.o Board.o -o test
testing.o: testing.cpp
	$(GCC) -c testing.cpp
Piece.o: Piece.cpp
	$(GCC) -c Piece.cpp
Board.o: Board.cpp
	$(GCC) -c Board.cpp