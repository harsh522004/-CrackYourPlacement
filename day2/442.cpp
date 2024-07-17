#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        int currentIndex = nums[i];

        if (currentIndex < 0)
        {
            currentIndex = currentIndex * -1;
        }

        currentIndex--;

        cout << "current index : " << currentIndex << endl;
        if (nums[currentIndex] < 0)
        {
            ans.push_back(abs(nums[i]));
        }
        else
        {
            nums[currentIndex] = nums[currentIndex] * -1;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {10, 2, 5, 10, 9, 1, 1, 4, 3, 7};
    vector<int> ans = findDuplicates(nums);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}