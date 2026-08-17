#include <bits/stdc++.h>
using namespace std;
// Method 1: Generate and count all substrings
long long countSubstringsM1(string s)
{
    int n = s.length();
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        string temp = "";
        for (int j = i; j < n; j++)
        {
            temp += s[j];
            cout << temp << " ";
            ans++;
        }
        cout << endl;
    }
    return ans;
}

// Method 2: Using Formula
long long countSubstringsM2(string s)
{
    long long n = s.length();
    return (n * (n + 1)) / 2;
}

int main()
{
    string s = "abcd";
    cout << "All Substrings:" << endl;
    long long ans1 = countSubstringsM1(s);
    cout << "\nTotal Substrings (Method 1): " << ans1 << endl;
    cout << "Total Substrings (Method 2): " << countSubstringsM2(s) << endl;
    return 0;
}
