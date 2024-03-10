#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool find_cycle(int i, vector<vector<int>> g, vector<bool> &vis, vector<bool> &stack){
    if(!vis[i]){
        vis[i] = 1;
        stack[i] = 1;
        for(int j = 1; j < g[i].size(); j++){
            if(!vis[g[i][j]] && find_cycle(j, g, vis, stack)){
                return 1;
            }
            else if(stack[g[i][j]]){
                return 1;
            }
        }
    }
    stack[i] = 0;
    return 0;
}

bool is_cycle(vector<vector<int>> g){
    int v = g.size();
    vector<bool> visited(v, 0);
    vector<bool> stack(v, 0);
    for(int i = 0; i < v; i++){
        if(!visited[i]){
            if(find_cycle(i, g, visited, stack)){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input4.txt", "r", stdin);
        freopen("output4.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
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

        if(is_cycle(graph)){
            cout << "cycle detected\n";
        }
        else{
            cout << "cycle not present\n";
        }
    }
    return 0;
}