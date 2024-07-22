// word search
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool recursion(vector<vector<char>> &grid, int maxRow, int maxCol, string &word, int destinationIndex, int row, int col)
{
    cout << endl;
    cout << endl;
    // if (!((0 <= row < maxRow) || (0 <= col < maxCol)))
    // cout << "true " << endl;
    if (destinationIndex >= word.size())
    {
        cout << "return true hello" << endl;
        return true;
    }

    if ((row < 0 || row >= maxRow) || (col < 0 || col >= maxCol))
    {
        cout << "return false 1" << endl;
        return false;
    }
    cout << "Row : " << row << "  col : " << col << endl;
    cout << "function call for : " << grid[row][col] << endl;

    cout << "char to find : " << word[destinationIndex] << endl;

    // base case
    if (grid[row][col] != word[destinationIndex])
    {
        cout << "return false 2" << endl;
        return false;
    }

    char temp = grid[row][col];
    grid[row][col] = '#';

    bool found = recursion(grid, maxRow, maxCol, word, destinationIndex + 1, row, col - 1) ||
                 recursion(grid, maxRow, maxCol, word, destinationIndex + 1, row, col + 1) ||
                 recursion(grid, maxRow, maxCol, word, destinationIndex + 1, row - 1, col) ||
                 recursion(grid, maxRow, maxCol, word, destinationIndex + 1, row + 1, col);

    grid[row][col] = temp;
    cout << "return " << (found) << endl;

    return found;
}
int main()
{
    vector<vector<char>> grid = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};

    string word = "SEE";
    bool found = false;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            if (recursion(grid, grid.size(), grid[0].size(), word, 0, i, j))
            {
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    cout << (found ? "Word found" : "Word not found") << endl;
    return 0;
}