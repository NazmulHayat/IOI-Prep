
#include<bits/stdc++.h>
using namespace std;

//debugging
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define check(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

//normal
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
#define F first
#define S second
#define mem(a, b) memset(a, (b), sizeof(a))
#define ch() getchar()
#define fast_io   ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
//#define endl '\n'
#define sz(x) ((int)x.size())

//LOOPS
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define PI 3.1415926535897932384626433832795
const int MOD = 1e9+7;
const ll INF = 1e18;

int dearrangement(int n){
	debug() << check(n);
	if(n==1) return 0;
	if(n==2) return 1;
	else return ((n-1)*(dearrangement(n-2) + dearrangement(n-1)));
}

void solve(){
   int x;
   cin>>x;
   cout<<dearrangement(x)<<endl;
}
 
int main(){
    fast_io;
    ll t, k=0;
    cin>>t;
  //t=1;
    while(t--){
        //k++;
        //cout<<"Case "<<k<<": ";
        solve();
    }
}
