/*
*	Problem : PROCESS CREATIION AND TERMINATION -> fork() , getpid() , getppid()
*	Author: PHI(φ) = SIMARJEET_2022UCM2327
*	Created: 19.03.2024 00:14:30 (GMT+5:30)
*/
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
 
#define SIMAR ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


signed main() {
    //SIMAR;
    pid_t pid, mypid, myppid;
    pid = getpid();
    cout << "Before fork: Process id is " << pid << "\n";
    pid = fork();

    if (pid < 0) {
        perror("fork() failure\n");
        return 1;
    }

    // Child process
    if (pid == 0) {
        cout << "This is child process\n";
        mypid = getpid();
        myppid = getppid();
        cout << "Process id is " << mypid << " and PPID is " << myppid << "\n";
    } else { // Parent process 
        sleep(2);
        cout << "This is parent process\n";
        mypid = getpid();
        myppid = getppid();
        cout << "Process id is " << mypid << " and PPID is " << myppid << "\n";
        cout << "Newly created process id or child pid is " << pid << "\n";
    }
    exit(0) ;
}