/*
*	Problem : SHORTEST REMAINING TIME FIRST SCHDEULING 
*	Author: PHI(φ) = SIMARJEET_2022UCM2327
*	Created: 18.03.2024 22:40:35 (GMT+5:30)
*/
#include<bits/stdc++.h>
using namespace std;
 
#define SIMAR ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pii pair<int,int> 
#define F first 
#define S second 
/*
    pair<pii , pii > 
    F.F = ID 
    F.S = Arrival Time 
    S.F = Burst Time 
    S.S = Remaining Time 
*/
struct mycom{
    bool operator()(const pair<pii,pii> &a , const pair<pii,pii> &b) const{
    return a.S.S < b.S.S ; 
    }
} ;

void solve() {
    int n , c = 0 , p = 0 ;
    cout <<"*******SHORTEST REMAINING TIME FIRST*******\n" ;
    cout <<"Enter Number of Processes : " ;
    cin >> n ;
    vector<pair<pii,pii>> v(n) ;
    vector<pii> ans ; 
    for(int i = 0 ; i < n ; ++i){
        cout <<"Enter the arrival time : " ;
        cin >> v[i].F.S;
        v[i].F.F = i + 1 ;
        cout << "Enter the burst time : " ;
        cin >> v[i].S.F ; 
        v[i].S.S = v[i].S.F ; 
    }
    sort(v.begin(),v.end(),[](const pair<pii,pii>  &a , const pair<pii,pii> &b){
        return a.F.S < b.F.S ; //SORT BASED ON ARRIVAL TIME
    }) ;
    int t= 0   ;
    multiset<pair<pii,pii>,mycom> s ; //PQ FOR GETTING SMALLEST REMAINING TIME 
    while( p < n or !s.empty()){
        while(!v.empty() and v.front().F.S <= t){
            s.insert(v.front()) ;
            v.erase(v.begin()) ;
        }
        
        if(!s.empty()){
            auto curr = *s.begin() ; 
            s.erase(s.begin()) ; 
            
            --curr.S.S ; 
            if(curr.S.S==0){
                ans.push_back({curr.F.F , t + 1}) ; 
                ++p ; 
            }
            else s.insert(curr) ; 
        }
        ++t ;
    } 
    
    cout << "\n**Completion Times**\n" ;
    for(auto &x : ans){
        cout << "PROCESS - ID P" << x.F <<" " << x.S <<"\n" ; 
    }
    return ;
}

signed main() {
    //SIMAR;
    solve() ;
    return 0;
}

/*
Sample INPUT : 
n = 5 
AT  CT
2   6
5   2
1   8
0   3
4   4
answer : 
P1 - 15
P2 - 7
P3 - 23
P4 - 3
P5 - 10
*/