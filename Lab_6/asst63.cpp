#include <iostream>
#include <vector>
using namespace std;

bool dfs(int src, int des, vector<vector<int>> g, vector<bool> vis){
    if(src == des){
        return 1;
    }
    vis[src] = 1;
    for(int i = 1; i < g[src].size(); i++){
        if(!vis[g[src][i]]){
            vis[g[src][i]] = 1;
            if(dfs(g[src][i], des, g, vis)){
                return 1;
            }
        }
    }
    return 0;
}

bool is_path(int src, int des, vector<vector<int>> g){
    vector<bool> visited(g.size(), 0);
    return dfs(src, des, g, visited);
}

void connected_components(vector<vector<int>> g){
    int v = g.size();
    vector<vector<int>> ans;
    vector<bool> is_part(v, 0);

    for(int i = 0; i < v; i++){
        if(!is_part[i]){
            vector<int> temp;
            temp.push_back(i);
            for(int j = i + 1; j < v; j++){
                if(!is_part[j] && is_path(i, j, g) && is_path(j, i, g)){
                    is_part[j] = 1;
                    temp.push_back(j);
                }
            }
            ans.push_back(temp);
        }
    }

    for(int i = 0; i < ans.size(); i++){
        for(auto adj : ans[i]){
            cout << adj << " ";
        }
        cout << endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input3.txt", "r", stdin);
        freopen("output3.txt", "w", stdout);
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

    // for(int i = 0; i < graph.size(); i++){
    //     for(auto adj : graph[i]){
    //         cout << adj << " ";
    //     }
    //     cout << endl;
    // }

    connected_components(graph);
    return 0;
}