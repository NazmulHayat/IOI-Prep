#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void timer()
{
    auto now=high_resolution_clock::now();
    static auto t=now;
    int diff=duration_cast<microseconds>(now - t).count();
    cout<<"time: "<<diff/1000000<<"."<<diff%1000000<<" seconds\n";
    t=now;
}

struct TrieNodes
{
    int cnt=0;
    int flag=0;
    int edge[26]={0};
};

const int Nodes=10000;
TrieNodes trie[Nodes];
int root=0;
int totalnodes=0;

void insrt(string s)
{
    int currnode=root;
    for(int i=0;i<s.length();i++)
    {
        if(trie[currnode].edge[s[i]-'a']==0) //trie[currnode].edge[s[i]-'a']==0?
            trie[currnode].edge[s[i]-'a']=++totalnodes;
        currnode=trie[currnode].edge[s[i]-'a'];
        trie[currnode].cnt++;
    }
    trie[currnode].flag=1;
}

int cntPref(string s)
{
    int currnode=root;
    for(int i=0;i<s.length();i++)
    {
        if(trie[currnode].edge[s[i]-'a']==0) return 0;
        currnode=trie[currnode].edge[s[i]-'a'];
    }
    return trie[currnode].cnt;
}

bool srch(string s){
	int currnode=root;
	for(int i=0;i<s.length();i++){
		if(trie[currnode].edge[s[i]-'a']==0)
			return 0;
		currnode=trie[currnode].edge[s[i]-'a'];
	} //asdasd
	return trie[currnode].flag;
}

void dlt(string s){
	int currnode=root;
	int prevnode=-1;
	for(int i=0;i<s.length();i++){
		currnode=trie[currnode].edge[s[i]-'a'];
		currnode=trie[currnode].cnt-=1;
	} 
	if(trie[currnode].flag){
		trie[currnode].flag=0;
	}
	else cout << "The word is not present" << endl;
}

int main()
{
    fast;   
    insrt("army");
    insrt("arm");
    insrt("arms");
    insrt("ary");
    insrt("amy");
    insrt("api");
    int a=cntPref("a");
    cout << a << endl;
    cout << srch("army") << endl;
    dlt("army");
	cout << srch("army") << endl;
	insrt("army");
	dlt("army");
	cout << srch("armyy") << endl;
}
