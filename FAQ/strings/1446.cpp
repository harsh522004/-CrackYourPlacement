// The power of the string is the maximum length of a non-empty substring that contains only one unique character.
// Given a string s, return the power of s.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxPower(string s)
{
    if (s.empty())
    {
        return 0;
    }

    int n = s.size();
    int max_len = 1;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            count++;
        }
        else
        {
            max_len = max(max_len, count);
            count = 1;
        }
    }

    max_len = max(max_len, count);
    return max_len;
}
int main()
{
}