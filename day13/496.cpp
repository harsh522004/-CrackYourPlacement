#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
// {
// }
int main()
{
    vector<int> nums1 = {2, 4, 3};
    vector<int> nums2 = {1, 2, 1, 3, 4, 2, 3};
    int n = nums2.size();
    stack<int> st;

    vector<pair<int, int>> ans;

    for (int i = n - 1; i >= 0; i--)
    {

        if (st.empty())
        {
            ans.push_back({nums2[i], -1});
            st.push(nums2[i]);
        }
        else
        {
            int top = st.top();
            if (top > nums2[i])
            {
                ans.push_back({nums2[i], top});
                st.push(nums2[i]);
            }
            else
            {
                while (!st.empty() && st.top() <= nums2[i])
                {
                    st.pop();
                }
                int next = st.empty() ? -1 : st.top();
                ans.push_back({nums2[i], next});
                st.push(nums2[i]);
            }
        }
    }
    map<int, int> tamp;

    for (auto i : nums1)
    {
        tamp[i] = -1;
    }

    for (auto i : ans)
    {
        if (tamp.find(i.first) != tamp.end())
        {
            tamp[i.first] = i.second;
        }
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        if (tamp.find(nums1[i]) != tamp.end())
        {
            nums1[i] = tamp[nums1[i]];
        }
    }
    for (auto i : nums1)
    {
        cout << i << " ";
    }
    return 0;
}