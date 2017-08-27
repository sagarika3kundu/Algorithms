#include<bits/stdc++.h>
using namespace std;

int visited[1000];
int level[1000];
void dfsGraph(vector <int> adj[], int s){
	int v,i;
	stack <int> st;
	st.push(s);

	visited[s] = 1;
	
	while (!st.empty()){
		v = st.top();
	//	cout << v <<" ";
		st.pop();
		for(i=0; i<adj[v].size(); i++){
			if(visited[adj[v][i]] == 0)
					{			
									st.push(adj[v][i]);
									visited[adj[v][i]] = 1;
					}		
		}
	}
}

int main() {
	// your code goes here
	int vertices, edges, i, j, v_source, v_destination, source, count= 0;
	cin >> vertices;
	cin >> edges;
	vector <int> adj[vertices+1];
	for(i=0; i<edges; i++){
		cin >> v_source;
		cin >> v_destination;
		adj[v_source].push_back(v_destination);  //if undirected graph hence adding to both adjacenct lists
		adj[v_destination].push_back(v_source);
	}
    cin >> source;
    dfsGraph(adj, source);
    for(i=1; i<=vertices; i++){
    	if(visited[i] == 0)
    		count++;
    }
    cout << count;
	return 0;
}
