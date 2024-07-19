#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxArea(vector<int> &height)
{
    int max_area = 0;
    int start = 0;
    int end = height.size() - 1;
    while (start < end)
    {

        int w = end - start;
        int h = min(height[start], height[end]);
        max_area = max(max_area, w * h);
        // cout << "start : " << start << endl;
        // cout << "end : " << end << endl;
        // cout << "width : " << w << endl;
        // cout << "hight : " << h << endl;
        // cout << "area : " << max_area << endl;
        if (height[start] == height[end])
        {
            // Safe handling by just moving one of the pointers
            start++;
        }
        else
        {
            (height[start] > height[end]) ? end-- : start++;
        }
    }
    return max_area;
}
int main()
{
    // vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    // vector<int> height = {1, 1};
    // vector<int> height = {1, 2, 3, 4, 5};
    // vector<int> height = {5, 4, 3, 2, 1};
    // vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    // vector<int> height = {5, 5, 5, 5, 5};
    // vector<int> height = {1, 3, 2, 5, 2, 4, 1, 6, 1};
    // vector<int> height = {5};
    vector<int> height = {};

    cout << maxArea(height);
    return 0;
}
