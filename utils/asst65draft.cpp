#include <iostream>
#include <vector>
#include <list>
using namespace std;

void dfs(vector<int> graph[], int totalVertices, vector<int>& visited, int excludeVertex, int start) {
    visited[start] = 1;
    for (auto neighbor : graph[start]) {
        if (neighbor != excludeVertex) {
            if (!visited[neighbor]) {
                dfs(graph, totalVertices, visited, excludeVertex, neighbor);
            }
        }
    }
}

void findArticulationPoints(vector<int> graph[], int totalVertices) {
    for (int currentVertex = 1; currentVertex <= totalVertices; currentVertex++) {
        int separateComponents = 0;
        vector<int> visited(totalVertices + 1, 0);
        for (int vertex = 1; vertex <= totalVertices; vertex++) {
            if (vertex != currentVertex) {
                if (!visited[vertex]) {
                    separateComponents++;
                    dfs(graph, totalVertices, visited, currentVertex, vertex);
                }
            }
        }
        if (separateComponents > 1) {
            cout << currentVertex << "\n";
        }
    }
}

void insertEdge(vector<int> graph[], int node1, int node2) {
    graph[node1].push_back(node2);
    graph[node2].push_back(node1);
}

class BridgeFinder {
    int vertices;
    list<int> *connections;
    void findBridgesUtil(int node, vector<bool>& visited, vector<int>& discovery, vector<int>& low, int parent);

public:
    BridgeFinder(int vertices);
    void addConnection(int node1, int node2);
    void findBridges();
};

BridgeFinder::BridgeFinder(int vertices) {
    this->vertices = vertices;
    connections = new list<int>[vertices];
}

void BridgeFinder::addConnection(int node1, int node2) {
    connections[node1].push_back(node2);
    connections[node2].push_back(node1);
}

void BridgeFinder::findBridgesUtil(int node, vector<bool>& visited, vector<int>& discovery, vector<int>& low, int ancestor) {
    static int time = 0;
    visited[node] = true;
    discovery[node] = low[node] = ++time;

    for (auto adjacent : connections[node]) {
        if (adjacent == ancestor) continue;
        if (!visited[adjacent]) {
            findBridgesUtil(adjacent, visited, discovery, low, node);
            low[node] = min(low[node], low[adjacent]);
            if (low[adjacent] > discovery[node])
                cout << node << " " << adjacent << endl;
        } else {
            low[node] = min(low[node], discovery[adjacent]);
        }
    }
}

void BridgeFinder::findBridges() {
    vector<bool> visited(vertices, false);
    vector<int> discovery(vertices, -1), low(vertices, -1);
    for (int i = 0; i < vertices; i++)
        if (!visited[i])
            findBridgesUtil(i, visited, discovery, low, -1);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input5.txt", "r", stdin);
        freopen("output5.txt", "w", stdout);
    #endif

    int v;
    cin >> v;
    vector<int> graph[v + 1];
    int E;
    cin >> E;
    BridgeFinder bf(v);
    for(int i = 0; i < E; i++){
        int a, b;
        cin >> a >> b;
        insertEdge(graph, a, b);
        bf.addConnection(a, b);
    }

    cout << "Articulation points in the graph \n";
    findArticulationPoints(graph, v);

    

    cout << "Bridges in the graph are\n";
    bf.findBridges();

    return 0;
}
