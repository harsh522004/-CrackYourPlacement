#include <bits/stdc++.h>
using namespace std;

bool isPalindrom(string s, int start , int end) {
    while (start <= end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void helper(string s, int index, vector<vector<string>> &result, vector<string> &path) {
    // Debug: Print current index and path
    cout << "helper called with index = " << index << " and path = { ";
    for (const string& p : path) {
        cout << p << " ";
    }
    cout << "}" << endl;

    if (index >= s.size()) {
        result.push_back(path);
        
        // Debug: Base case reached
        cout << "Base case: end of string reached, current path added to result." << endl;
        return;
    }

    for (int i = index; i < s.size(); i++) {
        if (isPalindrom(s, index, i)) {
            string currentPalindrome = s.substr(index, (i + 1) - index);
            
            // Debug: Found a palindrome
            cout << "Palindrome found: " << currentPalindrome << " from index " << index << " to " << i << endl;
            
            path.push_back(currentPalindrome);
            helper(s, i + 1, result, path);
            
            // Debug: Backtracking
            cout << "Backtracking: removing " << path.back() << " from path." << endl;
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> path;
    helper(s, 0, result, path);
    return result;
}

int main() {
    vector<vector<string>> result;
    result = partition("aabb");

    cout << "Final Partitions: " << endl;
    for (auto it : result) {
        for (auto k : it) {
            cout << k << " ";
        }
        cout << endl;
    }
    return 0;
}
