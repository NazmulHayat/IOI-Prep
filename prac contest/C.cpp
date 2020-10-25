/*
    If they say
    Who cares if one more light goes out?
    In a sky of a million stars
    It flickers, flickers
    Who cares when someone's time runs out?
    If a moment is all we are
    We're quicker, quicker
    Who cares if one more light goes out?
    Well I do
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) ((a) / gcd(a,b)) * (b)
#define all(x)  x.begin(),x.end()
 
#define ll long long
#define ull unsigned long long
#define VI vector<int>
#define VLL vector<ll>
#define VS vector<string>
#define MPII map<int, int>
#define SET set<int>
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define INF (int)1e9
#define MEM(a, b) memset(a, (b), sizeof(a))
#define fast_io   ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
 
void solve(){
    ll n;
    cin>>n;
	ll arr[n];
    ll f=0,b=0,one=0,none=0, te=0, to=0;
    for(ll i = 0 ; i < n ; i++){
		cin>>arr[i];
		if(arr[i]%4==0){
			f++;
			continue;
		}
		if(arr[i]%2==0){
			b++;
		}
	}
	if(b==0){	
		if(f>=n-f-1)
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	else{
		if(f>=n-f-b)
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;		
	}
	
}
int main(){
    fast_io;
    ll t, k=0;
    t=1;
    while(t--){
        //k++;
        //cout<<"Case "<<k<<": ";
        solve();
    }
}























