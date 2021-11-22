FLAGS=--std='c++20' -Wall -Wextra -Wpedantic -lfltk

all:CandyCrush

CandyCrush: main.o Matrice.o Cell.o Item.o Position.o
	g++ main.o Matrice.o Cell.o Item.o Position.o -o CandyCrush

Cell.o: Cell.h Cell.cpp
	g++ $(FLAGS) -c Cell.cpp -o Cell.o
Item.o: Item.h Item.cpp
	g++ $(FLAGS) -c Item.cpp -o Item.o
Position.o: Position.h Position.cpp
	g++ $(FLAGS) -c Position.cpp -o Position.o
Matrice.o: Matrice.h Matrice.cpp
	g++ $(FLAGS) -c Matrice.cpp -o Matrice.o
main.o: main.cpp
	g++ $(FLAGS) -c main.cpp -o main.o
clear:
	rm *.o