//https://leetcode.com/problems/valid-anagram/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        int freq[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            freq[s[i]- 'a']++;
            freq[t[i] - 'a']--;
        }
        
        for(auto i: freq)
            if (i != 0) {
                return false;
            }
        
        
        return true;
    }
int main()
{
    string A;string B;
    getline(cin, A);
    cout<<"Enter for B";

    getline(cin, B);
    cout << isAnagram(A,B);
    return 0;
}