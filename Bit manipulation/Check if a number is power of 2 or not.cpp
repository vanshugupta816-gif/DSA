#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n)
{
    if (n <= 0)
    {
        return false;
    }
    while (n % 2 == 0)
    {
        n /= 2;
    }
    return n == 1;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (isPowerOfTwo(n))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}
