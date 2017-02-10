# containers
You have already used a vector and a list, but there are also a number of other containers that you can use.  In this learning activity, you will experiment with several of these and compare their performance.

## vectors
Lets get started with a little benchmark program that should drive vectors wild.  Lets try repeatedly inserting at the front of the vector.  Notice that insert takes an iterator as the first parameter, and we can pass it the begin() function to insert at the beginning of the vector.  
```c++
    vector<string> mystrings;
    int n = 40000; // The number of inserts
    clock_t oldtime, newtime;
    double seconds;
    oldtime = clock(); 
    for(int i = 0; i < n; i++) {
        mystrings.insert(mystrings.begin(),"Hello");
    }
    newtime = clock();
    seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
    cout << "vector inserts begin took "<<seconds<<endl;
```
Get this code running and measure how long it takes to execute.  On my cloud9 with the -g option, it took 6.64 seconds.  Now lets try the same exact code except that we will insert at the back of the vector.  So, now the vector should allocate an array, and just fill it up until it runs out of space.  And it wont have to copy the data up into a different memory location.
```c++
    oldtime = clock(); 
    for(int i = 0; i < n; i++) {
        mystrings.insert(mystrings.end(),"Hello");
    }
    newtime = clock();
    seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
    cout << "vector inserts begin took "<<seconds<<endl;
    
```
This loop took 0.004 seconds or in other words, it ran almost 1600 times faster.  So, picking the right data structure for your application can make a big difference.

Lets try the same thing with linked lists.
