#include <bits/stdc++.h>
using namespace std;
// string frequencySort(string s)
// {
//     vector<int> freq(128, 0);
//     // Count frequency of each character
//     for (auto ch : s)
//     {
//         freq[ch]++;
//     }
//     // Custom comparator
//     auto cmp = [&](char a, char b)
//     {
//         if (freq[a] == freq[b])
//             return a < b;         // If frequencies are equal, sort alphabetically
//         return freq[a] > freq[b]; // Higher frequency comes first
//     };
//     sort(s.begin(), s.end(), cmp);
//     return s;
// }

string frequencySort4(string s)
{
    // map every char of string...
    unordered_map<char, int> mpp;
    for (auto ch : s)
        mpp[ch]++;

    // creating a bucket data to store chars on their index (frq)
    vector<vector<char>> bucket_data(s.length() + 1);
    for (auto itt : mpp)
        bucket_data[itt.second].push_back(itt.first); // adding the chars on their frequency index

    string ans = "";
    for (int i = s.length(); i >= 0; i--)
    {

        for (auto ch :
             bucket_data[i])
        {                      // it will add all the chars to ans that r present on that particular index
            ans.append(i, ch); // expand that char (freq times)...
        }
    }

    return ans;
}

int main()
{
    string s = "tree";
    cout << "Original String: " << s << endl;
    cout << "Sorted by Frequency: " << frequencySort4(s) << endl;
    return 0;
}
