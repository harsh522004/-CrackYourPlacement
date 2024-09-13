// Generate all binary strings without consecutive 1’s

#include <bits/stdc++.h>
using namespace std;

void generate (string &ans, int k){
    if(ans.size() == k){
        cout << ans << endl;
        return;
    }
    
    if(ans.size() == 0){
        ans.push_back('1');
        generate(ans,k);
        ans.pop_back();
    }
    
    // add 1 
    else if(ans.size() != 0 && ans[ans.size()-1] != '1'){
        ans.push_back('1');
        generate(ans,k);
        ans.pop_back();
    }
    
    ans.push_back('0');
    generate(ans,k);
    ans.pop_back();
    
}
int main() {
	// your code goes here
	string ans = "";
	generate(ans, 4);
	return 0;

}
