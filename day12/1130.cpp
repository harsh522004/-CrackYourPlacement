#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
{
    if (left == right)
    {
        return 0;
    }

    int ans = INT_MAX;

    for (int i = left; i < right; i++)
    {
        ans = min(ans, (maxi[{left, i}] * maxi[{i + 1, right}] + solve(arr, maxi, left, i) + solve(arr, maxi, i + 1, right)));
    }

    return ans;
}

int main()
{
    vector<int> arr = {6, 2, 4};
    int n = arr.size();
    // max from index x to index y
    map<pair<int, int>, int> maxi;

    for (int i = 0; i < n; i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i; j < n; j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }

    cout << solve(arr, maxi, 0, n - 1);

    return 0;
}