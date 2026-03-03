#include<iostream>
using namespace std;
// int reverseNo(int n){
//     int reverseNum = 0;
//     int dup = n; // duplicate 
//     while (n>0){
//         int lastDigit = n%10;
//         reverseNum = (reverseNum * 10) + lastDigit;
//         n = n/10;
//     }
//     if (dup == reverseNum) cout << "true";
//     else cout << "false"<< endl; 
// }
// int main(){
//     int n = 121;
//     reverseNo(n);
//     return 0;
// }

// print all divisors

void printDivisors(int n){
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            cout << i << " ";
        }
    }
}
int main(){
    int n = 10;
   // cin >> n;
    printDivisors(n);
    return 0;
}
