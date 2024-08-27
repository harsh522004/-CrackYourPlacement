// Given a string str, find the length of the longest substring without repeating characters.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxLength1(string str)
{
    if (str.empty())
    {
        return 0;
    }
    int max_length = 1;
    for (int i = 0; i < str.size(); i++)
    {
        int j = i + 1;
        int length = 0;
        for (j; j < str.size(); j++)
        {
            if (str[i] == str[j])
            {
                max_length = max(max_length, length);
                break;
            }
            else
                length++;
        }
    }
    return max_length;
}

int maxLength2(string str)
{
    if (str.empty())
    {
        return 0;
    }
    int n = str.size();
    int max_length = 0;
    map<char, int> hash;
    int left = 0;
    int right = 0;
    while (left <= right && left < n && right < n)
    {
        cout << str[right];
        // if element alredy in string
        if (hash.find(str[right]) != hash.end())
        {
            if (hash[str[right]] >= left)
            {
                // count the length
                int length = right - left;

                // update max
                max_length = max(length, max_length);

                // now update left
                left = hash[str[right]] + 1;

                // update the hash map value for current char
                hash[str[right]] = right;
            }
            else
            {
                hash[str[right]] = right;
            }
            right++;
        }

        // if not then include it
        else
        {
            hash[str[right]] = right;
            right++;
        }
    }

    return max_length;
}
int main()
{
    cout << maxLength2(" ");
    return 0;
}