// leet 287 :  Find the Duplicate Number
#include <iostream>
#include <vector>
using namespace std;
int findDuplicate(vector<int> &nums)
{
    // nested approch
    // for (int i = 0; i < nums.size() - 1; i++)
    // {
    //     for (int j = i + 1; j < nums.size(); j++)
    //     {
    //         if (nums[i] == nums[j])
    //         {
    //             return nums[i];
    //         }
    //     }
    // }

    int slow = 0;
    int fast = 0;
    int ans;

    while (true)
    {
        if (nums[slow] == nums[fast])
        {
            ans = nums[slow];
            break;
        }
        else
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {3, 1, 3, 4, 2};
    int ans = findDuplicate(nums);
    cout << ans;
    return 0;
}