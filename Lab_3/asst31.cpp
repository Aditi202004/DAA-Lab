#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void Padding(vector<vector<int>> &mat, int max, int m, int n)
{

    int p = 0;
    while (max > (pow(2, p)))
    {
        p++;
    }
    max = pow(2, p);
    for (int i = 0; i < max; i++)
    {
        if (i < m)
        {
            for (int j = n; j < max; j++)
            {
                mat[i].push_back(0);
            }
        }
        else
        {
            vector<int> v(max);
            mat.push_back(v);
        }
    }
}

void print(vector<vector<int>> mat, int sr, int sc, int l, int width)
{
    for (int i = sr; i < (sr + l); i++)
    {
        for (int j = sc; j < (sc + width); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void print(vector<vector<int>> mat)
{
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void MatrixAdd(vector<vector<int>> mat1, vector<vector<int>> mat2, vector<vector<int>> &result, int sr, int sc, int l, int width)
{
    for (int i = sr; i < (sr + l); i++)
    {
        for (int j = sc; j < (sc + width); j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

vector<vector<int>> MatrixMulti(vector<vector<int>> mat1, vector<vector<int>> mat2, int sr, int sc, int sr1, int sc1, int sr2, int sc2, int l, vector<vector<int>> &result)
{
    if (l == 1)
    {
        result[sr][sc] = mat1[sr1][sc1] * mat2[sr2][sc2];
        return result;
    }
    if (l == 2)
    {

        result[sr][sc] = mat1[sr1][sc1] * mat2[sr2][sc2] + mat1[sr1][sc1 + 1] * mat2[sr2 + 1][sc2];
        result[sr][sc + 1] = mat1[sr1][sc1] * mat2[sr2][sc2 + 1] + mat1[sr1][sc1 + 1] * mat2[sr2 + 1][sc2 + 1];
        result[sr + 1][sc] = mat1[sr1 + 1][sc1] * mat2[sr2][sc2] + mat1[sr1 + 1][sc1 + 1] * mat2[sr2 + 1][sc2];
        result[sr + 1][sc + 1] = mat1[sr1 + 1][sc1] * mat2[sr2][sc2 + 1] + mat1[sr1 + 1][sc1 + 1] * mat2[sr2 + 1][sc2 + 1];
        return result;
    }

    MatrixAdd(MatrixMulti(mat1, mat2, sr, sc, sr1, sc1, sr2, sc2, l / 2, result), MatrixMulti(mat1, mat2, sr, sc, sr1, sc1 + l / 2, sr2 + l / 2, sc2, l / 2, result), result, sr, sc, l / 2, l / 2);
    MatrixAdd(MatrixMulti(mat1, mat2, sr, sc + l / 2, sr1, sc1, sr2, sc2 + l / 2, l / 2, result), MatrixMulti(mat1, mat2, sr, sc + l / 2, sr1, sc1 + l / 2, sr2 + l / 2, sc2 + l / 2, l / 2, result), result, sr, sc + l / 2, l / 2, l / 2);
    MatrixAdd(MatrixMulti(mat1, mat2, sr + l / 2, sc, sr1 + l / 2, sc1, sr2, sc2, l / 2, result), MatrixMulti(mat1, mat2, sr + l / 2, sc, sr1 + l / 2, sc1 + l / 2, sr2 + l / 2, sc2, l / 2, result), result, sr + l / 2, sc, l / 2, l / 2);
    MatrixAdd(MatrixMulti(mat1, mat2, sr + l / 2, sc + l / 2, sr1 + l / 2, sc1, sr2, sc2 + l / 2, l / 2, result), MatrixMulti(mat1, mat2, sr + l / 2, sc + l / 2, sr1 + l / 2, sc1 + l / 2, sr2 + l / 2, sc2 + l / 2, l / 2, result), result, sr + l / 2, sc + l / 2, l / 2, l / 2);

    return result;
}

int main()
{   
    #ifndef ONLINE_JUDGE
	    freopen("input1.txt","r",stdin);
	    freopen("output1.txt","w",stdout);
    #endif
    int m, n, p, q;
    cin >> m >> n >> p >> q;
    if (n == p)
    {
        vector<vector<int>> mat1(m, vector<int>(n, 0)), mat2(p, vector<int>(q, 0)), result(m, vector<int>(q, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat1[i][j];
            }
        }
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                cin >> mat2[i][j];
            }
        }
        int c = max(max(m, n), max(p, q));
        Padding(result, c, m, q);
        Padding(mat1, c, m, n);
        Padding(mat2, c, p, q);
        result = MatrixMulti(mat1, mat2, 0, 0, 0, 0, 0, 0, result.size(), result);
        print(result, 0, 0, m, q);
        cout << endl;
    }
    else
    {
        cout << "Invalid input " << endl;
    }
}