#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define endl '\n'

vector<int> ans;

// 1 2 
// 1 3
// 1 4
// 1 5

void dfs(int source, vector<int> graph[], bool visited[]){
	//cout<<"hello"<<endl;
	visited[source] = 1;
	ans.pb(source);
	for(auto i: graph[source]){
		if(visited[i] == 1) continue; 
		dfs(i, graph, visited);
		ans.pb(source);
	}
}
int main()
{
	int n,m,k,x,y;
	cin>>n>>m>>k;
	vector<int> graph[n+1];
	bool visited[n+1];
	memset(visited, 0, sizeof(visited));
	set<int> s;
	for(int i = 0 ; i < m ; i++){
		cin>>x>>y;
		s.insert(x);
		s.insert(y); 
		graph[y].pb(x);
		graph[x].pb(y);
	}
	dfs(1, graph, visited);
	//~ for(auto &i: ans) 
		//~ cout<<i<<" ";
	//~ cout<<endl;
	//cout<<ans.size()<<endl;
	int j=0, tot = (n*2+k-1)/k, fixed= (n*2+k-1)/k;
	for(int i = 1 ; i <= k ; i++){
		tot = fixed*i;
		tot = min(tot, int(ans.size()));
		cout<<tot-j<<" ";
		while(j!=tot){
			cout<<ans[j]<<" ";
			j++;
		}
		cout<<endl;
		if(i!=k && j==ans.size())
			j-=fixed;
	}
}
// 1 2 3 4 5 6 7 8 8 8 8 



