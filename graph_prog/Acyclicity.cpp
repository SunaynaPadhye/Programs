#include <iostream>
#include <vector>

using namespace std;

bool acyclic(vector<vector<int> > &adj, vector<int> &visited, int u) {

  visited[u] = 1;
  int i;

  for(i = 0; i < adj[u].size(); i++)
  {
    if( visited[adj[u][i]] == 0)
    {
      if(acyclic(adj, visited, adj[u][i]))
      {
        return true;
      }
    }
    else if( visited[adj[u][i]] == 1 )
    {
      return true;
    }

  }
  visited[u] = 2;
  return false;
  //write your code here
  return false;
}

int main() {
  size_t n, m;
  int i,j;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<int> visited(adj.size());
  visited.assign(visited.size(), 0);

  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  
  
for(int x = 0; x < adj.size(); x++)
  if(visited[x] == 0)
    if(acyclic(adj, visited, x))
    {
      std::cout << "1";
      return 0;
    }
    
  std::cout << "0";
  return 0;
}
