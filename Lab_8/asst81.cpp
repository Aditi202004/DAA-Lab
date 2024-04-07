#include <iostream>
// #include <set>
#include <vector>
#include <algorithm>
using namespace std;

int maximum_spanning_tree(int v, vector<vector<int>> g){
    sort(g.begin(), g.end(), [](const vector<int>&a, const vector<int>&b){
        return a[2] > b[2];
    });

    int *sets = new int[v];
    for(int i = 0; i < v; i++){
        sets[i] = i;
    }

    int cost = 0;
    for(auto itr : g){
        if(sets[itr[0]] != sets[itr[1]]){
            cost += itr[2];
            int to_change = sets[itr[1]];
            for(int i = 0; i < v; i++){
                if(sets[i] == to_change){
                    sets[i] = sets[itr[0]];
                }
            }
        }
    }

    return cost;
}

int main(){
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    int t; cin >> t;
    while(t--){
        vector<vector<int>> graph;
        // {vertex1, vertex2, weight}

        int v, E; 
        cin >> v >> E;
        for(int i = 0; i < E; i++){
            int vertex1, vertex2, weight;
            cin >> vertex1 >> vertex2 >> weight;

            vector<int> temp;
            temp.push_back(min(vertex1, vertex2));
            temp.push_back(max(vertex1, vertex2));
            temp.push_back(weight);

            graph.push_back(temp);
        }
        int cost = maximum_spanning_tree(v, graph);
        cout << "max cost spanning tree is "<< cost << endl;
    }

    return 0;
}
