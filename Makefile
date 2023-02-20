all: build
delete:
	rm -f main
build:
	g++ chess.cpp board.cpp piece.cpp game.cpp debug.cpp roles.cpp -o main
run:
	./main