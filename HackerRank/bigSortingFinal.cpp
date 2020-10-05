#include <iostream>
#include <vector>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

bool comp(string &l, string &r){
    if(l.size() == r.size())
        return l < r;
    else
        return l.size() < r.size();
}

int main(){
    int n, i;
    int max_size = 0;
    cin >> n;
    vector<string> val(n);

    for(i = 0; i < n; i++){
        cin >> val[i];
        if(val[i].size() > max_size){
            max_size = val[i].size();
        }
    }

    sort(val.begin(), val.end(), comp);
    
    for(i = 0; i < n; i++){
        cout << val[i] << endl;
    }
    return 0;
}
