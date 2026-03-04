#include<iostream>
#include<map>
using namespace std;

int main(){

     int arr[] = {1, 2, 1, 3, 2};
    int n = 5;   
    map<int, int> mpp;

    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }

    int q = 2;
     
     while(q--){
        int numbers = 2;
       
        cout << mpp[numbers] << endl;
    }

    return 0;
}
