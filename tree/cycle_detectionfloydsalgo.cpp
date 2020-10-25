#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x,y;
	cin>>n;
	vector<int> adj[n+1];
	for(int i = 0 ; i < n ; i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
