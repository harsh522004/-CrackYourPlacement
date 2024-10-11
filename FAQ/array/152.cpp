#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &nums)
{

    int n = nums.size();
    int pre_mul = 1;
    int suf_mul = 1;
    int max_mul = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pre_mul == 0)
            pre_mul = 1;
        if (suf_mul == 0)
            suf_mul = 1;

        pre_mul = pre_mul * nums[i];
        suf_mul = suf_mul * nums[n - i - 1];
        int ans = max(pre_mul, suf_mul);
        max_mul = max(ans, max_mul);
    }
    return max_mul;
}
int main()
{
    vector<int> nums = {2, -5, -2, -4, 3};
    cout << maxProduct(nums);
    return 0;
}
