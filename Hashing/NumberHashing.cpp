#include<iostream>
using namespace std;

int main(){

    int arr[] = {1, 2, 1, 3, 2};
    int n = 5;

    int hash[13] = {0};   
   
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1;
    }

    int q = 1;
    
    while(q--){
        int number = 1;
        
        cout << hash[number] << endl;
    }

    return 0;
}
