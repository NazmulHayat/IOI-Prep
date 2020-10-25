#include<bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<bool> recStack;

int dfs(int src, vector<int> adj[]){
	if(visited[src] == false){
		visited[src] = true;
		recStack[src] = true;
		for(auto &i: adj[src]){
			if(!visited[i]&&dfs(i, adj))
				return true;
			else if(recStack[i])
				return true;
		}
	}
	recStack[src] = false;
	return false;
}

int isCycle(int n, vector<int> adj[]){

	for(int i = 1 ; i <= n+1 ; i++){
		cout<<i<<endl;
		if(dfs(i, adj))
			return true;
	}
	return false;
}

int main(){
	int n,x,y;
	cin>>n;
	vector<int> adj[n+2];
	for(int i = 0 ; i < n ; i++){
		cin>>x>>y;
		adj[x].push_back(y);
	}
	visited.resize(n+2);
	recStack.resize(n+2);
	for(int i = 1 ; i <= n+1 ; i++){
		visited[i] = false;
		recStack[i] = false;
	}
	//~ for(int i = 1; i <= n+1 ; i++)
	//~ {
		//~ cout<<i<<" ";
		//~ for(auto &j: adj[i])
			//~ cout<<j<<" ";
		//~ cout<<endl;
	//~ }
	if(isCycle(n, adj))
		cout<<"Cycle Present"<<endl;
	else 
		cout<<"No cycle is present"<<endl;
}
