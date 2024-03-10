#include <iostream>
#include <vector>
using namespace std;

class Node{
  public:
    int val;
    int disc;
    int low;
    vector<Node*> children;
    int num_of_children;
    Node(){
        val = 0;
        disc = -1;
        low = -1;
        num_of_children = 0;
    }
    Node(int a){
        val = a;
        disc = -1;
        low = -1;
        num_of_children = 0;
    }
};

class Graph{
  vector<vector<int>> g;
  vector<Node*> all_nodes;
  int v;
  public:
    Graph(vector<vector<int>> a){
        v = a.size();
        for(int i = 0; i < a.size(); i++){
            vector<int> temp;
            Node *newNode = new Node(i);
            all_nodes.push_back(newNode); 
            for(auto x : a[i]){
                temp.push_back(x);
            }
            g.push_back(temp);
        }
    }

    void dfs(int curr, vector<int> &vis, int &d, vector<Node*> &all_nodes, int parent_x){
        if(!vis[curr]){
            cout << "******visiting this node : " << curr << endl;
            vis[curr] = 1;
            Node *Curr = all_nodes[curr];
            for(auto x : g[curr]){
                if(x != parent_x){
                    if(!vis[x]){
                        cout << "adding to tree: " << x << endl;
                        // Node *newNode = all_nodes[x];
                        all_nodes[x] -> disc = d++;
                        Curr -> children.push_back(all_nodes[x]);
                        cout << "child pushed : " << (all_nodes[curr] -> children).back() << endl;
                        Curr -> num_of_children = Curr -> num_of_children + 1;
                        dfs(x, vis, d, all_nodes, curr);
                    }
                    else{
                        Curr -> low = min(Curr -> disc, all_nodes[x] -> disc);
                    }
                }
            }
            if((Curr -> low == -1) && (Curr -> num_of_children != 0)){
                int m = Curr -> disc;
                for(auto x : g[curr]){
                    if((x != parent_x) && (all_nodes[x] -> low != -1))
                        m = min(m, all_nodes[x] -> low);
                }
                Curr -> low = m;
            }
            else if((Curr -> low == -1) && (Curr -> num_of_children == 0)){
                Curr -> low = Curr -> disc;
            }
        }
    }

    void assign_disc(){
        vector<int> visited(v, 0);
        int d = 1;
        all_nodes[0] -> disc = d++;
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                dfs(i, visited, d, all_nodes, -1);
            }
        }
        // cout << "assigned";
    }

    void articulation_points(){
        assign_disc();
        for(int i = 0; i < v; i++){
            if(i == 0){
                if(all_nodes[i] -> num_of_children > 1){
                    cout << all_nodes[i] -> val << " ";
                }
            }
            else{
                for(auto temp : all_nodes[i] -> children){
                    if((temp -> low) >= (all_nodes[i] -> disc)){
                        cout << "comparing with " << temp << " ";
                        cout << all_nodes[i] -> val << " " << endl;
                        break;
                    }
                }
            }
        }
    }

    //write function to assign low time (bottom-down approach)

    //write a final function to compare low and disc time to find articulation points
    
};

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input1.txt", "r", stdin);
    //     freopen("output5.txt", "w", stdout);
    // #endif

    int v;
    cin >> v;
    vector<vector<int>> graph(v);
    int E;
    cin >> E;
    for(int i = 0; i < E; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    Graph g(graph); //making a graph

    g.articulation_points();
    return 0;
}