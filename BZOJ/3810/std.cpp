#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define LL long long
#define GET (ch>='0'&&ch<='9')
using namespace std;
const LL MAXLL=1ll<<62;
template<class classname>
inline void in(classname &x)
{
    char ch=getchar();x=0;
    while (!GET)    ch=getchar();
    while (GET) x=x*10+ch-'0',ch=getchar();
}
int n,m,k;
LL f[310][310][2][2][2][2];
LL dfs(int x,int y,int a,int b,int c,int d)
{
    LL ret=1ll*(x*y-k)*(x*y-k);int na,nb,nc,nd;
    if (x>y) swap(x,y),na=a,nb=b,nc=c,nd=d,a=nb,b=nc,c=nd,d=na;
    if (a>c) swap(a,c);
    if (b>d) swap(b,d);
    if (f[x][y][a][b][c][d]!=-1)    return f[x][y][a][b][c][d];
    if (!a&&!b&&!c&&!d) return f[x][y][a][b][c][d]=MAXLL;
    if (a+b+c>0&&a+d+c>0) for (int i=1;i<x;i++)    ret=min(ret,dfs(i,y,a,b,c,0)+dfs(x-i,y,a,0,c,d));
    if (a+b+d>0&&b+c+d>0) for (int i=1;i<y;i++)    ret=min(ret,dfs(x,i,a,b,0,d)+dfs(x,y-i,0,b,c,d));
    return f[x][y][a][b][c][d]=ret;
}
int main()
{
    in(n);in(m);in(k);memset(f,-1,sizeof(f));
    cout<<dfs(n,m,1,1,1,1)<<endl;
}
