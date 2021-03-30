#include<bits/stdc++.h>
using namespace std;
queue<int> q;
vector<int> ans1;
vector<int> ans2;

void bfs(int src, vector<int> graph[], vector<bool>& visited1, vector<int>& distance){
    visited1[src] = true;
    distance[src] = 0;
    q.push(src);
    while(!q.empty()){
		int s = q.front(); q.pop();
        ans1.push_back(s);
        for(auto u : graph[s]){
            if(visited1[u]) continue;
            visited1[u] = true;
            if(distance[u] == 0) continue;
            distance[u] = distance[s]+1;
            q.push(u);
        }
    }
}

void dfs(int src, vector<int> graph[], vector<bool>& visited2){
	if(visited2[src]) return;
	visited2[src]=1;
	for(auto &i: graph[src]){
		dfs(i, graph, visited2);
		ans2.push_back(i);
	}
}

int main(){
    int n,x,y, j=1;
    cin>>n;
    vector<int> graph[n+2];
    vector<bool> visited1(n+2, 0);
    vector<bool> visited2(n+2, 0);
    vector<int> distance(n+2);
    for(int i = 0 ; i < n ; i++){
        cin>>x>>y;
        graph[y].push_back(x);
        graph[x].push_back(y);
    }
    bfs(1, graph, visited1, distance);
    ans1.push_back(1);
    for(auto i : visited1){
        if(i==0) continue;
        if(i){
            cout<<"Node "<<j<<" is visited"<<endl;
            cout<<"The distance from the starting node to "<<j<<" is "<<distance[j]<<endl;
        }
        else{
            cout<<"Node "<<i<<" is not visited"<<endl;
        } j++;
        cout<<endl;
    }
    for(int i = 0 ; i < ans1.size() ; i++){
		cout<<ans1[i]<<" ";
	}
	cout<<endl<<endl;
	
    dfs(1, graph, visited2);
    ans2.push_back(1);
    j=1;
    for(auto i : visited2){
        if(i==0) continue;
        if(i){
            cout<<"Node "<<j<<" is visited"<<endl;
        }
        else{
            cout<<"Node "<<i<<" is not visited"<<endl;
        } j++;
        cout<<endl;
    }
    for(int i = 0 ; i < ans2.size() ; i++){
		cout<<ans2[i]<<" ";
	}
    
}

//~ 7
//~ 1 2
//~ 2 3
//~ 3 4
//~ 4 6
//~ 4 7
//~ 3 5
//~ 5 8
