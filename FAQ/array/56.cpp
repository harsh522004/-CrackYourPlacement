#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if (n == 0)
        return {};
    vector<vector<int>> result;

    vector<int> desicion = intervals[0];
    for (int i = 0; i < n; i++)
    {
        vector<int> current = intervals[i];
        if (desicion[0] <= current[1] && current[0] <= desicion[1])
        {
            desicion[0] = min(desicion[0], current[0]);
            desicion[1] = max(desicion[1], current[1]);
        }
        else
        {
            result.push_back(desicion);
            desicion = current;
        }
    }
    result.push_back(desicion);
    return result;
}
int main()
{
    // your code goes here
    vector<vector<int>> intervals = {
        {1,
         5},
        {0,
         3}

    };
    vector<vector<int>> result = merge(intervals);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}