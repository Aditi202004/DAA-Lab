#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <set>
using namespace std;

int knapsack_10(int i, int w, string* items, vector<vector<int>> k, vector<vector<int>> &dp, set<string> &to_include){
    // k(index, weights, vals, ratio)
    if(w < 0 || i < 0){
        return INT_MIN;
    }
    if(dp[i][w] != -1){
        return dp[i][w];
    }

    if(i == 0 || w == 0){
        return dp[i][w] == 0;
    }
    if(w < k[i-1][1]){
        return dp[i][w] = knapsack_10(i-1, w, items, k, dp, to_include);
    }

    return dp[i][w] = max(k[i - 1][2] + knapsack_10(i - 1, w - k[i - 1][1], items, k, dp, to_include), knapsack_10(i - 1, w, items, k, dp, to_include));

}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        string *items = new string[n];
        vector<vector<int>> knapsack(n, vector<int>(3));
        // (index, weights, vals, ratio)
        // taking inputs
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
        sort(knapsack.begin(), knapsack.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
        });
        
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        set<string> to_include;
        int prof = knapsack_10(n, W, items, knapsack, dp, to_include);

        // for printing what objects are selected
        int curr_prof = prof;
        int i = n, w = W;
        while(curr_prof != 0){
            // cout << "i = " << i << " and w = " << w << endl;
            if(dp[i-1][w] == dp[i][w]){
                // cout << "i'm useless\n";
                i = i - 1;
            }
            else{
                // cout << "I changed my i = " << i << " and w = " << w;
                cout << items[knapsack[i-1][0]] << " ";
                curr_prof -= knapsack[i-1][2];
                w -= knapsack[i-1][1];
                i -= 1;
                // cout << " to i = " << i << " and w = " << w << " and printing \n";
                
            }
        }


        cout << "with profit " << prof << endl;
    }
    return 0;
}