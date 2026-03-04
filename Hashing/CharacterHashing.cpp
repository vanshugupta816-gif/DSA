#include<iostream>
using namespace std;

int main(){

    string s = "abcadbefc";

    int hash[26] = {0};

    for(int i = 0; i < s.size(); i++){
        hash[s[i] - 'a']++;
    }

    char queries[3] = {'a','b','c'};

    for(int i = 0; i < 3; i++){
        char c = queries[i];
        cout << hash[c - 'a'] << endl;
    }

    return 0;
}
