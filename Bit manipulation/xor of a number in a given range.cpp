#include <bits/stdc++.h>
using namespace std;
int fun(int n)
{
    if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else if (n % 4 == 3)
        return 0;
    else
        return n;
}

int main()
{
    int L = 1, R = 10;
    int ans = fun(L - 1) ^ fun(R);
    cout << ans << endl;
    return 0;
}
