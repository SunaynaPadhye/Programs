// uses Radix sort

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void radix(vector<string> &val, int n,  int max_size){
    int i, j, k;
    int p, q;
    char x;
    
    for(i = 1; i <=max_size; i++){           // This loop ensures that all place values are covered
        vector<vector<string>> index(10); //bucket 0-9

        for(j = 0; j < n; j++){
            // finding char at place value
            x = ( i > val[j].size() ) ? 'x' : val[j][ val[j].size() - i ];

            //filling buckets
            switch(x){
                case 'x':
                case '0': index[0].push_back( val[j] ); break;
                case '1': index[1].push_back( val[j] ); break;
                case '2': index[2].push_back( val[j] ); break;
                case '3': index[3].push_back( val[j] ); break;
                case '4': index[4].push_back( val[j] ); break;
                case '5': index[5].push_back( val[j] ); break;
                case '6': index[6].push_back( val[j] ); break;
                case '7': index[7].push_back( val[j] ); break;
                case '8': index[8].push_back( val[j] ); break;
                case '9': index[9].push_back( val[j] ); break;
            }
        }
        
        //reading from buckets and writing int val[]
        k = 0;
        for(p = 0; p < 10; p++){
            for(q = 0; q < index[p].size(); q++){
                val[k] = index[p][q];
                k++;
            }
        }
    }
    return;
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

    radix(val, n, max_size);
    
    for(i = 0; i < n; i++){
        cout << val[i] << endl;
    }
    return 0;

}