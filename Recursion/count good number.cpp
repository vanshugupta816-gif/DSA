#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

// Calculate base^power
long long power(long long base, long long power)
{
    long long answer = 1;
    while (power > 0)
    {
        answer = (answer * base) % MOD;
        power--;
    }
    return answer;
}

int main()
{
    long long n = 4;
    // Number of even positions
    long long even = (n + 1) / 2;
    // Number of odd positions
    long long odd = n / 2;
    // 5 choices for even positions
    long long evenWays = power(5, even);
    // 4 choices for odd positions
    long long oddWays = power(4, odd);
    // Total answer
    long long answer = (evenWays * oddWays) % MOD;
    cout << answer << endl;

    return 0;
}
