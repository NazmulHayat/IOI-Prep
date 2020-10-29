#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
void dfs(vector<int> g[], int n, int v,int ans[])
{
    ans[n]=v;
    for(int i=0;i<g[n].size();i++)
    {
        if(ans[g[n][i]]==0)
            dfs(g,g[n][i],(v==1?2:1),ans);
    }
}
int main()
{
    //fast;
    int n;
    cin>>n;
    vector<int> g[n*2];
    int ans[n*2]={0},ind[n*2];
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        ind[i*2]=x-1,ind[i*2+1]=y-1;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
        g[i*2].push_back(i*2+1);
        g[i*2+1].push_back(i*2);
    }
    for(int i=0;i<2*n;i++)
        if(ans[i]==0)
            dfs(g,i,1,ans);
    for(int i=0;i<n;i++)
    cout<<ans[ind[i*2]]<<" "<<ans[ind[i*2+1]]<<endl;
}
