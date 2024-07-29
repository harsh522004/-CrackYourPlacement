#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void permutations(vector<vector<int>> &res,
                  vector<int> &arr, int l, int h, set<vector<int>> &isExist)
{
    // Base case
    // Add the vector to result and return
    if (l == h + 1)
    {

        // check uniquie ness
        if (isExist.find(arr) == isExist.end())
        {
            res.push_back(arr);
            isExist.insert(arr);
        }
        return;
    }

    // Permutations made
    for (int i = l; i <= h; i++)
    {

        // Swapping
        swap(arr[l], arr[i]);

        // Calling permutations for
        // next greater value of l
        permutations(res, arr, l + 1, h, isExist);

        // Backtracking
        swap(arr[l], arr[i]);
    }
}

vector<vector<int>> uniquePerms(vector<int> &arr, int n)
{

    set<vector<int>> isExist;
    vector<vector<int>> res;
    permutations(res, arr, 0, n, isExist);
    sort(res.begin(), res.end());

    return res;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    vector<vector<int>> ans = uniquePerms(arr, 2);
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
