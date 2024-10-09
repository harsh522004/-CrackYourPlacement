#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxSubarraySum(vector<int> &arr)
{
    int n = arr.size();
    int max_sum = arr[0];
    int pre_sum = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        max_sum = max(max_sum, pre_sum);
        if (pre_sum < 0)
        {
            pre_sum = 0;
        }
    }
    return max_sum;
}

int main()
{
    vector<int> arr = {12, 3, 4, 5, -2};
    cout << maxSubarraySum(arr);
    return 0;
}