#include <iostream>
#include <stack>
#include <string>
#include <ctime>
using namespace std;
int main()
{
    stack<string> mystrings;
    int n = 4000000; // The number of inserts
    clock_t oldtime, newtime;
    double seconds;
    
    // First insert at the beginning
    oldtime = clock(); 
    for(int i = 0; i < n; i++) {
        mystrings.push("Hello");
    }
    newtime = clock();
    seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
    cout << "stack pushs took "<<seconds<<endl;

    
    
}

