#include <iostream>
#include <deque>
#include <string>
#include <ctime>
using namespace std;
int main()
{
    deque<string> mystrings;
    int n = 40000; // The number of inserts
    clock_t oldtime, newtime;
    double seconds;
    
    // First insert at the beginning
    oldtime = clock(); 
    for(int i = 0; i < n; i++) {
        mystrings.insert(mystrings.begin(),"Hello");
    }
    newtime = clock();
    seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
    cout << "deque inserts begin took "<<seconds<<endl;
    mystrings.clear();
    
    // Now insert at the end
    oldtime = clock(); 
    for(int i = 0; i < n; i++) {
        mystrings.insert(mystrings.end(),"Hello");
    }
    newtime = clock();
    seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
    cout << "deque inserts end took "<<seconds<<endl;
    
    // Now retrieve from the middle
    oldtime = clock(); 
    string value;
    for(int i = 0; i < n*1000; i++) {
        deque<string>::iterator middle = mystrings.begin();
        advance(middle,n/2);
        value = *middle;
    }
    newtime = clock();
    seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
    cout << "deque get from middle took "<<seconds<<endl;
    
}

