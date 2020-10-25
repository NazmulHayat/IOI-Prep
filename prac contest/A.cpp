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
    int n;
    cin>>n;
    int arr[2*n];
    map<int, int> m;
    for(int i = 0 ; i < n ;i++){
		cin>>arr[i];
		m[arr[i]]++;
	}
	for(int i = n-1 ; i < 2*n-1 ; i++){
		cin>>arr[i];
		m[arr[i]]++;
	}
	int ans=0;
	for(int i = 0 ; i < n ; i++){
		if(m[arr[i]^arr[i]]>0)
			ans++;
		if(m[arr[i]^arr[i+1]]>0)
			ans+=2;
	}
	cout<<ans<<endl;
	(ans%2==0) ? cout<<"Karen"<<endl : cout<<"Koyomi"<<endl;
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



A^B=C
A^C=B || B^C=A



