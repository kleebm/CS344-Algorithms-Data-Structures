circularlist: circularlist.o main.o
	g++ circularlist.o main.o -o circularlist
main.o: main.cpp
	g++ -c main.cpp
linkedlist.o: circularlist.h circularlist.cpp
	g++ -c circularlist.cpp
clean:
	rm *.o circularlist