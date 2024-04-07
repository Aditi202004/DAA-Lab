#include <iostream>
#include <vector>
using namespace std;
#define ll long long

// O(2^n*(n+m)) is the time complexity

long long min_cost(int n, int m, int mask, int prev, int color, vector<vector<vector<int>>> &graph, vector<vector<vector<int>>> &dp){
    if(mask == ((1 << n) - 1)){
        return 0;
    }
    if(dp[mask][prev][color == 1] != 0){
        return dp[mask][prev][color == 1];
    }

    long long ans = 1e9;

    for(int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            if (graph[prev][i][j] && !(mask & (1 << i)) && (j != color)){
                long long z = graph[prev][i][j] +
                              min_cost(n, m, mask | (1 << i), i, j, graph, dp);
                ans = min(z, ans);
            }
        }
    }
    return dp[mask][prev][color == 1] = ans;
}

int get_cost(vector<pair<pair<int, int>, pair<int, char>>> &g, int m, int n){
    vector<vector<vector<int>>> graph(n, vector<vector<int>>(n, vector<int>(2)));
    for(int i = 0; i < m; i++){
        graph[g[i].first.first][g[i].first.second][g[i].second.second == 'G'] = g[i].second.first;
    }
    vector<vector<vector<int>>> dp((1 << n), vector<vector<int>>(n, vector<int>(2)));
    long long ans = 1e9;

    for(int i = 0; i < n; i++){
        ans = min(ans, min_cost(n, m, 1 << i, i, 2, graph, dp));
    }

    if(ans != 1e9){
        return ans;
    }
    else{
        return -1;
    }
}

int main()
{
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<pair<int, int>, pair<int, char>>> g;
        for (int i = 0; i < m; i++){
            int v1, v2, w;
            char color;
            cin >> v1 >> v2 >> w >> color;
            g.push_back(make_pair(make_pair(v1, v2), make_pair(w, color)));
        }
        cout << get_cost(g, m, n) << endl;
    }
}