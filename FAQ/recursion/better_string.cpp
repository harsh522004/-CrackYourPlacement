// better string in gfg

#include <bits/stdc++.h>
using namespace std;
// optimze

int countDistinct(string str)
{
    int n = str.size();
    vector<int> dp(n + 1, 0);
    unordered_map<char, int> hash;

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        char current_char = str[i - 1];
        dp[i] = 2 * dp[i - 1];

        // remove if any duplicate
        if (hash.find(current_char) != hash.end())
        {
            int lastIndex = hash[current_char];
            dp[i] = dp[i] - dp[lastIndex - 1];
        }

        hash[current_char] = i;
    }

    return dp[n];
}
void generate(string &str, vector<string> &subseq, int index, string &ans)
{

    if (index == str.size())
    {

        auto it = find(subseq.begin(), subseq.end(), ans);
        if (it == subseq.end())
        {
            // cout << ans << " ";
            subseq.push_back(ans);
        }
        return;
    }

    ans.push_back(str[index]);
    generate(str, subseq, index + 1, ans);
    ans.pop_back();

    generate(str, subseq, index + 1, ans);
}

int main()
{
    string str1 = "gfg";
    string str2 = "ggg";
    vector<string> str1vec;
    vector<string> str2vec;
    string ans = "";
    generate(str1, str1vec, 0, ans);
    ans = "";
    generate(str2, str2vec, 0, ans);
    for (auto i : str1vec)
    {
        cout << i << " ";
    }
    cout << "\n\n\n";
    for (auto i : str2vec)
    {
        cout << i << " ";
    }
    return 0;
}
