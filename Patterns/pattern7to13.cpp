#include<iostream>
using namespace std;
// 7th pattern
void print7(int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-i-1; j++){
            cout << " ";
        }
        for(int j = 0; j< 2*i+1; j++){
            cout << "*";
        }
        for(int j = 0; j<n-i-1; j++){
            cout << " ";
        }
        cout<< endl;
    }
}
// 8th pattern
void print8(int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            cout << " ";
        }
        for(int j = 0; j< 2*n-(2*i+1); j++){
            cout << "*";
        }
        for(int j = 0; j<i; j++){
            cout << " ";
        }
        cout<< endl;
    }
}
// 9th pattern combination of 7th and 8th pattern

// 10th pattern
void print10(int n){
    for(int i = 0; i<=2*n-1; i++){
        int stars = i;
        if(i > n) stars = 2*n-i;
        for(int j = 0; j <stars; j++){
            cout << "*";
        }
        cout<< endl;
    }
}

// 11th pattern
void print11(int n){
    int start = 1;
    for(int i = 0; i<n; i++){
        if(i % 2 == 0) start = 1;
        else start = 0;
        for(int j = 0; j<=i; j++){
            cout << start;
            start = 1 - start;
        }
        cout<<endl;
    }
}

// 12th pattern
void print12(int n){
    int space = 2 *(n-1);
    for(int i = 1; i <= n; i++){
        
        for(int j = 1; j <= i; j++){
            cout << j;
        }

        for(int j = 1; j <= space; j++){
            cout << " " ;
        }

        for(int j = i; j >= 1; j--){
            cout << j;
        }
        cout << endl;
        space -= 2;
    }
}

// 13th pattern
void print13 (int n){
    int num = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << num << " ";
            num = num + 1;
        }
        cout << endl;
    }
}

int main(){
    int n = 5;
    print7(n);
    print8(n);
    print10(n);
    print11(n);
    print12(n);
    print13(n);
    
    return 0;
}
