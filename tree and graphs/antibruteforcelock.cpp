#include<bits/stdc++.h>
using namespace std;

struct Edge {
	int v, u, w;
	Edge(int a, int b, int c){
		a = v, b = u, c = w;
	}
    bool operator<(Edge const& other) const{
        return w < other.w;
    }
}

int dist(string s, string x){
	int ans=0;
	for(int i = 0 ; i < 4 ; i++){
		ans += min(((x[i]-'0')-(s[i]-'0')),((s[i]-'0')+10-(x[i]-'0'));
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, sm = INT_MAX, tmp = 0;
		cin>>n;
		
		vector<Edge> edges;
		vector<int> size, link;
		link.resize(n+1), size.resize(n+1);
		for(int i = 1 ; i <= n ; i++) size[i] = 0;
		for(int i = 1 ; i <= n ; i++) link[i] = i;
	
		string s[n], small = "";
		s[0] = "0000";
		for(int i=1;i<=n;i++){
			cin>>s[i];
			tmp = dist(s[0], s[i];
			if(sm >= tmp){
				small = s[i], sm = tmp;
			} 
		}
		for(int i = 1 ; i < n+1 ; i++){
			for(int j = i+1 ; j < n+1 ; j++){
				edges.push_back(Edge(i-1, j-1, dist(s[i], s[j])));
			}
		}
		for(const auto &i : edges){
			unite(i.v, i.u);
		}
		int ans = INT_MIN;
		for(int i = 1; i <= n ; i++){
			ans = max(ans, size[i]);
		}
		cout<<ans<<endl;
	}
}
