#include <bits/stdc++.h>

using namespace std;

// ap 1
string largestOddNumber(string str)
{
    int lastOddindex;
    int n = str.size();
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        char ch = str[i];
        int num = '0' - ch;
        if (num % 2 != 0)
        {
            lastOddindex = i;
            break;
        }
    }
    if (i < 0)
    {
        return "";
    }
    else
    {
        return str.substr(0, lastOddindex - 0 + 1);
    }
}

// ap 2

bool isOdd(string str)
{

    int number = 0;
    for (int i = 0; i < str.size(); i++)
    {
        number = (number * 10) + ('0' - str[i]);
        // cout << number << endl;
    }

    if (number % 2 != 0)
    {
        return true;
    }

    return false;
}

int main()
{
    string str = "62433778";
    string final = "";
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        string ans = "";
        for (int j = i; j < n; j++)
        {
            ans += str[j];
            bool odd = isOdd(ans);
            if (odd && final.size() < ans.size())
            {
                final = ans;
                cout << "final" << final << endl;
            }
        }
    }
    cout << "after loop , final is: " << final << endl;
    return 0;
}