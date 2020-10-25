#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int succ[10][9];
int get(int x, int k)
{
    while(k!=0)
    {
        int step=k&-k;
        x=succ[x][step];
        k-=step;
    }
    return x;
}
void init(int x, int k)
{
    succ[x][k]=succ[succ[x][k/2]][k/2];
}

int main()
{
    succ[1][1]=2;
    succ[2][1]=3;
    succ[3][1]=4;
    succ[4][1]=5;
    succ[5][1]=6;
    succ[6][1]=4;
    int step=1;
    for(int i=0; i<log2(6); i++)
    {
        step*=2;
        for(int j=1; j<10; j++)
        {
            init(j,step);
        }
    }
    int a=succ[1][1],b=succ[1][2];
    while(a!=b)
    {
        a=succ[a][1],b=succ[b][2];
    }
    a = 1;
    while (a != b)
    {
        a = succ[a][1];
        b = succ[b][1];
    }
    int first = a;
    int len=1;

    a=succ[a][1];

    while(a!=b)
    {
        a=succ[a][1];
        len++;
    }
    cout<<len;
}
