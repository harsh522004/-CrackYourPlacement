#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sumOfBeauty(string s)
{
    int sum = 0;
    // First loop for starting index
    for (int i = 0; i < s.length(); i++)
    {

        vector<int> freqString(26, 0);
        // Second loop is generating sub-string
        for (int j = i; j < s.length(); j++)
        {
            char t = s[j];
            freqString[t - 'a']++;
            int max_count = INT_MIN;
            int min_count = INT_MAX;
            for (int k = 0; k < 26; k++)
            {
                if (freqString[k] > 0)
                {
                    max_count = max(max_count, freqString[k]);
                    min_count = min(min_count, freqString[k]);
                }
            }
            sum += (max_count - min_count);
        }
    }
    cout << sum;
}

int main()
{
    // cout << beautySum("abccba");
    sumOfBeauty("aabcb");
    return 0;
}