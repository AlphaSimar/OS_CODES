/*
*	Problem : InterProcess Communication (IPC)
*	Author: PHI(φ) = SIMARJEET_2022UCM2327
*	Created: 19.03.2024 00:30:35 (GMT+5:30)
*/
#include <unistd.h> // for fork()
#include <bits/stdc++.h> 
#include <fcntl.h> // for O_* constant
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h> // for print error message
using namespace std ;

#define NAMED_PIPE "/var/lock/pipename"

// shared data struct
struct message {
    int pid ,  counter;
} ; 

#define SIMAR ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

signed main() {
    //SIMAR;
    // create the named pipe (fifo) with permission
    int ret = mkfifo(NAMED_PIPE, 0666);
    if (ret < 0)
        cerr << "Error when creating FIFO.\n" ;
    // create a child process by calling folk,
    pid_t pid = fork();
    //--- the parent process will write to the pipe only
    if (pid != 0) {
        int fd = open(NAMED_PIPE, O_WRONLY);
        for(int i =0 ; i < 5 ; ++i) {
            message msg;
            msg.pid = pid;
            msg.counter = i;
            cout << "Process " << pid << ": Write " << i << ".\n";
            ret = write(fd, &msg, sizeof(msg));
            if (ret < 0)
                cout << "Process " << pid << ": Error while writing message. " << strerror(errno) << endl;
            usleep(100000); // 0.1 second sleep
        }
        close(fd);
    } else {//-- child process will read only
        int fd = open(NAMED_PIPE, O_RDONLY);
        for(int i = 0 ;i < 5 ; ++i) {
            message msg;
            ret = read(fd, &msg, sizeof(msg));
            if (ret < 0)
                cout << "Process " << pid << ": Error while reading message. " << strerror(errno) << endl;
            cout << "Process " << pid << ": Received value " << msg.counter << " from the parent process " << msg.pid << ".\n";
            usleep(100000); // 0.1 second sleep
        }
        close(fd);
    }

    unlink(NAMED_PIPE);
 
    return 0;
}