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
const int MOD = 1e9+7;
const ll INF = 1e18;

void solve(){
	
}

int main(){
    fast_io;
    int coin[]={1,5,10,25,50};
    int i,j,k=0;
    int dp[6][8000] = {0};
    dp[0][0] = 1;
    FOR(i, 1, 5) 
		dp[0][i] = 0;
	FOR(i, 1, 6){
		FOR(j, 0, 8000){
			if(j-coin[k]>=0)
				dp[i][j] = dp[i-1][j] + dp[i][j-coin[k]];
			else
				dp[i][j] = dp[i-1][j];
		}
		k++;
	} 
	//~ FOR(i, 1, 6){
		//~ FOR(j, 0, 27){
			//~ cout<<dp[i][j]<<" "; 
		//~ }
		//~ cout<<endl;
		//~ k++;
	//~ } 
    int n;
	while(scanf("%d",&n)==1)
		printf("%d\n",dp[5][n]);	
	return 0;
}
