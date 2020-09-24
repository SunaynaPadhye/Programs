#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

vector<int> do_process(vector<int> &values, int d)
{
    int i, j;
    vector<int> temp(d);
    int n = values.size();

    for(i = 0; i < d; i++)
        temp[i] = values[i];
    
    for(i = 0; i < n - d; i++)
        values[i] = values[d+i];

    for(i = 0; i < d; i++)
        values[n-d+i] = temp[i];
        
    return values;
}

int main()
{
    int n, d, i;
    cin >> n >> d;
    vector<int> values(n);
    for(i = 0; i < n; i++)
    {
        cin >> values[i]; 
    }
    
    values = do_process(values, d);
    for(i = 0; i < n; i++)
    {
        cout <<  values[i] << " "; 
    }
    return 0;

}
