#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int i, Q, y;
    long int x;
    cin >> Q;

    set<long int> s;

    for(i=0 ; i<Q ; i++)
    {
        cin >> y >> x;
        if(y==1)
            s.insert(x);
        else if(y==2)
            s.erase(x);
        else if(y==3)
        {
            auto it = s.find(x);

            if( it == s.end())
                cout << "No" << endl;
            else cout << "Yes" << endl;
        }

    }
    return 0;
}