// answering summation queries with fenwick tree or binary indexed tree

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mx 100005

int tree[mx];

void update(int index, int val, int n){ //O(log n) complexity
	while(index<=n){
		tree[index] += val;
		index += (index & -index);
	}
}

int query(int r){
	int sum = 0;
	while(r > 0){
		sum += tree[r];
		r -= (r & -r);
	}
	return sum;
}

//sum-query-example
main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n+1];
		for(int i = 1 ; i <= n ; i++){
			cin>>arr[i];
			update(i, arr[i], n);
		}
		int q;
		cin>>q;
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			cout<<query(r)-query(l-1)<<endl;
		}
	}
}
