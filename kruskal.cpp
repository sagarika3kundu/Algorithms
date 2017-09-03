#include <bits/stdc++.h>
using namespace std;
int arr[100000];   //in c++ global variables are initialized as zero.
pair <long long, pair<int, int> > p[100000];
 
void initialize(int nodes){
	int i;
	for(i=1; i<=nodes; i++)
		arr[i] = i;
}
 
bool find(int a, int b){
	if(arr[a] == arr[b])
		return true;		//they are connected hence connecting them again will generate a cycle.
	else
		return false;
}
 
void union1(int nodes, int a, int b){
	int i,temp = arr[a];
	for(i=1; i<=nodes; i++){
		if(arr[i] == temp)
			arr[i] = arr[b];
	}
}
 
long long kruskal(int nodes, int edges){
	int i, x, y;
	long long minCost = 0;
	for(i=0; i<edges; i++){
		x = p[i].second.first;
		y = p[i].second.second;
		if(!find( x, y)){
			union1(nodes, x, y);
			minCost += p[i].first;
		}
	}
	return minCost;
}
 
int main() {
	int nodes, edges, i, x, y, w, minC = 0;
	cin >> nodes >> edges;
	
	for(i = 0; i < edges; i++){
		cin >> x >> y >> w;
		p[i] = make_pair(w, make_pair(x, y));
	}
	initialize(nodes);
	sort(p, p + edges);
	minC = kruskal(nodes, edges);
	cout << minC << endl;
 
	return 0;
}
