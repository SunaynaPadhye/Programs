#include<bits/stdc++.h> 

using namespace std; 
# define INF 0x3f3f3f3f 


typedef pair<double, int> Pair; 

void makeEdge(vector <pair<int, double>> adj[], int u, 
									int v, double wt) 
{ 
	adj[u].push_back(make_pair(v, wt)); 
	adj[v].push_back(make_pair(u, wt)); 
} 


double prim_minimum_dist(vector<pair<int, double>> adj[], int V) 
{ 
    int i, j;
	priority_queue< Pair, vector <Pair> , greater<Pair> > pq; 
    double res = 0.000000d;
	int src = 0; 

	vector<double> key_wt(V, INF); 
	vector<int> parent(V, -1); 
	vector<bool> inMST(V, false); 

	pq.push(make_pair(0, src)); 
	key_wt[src] = 0; 


	while (!pq.empty()) 
	{ 
		int u = pq.top().second; 
		pq.pop(); 

		inMST[u] = true; 

		for (auto x : adj[u]) 
		{ 
			int v = x.first; 
			double weight = x.second; 

			if (inMST[v] == false && key_wt[v] > weight) 
			{ 
				key_wt[v] = weight; 
				pq.push(make_pair(key_wt[v], v)); 
				parent[v] = u; 
			} 
		} 
	} 

	for (i = 1; i < V; ++i) 
	{
        res += key_wt[i];
    }
return res;
} 


int main() 
{
    size_t n;
    int i, j, k;
    
    double weight;
    std::cin >> n;

    int V = n;

    vector<int> x(n), y(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> x[i] >> y[i];
    }
 
	vector<pair<int, double>> adj[V]; 

    for(i = 0; i < n; i++)
    {
        for(j = i + 1 ; j < n; j++)
        {
            weight = sqrt( pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2) );
            //cout<< "weight "  << weight <<" i: "<< i << " j: " << j  << endl;
            makeEdge(adj, i, j, weight); 
        }
    }

    //std::cout << std::setprecision(10) << prim_minimum_dist(adj, V) << std::endl;
    printf("%.9f",prim_minimum_dist(adj, V));
	return 0; 
} 
