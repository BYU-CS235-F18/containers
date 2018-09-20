#include <iostream>
#include <queue>
#include <string>
#include <ctime>
using namespace std;
int main()
{
    queue<string> mystrings;
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
    cout << "queue pushes took "<<seconds<<endl;

   // Pop them all
    oldtime = clock(); 
    while(!mystrings.empty()) {
      mystrings.pop();
    }
    newtime = clock();
    seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
    cout << "queue pops took "<<seconds<<endl;
}
