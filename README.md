# Containers
You have already used a vector and a list, but there are also a number of other containers that you can use.  In this learning activity, you will experiment with several of these and compare their performance.

## Vectors
Lets get started with a little benchmark program that should drive vectors wild.  Lets try repeatedly inserting at the front of the vector.  Notice that insert takes an iterator as the first parameter, and we can pass it the begin() function to insert at the beginning of the vector.  
```c++
    vector<string> mystrings;
    int n = 40000; // The number of inserts 
    for(int i = 0; i < n; i++) {
        mystrings.insert(mystrings.begin(),"Hello");
    }
```
Get this code running and measure how long it takes to execute.  On my cloud9 with the -g option, it took 6.64 seconds.  Now lets try the same exact code except that we will insert at the back of the vector.  So, now the vector should allocate an array, and just fill it up until it runs out of space.  And it wont have to copy the data up into a different memory location.
```c++
    vector<string> mystrings;
    for(int i = 0; i < n; i++) {
        mystrings.insert(mystrings.end(),"Hello");
    }
```
This loop took 0.004 seconds or in other words, it ran almost 1600 times faster.  So, picking the right data structure for your application can make a big difference.

## Linked Lists
Lets try the same thing with linked lists.
```c++
    list<string> mystrings;
    int n = 40000; // The number of inserts
    for(int i = 0; i < n; i++) {
        mystrings.insert(mystrings.begin(),"Hello");
    }
```
Notice that the only thing we had to change was the type of container.  On my cloud9, it took about 0.005 seconds to insert at the beginning and 0.003 seconds to insert at the end of the list.  So, it is about as fast as inserting at the end of the vector.  If we bump the number of inserts "n" up to 100 times as much (4000000), then the insert at the beginning takes about 1.48 seconds and inserting at the end takes 1.06 seconds.  We should normally not trust time measurements that take less than a second, so this gives us a better feel for the comparative time for each operation.

So, not lets look at a problem that should drive lists crazy.  How about looking up an element in the middle of the container.  A vector can just index into the array, but the list will have to follow next links to get to the correct offset.  First lets measure the time to access a member in the middle of the vector 40,000,000 times.  This took 0.9 seconds on my Cloud9 instance.  The advance() function moves an iterator ahead the given number of steps through the container.
```c++
    vector<string> mystrings;
    string value;
    for(int i = 0; i < n; i++) {
        vector<string>::iterator middle = mystrings.begin();
        advance(middle,n/2);
        value = *middle;
    } 
```
Now lets look at accessing a item out of the middle of a list.  The code is almost exactly the same, but 40,000 iterations takes 4.8 seconds.  The list takes almost 10,000 times as long as accessing an element in the middle of a vector.

```c++
    list<string> mystrings;
    string value;
    for(int i = 0; i < n; i++) {
        list<string>::iterator middle = mystrings.begin();
        advance(middle,n/2);
        value = *middle;
    }
```
## Stacks
You havent used a stack before, but lets look at how we would use a stack.  The only operations on a stack are push and pop, but 4,000,000 pushes took 0.44 seconds on my Cloud9, so it appears that the stack is faster than a vector, but slower than a list.  You will need to use a stack for lab #3.
```c++
    stack<string> mystrings;
    for(int i = 0; i < n; i++) {
        mystrings.push("Hello");
    }
```

