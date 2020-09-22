#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dfs(vector<vector<int>> &adj, int x, int y, vector<int> &visited)
{
    int ans = 0;
    if(x == y)
        ans = 1;
    else
    {
        visited[x] = 1;
        for(int i = 0; i < adj[x].size(); i++ )
        {
            if( !visited[ adj[x][i] ] )
            {
                if( dfs( adj, adj[x][i], y, visited))
                {
                    ans = 1;
                    return ans;
                }
            }
        }
    }
 return ans;   

}

int reach(vector<vector <int> > &adj, int x, int y)
{
    vector<int> visited (adj.size());
    return dfs(adj, x, y, visited);
    return 0;
}

bool allVisited(vector<int> visited)
{
    for(int i = 0; i < visited.size(); i++)
    {
        if(visited[i] == 0)
        return false;
    }
    return true;
}

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int &u, int v) {
    int i, j, min_temp_i =-1;
    long long int min_temp;
    vector<int> visited;
    visited.assign(adj.size(), 0);

    vector<long long int> minpath;
    minpath.assign(adj.size(), LLONG_MAX);

    minpath[u] = 0;

    while( !allVisited(visited) )
    {
        visited[u] = 1;
        for(i = 0; i < adj[u].size(); i++)
        {
            if( visited[ adj[u][i] ] == 1 )
                continue;
            minpath[ adj[u][i] ] = min( minpath[adj[u][i] ], minpath[u] + cost[u][i] );
        }
        
        min_temp = LLONG_MAX;
        for(j = 0; j < minpath.size(); j++)
        {
            if( visited[j] == 0 )
            {
                if( minpath[j] < min_temp )
                {
                    min_temp = minpath[j];
                    min_temp_i = j;
                }
            }
        }
        u = min_temp_i;

        if( u == v )
            return minpath[v];

    }
    return minpath[v];
 

  //write your code her
 
}

int main() {
  int n, m, ans;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
    ans = reach(adj, s, t);
    
    if(ans == 0)
    {
        cout<< "-1";
        return 0;
    }

  std::cout << distance(adj, cost, s, t);
}
