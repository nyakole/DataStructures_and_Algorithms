// https://leetcode.com/problems/reverse-words-in-a-string-iii
#include <iostream>
#include <string>
using namespace std;
string isBalanced(string s) {
    int i=-1;
        for(auto& ch:s){
            if(ch=='(' || ch=='{' || ch=='[')
                s[++i]=ch;
            else{
                if(i>=0 && ((s[i]=='(' && ch==')') || (s[i]=='{' && ch=='}') || (s[i]=='[' && ch==']')))
                    i--;
                else
                    return "NO";
            }
        }
        return "YES";

}
int main()
{
    string str;
    getline(cin, str);
    cout << isBalanced(str);
    return 0;
}