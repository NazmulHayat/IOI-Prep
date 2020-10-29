#include<bits/stdc++.h>
using namespace std;

int ancestor[9][10];

int get(int x, int  k){
	int step;
	while(k!=0){
		step = k&-k;
		x = ancestor[x][step];
		k-=step;
	}
	return x;
}

void init(int x, int k){
    ancestor[x][k]=ancestor[ancestor[x][k/2]][k/2];
} 
    
int main(){
	ancestor[1][1] = 0;
	ancestor[2][1] = 1;
	ancestor[3][1] = 4;
	ancestor[4][1] = 1;
	ancestor[5][1] = 1;
	ancestor[6][1] = 2;
	ancestor[7][1] = 4;
	ancestor[8][1] = 7;
	
	int step=1;
	for(int i = 0 ; i < log2(10); i++){
		step*=2;
		for(int j = 1; j <= 8 ; j++){
			init(j, step);
		}
	}
	
	int ans = get(8, 3);
	cout<<ans<<endl;
}
