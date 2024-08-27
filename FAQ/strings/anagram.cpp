#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str1 = "gram";
    string str2 = "aram";
    bool isAnagram = false;

    // first
    // sort(str1.begin(), str1.end());
    // sort(str2.begin(), str2.end());

    // if (str1 == str2)
    // {
    //     isAnagram = true;
    // }

    // second
    // map<char, int> count2;
    // map<char, int> count1;
    // int n = str1.size();
    // int m = str2.size();
    // if (n != m)
    // {
    //     return false;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     char first = str1[i];
    //     char second = str2[i];

    //     count1[first]++;
    //     count2[second]++;
    // }

    // for (auto i : count1)
    // {
    //     int count = i.second;
    //     char ch = i.first;
    //     if (count2.find(ch) == count2.end())
    //     {
    //         return false;
    //     }
    //     if (count2[ch] != count1[ch])
    //     {
    //         return false;
    //     }
    // }
    // cout << isAnagram << endl;
    return 0;
}