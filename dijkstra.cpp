#include<bits/stdc++.h>
using namespace std;
#define SIZE 100000 + 1

vector < pair<long long, int> > v[SIZE];    //to store the adjacency list of the directed graph.
int parent[SIZE];							//to store the parent of the current node in its shortest path so that we can track the path later.
long long dist[SIZE];						//to store min distance from source.
bool vis[SIZE];

void dijkstra(){
	memset(vis, false, sizeof vis);        //marking all nodes unvisited initially.

	dist[1] = 0;						  //source node distance value is '0'.
	multiset<pair< long long, int> > s;	  //acts as min-priority queue but faster as logarithmic height is maintained by red-black tree, 
										  //whereas in priority-queue(heaping-technique)  the heap-height is highly dependent on the inputs

	parent[1] = 1;
	s.insert(make_pair(0,1));
	
	while( !s.empty() ){
		pair< long long, int> p = *s.begin();
		s.erase(*s.begin());
		
		int weight = p.first;
		int x = p.second;
		
		if(vis[x])
			continue;
		vis[x] = true;
		
		for(int i=0; i < v[x].size(); i++){
			int w = v[x][i].first;
			int e = v[x][i].second;
			
			if(dist[x] + w < dist[e]){
				dist[e] = dist[x] + w;
				parent[e] = x;
				s.insert(make_pair(dist[e], e));
			}
			
		}
	}
}
int main() {
	int n, m, a, b;
	long long w;
	cin >> n >> m;					//n = nodes, m = edges
	for(int i=0; i<m; i++){
		cin >> a >> b >> w;			//edge from 'a' to 'b' having weight w.
		v[a].push_back(make_pair(w, b));
	}
	for(int i = 0; i <= n; i++)
		dist[i] = 1000000000;       //initializing all distances to max value
		
	dijkstra();
	
	for(int i=2; i<=n; i++){
	cout << dist[i] << "\n";       //print shortest distance form source node(here '1') to i-th node
	
								   //to print the path we print it backwards, 
	cout << i << " ";			   //i.e. from i-th node to its source node
	int j = i;
	while(parent[j] != 1)
		{	
			cout << parent[j] << " ";
			j = parent[j];
		}	
		cout << "1 " << "\n";	  //printing source node at end.
	}
	return 0;
}
