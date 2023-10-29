// https://leetcode.com/problems/my-calendar-i/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstddef>
#include <map>
using namespace std;

map<int, int> mp;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        auto it = mp.upper_bound(start);
		// it->first = min end time greater than start
		// it->second = start time of above obtained end time
        if (it == mp.end() || it->second >= end)
        {
            mp[end] = start;
            return true;
        }
        else
            return false;
    }

int main()
{
    int str;
    int str1;
    cin>>str;
    cout<<"enter second int";
    cin>>str1;
    cout << book(str, str1);
    return 0;
}