#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
    int n = s.length();
    string ans = "";
    // Reverse the entire string
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++)
    {
        string word = "";
        while (i < n && s[i] != ' ')
        {
            word += s[i];
            i++;
        }
        // Reverse the individual word
        reverse(word.begin(), word.end());

        if (word.length() > 0)
        {
            ans += " " + word;
        }
    }
    return ans.substr(1);
}

int main()
{
    string s = "the sky is blue";
    cout << "Original String: " << s << endl;
    cout << "Reversed Words: " << reverseWords(s) << endl;
    return 0;
}
