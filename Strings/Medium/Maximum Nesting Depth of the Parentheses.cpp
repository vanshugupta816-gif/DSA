#include <bits/stdc++.h>
using namespace std;
int maxDepth(string s)
{
    int res = 0, cur = 0;
    for (char &c : s)
    {
        if (c == '(')
            res = max(res, ++cur);
        if (c == ')')
            cur--;
    }
    return res;
}

int main()
{
    string s = "(1+(2*3)+((8)/4))+1";
    cout << "String: " << s << endl;
    cout << "Maximum Depth: " << maxDepth(s) << endl;

    return 0;
}
