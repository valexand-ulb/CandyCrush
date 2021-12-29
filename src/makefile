FLAGS=--std='c++20' -Wall -Wextra -Wpedantic -lfltk

all:CandyCrush

CandyCrush: main.o Matrice.o Cell.o Item.o Position.o Mainwindow.o Canvas.o BasicShape.o Functionable.o Point.o
	g++ -o CandyCrush main.o Matrice.o Cell.o Item.o Position.o Mainwindow.o Canvas.o BasicShape.o Functionable.o Point.o -lfltk
Cell.o: logic/Cell.h logic/Cell.cpp
	g++ $(FLAGS) -c logic/Cell.cpp -o Cell.o
Item.o: logic/Item.h logic/Item.cpp
	g++ $(FLAGS) -c logic/Item.cpp -o Item.o
Position.o: logic/Position.h logic/Position.cpp
	g++ $(FLAGS) -c logic/Position.cpp -o Position.o
Matrice.o: logic/Matrice.h logic/Matrice.cpp
	g++ $(FLAGS) -c logic/Matrice.cpp -o Matrice.o

Point.o: gui/Point.h gui/Point.cpp
	g++ $(FLAGS) -c gui/Point.cpp -o Point.o
BasicShape.o: gui/BasicShapes.h gui/BasicShapes.cpp
	g++ $(FLAGS) -c gui/BasicShapes.cpp -o BasicShape.o
Functionable.o: gui/Functionable.h gui/Functionable.cpp
	g++ $(FLAGS) -c gui/Functionable.cpp -o Functionable.o
Canvas.o: gui/Canvas.h gui/Canvas.cpp
	g++ $(FLAGS) -c gui/Canvas.cpp -o Canvas.o
Mainwindow.o: gui/Mainwindow.h gui/Mainwindow.cpp
	g++ $(FLAGS) -c gui/Mainwindow.cpp -o Mainwindow.o

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp -o main.o

clear:
	rm *.o

