// #include<iostream>
// #include<vector>
// #include<set>
// using namespace std;

// int g(int i, set<int>S, int start, const vector<int, vector<int>>&W){
//     if(S.empty()){
//         return W[i][start];
//     }
//     vector<int> temp;
//     vector<int, vector<int>>pairs;
//     set<int>::iterator itr;
//     for(itr = S.begin(); itr != S.end(); itr++){
//         set<int> ha = S;
//         ha.erase(*itr);
//         temp.push_back(W[i][*itr] + g(*itr, ha, start, W));
//         pairs.push_back((i, *itr));
//     }
//     return *min_element(temp.begin(), temp.end());
    
// }

// int main(){
//     int n;
//     cout << "enter number of cities: ";
//     cin >> n;
//     cout << "enter names of cities: ";
//     string *names = new string[n];
//     for(int i = 0; i<n; i++){
//         cin >> names[i];
//     }
//     vector<int, vector<int>>matrix[n][n];
//     cout << "enter the adjacency matrix: " << endl;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             cin >> matrix[i][j];
//         }
//     }
// }

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
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    string *names = new string[n];

    cout << "Enter names of cities: ";
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter the adjacency matrix: " << endl;
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

    delete[] names;
    return 0;
}

