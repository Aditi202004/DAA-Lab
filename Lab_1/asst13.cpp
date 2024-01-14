#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;

int g(int i, set<int> S, int start, const vector<vector<int>>& W, vector<char>& path) {
    if (S.empty()) {
        // path.push_back(char(i)); // Add the current city to the path
        // cout << "S empty "<< i << endl;
        return W[i][start];
    }

    vector<int> temp;
    vector<pair<int, int>> pairs;
    set<int>::iterator itr;

    for (itr = S.begin(); itr != S.end(); itr++) {
        set<int> ha = S;
        ha.erase(*itr);
        int cost = W[i][*itr] + g(*itr, ha, start, W, path);
        temp.push_back(cost);
        pairs.push_back(make_pair(i, *itr));
    }

    int min_cost = *min_element(temp.begin(), temp.end());

    // Add the current city to the path
    // path.push_back(char(i));

    return min_cost;
}

int main() {
    ofstream input;
    input.open("input3.txt",ios::in);
    int testcase;
    testcase = rand()%9+1;
    input << testcase << endl;
    while(testcase--){
        int num = rand()%10+1;
        input << num << endl;
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                if(i==j) input << 0 << " " ;
                else input << rand()%10+1 << " ";
            }
            input << endl;
        }
    }
    #ifndef ONLINE_JUDGE
	    freopen("input3.txt","r",stdin);
	    freopen("output3.txt","w",stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<vector<int>> matrix(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        set<int> cities;
        for (int i = 0; i < n; i++) {
            cities.insert(i);
        }

        int start_city = 0; // You can change this to any city as the starting point
        cities.erase(start_city);

        vector<char> path;
        int min_cost = g(start_city, cities, start_city, matrix, path);

        cout << "Minimum cost for the Travelling Salesman Problem: " << min_cost << endl;
        
        // // Output the path
        // cout << "Path: ";
        // for (int i = path.size() - 1; i >= 0; i--) {
        //     cout << names[int(path[i])] << " ";
        // }
    }
    return 0;
}

