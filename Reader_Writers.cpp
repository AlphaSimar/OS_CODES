#include <semaphore.h>
#include <pthread.h>
#include<bits/stdc++.h>
using namespace std;
 
#define SIMAR ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

sem_t wrt;
pthread_mutex_t mutex_lock; // Renamed from mutex
int cnt = 1;
int numreader = 0;

void *writer(void *wno) {   
    sem_wait(&wrt);
    cnt = cnt * 2;
    cout << "Writer " << (*((int *)wno)) << " modified cnt to " << cnt << '\n';
    sem_post(&wrt);
    return nullptr;
}

void *reader(void *rno){   
    // Reader acquires the lock before modifying numreader
    pthread_mutex_lock(&mutex_lock); // Renamed from mutex
    numreader++;
    if(numreader == 1) 
        sem_wait(&wrt); // If this is the first reader, then it will block the writer

    pthread_mutex_unlock(&mutex_lock);
    
    // Reading Section
    cout << "Reader " << (*((int *)rno)) << ": read cnt as " << cnt << '\n';

    // Reader acquires the lock before modifying numreader
    pthread_mutex_lock(&mutex_lock); // Renamed from mutex
    --numreader;
    if (numreader == 0) 
        sem_post(&wrt); // If this is the last reader, it will wake up the writer
    
    pthread_mutex_unlock(&mutex_lock);
    return nullptr;
}

int main(){   
    pthread_t read[10], write[5];
    pthread_mutex_init(&mutex_lock, NULL); // Renamed from mutex
    sem_init(&wrt, 0, 1);

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 

    for (int i = 0; i < 10; ++i)
    pthread_create(&read[i], NULL, reader, reinterpret_cast<void *>(&a[i]));

for (int i = 0; i < 5; ++i )
    pthread_create(&write[i], NULL, writer, reinterpret_cast<void *>(&a[i]));


    for (int i = 0; i < 10; ++i) 
        pthread_join(read[i], NULL);
    
    for (int i = 0; i < 5; ++i) 
        pthread_join(write[i], NULL);
    
    pthread_mutex_destroy(&mutex_lock); // Renamed from mutex
    sem_destroy(&wrt);
    return 0;
}
