#include <bits/stdc++.h>
using namespace std;
bool rotateString(string s, string goal)
{
    if (s.length() != goal.length())
        return false;
    return (s + s).find(goal) != string::npos;
}

int main()
{
    // Test case
    string s = "abcde";
    string goal = "cdeab";
    if (rotateString(s, goal))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
