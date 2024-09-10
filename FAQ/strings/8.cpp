#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        int firstIndex = 0;
        int nonZeroIndex = 0;
        bool isPositive = true;
        long long number = 0;
        int n = s.size();
        // int INT_MAX = 2147483647;
        // int INT_MIN = -2147483648;

        // ignore whitespace
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
                firstIndex++;
            else
                break;
        }
        // cout << "first index : " << firstIndex << endl;
        // cout << "at first index : " << s[firstIndex] << endl;

        // recognize the sign
        if (s[firstIndex] == '-')
        {
            isPositive = false;
            firstIndex++;
        }

        else if (s[firstIndex] == '+')
        {
            firstIndex++;
        }

        // unvalid if firstIndex is not 0 - 9 and - +
        else if (s[firstIndex] >= 65 && s[firstIndex] <= 122)
        {
            // cout << "not number" << endl;
            return 0;
        }

        nonZeroIndex = firstIndex;
        // cout << nonZeroIndex << endl;
        // cout << s[nonZeroIndex] << endl;

        while (nonZeroIndex < n && s[nonZeroIndex] >= 48 && s[nonZeroIndex] <= 57)
        {
            // cout << "current non zero is : " << s[nonZeroIndex] << endl;
            number = number * 10 + (s[nonZeroIndex] - '0');
            // cout << "number is : " << number << endl;

            if (isPositive && number > INT_MAX)
            {
                return INT_MAX;
            }
            if (!isPositive && -number < INT_MIN)
            {
                return INT_MIN;
            }
            nonZeroIndex++;
        }

        if (!isPositive)
            number = number * -1;
        // cout << "number is : " << number << endl;
        return (int)number;
    }
};