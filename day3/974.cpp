// 974. Subarray Sums Divisible by K
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
        int reminder = prefixSum % k;
        if (reminder < 0)
        {
            reminder = reminder + k;
        }
        auto it = pre_map.find(reminder);
        if (it != pre_map.end())
        {
            count = count + pre_map[reminder];
        }
        pre_map[reminder]++;
        i++;
    }

    return count;
}

int main()
{
    vector<int> nums = {5};
    cout << subarraySum(nums, 9);
}