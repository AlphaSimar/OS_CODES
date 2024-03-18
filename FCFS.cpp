/*
*	Problem : FCFS Scheduling 
*	Author: PHI(φ) = SIMARJEET_2022UCM2327
*	Created: 18.03.2024 21:59:00 (GMT+5:30)
*/
#include<bits/stdc++.h>
using namespace std;
 
#define SIMAR ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

struct Process {
    int idx , at , bt , ct ;
    //PROCESS_ID , ARRIVAL TIME , BURST TIME , COMPLETION TIME 
    Process() : ct(0) {}
}; 

void solve() {
    cout <<"*********FIRST  COME FIRST SERVE SCHEDULING*********\n" ;
    int n ;
    cout <<"Enter number of Processes : " ;
    cin >> n ; 
    vector<Process> v(n) ; 
   
    for(int i = 0 ; i < n ; ++i)  {
        v[i].idx = i + 1 ; 
        cout <<"Enter Arrival Time of Process P" << i +1 <<": " ;
        cin >> v[i].at ; 
       cout <<"Enter Burst Time of Process P" << i +1 <<": " ;
        cin >> v[i].bt ;
    }
    sort(v.begin() , v.end() , [](const Process &p1 , const Process &p2) {
        return p1.at < p2.at ; 
    }) ;
    int time = 0 ;
    for(Process &p : v) {
        if(time >= p.at) {
            p.ct = time + p.bt ;
            time = p.ct ;
        } else {
            p.ct = p.at + p.bt ;
            time = p.ct ;
        }
    }
    cout <<"THE COMPLETION TIMES ARE : \n" ;
    for(Process &i : v) {
        cout <<"PROCESS - ID " << i.idx <<" " << i.ct << '\n' ;
    }

    return ;
}

signed main() {
  //  SIMAR;
    solve() ;
    return 0;
}
