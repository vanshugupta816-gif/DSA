#include<iostream>
using namespace std;
int main(){
    int n = 1234;
    // cin >> n;
    int reverseNum = 0;
    while (n>0){
        int lastDigit = n%10;
        reverseNum = (reverseNum * 10) + lastDigit;
        n = n/10;
        cout << reverseNum << endl;
    }
    return 0;
}
