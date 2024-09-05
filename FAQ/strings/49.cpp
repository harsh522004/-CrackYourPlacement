#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// vector<vector<string>> groupAnagrams(vector<string> &strs)
// {
// }
int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> strs1;
    vector<vector<string>> ans;
    map<string, vector<string>> hash1;
    // sort(strs.begin(), strs.end());
    for (int i = 0; i < strs.size(); i++)
    {
        /* code */
        string init = strs[i];
        sort(strs[i].begin(), strs[i].end());
        hash1[strs[i]].push_back(init);
    }

    for (auto &i : hash1)
    {
        ans.push_back(i.second);
    }

    // for (auto an : strs)
    // {
    //     cout << an << " ";
    // }
    // cout << endl;

    // map<string, vector<int>> hash;
    // for (int i = 0; i < strs1.size(); i++)
    // {
    //     hash[strs1[i]].push_back(i);
    // }

    // for (auto i : hash)
    // {
    //     vector<string> test;
    //     for (auto j : i.second)
    //     {
    //         test.push_back(strs[j]);
    //     }
    //     ans.push_back(test);
    // }

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}