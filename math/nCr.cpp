#include<bits/stdc++.h>
using namespace std;
 
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
const int MOD = 1000003;
const ll INF = 1e18;
const ll mx = 1e6+5;
ll fac[mx+1];

void fact(){
	
	fac[0] = 1;
    for (int i = 1; i <= mx; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
	
}

ll mult(ll a, ll b)
{
    if(a>MOD) a%=MOD;
    if(b>MOD) b%=MOD;
    ll ans=(a*b)%MOD;
    if(ans<0) ans+=MOD;
    return ans;
}

ll pw(ll a, ll b)
{
    ll r=1;
    while(b){
        if(b&1) r=mult(r,a);
        a=mult(a, a);
        b>>=1;
    }
    return r;
}

ll modinv(ll a){
	return pw(a, 1000001); //exp2 == 1000003-2 == 1000001
}

ll nCr(int n, int r){
	ll ans = (fac[n] * modinv(fac[r]) % MOD 
		* modinv(fac[n - r]) % MOD) % MOD;
	return ans;
}
int main(){
    fast_io;
    fact();
    int t, k=1;
    cin>>t;
    while(t--){
		int a,b;
		cin>>a>>b;
		cout<<"Case "<<k<<": "; 
		ll ans = nCr(a, b);
		cout<<ans<<endl;
		k++;
	}
}
