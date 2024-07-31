#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
vector<int> prev_smaller_equal_element_index(vector<int> &arr, int n)
{
    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i]) // don't take >= as we have to consider for smaller equal element also eg [1,1,1]
        {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}
vector<int> next_smaller_element_index(vector<int> &arr, int n)
{
    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int n = arr.size();
    vector<int> prev(n);
    vector<int> next(n);
    prev = prev_smaller_equal_element_index(arr, n); // used to store the index of the previous smallest element;
    next = next_smaller_element_index(arr, n);
    // for(auto it: prev) cout<<it<<" ";
    // cout<<endl;
    // for(auto it: next) cout<<it<<" ";
    // // return 0;
    long long sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        long long left = i - prev[i];
        long long right = next[i] - i;
        sum = (sum + (left * right * arr[i]) % MOD) % MOD;
    }
    return sum;
}

// approch 1
// int main()
// {
//     vector<int> arr = {11, 81, 94, 43, 3};
//     int n = arr.size();
//     int sum = 0;
//     int prev_small = -1;

//     for (int i = 0; i < n; i++)
//     {
//         prev_small = arr[i];
//         sum = (sum + prev_small) % MOD;
//         cout << "i: " << i << ", arr[i]: " << arr[i] << ", sum: " << sum << endl;

//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] > prev_small)
//             {
//                 sum = (sum + prev_small) % MOD;
//             }
//             else
//             {
//                 prev_small = arr[j];
//                 sum = (sum + arr[j]) % MOD;
//             }
//             cout << "  j: " << j << ", arr[j]: " << arr[j] << ", prev_small: " << prev_small << ", sum: " << sum << endl;
//         }
//     }

//     cout << "Final sum: " << sum << endl;
//     return 0;
// }
