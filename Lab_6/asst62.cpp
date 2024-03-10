#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void topological_sort(int node, vector<vector<int>> g, bool visited[], int LP[]){
    visited[node] = 1;

    for(int i = 1; i < g[node].size(); i++){
        if(!visited[g[node][i]]){
            topological_sort(g[node][i], g, visited, LP);
        }
        LP[node] = max(LP[node], 1 + LP[g[node][i]]); //calculates longest path considering node as the starting vertex
    }
    return;
}

int get_LP(vector<vector<int>> g){
    int v = g.size();

    bool visited[v];
    memset(visited, 0, sizeof visited);

    int LP[v];
    memset(LP, 0, sizeof LP);

    for(int i = 0; i < v; i++){
        if(!visited[i]){
            topological_sort(i, g, visited, LP);
        }
    }

    int max = LP[0];
    for(int i = 0; i < v; i++){
        if(max < LP[i]){
            max = LP[i];
        }
    }

    return max;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);
    #endif 

    vector<vector<int>> graph;
    int v; cin >> v;
    for(int i = 0; i < v; i++){
        int vertex; cin >> vertex;

        vector<int> temp;
        temp.push_back(vertex);

        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            temp.push_back(a);
        }
        
        graph.push_back(temp);
    }

    cout << get_LP(graph);
    return 0;
}