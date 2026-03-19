#include <iostream>
using namespace std;

int missingNumber(int arr[], int n, int N) {
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < n; i++) {
        xor2 = xor2 ^ arr[i];
    }
    for (int i = 1; i <= N; i++) {
        xor1 = xor1 ^ i;
    }
    return xor1 ^ xor2;
}

int main() {
    int arr[] = {1, 2, 4, 5};
    int n = 4;   
    int N = 5;  
    cout << "Missing number is: " << missingNumber(arr, n, N);

    return 0;
}
