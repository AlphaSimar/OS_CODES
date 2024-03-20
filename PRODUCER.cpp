#include <bits/stdc++.h>
using namespace std;

int mutex = 1, full = 0, emp = 3, x = 0;

int wait(int);
int signal(int);
void producer();
void consumer();

int main() {
    int n;
    cout << "\n1.Producer\n2.Consumer\n3.Exit" << endl;
    while (true) {
        cout << "\nEnter Your Choice : ";
        cin >> n;
        switch (n) {
            case 1:
                if ((mutex == 1) and (emp != 0))
                    producer();
                else
                    cout << "Buffer Is Full !!" << endl;
                break;
            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    cout << "Buffer Is Empty !!" << endl;
                break;
            case 3:
                exit(0);
                break;
            default:
                cout << "Invalid Choice Entered !!" << endl;
                break;
        }
    }
    return 0;
}

int wait(int s) {
    return (--s);
}

int signal(int s) {
    return (++s);
}

void producer() {
    mutex = wait(mutex);
    full = signal(full);
    emp = wait(emp);
    ++x ; 
    cout << "\nProducer Produces The Item " << x << endl;
    mutex = signal(mutex);
}
void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    emp = signal(emp);
    cout << "\nConsumer Consumes The Item " << x << endl;
    --x ;
    mutex = signal(mutex);
}


#include <bits/stdc++.h>
using namespace std;

int mutex = 1, full = 0, emp = INT_MAX, x = 0;

int wait(int);
int signal(int);
void producer();
void consumer();

int main() {
    int n;
    cout << "\n1.Producer\n2.Consumer\n3.Exit" << endl;
    while (true) {
        cout << "\nEnter Your Choice : ";
        cin >> n;
        switch (n) {
            case 1:
                if ((mutex == 1) and (emp != 0))
                    producer();
                else
                    cout << "Buffer Is Full !!" << endl;
                break;
            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    cout << "Buffer Is Empty !!" << endl;
                break;
            case 3:
                exit(0);
                break;
            default:
                cout << "Invalid Choice Entered !!" << endl;
                break;
        }
    }
    return 0;
}

int wait(int s) {
    return (--s);
}

int signal(int s) {
    return (++s);
}

void producer() {
    mutex = wait(mutex);
    full = signal(full);
    emp = wait(emp);
    x++;
    cout << "\nProducer Produces The Item " << x << endl;
    mutex = signal(mutex);
}

void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    emp = signal(emp);
    cout << "\nConsumer Consumes The Item " << x << endl;
    x--;
    mutex = signal(mutex);
}
