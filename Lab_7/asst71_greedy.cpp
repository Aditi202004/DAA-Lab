#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(int n, string* items, vector<vector<int>> k, int W){
    for(int i = 0; i < n; i++){
        k[i][3] = k[i][1] / k[i][2];
    }
    sort(k.begin(), k.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[3] > b[3];
    });

    // for(int i = 0; i < n; i++){
    //     cout << items[k[i][0]] << endl;
    // }

    int curr_wt = 0;
    int final_val = 0;
    for(int i = 0; i < n; i++){
        if(curr_wt + k[i][1] <= W){
            curr_wt += k[i][1];
            final_val += k[i][2];
            cout << items[k[i][0]] << " ";
        }
    }
    cout << endl << final_val << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1_greedy.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        string *items = new string[n];
        vector<vector<int>> knapsack(n, vector<int>(4));
        // (index, weights, vals, ratio)
        for (int i = 0; i < n; i++){
            knapsack[i][0] = i;
            cin >> items[i];
        }
        for (int i = 0; i < n; i++){
            cin >> knapsack[i][1];
        }
        for (int i = 0; i < n; i++){
            cin >> knapsack[i][2];
        }
        int W; cin >> W;
        solution(n, items, knapsack, W);
    }
    return 0;
}