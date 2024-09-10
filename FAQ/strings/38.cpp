#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
        return "1";

    }

    string target = countAndSay(n - 1);
    int freq = 1;
    //char element = str[0];
    string ans = "";
    int i = 1;
    for (i = 1; i < target.size(); i++) {
        if (target[i] != target[i - 1]) {
            ans += freq + '0';
            ans += target[i - 1];
            freq = 1;
           // cout << ans << endl;
        }
        else {
            freq++;
        }
    }
    ans += freq + '0';
    ans += target[i - 1];

    return ans;

        
    }
};