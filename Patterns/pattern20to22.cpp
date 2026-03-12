#include<iostream>
using namespace std;

// 20th pattern
void print20(int n){
    int spaces = 2*n-2;
    for(int i = 1; i<=2*n-1; i++){
        int star = i;
        if(i > n) star = 2*n-i;
        for(int j = 1; j<=star; j++){
            cout << "*";
        }
        for(int j = 1; j<=spaces; j++){
            cout << " ";
        }
         for(int j = 1; j<=star; j++){
            cout << "*";
        }
        cout << endl;
        if(i < n) spaces -= 2;
        else spaces += 2;
    }
}

// 21th pattern
void print21(int n){
     for (int i = 0; i < n; i++){
        for(int j = 0; j<n; j++){
            if(i == 0 || j == 0 || i == n-1 || j == n-1 ){
                cout << "*";
            }
            else cout << " ";
        }
        cout << endl;
     }
}

// 22th pattern
void print22(int n){
    for(int i = 0; i < 2*n-1; i++){
        for(int j = 0; j<2*n-1; j++){
            int top = i;
            int left = j;
            int right = (2*n-2)-j;
            int down = (2*n-2)-i;
            cout << (n-min(min(top , down), min(left , right)));
        }
        cout << endl;
    }
}

int main(){
    int n = 5;
    print20(n);
    print21(n);
    print22(n);
     return 0;
}
