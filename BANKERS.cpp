#include<bits/stdc++.h>
using namespace std;

#define P 4
#define R 3
int total = 0;

// Check Allocation Of Resource.

bool is_available(int process_id, int allocated[][R], int max[][R], int need[][R], int available[]) {
    bool flag = true;
    for (int i = 0; i < R; i++) {
        if (need[process_id][i] > available[i])
            flag = false;
    }
    return flag;
}

// Find All Safe Sequences Using Recursion.

void safe_sequence (bool marked[], int allocated[][R], int max[][R], int need[][R], int available[], vector<int> safe) {
    for (int i = 0; i < P; i++) {
        if (!marked[i] && is_available(i, allocated, max, need, available)) {
            marked[i] = true;
            for (int j = 0; j < R; j++)
                available[j] += allocated[i][j];
            safe.push_back(i); 
            safe_sequence(marked, allocated, max, need, available, safe); 
            safe.pop_back(); 
            marked[i] = false;
            for (int j = 0; j < R; j++)
                available[j] -= allocated[i][j];
        }
    }
    if (safe.size() == P) {
        total++;
        for (int i = 0; i < P; i++) {
            cout << "P" << safe[i] + 1;
            if (i != (P - 1)) cout << "--> ";
        }
        cout << endl;
    }
}

int main() {
    // Allocation Matrix (P X R).
    int allocated[P][R] = { { 0, 1, 0 },
                            { 2, 0, 0 },
                            { 3, 0, 2 },
                            { 2, 1, 1 } };
    // Maximum Matrix (P X R).
    int max[P][R] = { { 7, 5, 3 },
                    { 3, 2, 2 },
                    { 9, 0, 2 },
                    { 2, 2, 2 } };
    int resources[R] = {10, 5, 7};
    int available[R];
    for (int i = 0; i < R; i++) {
        int sum = 0;
        for (int j = 0; j < P; j++)
            sum += allocated[j][i];
        available[i] = resources[i] - sum;
    }
    vector<int> safe;
    bool marked[P];
    memset (marked, false, sizeof(marked));
    // Need Matrix (P X R).
    int need[P][R];
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - allocated[i][j];
    cout << "Safe Sequences Are:" << endl;
    safe_sequence(marked, allocated, max, need, available, safe);
    cout << "\nThere Are Total " << total << " Safe-Sequences" << endl;
    return 0;
}
