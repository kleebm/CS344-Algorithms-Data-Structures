linkedlist: linkedlist.o main.o
	g++ linkedlist.o main.o -o linkedlist
main.o: main.cpp
	g++ -c main.cpp
linkedlist.o: linkedlist.h linkedlist.cpp
	g++ -c linkedlist.cpp
clean:
	rm *.o linkedlist
