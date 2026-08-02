#include <bits/stdc++.h>
using namespace std;
string largestOddNumber(string num)
{
    // Traverse from the last digit to the first digit
    for (int i = num.size() - 1; i >= 0; i--)
    {
        // Check if the current digit is odd
        if ((num[i] - '0') % 2 != 0)
        {
            // Return substring from index 0 to i
            return num.substr(0, i + 1);
        }
    }
    // If no odd digit is found
    return "";
}

int main()
{
    string num = "35427";
    string ans = largestOddNumber(num);
    if (ans == "")
        cout << "No odd number exists." << endl;
    else
        cout << "Largest Odd Number: " << ans << endl;
    return 0;
}
