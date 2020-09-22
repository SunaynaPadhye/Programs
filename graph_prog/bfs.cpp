#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int distance(vector<vector<int> > &adj, int u, int v) {
  int i,j;

  vector<int> visited;
  visited.assign(adj.size(), -1);
  visited[u] = 0;

  queue<int> current;
  current.push(u);


  while(!current.empty())
  {
    for( i = 0; i < adj[ current.front() ].size(); i++ )
    {
      if( visited[ adj[ current.front() ][i] ] == -1)
      {
        visited[ adj[ current.front() ][i] ] = visited[ current.front() ] +1;
        if( adj[ current.front() ][i] == v)
        {
          return visited[ adj[ current.front() ][i] ];
        }
        else current.push( adj[ current.front() ][i] );
      }
      
    }
    current.pop();
  }
  return visited[v];
  
  
  //write your code here
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
