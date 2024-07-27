// 1209. Remove All Adjacent Duplicates in String II
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
string removeDuplicates(string s, int k)
{
    // element , current count
    stack<pair<char, int>> entry;

    for (int i = 0; i < s.size(); i++)
    {
        char currentChar = s[i];

        if (entry.empty())
        {
            entry.push(make_pair(currentChar, 1));
            continue;
        }

        if (currentChar == entry.top().first)
        {
            pair<char, int> top = entry.top();
            top = make_pair(top.first, top.second + 1);

            if (top.second == k)
            {
                entry.pop();
            }
            else
            {
                entry.pop();
                entry.push(top);
            }
        }
        else
        {
            entry.push(make_pair(currentChar, 1));
        }
    }

    string ans;
    while (!entry.empty())
    {
        pair<char, int> test = entry.top();
        entry.pop();
        int count = test.second;

        for (int i = 0; i < count; ++i)
        {
            ans += test.first;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string ans = removeDuplicates("pbbcggttciiippooaais", 2);
    cout << ans << endl;
    return 0;
}