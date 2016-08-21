#include<iostream>
#include<ctime>
#include<cstdio>
#include<algorithm>
//#include<cstdlib>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=5e5+10,reptime=12;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int tmp=0;char c=gc();while(vaild(c))tmp=tmp*10+c-'0',c=getchar();return tmp;}
inline void writeln(int x){
	int a[10],l=0;
	if(!x){puts("0");return;}
	while(x)a[++l]=x%10,x/=10;
	while(l)putchar(a[l--]+'0');puts("");
}
int n,m,b[maxn];
struct num{
	int p,v;
}a[maxn];
int getr(int v,int p){
	int l=1,r=n;
	while(l<r){
		int m=(l+r+1)>>1;
		if(a[m].v<v||a[m].v==v&&a[m].p<=p)l=m;
		else r=m-1;
	}
	return l;
}
int getl(int v,int p){
	int l=1,r=n;
	while(l<r){
		int m=(l+r)>>1;
		if(a[m].v<v||a[m].v==v&&a[m].p<p)l=m+1;
		else r=m;
	}
	return l;
}
int rnd=131313131;
inline int rrr(){
	int last=rnd;
	rnd*=rnd;if(rnd<0)rnd=-rnd;
	if(last==rnd)rnd+=2;
	return rnd;
}
bool operator<(num a,num b){return a.v<b.v||a.v==b.v&&a.p<b.p;}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	n=read();m=read();
	rep(i,1,n)a[i].p=i,b[i]=a[i].v=read();
	sort(a+1,a+1+n);
	rep(i,1,m){
		int l=read(),r=read();
		int ans=0;
		rep(j,1,reptime){
			int x=b[rrr()%(r-l+1)+l];
			int len=getr(x,r)-getl(x,l)+1;
			if(len>(r-l+1)/2){
				ans=x;
				break;
			}
		}
		writeln(ans);
	}
	cerr<<clock();
	return 0;
}
