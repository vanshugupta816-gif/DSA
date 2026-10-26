#include <bits/stdc++.h>
using namespace std;
int countBitsToFlip(int A, int B)
{
    int ans = A ^ B;
    int count = 0;
    while (ans > 0)
    {
        count += ans & 1;
        ans = ans >> 1;
    }
    return count;
}

int main()
{
    int A, B;
    cout << "Enter A and B: ";
    cin >> A >> B;
    cout << countBitsToFlip(A, B) << endl;
    return 0;
}
