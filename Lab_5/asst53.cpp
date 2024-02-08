#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

bool checkBipartiteComponent(vector<vector<int>> graph, int start, int colorTracker[], int SIZE) {
    colorTracker[start] = 1;
    queue<int> verticesQueue;
    verticesQueue.push(start);

    while (!verticesQueue.empty()) {
        int currentVertex = verticesQueue.front();
        verticesQueue.pop();

        for (int nextVertex = 0; nextVertex < SIZE; ++nextVertex) {
            if (graph[currentVertex][nextVertex] && colorTracker[nextVertex] == -1) {
                colorTracker[nextVertex] = 1 - colorTracker[currentVertex];
                verticesQueue.push(nextVertex);
            } else if (graph[currentVertex][nextVertex] && colorTracker[nextVertex] == colorTracker[currentVertex]) {
                return false;
            }
        }
    }
    return true;
}

bool isGraphBipartite(vector<vector<int>> graph, int SIZE) {
    int *vertexColors = new int[SIZE];
    for (int i = 0; i < SIZE; ++i)
        vertexColors[i] = -1;

    for (int i = 0; i < SIZE; i++)
        if (vertexColors[i] == -1)
            if (!checkBipartiteComponent(graph, i, vertexColors, SIZE))
                return false;
    delete[] vertexColors;
    return true;
}

bool canSplitIntoTwoCliques(vector<vector<int>> graph, int SIZE) {
    vector<vector<int>> complementGraph(SIZE, vector<int>(SIZE));
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            complementGraph[i][j] = (i != j) ? !graph[i][j] : 0;

    return isGraphBipartite(complementGraph, SIZE);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input3.txt", "r", stdin);
        freopen("output3.txt", "w", stdout);
    #endif

    int SIZE;
    cin >> SIZE;

    vector<vector<int>> graph(SIZE, vector<int>(SIZE));
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cin >> graph[i][j];
        }
    }

    // int graph[SIZE][SIZE] = {
    //     {0, 1, 1, 1, 0},
    //     {1, 0, 1, 0, 0},
    //     {1, 1, 0, 0, 0},
    //     {0, 1, 0, 0, 1},
    //     {0, 0, 0, 1, 0}
    // };

    canSplitIntoTwoCliques(graph, SIZE) ? cout << "Yes" : cout << "No";
    return 0;
}
