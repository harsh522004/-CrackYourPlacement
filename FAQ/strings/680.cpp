#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "eeccccbebaeeabebccceea";
    int n = str.size();
    int left = 0;
    int right = n - 1;
    bool isValid = true;
    bool isChanged = false;

    while (left <= right)
    {
        if (str[left] != str[right])
        {
            if (!isChanged)
            {
                // Decide to remove a character
                if (str[left + 1] == str[right])
                {
                    // Remove left character
                    left++;
                }
                else if (str[right - 1] == str[left])
                {
                    // Remove right character
                    right--;
                }
                else
                {
                    // No valid palindrome after one removal
                    isValid = false;
                    break;
                }
                isChanged = true; // Mark that a removal has been made
            }
            else
            {
                // If a removal has already been made and still not matching
                isValid = false;
                break;
            }
        }
        else
        {
            // Move pointers inward if characters match
            left++;
            right--;
        }
    }
    if (isValid)
    {
        cout << "valid" << endl;
    }
    else
    {
        cout << "Not valid " << endl;
    }
    return 0;
}