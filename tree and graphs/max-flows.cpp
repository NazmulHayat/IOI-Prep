#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
vector<int> g[7];
map<pair<int,int>,int> w;
int mp[7];
int source=1,sink=6;
void aug(int val)
{
    int n=sink;
    while(n!=1)
    {
        w[{mp[n],n}]-=val;
        n=mp[n];
    }
}
int maxFlow()
{
    int maxflow=0;
    queue<pair<int,int>> q;
    q.push({1,INT_MAX});
    while(!q.empty())
    {
        int s=q.front().first,f=q.front().second;
        q.pop();
        for(auto &i:g[s])
        {
            int edge=w[{s,i}];
            if(mp[i]!=0 || edge==0) continue;
            mp[i]=s;
            if(i==sink)
            {
                aug(min(f,edge));
                maxflow+=min(f,edge);
                queue<pair<int,int>> emp;
                swap(q,emp);
                memset(mp,0,sizeof(mp));
                q.push({1,INT_MAX});
                break;
            }
            else
            {
                q.push({i,min(f,edge)});
            }
        }
    }
    return maxflow;
}
int main()
{
    fast;
    g[1].push_back(2);
    w[{1,2}]=5;
    g[1].push_back(4);
    w[{1,4}]=4;
    g[2].push_back(3);
    w[{2,3}]=6;
    g[3].push_back(6);
    w[{3,6}]=5;
    g[3].push_back(5);
    w[{3,5}]=8;
    g[4].push_back(2);
    w[{4,2}]=3;
    g[4].push_back(5);
    w[{4,5}]=1;
    g[5].push_back(6);
    w[{5,6}]=2;
    cout<<maxFlow();
}
