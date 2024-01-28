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

void print(vector<vector<int>> mat, int startrow, int startcol, int length, int width)
{
    for (int i = startrow; i < (startrow + length); i++)
    {
        for (int j = startcol; j < (startcol + width); j++)
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

void MatrixAdd(vector<vector<int>> mat1, vector<vector<int>> mat2, vector<vector<int>> &result, int startrow, int startcol, int length, int width)
{
    for (int i = startrow; i < (startrow + length); i++)
    {
        for (int j = startcol; j < (startcol + width); j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

vector<vector<int>> MatrixMulti(vector<vector<int>> mat1, vector<vector<int>> mat2, int startrow, int startcol, int startrow1, int startcol1, int startrow2, int startcol2, int length, vector<vector<int>> &result)
{
    if (length == 1)
    {
        result[startrow][startcol] = mat1[startrow1][startcol1] * mat2[startrow2][startcol2];
        return result;
    }
    if (length == 2)
    {

        result[startrow][startcol] = mat1[startrow1][startcol1] * mat2[startrow2][startcol2] + mat1[startrow1][startcol1 + 1] * mat2[startrow2 + 1][startcol2];
        result[startrow][startcol + 1] = mat1[startrow1][startcol1] * mat2[startrow2][startcol2 + 1] + mat1[startrow1][startcol1 + 1] * mat2[startrow2 + 1][startcol2 + 1];
        result[startrow + 1][startcol] = mat1[startrow1 + 1][startcol1] * mat2[startrow2][startcol2] + mat1[startrow1 + 1][startcol1 + 1] * mat2[startrow2 + 1][startcol2];
        result[startrow + 1][startcol + 1] = mat1[startrow1 + 1][startcol1] * mat2[startrow2][startcol2 + 1] + mat1[startrow1 + 1][startcol1 + 1] * mat2[startrow2 + 1][startcol2 + 1];
        return result;
    }

    MatrixAdd(MatrixMulti(mat1, mat2, startrow, startcol, startrow1, startcol1, startrow2, startcol2, length / 2, result), MatrixMulti(mat1, mat2, startrow, startcol, startrow1, startcol1 + length / 2, startrow2 + length / 2, startcol2, length / 2, result), result, startrow, startcol, length / 2, length / 2);
    MatrixAdd(MatrixMulti(mat1, mat2, startrow, startcol + length / 2, startrow1, startcol1, startrow2, startcol2 + length / 2, length / 2, result), MatrixMulti(mat1, mat2, startrow, startcol + length / 2, startrow1, startcol1 + length / 2, startrow2 + length / 2, startcol2 + length / 2, length / 2, result), result, startrow, startcol + length / 2, length / 2, length / 2);
    MatrixAdd(MatrixMulti(mat1, mat2, startrow + length / 2, startcol, startrow1 + length / 2, startcol1, startrow2, startcol2, length / 2, result), MatrixMulti(mat1, mat2, startrow + length / 2, startcol, startrow1 + length / 2, startcol1 + length / 2, startrow2 + length / 2, startcol2, length / 2, result), result, startrow + length / 2, startcol, length / 2, length / 2);
    MatrixAdd(MatrixMulti(mat1, mat2, startrow + length / 2, startcol + length / 2, startrow1 + length / 2, startcol1, startrow2, startcol2 + length / 2, length / 2, result), MatrixMulti(mat1, mat2, startrow + length / 2, startcol + length / 2, startrow1 + length / 2, startcol1 + length / 2, startrow2 + length / 2, startcol2 + length / 2, length / 2, result), result, startrow + length / 2, startcol + length / 2, length / 2, length / 2);

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