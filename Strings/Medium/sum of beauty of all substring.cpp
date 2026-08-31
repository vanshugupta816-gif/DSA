#include <bits/stdc++.h>
using namespace std;
int getMinCount(vector<int> &freq)
{
    int minCount = INT_MAX;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            minCount = min(minCount, freq[i]);
        }
    }
    return minCount;
}
int getMaxCount(vector<int> &freq)
{
    int maxCount = 0;
    for (int i = 0; i < 26; i++)
    {
        maxCount = max(maxCount, freq[i]);
    }
    return maxCount;
}
int beautySum(string s)
{
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        vector<int> freq(26, 0);
        for (int j = i; j < s.length(); j++)
        {
            freq[s[j] - 'a']++;
            int beauty = getMaxCount(freq) - getMinCount(freq);
            sum += beauty;
        }
    }
    return sum;
}

int main()
{
    // Test Case 1
    string s = "aabcb";
    cout << "Input : " << s << endl;
    cout << "Output: " << beautySum(s) << endl;
    cout << endl;

    return 0;
}
