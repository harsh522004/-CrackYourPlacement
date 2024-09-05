#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

// int maxDepth(string s) {
//         int max_deapth = 0;
//         int count = 0;
//         for (int i = 0; i < s.size(); i++) {
//             char ch = s[i];
//             if (ch == '(') {
//                 count++;
//                 max_deapth = max(count, max_deapth);
//             } else if (ch == ')') {
//                 count--;
//             }
//         }
//         return max_deapth;
//     }

// approch 2
int maxDepth(string s)
{
    int max_deapth = INT_MIN;
    vector<char> test;

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            test.push_back('(');
            int n = test.size();
            max_deapth = max(n, max_deapth);
        }
        else if (ch == ')')
        {
            test.pop_back();
        }
    }
    return max_deapth;
}
int main()
{

    cout << maxDepth("(1)+((2))+(((3)))");
    return 0;
}
