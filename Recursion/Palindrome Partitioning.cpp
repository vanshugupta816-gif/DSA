#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> path;
    func(0, s, path, res);
    return res;
}

void func(int index, string s, vector<string> &path, vector<vector<string>> &res)
{
    if (index == s.size())
    {
        res.push_back(path);
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        if (isPalindrome(s, index, i))
        {
            path.push_back(s.substr(index, i - index + 1));
            func(i + 1, s, path, res);
            path.pop_back();
        }
    }
}
bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "aab";
    vector<vector<string>> result = partition(s);
    cout << "Palindrome partitions are:\n";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
