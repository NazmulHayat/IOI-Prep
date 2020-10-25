#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t;
    cin>>n;
    int a[n];
    for(auto &i : a) cin>>i;
    cin>>t;
    int b[t];
    for(auto &i : b) cin>>i;

    //processing two arrays
    int x = 1<<a[0];
    int y = 1<<b[0];
    for(int i = 1 ; i < n ; i++)
        x |= 1<<a[i];
    for(int i = 1 ; i < t ; i++)
        y |= 1<<b[i];

    int Union = x | y;
    int Common = x & y;

    int cm = min(n, t);
    int um = max(n, t);

    cout<<"Common elements: ";
    for(int i = 0 ; i < 32 ; i++){ //(1<<k) means 2^k
        if(Common&(1<<i)) cout<<i<<" "; //prints out all the common elements
    }
    cout<<endl<<"Union elements: ";
    for(int i = 0 ; i < 32 ; i++){
        if(Union&(1<<i)) cout<<i<<" "; //prints out all the elements-
    }
}

//important N.B. this code can contain only elements with a range of(0...31) not
//more than that or less than that
//there is another approach like (1<<n) which will contain subset (0...n-1)
