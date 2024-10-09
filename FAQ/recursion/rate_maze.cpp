#include <bits/stdc++.h>

using namespace std;

void findPath(vector<vector<int>> &mat, int row, int col, int n, vector<string> &result, string &ans)
{

    if (row == n - 1 && col == n - 1)
    {
        result.push_back(ans);
        return;
    }

    if (mat[row][col] == 0 || mat[row][col] == -1)
    {
        return;
    }

    mat[row][col] = -1;

    // up
    if (row - 1 >= 0)
    {
        ans.push_back('U');
        findPath(mat, row - 1, col, n, result, ans);
        ans.pop_back();
    }

    // down

    if (row + 1 < n)
    {
        ans.push_back('D');
        findPath(mat, row + 1, col, n, result, ans);
        ans.pop_back();
    }

    // left

    if (col - 1 >= 0)
    {
        ans.push_back('L');
        findPath(mat, row, col - 1, n, result, ans);
        ans.pop_back();
    }

    // right

    if (col + 1 < n)
    {
        ans.push_back('R');
        findPath(mat, row, col + 1, n, result, ans);
        ans.pop_back();
    }

    mat[row][col] = 1;
}
int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};
    vector<string> result;
    string ans = "";

    findPath(mat, 0, 0, 4, result, ans);

    for (auto it : result)
    {
        for (auto i : it)
        {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}