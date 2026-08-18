#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string s)
{

    int start = 0;
    int maxLen = 1;
    int n = s.length();
    for (int i = 1; i < n; i++)
    {
        // Odd Length Palindrome
        int l = i - 1;
        int r = i;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            if (r - l + 1 > maxLen)
            {
                maxLen = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }

        // Even Length Palindrome
        l = i - 1;
        r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            if (r - l + 1 > maxLen)
            {
                maxLen = r - l + 1;
                start = l;
            }

            l--;
            r++;
        }
    }
    return s.substr(start, maxLen);
}

int main()
{
    string s1 = "babad";
    cout << "Input: " << s1 << endl;
    cout << "Longest Palindrome: " << longestPalindrome(s1) << endl
         << endl;
    return 0;
}
