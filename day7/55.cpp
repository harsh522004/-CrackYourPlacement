// jump game
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums, vector<int> &dp, int index)
{
    if (index >= nums.size())
    {
        return false;
    }

    if (index == nums.size() - 1)
    {
        return true;
    }

    int maxJump = nums[index];
    for (int i = 1; i <= maxJump; i++)
    {
        int newIndex = index + i;
        if (newIndex < nums.size() && dp[newIndex] == -1)
        {
            bool ans = canJump(nums, dp, newIndex);
            if (ans)
            {
                dp[index] = 1;
                return true;
            }
        }
        else if (newIndex < nums.size())
        {
            if (dp[newIndex] == 1)
            {
                dp[index] = 1;
                return true;
            }
            else
            {
                dp[index] = 0;
            }
        }
    }
    dp[index] = 0;
    return false;
}
int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    vector<int> dp(5, -1);
    bool result = canJump(nums, dp, 0);
    cout << (result ? "Can jump" : "Cannot jump") << endl;
    return 0;
}
