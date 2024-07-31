
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> temprature = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = temprature.size();
    vector<int> result(n, 0); // Result array to store the days to wait
    stack<int> s;             // Stack to store indices

    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && temprature[s.top()] <= temprature[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            result[i] = s.top() - i; // Calculate the number of days to wait
        }
        s.push(i); // Push current index onto the stack
    }

    for (int i = 0; i < n; ++i)
    {
        cout << "Days to wait for a warmer temperature for day " << i << ": " << result[i] << endl;
    }

    return 0;
}