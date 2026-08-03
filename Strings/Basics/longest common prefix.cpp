#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &str)
{
    sort(str.begin(), str.end());
    string s1 = str[0];
    string s2 = str[str.size() - 1];
    int idx = 0;
    while (idx < min(s1.length(), s2.length()))
    {
        if (s1[idx] == s2[idx])
        {
            idx++;
        }
        else
            break;
    }
    return idx == 0 ? "" : s1.substr(0, idx);
}
int main()
{
    vector<string> str = {"flower", "flow", "flight"};
    string ans = longestCommonPrefix(str);
    cout << "Longest Common Prefix: " << ans << endl;
    return 0;
}
