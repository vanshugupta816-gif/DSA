#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t)
{
    unordered_map<char, int> ma;
    unordered_map<char, int> mb;
    for (const auto &el : s)
    {
        ma[el]++;
    }
    for (const auto &el : t)
    {
        mb[el]++;
    }
    return ma == mb;
}

int main()
{
    string s = "anagram";
    string t = "nagaram";
    if (isAnagram(s, t))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}
