tree: main.o avl.o
	g++ main.o avl.o -o tree
main.o: main.cpp
	g++ -c main.cpp
avl.o: avl.h avl.cpp
	g++ -c avl.h avl.cpp
clean:
	rm *.o tree avl.h.gch
