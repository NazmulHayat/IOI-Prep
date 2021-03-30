#include <bits/stdc++.h>
using namespace std;

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

void solve(){
	debug("Gello wor");
	ll n;
	cin >> n;
	ll arr[n];
	FOR(i, 0, n)
		cin >> arr[i];
	sort(arr, arr+n);
	ld sm=0, diff=0, ans=INT_MIN;
    int p1=1,p2=n-2;
	if(n%2==0){
		for(int i = 0 ; i < n-1 ; i++){
			ld tmp = (arr[n-1]+arr[n-2])*1.0;
			tmp/=(arr[i+1]-arr[i]);
			if(i==n-3){
				tmp = (arr[n-1]+arr[n-4])*1.0;
				debug(tmp);
				tmp /= (arr[i+1]-arr[i]);
				debug(tmp, arr[i+1], arr[i]);
			}
			else if(i==n-2){
				tmp = (arr[n-3]+arr[n-4])*1.0;
				debug(tmp);
				tmp /= (arr[i+1]-arr[i]);
				debug(tmp, arr[i+1], arr[i]);
			}
			if(ans < tmp) ans = tmp;
			debug(i, tmp, ans);
		}
	}
	else{
		for(int i = 0 ; i < n-1 ; i++){
			ld tmp = (arr[n-1]+arr[n-2])*1.0;
			tmp /= (arr[i+1]-arr[i]);
			if(i==n-3){
				tmp = (arr[n-1]+arr[n-4])*1.0;
				debug(tmp);
				tmp /= (arr[i+1]-arr[i]);
				debug(tmp, arr[i+1], arr[i]);
			}
			else if(i==n-2){
		      	tmp = (arr[n-3]+arr[n-4])*1.0;
				debug(tmp);
				tmp /= (arr[i+1]-arr[i]);
				debug(tmp, arr[i+1], arr[i]);	
			}
			if(ans < tmp) ans = tmp;
			debug(i, tmp);
		}
	}
	cout << ans << endl;	

}

int main(){
	fast;
	timer();
	int t=1;
	FOR(i, 1, t+1){
		//cout << "Case " << i << ": ";
		solve();
	}
	timer();
}

//1 2 3 4 5 6 



