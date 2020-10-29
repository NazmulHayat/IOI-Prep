#include<bits/stdc++.h>
using namespace std;
queue<int> q;
void bfs(int src, vector<int> graph[], vector<bool>& visited, vector<int>& distance){
    visited[src] = true;
    distance[src] = 0;
    q.push(src);
    while(!q.empty()){
        int s = q.front(); q.pop();
        for(auto u : graph[s]){
            if(visited[u]) continue;
            visited[u] = true;
            distance[u] = distance[s]+1;
            q.push(u);
        }
    }
}
int main(){
    int n,x,y, j=1;
    cin>>n;
    vector<int> graph[n+1];
    vector<bool> visited(n+1);
    vector<int> distance(n+1);
    for(int i = 0 ; i < n ; i++){
        cin>>x>>y;
        graph[y].push_back(x);
        graph[x].push_back(y);
    }
    bfs(1, graph, visited, distance);
    for(auto i : visited){
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
}
