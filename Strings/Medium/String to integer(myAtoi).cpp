#include <bits/stdc++.h>
using namespace std;
int myAtoi(string s)
{
    int i = 0, n = s.length();
    // Skip leading spaces
    while (i < n && s[i] == ' ')
    {
        i++;
    }
    // Check sign
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-'))
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }
    long long result = 0;
    // Convert digits
    while (i < n && isdigit(s[i]))
    {
        result = result * 10 + (s[i] - '0');
        // Handle overflow
        if (sign * result > INT_MAX)
            return INT_MAX;
        if (sign * result < INT_MIN)
            return INT_MIN;
        i++;
    }
    return sign * result;
}

int main()
{

    // Test cases (No cin used)
    cout << myAtoi("42") << endl;              // 42
    cout << myAtoi("   -42") << endl;          // -42
    cout << myAtoi("4193 with words") << endl; // 4193

    return 0;
}
