// https://leetcode.com/problems/fibonacci-number/
#include <iostream>
using namespace std;
int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    int num;
    cin >> num;
    cout << fib(num);
    return 0;
}