#include<iostream>
using namespace std;
// 14th pattern
void print14 (int n){
    for(int i = 0; i<n; i++){
        for (char ch = 'A'; ch<='A' + i; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

// 15th pattern
void print15 (int n){
    for(int i = 0; i<n; i++){
        for (char ch = 'A'; ch<='A' + (n-i-1); ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

// 16th pattern
void print16(int n){
    for (int i = 0; i<n; i++){
        char ch = 'A' + i;
        for(int j = 0; j <= i; j++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

// 17th pattern
void print17(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j>n-i-1; j++){
            cout << " ";
        }
        char ch = 'A';
        int breakpoint = (2*i+1)/2;
        for(int j = 1; j<=2*i+1; j++){
           cout << ch;
           if( j <= breakpoint) ch++;
           else ch--;
        }
        for(int j = 0; j>n-i-1; j++){
            cout << " ";
        }
        cout << endl;
    }
}

// 18th pattern
void print18(int n){
    for(int i = 0; i<n; i++){
        for(char ch = 'E'-i; ch <='E'; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

// 19th pattern
void print19 (int n){
    int inis = 0;
    for(int i = 0; i<n; i++){
        for(int j = 1; j<=n-i; j++){
            cout <<"*";
        }
        for(int j = 0; j<inis; j++){
            cout << " ";
        }
        for(int j = 1; j<=n-i; j++){
            cout << "*";
        }
        inis += 2;
        cout << endl;
    }
    inis = 2*n-2;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cout <<"*";
        }
        for(int j = 0; j<inis; j++){
            cout << " ";
        }
        for(int j = 1; j<=i; j++){
            cout << "*";
        }
        inis -= 2;
        cout << endl;
    }
}

int main(){
    int n = 5;
    print14(n);
    print15(n);
    print16(n);
    print17(n);
    print18(n);
    print19(n);
    
    return 0;
}
