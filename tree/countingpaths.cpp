
#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<bool> visited;
vector<int> path;

void dfs(int v, vector<int> adj[]) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u, adj);
    }
    ans.push_back(v);
}

void countallpaths(int n, vector<int> adj[]){
	for(int i = 0 ; i < n ; i++){
		for(int &j : adj[ans[i]]){
			path[j]+=path[ans[i]];
			//cout<<ans[i]<<" "<<j<<" "<<path[j]<<endl; 
		}
	}
	//for(int i = 0;  i < n ; i++) cout<<ans[i]<<" "<<path[ans[i]]<<endl;
	cout<<"Total number of ways: "<<path[6]<<endl;
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
    cout<<"After topological sorting: ";
    for(int i = 0 ; i < n-1 ; i++) cout<<ans[i]<<" ";
    cout<<endl;
    path.resize(n+1);
    for(int i = 1 ; i <= n ; i++) path[i]=0;
	path[1] = 1;
    countallpaths(n, adj);
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













	






