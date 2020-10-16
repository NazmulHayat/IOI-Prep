#include<bits/stdc++.h>
using namespace std;

#define Max 100005

int tree[Max];

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

//the tree's index is one-based

void construct(int n, int SIZE, int arr[]){

    //initializing the tree
    int j = 0;
    for(int i = SIZE ; i < SIZE+n ; i++){
        tree[i] = arr[j]; j++;
    }

    //updating its other nodes (for summation in this case)
    j = SIZE-1;
    for(int i = SIZE*2-1 ; j>=1 ; i-=2,j--)
        tree[j]=tree[i]+tree[i-1];
}

void update(int pos, int val, int n){
    pos--;pos += n;
    for(; pos!=0; pos/=2) tree[pos] += val;
}

int querysum(int l, int r, int n){
    int sum = 0; l--,r--;
    l += n, r += n;
    while(l <= r){
        if(l%2 == 1) sum += tree[l++];
        if(r%2 == 0) sum += tree[r--];
        l/=2, r/=2;
    }
    return sum;
}

main(){
    int n, SIZE;
    cin>>n;
    SIZE = binpow(2, ceil(log2(n)));
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    construct(n, SIZE, arr);
    for(int i = 1; i <= SIZE*2 - 1 ; i++) cout<<tree[i] <<" ";
    //example: cout<<querysum(1, 5, SIZE);
    //for updating remember to subtract the old value from it (THE DIFFERENCE BASICALLY WILL BE ADDED TO THE OLD_VALUE)
}
