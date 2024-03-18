#include<bits/stdc++.h>
#include <thread>
#include<atomic>
using namespace std ;

atomic<int> turn, ans;
atomic<bool> flag[2];

void lock_init() {
    flag[0] = false;
    flag[1] = false;
    turn = 0;
    ans = 0;
}

void lock(int self) {
    flag[self] = true;
    turn = 1 - self;
    while (flag[1 - self] && turn == 1 - self);
}

void unlock(int self) {
    flag[self] = false;
}

void func(int self) {
    cout << "Thread " << self << " in queue for critical section\n";
    lock(self);
    cout << "Thread " << self << " entered critical section\n";
    for (int i = 0; i < (int)1e8 ; i++)
        ans++;
    cout << "Thread " << self << " completed executing\n";
    cout << "Thread " << self << " is exiting critical section\n";
    unlock(self);
}

int main() {
    thread p1(func, 0);
    thread p2(func, 1);
    lock_init();
    p1.join();
    p2.join();
    cout << "Exiting main()\n";
    return 0;
}
