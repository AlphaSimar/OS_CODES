#include <bits/stdc++.h>
using namespace std;

// Arrival Time, Burst Time, Waiting Time, Turn-Around Time, Response Time, Completion Time.
struct Process {
    string name;
    int AT, BT, WT, TAT, RT, CT;
};

int n;

void sortByArrival(Process Q1[]) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) 
            if (Q1[i].AT > Q1[j].AT)
                swap(Q1[i], Q1[j]);
}

signed main() {

    int time_quanta1 = 5, time_quanta2 = 8;
    int k = 0, r = 0, time = 0, flag = 0;
    char c;
    cout << "Enter No. Of Processes: ";
    cin >> n;
    Process Q1[n], Q2[n], Q3[n];
    for(int i = 0, c = 'A'; i < n; i++, c++) {
        Q1[i].name = c;
        cout << "Enter The Arrival Time And Burst Time Of Process " << Q1[i].name << ": ";
        cin >> Q1[i].AT >> Q1[i].BT;
        Q1[i].RT = Q1[i].BT;
    }
    sortByArrival(Q1);
    time = Q1[0].AT;
    cout << "Processes In The First Queue Following RR With Time Quanta = 5" << endl;
    cout << "Process\t\tRT\t\tWT\t\tTAT" << endl;
    for (int i = 0; i < n; i++) {
        if (Q1[i].RT <= time_quanta1) {
            time += Q1[i].RT;
            Q1[i].RT = 0;
            Q1[i].WT = time - Q1[i].AT - Q1[i].BT;
            Q1[i].TAT = time - Q1[i].AT;
            cout << Q1[i].name << "\t\t" << Q1[i].BT << "\t\t" << Q1[i].WT << "\t\t" << Q1[i].TAT << endl;
        } else {
            Q2[k].WT = time;
            time += time_quanta1;
            Q1[i].RT -= time_quanta1;
            Q2[k].BT = Q1[i].RT;
            Q2[k].RT = Q2[k].BT;
            Q2[k].name = Q1[i].name;
            ++k , flag = 1 ; 
        }
    }
    if (flag == 1) {
        cout << "Processes In The Second Queue Following RR With Time Quanta = 8" << endl;
        cout << "Process\t\tRT\t\tWT\t\tTAT" << '\n';
    }
    for (int i = 0; i < k; i++) {
        if (Q2[i].RT <= time_quanta2) {
            time += Q2[i].RT;
            Q2[i].RT = 0;
            Q2[i].WT = time - time_quanta1 - Q2[i].BT;
            Q2[i].TAT = time - Q2[i].AT;
            cout << Q2[i].name << "\t\t" << Q2[i].BT << "\t\t" << Q2[i].WT << "\t\t" << Q2[i].TAT << endl;
        } else {
            Q3[r].AT = time;
            time += time_quanta2;
            Q2[i].RT -= time_quanta2;
            Q3[r].BT = Q2[i].RT;
            Q3[r].RT = Q3[r].BT;
            Q3[r].name = Q2[i].name;
            ++r , flag = 2 ;
        }
    }
    if (flag == 2) {
        cout << "Processes In The Third Queue Following FCFS" << endl;
        cout << "Process\t\tBT\t\tWT\t\tTAT" << endl;
    }
    for (int i = 0; i < r; i++) {
        if (i == 0)
            Q3[i].CT = Q3[i].BT + time - time_quanta1 - time_quanta2;

        else
            Q3[i].CT = Q3[i - 1].CT + Q3[i].BT;

        Q3[i].TAT = Q3[i].CT;
        Q3[i].WT = Q3[i].TAT - Q3[i].BT;

        cout << Q3[i].name << "\t\t" << Q3[i].BT << "\t\t" << Q3[i].WT << "\t\t" << Q3[i].TAT << endl;
    }

    return 0;
}
