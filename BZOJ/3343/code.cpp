#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e6+10,maxb=5e3+10;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int tmp=0;char c=gc();while(vaild(c))tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n,q,b,fr,a[maxn],c[maxn/maxb+10][maxb],mark[maxn/maxb+10];
bool comp(int a,int b){return a>b;}
void rebuild(int k){
	rep(i,1,b)c[k][i]=a[k*b-1+i];
	sort(c[k]+1,c[k]+1+b,comp);
}
int find(int k,int w){
	int l=0,r=b;
	while(l<r){
		int m=(l+r+1)>>1;
		if(c[k][m]>=w)l=m;else r=m-1;
	}
	return l;
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d%d",&n,&q);b=5e3;
	rep(i,1,n)a[i]=read();
	rep(i,1,n)c[i/b][i%b+1]=a[i];
	fr=n/b;rep(i,0,fr)sort(c[i]+1,c[i]+1+b,comp);
	while(q--){
		char op;int l,r,w;
		scanf("\n%c%d%d%d",&op,&l,&r,&w);
		if(op=='A'){
			int ans=0;
			if(l/b==r/b){
				fr=l/b;rep(i,l,r)ans+=(a[i]+mark[fr]>=w);
			}else{
				fr=l/b*b+b-1;rep(i,l,fr)ans+=(a[i]+mark[l/b]>=w);
				rep(i,r/b*b,r)ans+=(a[i]+mark[r/b]>=w);
				fr=r/b-1;rep(i,l/b+1,fr)ans+=find(i,w-mark[i]);
			}
			printf("%d\n",ans);
		}else{
			if(l/b==r/b){
				rep(i,l,r)a[i]+=w;
				rebuild(l/b);
			}else{
				fr=l/b*b+b-1;rep(i,l,fr)a[i]+=w;rebuild(l/b);
				rep(i,r/b*b,r)a[i]+=w;rebuild(r/b);
				fr=r/b-1;rep(i,l/b+1,fr)mark[i]+=w;
			}
		}
	}
	return 0;
}
