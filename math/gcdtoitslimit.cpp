// C++ program for queries of GCD excluding 
// given range of elements. 

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<debugging.h>
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

// Filling the prefix and suffix array 
void FillPrefixSuffix(int prefix[], int arr[], 
                           int suffix[], int n) 
{ 
    // Filling the prefix array following relation 
    // prefix(i) = __gcd(prefix(i-1), arr(i)) 
    prefix[0] = arr[0]; 
    for (int i=1 ;i<n; i++) 
        prefix[i] = __gcd(prefix[i-1], arr[i]); 
  
    // Filling the suffix array following the 
    // relation suffix(i) = __gcd(suffix(i+1), arr(i)) 
    suffix[n-1] = arr[n-1]; 
  
    for (int i=n-2; i>=0 ;i--) 
        suffix[i] = __gcd(suffix[i+1], arr[i]); 
} 
  
// To calculate gcd of the numbers outside range 
int GCDoutsideRange(int l, int r, int prefix[], 
                           int suffix[], int n) 
{ 
    // If l=0, we need to tell GCD of numbers 
    // from r+1 to n 
    if (l==0) 
        return suffix[r+1]; 
  
    // If r=n-1 we need to return the gcd of 
    // numbers from 1 to l 
    if (r==n-1) 
        return prefix[l-1]; 
    return __gcd(prefix[l-1], suffix[r+1]); 
} 
  
// Driver function 
int main() 
{ 
	#ifdef LOCAL
		freopen("input1.txt", "r", stdin);
		freopen("output1.txt", "w", stdout);
	#endif
    int arr[] = {2, 6, 9}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int prefix[n], suffix[n]; 
    FillPrefixSuffix(prefix, arr, suffix, n); 
  
    int l = 0, r = 0; 
    cout << GCDoutsideRange(l, r, prefix, suffix, n) 
         << endl; 
    l = 1 ; r = 1; 
    cout << GCDoutsideRange(l, r, prefix, suffix, n) 
         << endl; 
    l = 1 ; r = 2; 
    cout << GCDoutsideRange(l, r, prefix, suffix, n) 
         << endl; 
    return 0; 
} 