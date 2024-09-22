#include <bits/stdc++.h>
using namespace std;
void generate(vector<vector<int>> &result, vector<int> &candidates, int index, int target, vector<int> &ds)
{
    // Debug statement: current state
    cout << "Index: " << index << ", Target: " << target << ", Current DS: ";
    for (int num : ds)
        cout << num << " ";
    cout << endl;

    if (target == 0)
    {
        cout << "Target reached 0! Current combination: ";
        for (int num : ds)
            cout << num << " ";
        cout << endl;

        result.push_back(ds);
        return;
    }

    // Base case
    if (index >= candidates.size() || target < 0)
    {
        cout << "Base case hit! Returning..." << endl;
        return;
    }

    if (target == 0)
    {
        cout << "Target reached 0! Current combination: ";
        for (int num : ds)
            cout << num << " ";
        cout << endl;

        result.push_back(ds);
        return;
    }

    // Include current candidate
    ds.push_back(candidates[index]);
    cout << "Including: " << candidates[index] << endl;
    generate(result, candidates, index + 1, target - candidates[index], ds);
    ds.pop_back(); // Backtrack
    cout << "Backtracking after including: " << candidates[index] << endl;

    // Exclude current candidate
    cout << "Excluding: " << candidates[index] << endl;
    generate(result, candidates, index + 1, target, ds);
}

int main()
{
    // your code goes here
    vector<vector<int>> result;
    vector<int> candidates = {
        10, 1, 2, 7, 6, 1, 5};
    vector<int> ds;
    generate(result, candidates, 0, 8, ds);
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