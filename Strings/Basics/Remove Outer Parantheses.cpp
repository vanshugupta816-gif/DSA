#include <bits/stdc++.h>
using namespace std;
string RemoveOuterParantheses(string s)
{
    int count = 0;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
            count--;
        if (count != 0)
            ans += s[i];
        if (s[i] == '(')
            count++;
    }
    return ans;
}

int main()
{
    string s = "(()())(())";
    string result = RemoveOuterParantheses(s);
    cout << result << endl;
    return 0;
}
