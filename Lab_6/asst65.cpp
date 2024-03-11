#include <iostream>
#include <vector>
#include <climits>
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
        disc = INT_MAX;
        low = INT_MAX;
        num_of_children = 0;
    }
    Node(int a){
        val = a;
        disc = INT_MAX;
        low = INT_MAX;
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
            // cout << "******visiting this node : " << curr << endl;
            vis[curr] = 1;
            all_nodes[curr] -> disc = ++d;
            // cout << "WE assigned disc of " << all_nodes[curr] -> val << " as " <<  all_nodes[curr] -> disc << endl;
            Node *Curr = all_nodes[curr];
            for(auto x : g[curr]){
                if(x != parent_x){
                    if(!vis[x]){
                        // cout << "adding to tree: " << x << endl;
                        // Node *newNode = all_nodes[x];
                        // (all_nodes[x] -> disc) = ++d;
                        // cout << "WE assigned disc of " << all_nodes[x] -> val << " as " <<  all_nodes[x] -> disc << endl;
                        (Curr -> children).push_back(all_nodes[x]);
                        // cout << "child pushed : " << (all_nodes[curr] -> children).back() -> val << endl;
                        (Curr -> num_of_children) = (Curr -> num_of_children) + 1;
                        dfs(x, vis, d, all_nodes, curr);
                        Curr -> low = min(Curr -> disc, (min(Curr -> low, all_nodes[x] -> low)));
                        // cout << "I assigned lowsss of " << curr << " as " <<  Curr -> low << endl;
                    }
                    else{
                        Curr -> low = min(Curr -> low, all_nodes[x] -> disc);
                        // cout << "I assigned low of " << curr << " as " <<  Curr -> low << endl;
                    }
                }
            }
            // if(Curr -> disc == INT_MAX){
            //     all_nodes[curr] -> disc = ++d;
            //     cout << "WE assigned disc of " << curr << " as " <<  Curr -> disc << endl;
            // }
            if((Curr -> low == INT_MAX) && (Curr -> num_of_children != 0)){
                int m = Curr -> disc;
                for(auto x : g[curr]){
                    if((x != parent_x) && (all_nodes[x] -> low != INT_MAX))
                        m = min(m, all_nodes[x] -> low);
                }
                Curr -> low = m;
                // cout << "I assigned low of " << curr << " as " <<  Curr -> low << endl;
            }
            else if((Curr -> low == INT_MAX) && (Curr -> num_of_children == 0)){
                Curr -> low = Curr -> disc;
                // cout << "I assigned low of " << curr << " as " <<  Curr -> low << endl;
            }
        }
    }

    void assign_disc(){
        vector<int> visited(v, 0);
        int d = 0;
        // all_nodes[0] -> disc = ++d;
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                dfs(i, visited, d, all_nodes, -1);
            }
        }
        // cout << "assigned";
    }

    void articulation_points(){
        cout << "articulation points: \n";
        assign_disc();
        vector<int> visited(v, 0);
        // for(int j = 0; j < v; j++){
        //     bool root = 1;
        //     for(int i = j; i < v; i++){
        //         if(i == 0){
        //             if(all_nodes[i] -> num_of_children > 1){
        //                 cout << all_nodes[i] -> val << " ";
        //             }
        //         }
        //         else{
        //             for(auto temp : all_nodes[i] -> children){
        //                 if((temp -> low) >= (all_nodes[i] -> disc)){
        //                     // cout << "comparing " << temp-> low << " ka low with" << all_nodes[i] -> disc << " ka disc time " << endl;
        //                     cout << all_nodes[i] -> val << " " << endl;
        //                     break;
        //                 }
        //             }
        //         }
        //     }
        // }
        for(int i = 0; i < v; i++){
                if(i == 0){
                    if(all_nodes[i] -> num_of_children > 1){
                        cout << all_nodes[i] -> val << " ";
                    }
                }
                else{
                    for(auto temp : all_nodes[i] -> children){
                        if((temp -> low) >= (all_nodes[i] -> disc)){
                            // cout << "comparing " << temp-> low << " ka low with" << all_nodes[i] -> disc << " ka disc time " << endl;
                            cout << all_nodes[i] -> val << " " << endl;
                            break;
                        }
                    }
                }
            }
    }

    void bridges(){
        cout << "bridges: \n";
        assign_disc();
        for(int i = 0; i < v; i++){
            for(auto temp : all_nodes[i] -> children){
                // cout << "comparing " << temp-> val << " ka low( " << temp->low << " ) with" << all_nodes[i] -> val << " ka disc time( " <<  all_nodes[i] -> disc << " )"<< endl;
                if((temp -> low) > (all_nodes[i] -> disc)){
                    cout << all_nodes[i] -> val << " "  << temp -> val << endl;
                    break;
                }
            } 
        }
    }
    
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input5.txt", "r", stdin);
        freopen("output5.txt", "w", stdout);
    #endif

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
    g.bridges();
    return 0;
}