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
	*this << ", " + 2 * (it == d.b) << *it	;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define check(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using namespace std;

const int A=3, B=97; 
long long h[100005];
long long h1[100005];
long long p[100005];

void computingpowers(int k){
	p[0]=1;
	for(int i = 1; i <= k; i++)
		p[i] = (p[i-1]*A) % B;
}

void preprocess(string s){
	h[0] = int(s[0]);
	for(int k = 1; k < s.length(); k++){
		h[k] = (h[k-1]*A + s[k]) % B;
	}
}		

int hashh(string s, int a, int b){
	if(a==0) return h[b];
	int ans = (h[b] - (h[a-1] * p[b-a+1] % B) + B) % B;
	return ans;
}

int patt_hash(string wrd){
	h1[0] = int(wrd[0]);
	for(int k = 1; k < wrd.length(); k++){
		h1[k] = (h1[k-1]*A + wrd[k]) % B;
	}
	int ans = h1[wrd.length()-1] % B;
	return ans;
}

// a b c d 
// h[k] = a*h[k-1]*107 + b

void patt_match(string s, string wrd){
	computingpowers(s.length());
	preprocess(s);
	for(int i=0;i<s.length();i++)
		debug() << check(h[i]);
	int wl = wrd.length();
	int h2 = patt_hash(wrd);
	cout << h2 << endl;
	for(int i = 0 ; i < s.length()-wl+1; i++){
		int tmp = hashh(s, i, i+wl);
		cout << s.substr(i, wl) << endl;
		cout << tmp << " ";
		if(h2 == tmp)
			cout << i << " ";
	}
}

int main(){
	string s, wrd;
	cin >> s >> wrd;
	patt_match(s, wrd);
}
