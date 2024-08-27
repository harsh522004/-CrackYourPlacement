#include <iostream>
#include <string>
#include <stack>
using namespace std;

string reverseWords(string s)
{
    // Remove trailing and leading space
    int start = -1;
    while (s[start + 1] == ' ')
    {
        start++;
        cout << "Skipping leading space, start: " << start << endl;
    }
    int end = s.size();
    while (s[end - 1] == ' ')
    {
        end--;
        cout << "Skipping trailing space, end: " << end << endl;
    }

    start++;
    end--;

    cout << "start is : " << start << "  " << "end is : " << end << endl;

    // Start reverse string
    stack<char> st;
    string test;
    for (int i = end; i >= start; i--)
    {
        cout << "Current character: " << s[i] << " at index " << i << endl;
        if (s[i] != ' ')
        {
            cout << "Character is not a space, pushing to stack: " << s[i] << endl;
            st.push(s[i]);
        }
        else
        {
            cout << "Encountered a space" << endl;
            // Pop characters from stack to form the word
            while (!st.empty())
            {
                char temp = st.top();
                st.pop();
                test += temp;
                cout << "Popped from stack and added to test: " << temp << endl;
            }
            if (!test.empty())
            {
                test += ' ';
                cout << "Added space to test: " << test << endl;
            }

            // Skip consecutive spaces
            while (i >= start && s[i] == ' ')
            {
                i--;
                cout << "Skipping space at index " << i << endl;
            }
            i++;
        }
    }

    // Pop any remaining characters from stack to form the last word
    while (!st.empty())
    {
        char temp = st.top();
        st.pop();
        test += temp;
        cout << "Popped from stack and added to test (last word): " << temp << endl;
    }

    // Remove trailing space if present
    if (!test.empty() && test.back() == ' ')
    {
        test.pop_back();
        cout << "Removed trailing space from test: " << test << endl;
    }

    return test;
}

int main()
{
    string s = "   example   good a   ";
    cout << "Reversed words: \"" << reverseWords(s) << "\"" << endl;
    return 0;
}
