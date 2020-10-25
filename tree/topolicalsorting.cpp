#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<bool> visited;

void dfs(int v, vector<int> adj[]) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u, adj);
    }
    ans.push_back(v);
}

void topological_sort(vector<int> adj[], int n) {
    visited.resize(n+1);
    ans.clear();
    for(int i = 1 ; i <= n ; i++) visited[i]=0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i, adj);
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0 ; i < n ;i++)
		cout<<ans[i]<<" ";
}

int main(){
	int n;
	cin>>n;
	vector<int> adj[n+1];
	int x,y;
	for(int i = 0 ; i < n ; i++){
		cin>>x>>y;
		adj[x].push_back(y);
	}
	topological_sort(adj, n);
}

//~ 6
//~ 1 2 
//~ 2 3
//~ 3 6
//~ 5 3
//~ 1 4
//~ 4 5

