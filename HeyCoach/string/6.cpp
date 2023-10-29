// https://leetcode.com/problems/zigzag-conversion/
#include <iostream>
#include <string>
using namespace std;
string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        
        string result;
        int n = s.length();
        int cycleLen = 2 * numRows - 2;
        
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                result.push_back(s[j + i]);
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
                    result.push_back(s[j + cycleLen - i]);
                }
            }
        }
        
        return result;
    }
int main()
{
    string str;
    getline(cin, str);
    cout << convert(str,3);
    return 0;
}