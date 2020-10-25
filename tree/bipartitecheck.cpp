#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<int> graph[], int src, vector<bool>& visited, vector<int>& color){

    for(auto &i: graph[src]){
        if(visited[i] == false){
            visited[i] = true;
            color[i] =  !color[src];
            if(!isBipartite(graph, i, visited, color))
                return false;
        }
        else if(color[i] == color[src])
            return false;
    }
    return true;

}

int main(){
    int n,x,y;
    cin>>n;
    vector<int> graph[n+1];
    vector<bool> visited(n+1, 0);
    vector<int> color(n+1, 0);

    for(int i = 0; i < n; i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    if(isBipartite(graph, 1, visited, color))
        cout<<"The Graph is Bipartite"<<endl;
    else
        cout<<"The Graph is not Bipartite"<<endl;
}
