stack: stack.o main.o
	g++ stack.o main.o -o stack
stack.o: stack.h stack.cpp
	g++ stack.cpp -c
main.o: main.cpp
	g++ main.cpp -c
clean:
	rm *.o stack
