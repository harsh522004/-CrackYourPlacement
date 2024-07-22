// 1499. Max Value of Equation
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMaxValueOfEquation(vector<vector<int>> &points, int k)
{
    int max_ans = INT_MIN;
    for (int i = 0; i < points.size() - 1; i++)
    {
        for (int j = i + 1; j < points.size(); j++)
        {
            // here i is vector x =  points[i][0] , y = points[i][1]
            // j is vector  x =  points[j][0] , y = points[j][1]
            int x1 = points[i][0];
            int x2 = points[j][0];
            int y1 = points[i][1];
            int y2 = points[j][1];
            // cout << "x1: " << x1 << ", x2: " << x2 << ", y1: " << y1 << ", y2: " << y2 << endl;
            int diff = abs(x1 - x2);
            if (diff <= k)
            {
                // cout << "diffrence : " << diff << endl;
                int ans = y1 + y2 + diff;
                max_ans = max(max_ans, ans);
            }
        }
    }

    return max_ans;
}

int main()
{
    vector<vector<int>> points = {{1, 3}, {2, 0}, {5, 10}, {6, -10}};
    ;
    cout << findMaxValueOfEquation(points, 1);
}