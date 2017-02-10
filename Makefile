CFLAGS=-std=c++11 -g

all: vector list stack

vector: vector.cpp 
	g++ $(CFLAGS) vector.cpp -o vector
	
list: list.cpp 
	g++ $(CFLAGS) list.cpp -o list

stack: stack.cpp 
	g++ $(CFLAGS) stack.cpp -o stack