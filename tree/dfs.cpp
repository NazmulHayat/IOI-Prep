#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> g[], int n)
{
	//BT:pre_order://ans.pb(n)
    for(auto& i:g[n])
       dfs(g,v,i);
    //BT:post_order://ans.pb(n);
}
