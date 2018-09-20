CFLAGS=-std=c++11

all: vector list stack queue deque

vector: vector.cpp 
	g++ $(CFLAGS) vector.cpp -o vector
	
list: list.cpp 
	g++ $(CFLAGS) list.cpp -o list

stack: stack.cpp 
	g++ $(CFLAGS) stack.cpp -o stack

queue: queue.cpp 
	g++ $(CFLAGS) queue.cpp -o queue

deque: deque.cpp 
	g++ $(CFLAGS) deque.cpp -o deque

clean:
	rm -f vector
	rm -f list
	rm -f stack
	rm -f queue
	rm -f deque
