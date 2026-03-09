#include<iostream>
using namespace std;
// 1st pattern
void print1(int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            cout << "*";
        }
        cout << endl;
    }
}

// 2nd pattern
void print2(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j<=i; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

// 3rd pattern
void print3(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<=i; j++){
            cout << j << "";
        }
        cout << endl;
    }
}

// 4th pattern
void print4(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cout<< i << " ";
        }
        cout << endl;
    }
}

// 5th pattern
void print5(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= n-i+1; j++){
            cout << "*";
        }
        cout << endl;
    }
}

// 6th pattern
void print6(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<=n-i+1; j++){
            cout << j << "";
        }
        cout << endl;
    }
}

int main(){
    int n = 5;
    print1(n);
    print2(n);
    print3(n);
    print4(n);
    print5(n);
    print6(n);
    return 0;
}
