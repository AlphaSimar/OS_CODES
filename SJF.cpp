/*
*	Problem : SHORTEST JOB FIRST 
*	Author: PHI(φ) = SIMARJEET_2022UCM2327
*	Created: 18.03.2024 22:30:07 (GMT+5:30)
*/
#include<bits/stdc++.h>
using namespace std;
 
#define SIMAR ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pii pair<int,int> 
#define F first 
#define S second 

void solve() {
    int n ;
    cout <<"*******SHORTEST JOB FIRST*******\n" ;
    cout <<"Enter Number of Processes : " ;
    cin >> n ;
    vector<pii> v(n) ;
    for(int idx = 0 ; idx < n ; ++idx){
        cout <<"Enter burst time for Process P" << idx+1 <<": " ;
        cin >> v[idx].S ;
        v[idx].F = idx + 1 ; 
    }
    sort(v.begin() , v.end() , [](const pii &p1 , const pii &p2) {
        return p1.S < p2.S ; 
    }) ;
    int time = 0 ; 
    cout <<"THE COMPLETION TIMES ARE : \n" ;
    for(auto &i : v) {
        time += i.S ; 
        cout << "PROCESS-ID" << i.F <<" " << time << '\n' ;
    }

    return ;
}

signed main() {
    //SIMAR;
    solve() ;
    return 0;
}