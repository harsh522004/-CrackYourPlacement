// sub array sum == k
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> pre_map;
    pre_map[0] = 1;

    int prefixSum = 0;
    int count = 0;
    int i = 0;
    while (i < nums.size())
    {
        prefixSum = prefixSum + nums[i];
        int xSum = prefixSum - k;
        auto it = pre_map.find(xSum);
        if (it != pre_map.end())
        {
            count++;
        }
        pre_map[prefixSum]++;
        i++;
    }

    return count;
}

int main()
{
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    cout << subarraySum(nums, 5);
}