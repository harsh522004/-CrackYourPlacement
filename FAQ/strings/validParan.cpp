#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {

        char current = s[i];
        if (current == '(' || current == '{' || current == '[')
        {
            st.push(current);
        }
        else if (current == ')' || current == '}' || current == ']')
        {
            if (st.empty())
            {
                return false;
            }
            char top = st.top();
            if (!((current == ')' && top == '(') ||
                  (current == ']' && top == '[') ||
                  (current == '}' && top == '{')))
            {
                return false;
            }

            st.pop();
        }
    }
    return st.empty();
}
int main()
{
    cout << isValid("[{([)}]]{}()[]") << endl;
    return 0;
}