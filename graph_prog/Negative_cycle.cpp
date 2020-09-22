#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost, int n, int m, int src) {
    int i, j, k, u, v, weight;
  vector<long long int> dist;
  dist.assign(n, INT_MAX);
  dist[src] = 0;


  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
        u = j;
        for(k = 0; k < adj[j].size(); k++)
        {
            v = adj[j][k];
            weight = cost[j][k];

            if(dist[u] != INT_MAX && (dist[u] + weight) <  dist[v] )
            {
                dist[v] = dist[u] + weight;
                if( i == n-1 )
                    return 1;
            }
        }
    }
  }
 /*   for(j = 0; j < n; j++)
    {
        u = j;
        for(k = 0; k < adj[j].size(); k++)
        {
            v = adj[j][k];
            weight = cost[j][k];

            if(dist[u] != INT_MAX && (dist[u] + weight) <  dist[v] )
            {
                return 1;
            }
        }
    }
    */
    return 0;

  
  
  //write your code here
  
}

int main() {
  int n, m, i, j;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for ( i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
    for( i = 0; i < n; i++ )
    {
        for( j = 0; j < adj[i].size(); j++)
        {
            if( negative_cycle(adj, cost, n , m, i) == 1)
            {
                std::cout<< "1";
                return 0;
            }
        }
    }
    std::cout<< "0";
    return 0;
   
}
