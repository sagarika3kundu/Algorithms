#include<bits/stdc++.h>
using namespace std;

int visited[1000];

void bfsGraph(vector <int> adj[], int s){
	int v,i;
	queue <int> q;
	q.push(s);
//	vector <bool> visited[n];
	visited[s] = 1;
	
	while (!q.empty()){
		v = q.front();
		cout << v <<" ";
		q.pop();
		for(i=0; i<adj[v].size(); i++){
			if(visited[adj[v][i]] == 0)
					{			//	cout << adj[v][i] <<" ";
									q.push(adj[v][i]);
									visited[adj[v][i]] = 1;
					}		
		}
	}
}

int main() {
	// your code goes here
	int vertices, edges, i, j, v_source, v_destination;
	cin >> vertices;
	cin >> edges;
	vector <int> adj[vertices+1];
	for(i=0; i<edges; i++){
		cin >> v_source;
		cin >> v_destination;
		adj[v_source].push_back(v_destination);  //if undirected graph hence adding to both adjacenct lists
		adj[v_destination].push_back(v_source);
	}
	
	for( i = 1;i <= vertices;++i)
    {   
            cout << "Adjacency list of node " << i << ": ";
        for( j = 0;j < adj[i].size();++j)
            {
            if(j == adj[i].size() - 1)
                    cout << adj[i][j] << endl;
            else
                cout << adj[i][j] << " --> ";
    }
    }
    int root;
    cout << "enter root node\n";
    cin >> root;
    bfsGraph(adj, root);
	return 0;
}
