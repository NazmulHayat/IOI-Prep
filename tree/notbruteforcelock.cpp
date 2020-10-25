#include<bits/stdc++.h>
using namespace std;

struct Edge {
	int v, u, w;
    Edge(int a, int b, int c){
		u = a;
		v = b;
		w = c;
	};
    bool operator<(Edge const& other) const{
        return w < other.w;
    }
};

vector<int> size, link;
int ans = 0;

int dist(string s, string x){
	int a=0;
	for(int i = 0 ; i < 4 ; i++){
		if(x[i]-'0' > s[i] -'0') swap(s[i], x[i]);
		a += min(abs((x[i]-'0')-(s[i]-'0')), abs((x[i]-'0')+10-(s[i]-'0')));
	}
	return a;
}

int find(int x){
	while(x != link[x]) x = link[x];
	return x;
}

void unite(int a, int b, int w){
	a = find(a);
	b = find(b);
	//cout<<a<<" "<<b<<" "<<size[a]<<" "<<size[b]<<endl;
	if(a == b) return;
	if(size[a] < size[b]) swap(a, b);
	size[a] += size[b];
	link[b] = a;
	ans += w;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, sm = INT_MAX, tmp = 0;
		cin>>n;
		
		vector<Edge> edges;
		link.resize(n+1), size.resize(n+1);
		for(int i = 1 ; i <= n ; i++) size[i] = 1;
		for(int i = 1 ; i <= n ; i++) link[i] = i;
	
		string s[n+1], small = "";
		s[0] = "0000";
		for(int i=1;i<=n;i++){
			cin>>s[i];
			tmp = dist(s[0], s[i]);
			if(sm > tmp){
				small = s[i], sm = tmp;
			} 
		}
		ans = sm;
		//cout<<small<<" "<<sm<<endl;
		for(int i = 1 ; i < n+1 ; i++){
			for(int j = i+1 ; j < n+1 ; j++){
				edges.push_back(Edge(i, j, abs(dist(s[i], s[j]))));
			}
		}
		sort(edges.begin(), edges.end());
		for(const auto &i : edges){
			unite(i.u, i.v, i.w);
		}
		cout<<ans<<endl;
	}
}
