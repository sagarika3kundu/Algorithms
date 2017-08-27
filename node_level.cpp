//this can be done using BFS as it traverses level wise.
#include<bits/stdc++.h>
using namespace std;

int visited[1000];
int level[1000];
void bfsGraph(vector <int> adj[], int s){
	int v,i;
	queue <int> q;
	q.push(s);
//	vector <bool> visited[n];
	visited[s] = 1;
	level[s] = 1;
	while (!q.empty()){
		v = q.front();
	//	cout << v <<" ";
		q.pop();
		for(i=0; i<adj[v].size(); i++){
			if(visited[adj[v][i]] == 0)
					{			
									q.push(adj[v][i]);
									visited[adj[v][i]] = 1;
									level[adj[v][i]] = level[v] + 1;
					}		
		}
	}
}

int main() {
	// your code goes here
	int vertices, x, i, j, v_source, v_destination,count = 0;
	cin >> vertices;
	
	vector <int> adj[vertices+1];
	for(i=0; i<vertices-1; i++){
		cin >> v_source;
		cin >> v_destination;
		adj[v_source].push_back(v_destination);  //if undirected graph hence adding to both adjacenct lists
		adj[v_destination].push_back(v_source);
	}
	cin >> x;
    
    bfsGraph(adj, 1);
    for(i=1;i<=vertices;i++){
    	if(level[i] == x)
    	count++;
    }
    cout << "\n" << count << endl;
	return 0;
}
