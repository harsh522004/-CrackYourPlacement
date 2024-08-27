// Given a string S, the task is to print all the duplicate characters with their occurrences in the given string.

// Example:

// Input: S = “geeksforgeeks”
// Output:
// e, count = 4
// g, count = 2
// k, count = 2
// s, count = 2

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "geeksforgeeks";
    int n = s.size();
    sort(s.begin(), s.end());

    cout << s << endl;
    int count = 1;
    int i = 1;

    for (i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            count++;
        }
        else
        {
            if (count > 1)
            {
                cout << s[i - 1] << " -> " << count << endl;
            }

            count = 1;
        }
    }

    if (count > 1)
        cout << s[i - 1] << " -> " << count << endl;

    return 0;
}