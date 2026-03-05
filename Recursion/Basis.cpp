#include<iostream>
using namespace std;
// void recursion (int i, int n){
//     if(i>n)
//     return ;
//    // cout<< " vanshu";
//     cout<< i<< " ";
//     recursion(i+1, n);
// }

// n to 1 

void recursion (int i, int n){
    if(i<1)
    return ;
   // cout<< " vanshu";
   recursion(i-1, n);
    cout<< i<< " ";
    // recursion(i-1, n);
}
int main(){
    int n = 3;
    //recursion(1,n);
    recursion(n,n);
    return 0;
}
