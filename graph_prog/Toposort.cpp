#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
  //write your code here
}     

vector<int> toposort(vector<vector<int> > adj, vector<int> &in_order) {
  //vector<int> used(adj.size(), 0);
  int i, j;
  vector<int> order;
  vector<int> temp;

    for(i = 0; i < in_order.size(); i++)
    {
        
      if( in_order[i] == 0 )
        {
          temp.push_back(i);
          in_order[i] = -1;
        }
    }

    for( i = 0; i < temp.size(); i++)
    {
        for( j = 0; j < adj[ temp[i] ].size(); j++)
        {
            in_order[ adj[ temp[i] ][j] ]--;

            if(in_order[ adj[ temp[i] ][j] ] == 0)
                temp.push_back( adj[ temp[i] ][j] );
        }

        if( temp.size() == adj.size() )
            return temp;
    }




  //write your code here
  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<int> in_order;
  in_order.assign(n,0);

  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    in_order[y-1]++;
  }
  
  vector<int> order = toposort(adj, in_order);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
