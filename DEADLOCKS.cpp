#include <iostream>
using namespace std;

int arrmax[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;

void input() {
    cout << "Enter No. Of  Processes\n";
    cin >> n;
    cout << "Enter The No. Of Resources Instances\n";
    cin >> r;
    cout << "Enter The Max Matrix\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) 
            cin >> arrmax[i][j];
    }
    cout << "Enter The Allocation Matrix\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++)
            cin >> alloc[i][j];
    }
    cout << "Enter The Available Resources\n";
    for (int j = 0; j < r; j++)
        cin >> avail[j];
}

void show() {
    cout << "Process\t Allocation\t Max\t Available\t";
    for (int i = 0; i < n; i++) {
        cout << "\nP" << i + 1 << "\t ";
        for (int j = 0; j < r; j++)
            cout << alloc[i][j] << " ";
        cout << "\t\t";
        for (int j = 0; j < r; j++)
            cout << arrmax[i][j] << " ";
        cout << "\t ";
        if (i == 0) {
            for (int j = 0; j < r; j++)
                cout << avail[j] << " ";
        }
    }
}

void cal() {
    int finish[100], temp, flag = 1, k, c1 = 0;
    int dead[100];
    int safe[100];
    int i, j;
    for (i = 0; i < n; i++)
        finish[i] = 0;

    // Compute Need Matrix.

    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++)
            need[i][j] = arrmax[i][j] - alloc[i][j];
    }

    while (flag) {
        flag = 0;
        for (i = 0; i < n; i++) {

            int c = 0;

            for (j = 0; j < r; j++) {

                if ((finish[i] == 0) && (need[i][j] <= avail[j])) {

                    c++;

                    if (c == r) {

                        for (k = 0; k < r; k++) {

                            avail[k] += alloc[i][j];
                            finish[i] = 1;
                            flag = 1;
                        }

                        if (finish[i] == 1)
                            i = n;
                    }
                }
            }
        }
    }
    j = 0;
    flag = 0;
    for (i = 0; i < n; i++) {
        if (finish[i] == 0) {
            dead[j] = i;
            j++;
            flag = 1; }} 
    if (flag == 1) {
        cout << "\n\nSystem Is In Deadlock And The Deadlock Process Are: \n";
        for (i = 0; i < n; i++) 
            cout << "P" << dead[i] << "\t";
        cout << "."; } 
    else cout << "\nNo Deadlock Occurs."; }

int main() {
    cout << "**** Deadlock Detection Algorithm ****\n";
    input();
    show();
    cal();
    return 0;
}
