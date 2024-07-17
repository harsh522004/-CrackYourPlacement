// Chocolate Distribution Problem
// Given an array A[ ] of positive integers of size N,
//  where each value represents the number of chocolates in a packet.
//  Each packet can have a variable number of chocolates.
//  There are M students, the task is to distribute chocolate packets among M students such that :
// 1. Each student gets exactly one packet.
// 2. The difference between maximum number of chocolates given to a student and
// minimum number of chocolates given to a student is minimum.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());
    int start = 0;
    int end = m - 1;
    long long min_dif = INT_MAX;
    while (end < a.size())
    {
        cout << "start element : " << a[start] << endl;
        cout << "end element : " << a[end] << endl;
        long long difference = a[end] - a[start];
        cout << "difference is : " << difference << endl;
        min_dif = min(difference, min_dif);
        cout << "min difference is : " << min_dif << endl;
        start++;
        end++;
    }
    return min_dif;
}
int main()
{
    vector<long long> choclates = {7, 3, 2, 4, 9, 12, 56};
    long long childs = 3;
    findMinDiff(choclates, 8, childs);
    return 0;
}