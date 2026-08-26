#include <bits/stdc++.h>
using namespace std;
int romanToInt(string s)
{
    unordered_map<char, int> hm;
    hm['I'] = 1;
    hm['V'] = 5;
    hm['X'] = 10;
    hm['L'] = 50;
    hm['C'] = 100;
    hm['D'] = 500;
    hm['M'] = 1000;
    int result = hm[s[s.length() - 1]];
    for (int i = s.length() - 2; i >= 0; i--)
    {
        if (hm[s[i]] < hm[s[i + 1]])
        {
            result = result - hm[s[i]];
        }
        else
        {
            result = result + hm[s[i]];
        }
    }
    return result;
}

int main()
{
    string s = "MCMXCIV";
    cout << "Roman Number : " << s << endl;
    cout << "Integer Value : " << romanToInt(s) << endl;
    return 0;
}
