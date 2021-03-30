//minimum spanning tree (Kruskal's Algorithm) with Union-find data structure
#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)

int const mx = 1e5;
int link[mx], size[mx];

struct Graph{
	int from, to, weight;
	bool operator<(const Graph& a) const {
		return weight<a.weight;
	}
};

int find(int x){ //finding the rep. of the component
	while(x != link[x]) {
		x = link[x];
		cout << x << endl;
	}
	return x;
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	cout << a << " " << b << endl;
	if(a==b) return; //checking if both the nodes have the same representatives
	if(size[a] < size[b]) swap(a,b);
	size[a] += size[b];
	link[b] = a;
}

int main(){
	int n, m, x, y, w;
	cin >> n >> m;
	Graph adj[m];
	FOR(i, 0, m){
		cin >> x >> y >> w;
		adj[i].from=x, adj[i].to=y, adj[i].weight=w;
	}
	sort(adj, adj+m);
	iota(link, link+n+1, 0);
	fill(size, size+n+1, 1);
	FOR(i, 0, n) cout << link[i] << " ";	
	FOR(i, 0, m){
		cout << adj[i].from << " " << adj[i].to << endl;
		unite(adj[i].from, adj[i].to);
	}	
	FOR(i, 0, n){
		cout << i+1 << " " << link[i+1] << "\n";
	}
	return 0;
}	

//6 8
//1 2 3
//1 5 5
//2 5 6
//2 3 5
//5 6 2
//3 6 3
//3 4 9
//6 4 7

//use csacademygraph website to plot this graph

