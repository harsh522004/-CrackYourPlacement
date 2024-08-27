// Find the Index of the First Occurrence in a String
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string haystack = "helloharsh";
    string needle = "ozhar";
    int n = haystack.size();
    int m = needle.size();
    for (int i = 0; i < n; i++)
    {
        if (haystack[i] == needle[0])
        {
            int FirstOccur = i;
            int j = 0;
            while (i < n && j < m && haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            if (j == m)
            {
                cout << "First Index : " << FirstOccur << endl;
                break;
            }
            else
            {
                i = FirstOccur;
            }
        }
    }
    cout << "Loop End" << endl;
    return 0;
}