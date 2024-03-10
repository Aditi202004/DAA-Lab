#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topological_sort(vector<vector<int>> g){
    int v = g.size();
    int *deg = new int[v]();
    // bool *visited = new bool[v];
    // visited = {0};

    for(int i = 0; i < v; i++){
        int n = g[i].size();
        for(int j = 0; j < n; j++){
            if(j != 0){
                deg[g[i][j]]++;
            }
        }
    }

    queue <int> Q;
    for(int i = 0; i < v; i++){
        if(deg[i] == 0){
            Q.push(i);
        }
    }

    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        cout << curr << " ";
        int n = g[curr].size();
        for(int i = 0; i < n; i++){
            if(i != 0){
                deg[g[curr][i]]--;
                if(deg[g[curr][i]] == 0){
                    Q.push(g[curr][i]);
                }
            }
        }
    }
    cout << endl;
    delete[] deg;
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
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

    topological_sort(graph);
    return 0;
}