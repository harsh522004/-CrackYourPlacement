#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> arr = {"interspecies",
                          "interstellar",
                          "interstate"};

    sort(arr.begin(), arr.end());
    string ans = "";
    string first = arr[0];
    string last = arr[arr.size() - 1];
    for (int i = 0; i < min(first.size(), last.size()); i++)
    {
        if (first[i] != last[i])
        {
            cout << ans << endl;
            break;
        }
        ans = ans + first[i];
    }
    cout << "Loop End" << endl;
    return 0;
}