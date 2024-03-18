/*
*	Problem : THREAD PROGRAMMING 
*	Author: PHI(φ) = SIMARJEET_2022UCM2327
*	Created: 18.03.2024 23:23:12 (GMT+5:30)
*/
#include<bits/stdc++.h>
#include<thread>
using namespace std;
 
#define SIMAR ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void thread_function() {

    cout << "thread_function 1 -> thread :  Thread created successfully and is currently running Thread ID " << this_thread::get_id() << '\n';
}

void thread_function2() {
    cout <<"thread_function 2-> thread :  Thread created successfully and is currently running Thread ID " << this_thread::get_id() << '\n';
}

signed main() {
    //SIMAR;
    thread t1(&thread_function) ;  //Thread t starts running 
    cout << "main_function -> main_thread with Thread ID : " << this_thread::get_id() << '\n';
    t1.join() ; // main thread waits for thread t to finish
    thread t2(&thread_function2);
    t2.join() ;
    cout << "Number of threads running : " << thread::hardware_concurrency() ; //provides the suggestion for the number of threads
    t1.detach() ;
    t2.detach() ;
    return 0;
}

/*
Compile using : g++ Threads1.cpp -o t1 -std=c++11 -pthread && ./t1 
*/