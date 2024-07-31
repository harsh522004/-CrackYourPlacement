// Evaluate Reverse Polish Notation
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int evalRPN(vector<string> &tokens)
{
    stack<int> store;
    for (int i = 0; i < tokens.size(); i++)
    {
        string current = tokens[i];
        cout << "current string  : " << current << endl;

        if (current == "+")
        {
            int a = store.top();
            store.pop();
            int b = store.top();
            store.pop();

            int sum = a + b;
            cout << "sum added into stack : " << trunc(sum) << endl;
            store.push(trunc(sum));
        }
        else if (current == "-")
        {
            int a = store.top();
            store.pop();
            int b = store.top();
            store.pop();

            int sub = b - a;
            cout << "sub added into stack : " << trunc(sub) << endl;
            store.push(trunc(sub));
        }
        else if (current == "*")
        {
            int a = store.top();
            store.pop();
            int b = store.top();
            store.pop();

            int mul = a * b;
            cout << "mul added into stack : " << trunc(mul) << endl;
            store.push(trunc(mul));
        }
        else if (current == "/")
        {
            int a = store.top();
            store.pop();
            int b = store.top();
            store.pop();

            int div = b / a;
            cout << "div added into stack : " << trunc(div) << endl;
            store.push(trunc(div));
        }
        else
        {
            // convert sting into int
            int num = stoi(current);
            cout << "value added into stack : " << trunc(num) << endl;
            store.push(trunc(num));
        }
    }

    int ans = store.top();
    return ans;
}
int main()
{
    vector<string> tokens = {"5", "1", "2", "+", "4", "*", "+", "3", "-"};
    cout << evalRPN(tokens) << "\n\n";
    return 0;
}