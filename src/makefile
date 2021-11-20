FLAGS=-Wall -Wextra -Wpedantic -lfltk

all:CandyCrush

CandyCrush: Cell.o Item.o Position.o Matrice.o main.o
	g++ Cell.o Item.o Position.o Matrice.o main.o -o CandyCrush

Cell.o: Cell.cpp
	g++ $(FLAGS) -c Cell.cpp -o Cell.o
Item.o: Item.cpp
	g++ $(FLAGS) -c Item.cpp -o Item.o
Position.o: Position.cpp
	g++ $(FLAGS) -c Position.cpp -o Position.o
Matrice.o: Matrice.cpp
	g++ $(FLAGS) -c Matrice.cpp -o Matrice.o
main.o: main.cpp
	g++ $(FLAGS) -c main.cpp -o main.o

clear:
	rm *.o