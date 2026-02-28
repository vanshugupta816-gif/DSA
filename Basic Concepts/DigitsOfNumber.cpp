#include<iostream>
using namespace std;
int main() {
    int n = 7789;   // given number
    int count = 0;

    while (n > 0) {
        n = n / 10;
        count = count + 1;
    }

    cout << count;
    return 0;
}
