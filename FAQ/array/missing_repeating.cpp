// Given an unsorted array arr of of positive integers. One number A from set [1, 2,....,n] is missing and one number B occurs twice in array. Find numbers A and B.

// Note: The test cases are generated such that there always exists one missing and one repeating number within the range [1,n].

// gfg
#include <bits/stdc++.h>
using namespace std;
vector<int> findTwoElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result;
    int a;
    int b;

    vector<bool> helper(n, false);
    for (int i = 0; i < n; i++)
    {
        if (helper[arr[i] - 1] == true)
        {
            b = arr[i];
        }
        else
        {
            helper[arr[i] - 1] = true;
        }
    }
    for (auto it : helper)
    {
        cout << it << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (helper[i] == false)
        {
            a = i + 1;
        }
    }

    result.push_back(a);
    result.push_back(b);
    return result;
}
int main()
{
    // your code goes here
    vector<int> arr = {2, 2};
    vector<int> ans = findTwoElement(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
