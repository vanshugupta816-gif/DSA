#include<iostream>
using namespace std;
int main(){
    int n = 121;
    int reverseNum = 0;
    int dup = n;
    while(n>0){
        int lastDigit = n % 10;
        reverseNum = reverseNum*10 +lastDigit;
        n = n/10;
    }
    if(dup = reverseNum)
    cout << "true";
    else
    cout << "false";
    
    return 0;
}
