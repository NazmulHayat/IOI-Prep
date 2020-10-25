#include<bits/stdc++.h>
using namespace std;

#define int long long

int binarysearch(int n, int arr[], int val){
    int mid=0, l=0, r=n-1;
    while(l<=r){
        mid = l + floor((r-l)/2);
        if(arr[mid] == val){
            return mid;
        }
        if(arr[mid] > l) l = mid+1;
        else r = mid-1;
    }
    return -1;
}

main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    //0-base
    cout<<binarysearch(n, arr, 11)+1<<endl;;
}
