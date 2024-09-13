#include <bits/stdc++.h>
using namespace std;

void generate(vector<vector<int>> &result,
              vector<int> &candidates, int index, int target, vector<int> &ds)
{

    if (index >= candidates.size() || target < 0)
    {
        return;
    }

    if (target == 0)
    {
        result.push_back(ds);
        return;
    }

    // includeing current one repeted times
    ds.push_back(candidates[index]);
    generate(result, candidates, index, target - candidates[index], ds);
    ds.pop_back();

    // not include

    generate(result, candidates, index + 1, target, ds);
}

int main()
{
    // your code goes here
    vector<vector<int>> result;
    vector<int> candidates = {2, 3, 6, 7};
    vector<int> ds;
    generate(result, candidates, 0, 7, ds);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
