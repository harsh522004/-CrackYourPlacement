#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int liveCount(vector<vector<int>> &city, int currentRow, int currentCol)
{
    int row = city.size();
    int col = city[0].size();
    int count = 0;

    // horizontal and vertical
    if (currentCol - 1 >= 0 && city[currentRow][currentCol - 1])
        count++;

    if (currentCol + 1 < col && city[currentRow][currentCol + 1])
        count++;

    if (currentRow - 1 >= 0 && city[currentRow - 1][currentCol])
        count++;

    if (currentRow + 1 < row && city[currentRow + 1][currentCol])
        count++;

    // diagonal checks
    if (currentRow - 1 >= 0 && currentCol - 1 >= 0 && city[currentRow - 1][currentCol - 1])
        count++;

    if (currentRow - 1 >= 0 && currentCol + 1 < col && city[currentRow - 1][currentCol + 1])
        count++;

    if (currentRow + 1 < row && currentCol - 1 >= 0 && city[currentRow + 1][currentCol - 1])
        count++;

    if (currentRow + 1 < row && currentCol + 1 < col && city[currentRow + 1][currentCol + 1])
        count++;

    return count;
}

void printLoop(vector<vector<int>> &city)
{
    for (auto x : city)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}

void gameOfLife(vector<vector<int>> &city)
{
    int row = city.size();
    int col = city[0].size();
    // vector<vector<bool>> isChange(row, vector<bool>(col, false));

    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {

            // count neighbours
            int liveNeighbours = liveCount(city, i, j);

            if (city[i][j] == 1)
            {

                if (liveNeighbours < 2 || liveNeighbours > 3)
                {
                    // isChange[i][j] = true;
                    city[i][j] |= 2;
                }
            }
            else
            {

                if (liveNeighbours == 3)
                {
                    // isChange[i][j] = true;
                    city[i][j] |= 2;
                }
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            city[i][j] >>= 1; // move second bit to first bit
        }
    }

    // for (auto x : city)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
}

int main()
{
    vector<vector<int>> city = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    gameOfLife(city);
    return 0;
}