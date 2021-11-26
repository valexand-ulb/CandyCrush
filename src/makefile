FLAGS=--std='c++20' -Wall -Wextra -Wpedantic -lfltk

all:CandyCrush

CandyCrush: main.o Matrice.o Cell.o Item.o Position.o
	g++ main.o Matrice.o Cell.o Item.o Position.o -o CandyCrush

Cell.o: logic/Cell.h logic/Cell.cpp
	g++ $(FLAGS) -c logic/Cell.cpp -o Cell.o
Item.o: logic/Item.h logic/Item.cpp
	g++ $(FLAGS) -c logic/Item.cpp -o Item.o
Position.o: logic/Position.h logic/Position.cpp
	g++ $(FLAGS) -c logic/Position.cpp -o Position.o
Matrice.o: logic/Matrice.h logic/Matrice.cpp
	g++ $(FLAGS) -c logic/Matrice.cpp -o Matrice.o
main.o: main.cpp
	g++ $(FLAGS) -c main.cpp -o main.o
clear:
	rm *.o