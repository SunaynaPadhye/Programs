#include <iostream>
#include <vector>

using namespace std;

int explore(vector<vector<int> > &adj, int x, int y, vector<int> &touched) {
	int ans = 0;
    if (x == y) {
		ans = 1;
	}
    else{	
	    touched[x] = 1;
	    for(int i = 0; i < adj[x].size(); i++) {
		    if (!touched[adj[x][i]]) {
			    if(explore(adj, adj[x][i], y, touched)) {
				    ans = 1;
            return ans;
			    }
		    }
	    }
    }
	return ans;
}

int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  
  vector<int> touched(adj.size());
  return explore(adj, x, y, touched);
  return 0;
}

int main() {
  size_t n, m;
  int x, y;

  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());

  for (size_t i = 0; i < m; i++) {
   
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  
  cin >> x >> y;
  cout << reach(adj, x - 1, y - 1);
}
