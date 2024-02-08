#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <fstream>
using namespace std;

bool isSafe(vector <vector<pair<int, int>>> matrix, int i, int j, int rows, int cols){
    return (i >= 0) && (j >= 0) && (i < rows) && (j < cols) && ((matrix[i][j].first != 0) && (matrix[i][j].second != 1)); 
}

void DFS(vector <vector<pair<int, int>>> &matrix, int i, int j, int rows, int cols, int &count){
    int r[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int c[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

    matrix[i][j].second = 1;
    for(int k = 0; k < 8; k++){
        if(isSafe(matrix, i + r[k], j + c[k], rows, cols)){
            count++;
            DFS(matrix, i + r[k], j + c[k], rows, cols, count);
        }
    }
}

int largest_region(vector <vector<pair<int, int>>> matrix, int rows, int cols){
    int answer = INT_MIN;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if((matrix[i][j].first != 0) && (matrix[i][j].second != 1)){
                int count = 1;
                DFS(matrix, i, j, rows, cols, count);
                answer = max(answer, count);
            }
        }
    }
    return answer;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif

    int m , n;
    cin >> m >> n;

    vector <vector <pair <int, int>>> mat(m, vector<pair<int, int>>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int val;
            cin >> val;
            mat[i][j] = make_pair(val, 0);
        }
    }

    // mat[0][1] = make_pair(1,0);
    // mat[0][2] = make_pair(1,0);
    // mat[0][0] = make_pair(1,0);
    // mat[1][0] = make_pair(1,0);
    // mat[1][1] = make_pair(1,0);
    // mat[1][2] = make_pair(0,0);
    // mat[2][0] = make_pair(1,0);
    // mat[2][1] = make_pair(1,0);
    // mat[2][2] = make_pair(1,0);

    int curr = 0;
    int max = 0;
    cout << "the largest region is " << largest_region(mat, m, n);
    return 0;
}