#include<bits/stdc++.h>
using namespace std;

const int A=911382323, B=972663749; 
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
	int ans = (h[b]-h[a-1]*p[b-a+1]) % B;
	return ans;
}

int patt_hash(string wrd, int a, int b){
	h1[0] = int(wrd[0]);
	for(int k = 1; k < wrd.length(); k++)
		h1[k] = (h1[k-1]*A + wrd[k]) % B;
	int ans = (h1[b]-h1[a-1]*p[b-a+1]) % B;
	return ans;
}

// a b c d 
// h[k] = a*h[k-1]*107 + b

void patt_match(string s, string wrd){
	computingpowers(s.length());
	preprocess(s);
	int wl = wrd.length();
	int h2 = patt_hash(wrd, 0, wl);
	for(int i = 0 ; i < s.length(); i++){
		int tmp = hashh(s, i, i+wl);
		if(h2 == tmp)
			cout << i << " ";
	}
}

int main(){
	string s, wrd;
	cin >> s >> wrd;
	patt_match(s, wrd);
}
