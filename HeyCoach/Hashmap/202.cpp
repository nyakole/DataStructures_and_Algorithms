// https://leetcode.com/problems/happy-number/description/
// https://leetcode.com/problems/majority-element/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
  int nextNumber(int n){
        int newNumber = 0;
        while(n!=0){
            int num = n%10;
            newNumber += num*num;
            n = n/10;
        }
        return newNumber;
    }
    bool isHappy(int n) {
        int slowPointer = n;
        int fastPointer = nextNumber(n);
        while(fastPointer != 1 && fastPointer != slowPointer){
            slowPointer = nextNumber(slowPointer);
            fastPointer = nextNumber(nextNumber(fastPointer));
        }
        return fastPointer==1;
    }
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

   /*  vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    } */

    cout << "Output: " << isHappy(n) << endl;

    return 0;
}