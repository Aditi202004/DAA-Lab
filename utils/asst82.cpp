#include <iostream>
#include <vector>
using namespace std;

long long calcMin(int n, int m, int mask, int prev, int col, const vector<vector<vector<int>>>& g, vector<vector<vector<long long>>>& dp) {
    if (mask == ((1 << n) - 1)) {
        return 0;
    }
    if (dp[mask][prev][col] != 0) {
        return dp[mask][prev][col];
    }

    long long ans = 1e9;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (g[prev][i][j] && !(mask & (1 << i)) && (j != col)) {
                long long temp = g[prev][i][j] + calcMin(n, m, mask | (1 << i), i, j, g, dp);
                ans = min(temp, ans);
            }
        }
    }

    return dp[mask][prev][col] = ans;
}

void createGraph(vector<pair<pair<int,int>, pair<int,char>>>& edges, int m, vector<vector<vector<int>>>& g) {
    for (int i = 0; i < m; i++) {
        int a = edges[i].first.first - 1;
        int b = edges[i].first.second - 1;
        int cost = edges[i].second.first;
        char color = edges[i].second.second;
        g[a][b][color == 'W'] = cost;
        g[b][a][color == 'W'] = cost;
    }
}

int findMinCost(int n, int m, const vector<vector<vector<int>>>& g, vector<vector<vector<long long>>>& dp) {
    long long ans = 1e9;
    for (int i = 0; i < n; i++) {
        ans = min(ans, calcMin(n, m, 1 << i, i, 2, g, dp));
    }

    return ans == 1e9 ? -1 : ans;
}

int main() {
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        vector<pair<pair<int, int>, pair<int, char>>> edges;
        int v, E;
        cin >> v >> E;
        vector<vector<vector<int>>> g(v, vector<vector<int>>(v, vector<int>(2)));
        vector<vector<vector<long long>>> dp(1 << v, vector<vector<long long>>(v, vector<long long>(2)));

        for (int i = 0; i < E; i++) {
            int vertex1, vertex2, weight;
            char color;
            cin >> vertex1 >> vertex2 >> weight >> color;

            edges.push_back({{vertex1, vertex2}, {weight, color}});
        }

        createGraph(edges, E, g);
        cout << findMinCost(v, E, g, dp) << '\n';
    }
    return 0;
}
