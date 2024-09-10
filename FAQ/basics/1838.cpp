#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        int left = 0;
        int right = 0;
        int n = nums.size();
        long long total = 0;
        int maxSize = 0;
        sort(nums.begin(), nums.end());
        while (right < n)
        {

            int windowSize = right - left + 1;
            long long imagineSum = static_cast<long long>(nums[right]) * windowSize;
            total += nums[right];
            long long actualSum = total + k;
            if (imagineSum <= actualSum)
            {
                maxSize = max(maxSize, windowSize);
                right++;
            }
            else
            {
                total = total - nums[left] - nums[right];
                left++;
            }
        }
        return maxSize;
    }
};