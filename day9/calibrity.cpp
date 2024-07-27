#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> &M, int n)
{
    if (n == 1)
    {
        return 0;
    }
    int index = -1;
    for (int row = 0; row < n; row++)
    {
        // for each person
        bool isCelebiry = true;
        int col = 0;
        for (col = 0; col < n; col++)
        {
            if (M[row][col] == 1)
            {
                isCelebiry = false;
                break;
            }
        }

        if (isCelebiry)
        {
            index = row;
            break;
        }
    }

    if (index != -1)
    {
        for (int j = 0; j < n; j++)
        {
            if (index != j)
            {
                if (M[j][index] == 0)
                {
                    index = -1;
                    break;
                }
            }
        }
    }

    return index;
}
int main()
{
    vector<vector<int>> M = {{0}};

    cout << celebrity(M, 4);
    return 0;
}