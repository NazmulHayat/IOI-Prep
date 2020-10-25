#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    Edge(int a, int b, int c){
		u = a;
		v = b;
		w = c;
	};
    bool operator<(Edge const& other) const{
        return w < other.w;
    }
};

vector<int> link;
vector<int> size;

int find(int x){
	while(x != link[x]) x = link[x];
	return x;
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	if(size[a] < size[b]) swap(a, b);
	size[a] += size[b];
	link[b] = a;
}

int main(){
	int n;
	cin>>n;
	vector<Edge> edges;
	link.resize(n+1), size.resize(n+1);
	for(int i = 1 ; i <= n ; i++) size[i] = 0;
	for(int i = 1 ; i <= n ; i++) link[i] = i;
	
	for(int i = 1 ; i <= n ; i++)
	{
		int v,u,w;
		cin>>v>>u>>w;
		edges.push_back((Edge(v, u, w)));
	}
		
	sort(edges.begin(), edges.end());
	
	for(const auto &i : edges){
		unite(i.v, i.u);
	}
	for(int i = 1 ; i <= n ; i++){
		cout<<size[i]<<" ";
	}
}

/*
 * 1111 1213 1155  2211 
 * 		0000
 * 		 4|  \3 
 * 		1111 1213 
 *    12/     2/
 *  1155    2211
 *
 *  1111- 1213 1155 2211   
 *  1213- 1155 2211 
 *  1155- 2211
 * 
 */



 




