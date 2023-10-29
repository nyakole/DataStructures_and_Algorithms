// https://leetcode.com/problems/valid-parentheses/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;
int solve(string A) {
    int c=0;
    int ans =0;
    for(int i =0;i<A.size();i++  ){
        if(A[i]=='>') c++;
        else if (A[i]=='<') ans+=c;
        
    }
    return ans;
}
int main()
{
    string n;
    cout << "Enter the number of elements: ";
    getline(cin, n);

    cout << "Output: " << solve(n) << endl;

    return 0;
}