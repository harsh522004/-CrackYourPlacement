#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size() - 3; i++)
    {
        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            set<long long> hashset;
            for (int k = j + 1; j < nums.size() - 1; k++)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end())
                {
                    vector<int> test = {nums[i],
                                        nums[j],
                                        nums[k], (int)(fourth)};

                    sort(test.begin(), test.end());
                    ans.push_back(test);
                }

                hashset.insert(nums[k]);
            }
        }
    }

    return ans;
}
int main()
{

    vector<int> height = {};

    

    return 0;
}
