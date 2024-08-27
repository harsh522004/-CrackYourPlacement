#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<string> generateParenthesis(int n)
{
}

void generate(int open, int close, vector<string> &ans, string &current, stack<char> &st)
{
    if (open == 0 && close == 0)
    {
        ans.push_back(current);
        return;
    }

    // add open
    if (open != 0 && open <= close)
    {
        current = current + "(";
        st.push('(');
        generate(open - 1, close, ans, current, st);
        current.pop_back();
        st.pop();
    }

    // add close
    if (close != 0 && !st.empty() && st.top() == '(')
    {
        current += ")";
        st.pop();
        generate(open, close - 1, ans, current, st);
        current.pop_back();
        st.push('(');
    }
}
int main()
{
    vector<string> ans;
    stack<char> st;
    string current = "";
    generate(3, 3, ans, current, st);
    cout << "end" << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}