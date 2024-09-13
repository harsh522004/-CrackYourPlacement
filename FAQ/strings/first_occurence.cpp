// gfg

#include <bits/stdc++.h>
using namespace std;

int findMatching(string text, string pattern)
{
    if (text == pattern)
    {
        return 0;
    }

    int textIndex = 0;
    int patternIndex = 0;
    int firstOccurence = -1;

    int n = text.size();
    int m = pattern.size();

    if (n < m)
    {
        return -1;
    }

    int ansIndex = -1;

    while (textIndex < text.size())
    {
        if (text[textIndex] == pattern[patternIndex])
        {

            while (text[textIndex] == pattern[patternIndex] && textIndex < n && patternIndex < m)
            {
                textIndex++;
                patternIndex++;
            }

            if (patternIndex >= m)
            {
                ansIndex = textIndex - patternIndex;

                break;
            }
            else
            {
                textIndex = textIndex - patternIndex + 1;

                patternIndex = 0;
            }
        }
        else
        {
            textIndex++;
        }
    }

    return ansIndex;
}

int main()
{
    string text = "mississippi";
    string pattern = "issip"; // 4

    cout << findMatching(text, pattern);

    // my -1
    return 0;
}
