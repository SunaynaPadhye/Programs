#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    long int n, m, p, q, sum, i, j, max=0, x=0;

    cin >> n >> m;
    long int *a=new long int[n+1]();

    for(i = 0; i < m; i++)
    {
        cin >> p >> q >> sum;
        a[p] += sum;
        if( (q+1) <= n )
            a[q+1] -= sum;
    }

    for(i = 1;i <= n; i++)
    {
       x += a[i];
       if(max < x)
            max=x;
    }

    cout << max;
    return 0;
}