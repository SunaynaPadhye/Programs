#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void search(vector<long int> &val, long int a)
{

    int index=-1, current=-1;
    int first=0, last = val.size()-1 ;

    while( first<=last )
    {
        current = ( first+last )/2;

        if( val[current] < a )
        {
            first = current+1;
        }
        else if( val[current] == a)
        {
            index = current;
            break;
        }
        else
        {
            last = current-1;
        }
    }

    if(val[index] == a)
    {
        while(val[index] == a)
        {
            index--;
        }
        index++;
        cout << "Yes " << index+1 << endl;
    }
    else
    {
        if(val[current] < a)
        {
            current++;
        }
        cout << "No " << current+1 << endl;
    }

return;
}

int main() {
    int num_of_val, num_of_q , i;
    long int a;

    cin >> num_of_val;
    vector<long int> val(num_of_val);

    for(i=0 ; i<num_of_val ; i++)
    {
        cin >> val[i];
    }

    cin >> num_of_q;
    
    for(i=0 ; i<num_of_q ; i++)
    {
        cin >> a;
        search(val, a);
    }


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
