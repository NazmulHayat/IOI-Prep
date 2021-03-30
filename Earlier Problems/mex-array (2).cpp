#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; 
#ifndef EVAL
void timer(string msg=""){double now=(double)clock()/CLOCKS_PER_SEC;static double t=now;static int cnt=0;
double diff=now - t;if(cnt!=0)cout<<"\n[time "<<cnt<<" "<<msg<<": "<<fixed<<setprecision(3)<<diff<<" seconds]\n";cnt++;t=now;}
#define fast ;
#else
#define debug(...)
void timer() {return;}
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif

#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) ((a) / gcd(a,b)) * (b)
#define all(x)  x.begin(),x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define ll long long
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mem(a, b) memset(a, (b), sizeof(a))
#define ch() getchar()
#define sz(x) ((int)x.size())
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
string ds="RLDU";

int const mx=(2*1e6)+10;

void solve(){
	int n,m,a,b,c;
	cin >> n >> m;
	while(m--){
		cin >> a >> b >> c;
	}
	if(c==0){
		cout << "YES" << endl;
		FOR(i, 0, n){
			cout << 1 << " ";
		}
	}
	else{
		cout << "YES" << endl;
		FOR(i, 0, n){
			if(i%2==0)cout << 0 << " ";
			else cout << 2 << " ";
		}
	}

}

int main(){
	fast;
	timer();
	int t=1;
	//cin >> t;
	FOR(i, 1, t+1){
    	//cout << "Case " << i << ": ";
		solve();
	}
	timer();
}

//dont forget to use EVALLLLL
//remember abt the testcase input in main() 




