#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// time complexity is O(V*E)

class DSU
{
    int *parent_mst;
    int V;

public:
    vector<int> parent_second_mst;
    vector<int> present;
    int edgecount;
    DSU(int n)
    {
        this->V = n;
        parent_mst = new int[n];
        parent_second_mst = vector<int>(n, -1);
        for (int i = 0; i < n; i++)
        {
            parent_mst[i] = -1;
        }
    }

    int find_mst(int i)
    {
        if (parent_mst[i] == -1)
        {
            return i;
        }
        return find_mst(parent_mst[i]);
    }

    int find_second_mst(int i)
    {
        if (parent_second_mst[i] == -1)
        {
            return i;
        }
        return find_second_mst(parent_second_mst[i]);
    }

    int uni1(int i, int sum, vector<vector<int>> &graph)
    {
        int set1 = find_mst(graph[i][1]);
        int set2 = find_mst(graph[i][2]);
        if (set1 != set2)
        {
            parent_mst[set1] = set2;
            present.push_back(i);
            sum += graph[i][0];
        }
        return sum;
    }

    int uni2(int i, int sum, vector<vector<int>> &graph)
    {
        int set1 = find_second_mst(graph[i][1]);
        int set2 = find_second_mst(graph[i][2]);
        if (set1 != set2)
        {
            parent_second_mst[set1] = set2;
            sum += graph[i][0];
            edgecount++;
        }
        return sum;
    }
};

void Krushkal_mst(vector<vector<int>> &graph, int E, int V)
{
    int sum = 0;
    sort(graph.begin(), graph.end());
    DSU dsu(V);
    for (int i = 0; i < E; i++)
    {
        sum = dsu.uni1(i, sum, graph);
    }
    cout << "MST: " << sum << endl;
    int sec_best_mst = INT_MAX;
    sum = 0;
    for (int j = 0; j < dsu.present.size(); j++)
    {
        dsu.parent_second_mst = vector<int>(V, -1);
        dsu.edgecount = 0;
        for (int i = 0; i < E; i++)
        {
            if (i == dsu.present[j])
            {
                continue;
            }
            sum = dsu.uni2(i, sum, graph);
        }
        if (dsu.edgecount != V - 1)
        {
            sum = 0;
            continue;
        }
        if (sec_best_mst > sum)
            sec_best_mst = sum;
        sum = 0;
    }
    cout << "Second minimum spanning tree is: " << sec_best_mst << endl;
}

int main()
{
    freopen("input3.txt", "r", stdin);
    freopen("output3.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> graph(E, vector<int>(3));
        for (int i = 0; i < E; i++)
        {
            int src, dest, wt;
            cin >> src >> dest >> wt;
            graph[i][0] = wt;
            graph[i][1] = src;
            graph[i][2] = dest;
        }
        Krushkal_mst(graph, E, V);
    }
}