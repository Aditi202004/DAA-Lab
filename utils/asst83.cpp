#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


struct edge {
    int src, dest, weight;
};

bool cmp(edge x, edge y) {
    return x.weight < y.weight;
}

void initialise(int n, int *&parent) {
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int find(int x, int *&parent) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x], parent);
}

int union1(int i, int sum, edge *edges, int *&parent, vector<int> &present) {
    int x, y;
    x = find(edges[i].src, parent);
    y = find(edges[i].dest, parent);
    if (x != y) {
        parent[x] = y;
        present.push_back(i);
        sum += edges[i].weight;
    }
    return sum;
}

int union2(int i, int sum, edge *edges, int *&parent, int &edg) {
    int x, y;
    x = find(edges[i].src, parent);
    y = find(edges[i].dest, parent);
    if (x != y) {
        parent[x] = y;
        sum += edges[i].weight;
        edg++;
    }
    return sum;
}

int main() {
    int t; cin >> t;
    while(t--){   
        int V, E;
        cin >> V >> E;

        int *parent = new int[V + 1];
        vector<int> present;
        int edg;
        edge *edges = new edge[V + 1];

        initialise(V, parent);

        vector<int> source;
        vector<int> destination;
        vector<int> weights;
        cout << "here\n";
        for(int i = 0; i < E; i++){
            int sour_ce, dest_n, w_t;
            cin >> sour_ce >> dest_n >> w_t;
            source.push_back(sour_ce);
            destination.push_back(dest_n);
            weights.push_back(w_t);
        }
        // cout << "here\n";
        for (int i = 0; i < E; i++) {
            edges[i].src = source[i];
            edges[i].dest = destination[i];
            edges[i].weight = weights[i];
        }

        sort(edges, edges + E, cmp);
        // cout << "here\n";
        int sum = 0;
        for (int i = 0; i < E; i++) {
            sum = union1(i, sum, edges, parent, present);
        }

        cout << "MST: " << sum << "\n";

        int sec_best_mst = INT_MAX;
        sum = 0;
        int j;
        for (j = 0; j < present.size(); j++) {
            initialise(V, parent);
            edg = 0;
            for (int i = 0; i < E; i++) {
                if (i == present[j])
                    continue;
                sum = union2(i, sum, edges, parent, edg);
            }
            if (edg >= V - 1) {
                sum = 0;
                continue;
            }
            if (sec_best_mst > sum)
                sec_best_mst = sum;
            sum = 0;
        }

        cout << "Second Best MST: " << sec_best_mst << "\n";
    }
    return 0;
}