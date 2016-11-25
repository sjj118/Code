#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{
 
typedef long long LL;
const int N=1e6+10;
const LL inf=1e18;
template<class T>inline void up(T&x,T y){if(y>x)x=y;}
template<class T>inline void dn(T&x,T y){if(y<x)x=y;}
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
inline void output(LL x){
	int a[20],l=0;
	while(x)a[++l]=x%10,x/=10;
	per(i,l,1)putchar(a[i]+'0');
	if(l==0)putchar('0');
	puts(""); 
}
int n;
LL dissum[N],ans[N],dissumup[N];
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],size[N],firdis[N],fir[N],secdis[N],disup[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void getdis(int k,int pre){
		fir[k]=k;size[k]=1; 
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			getdis(to[p],k);
			size[k]+=size[to[p]];
			if(firdis[to[p]]+1>firdis[k]){
				secdis[k]=firdis[k];firdis[k]=firdis[to[p]]+1;
				fir[k]=to[p];
			}else if(firdis[to[p]]+1>secdis[k]){
				secdis[k]=firdis[to[p]]+1;
			}
			dissum[k]+=dissum[to[p]]+size[to[p]];
		}
	}
	void getup(int k,int pre){
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			disup[to[p]]=disup[k]+1;
			if(fir[k]!=to[p])up(disup[to[p]],firdis[k]+1);
			else up(disup[to[p]],secdis[k]+1);
			dissumup[to[p]]+=dissumup[k]+dissum[k]-dissum[to[p]]-size[to[p]]+n-size[to[p]];
			getup(to[p],k);
		}
		int maxpos=k,maxsize=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)if(size[to[p]]>maxsize)maxsize=size[to[p]],maxpos=to[p];
		int dismax=0,disoth=0;
		if(n-size[k]>maxsize){
			dismax=disup[k];
			disoth=firdis[k];
			maxpos=0;
			maxsize=n-size[k];
		}else{
			dismax=firdis[maxpos]+1;
			if(fir[k]==maxpos)disoth=secdis[k];
			else disoth=firdis[k];
			up(disoth,disup[k]);
		}
		int othsize=n-1-maxsize;
		ans[k]=inf;
		if(maxsize-1<=othsize)dn(ans[k],dissum[k]*2+dissumup[k]*2-dismax);
		if(maxsize<=othsize-1)dn(ans[k],dissum[k]*2+dissumup[k]*2-disoth);
	}
}G;
int main(){
	n=read();
	if(n==1){puts("0");return 0;} 
	rep(i,1,n-1){int a=read(),b=read();G.addedge(a,b);}
	G.getdis(1,0);
	G.getup(1,0);
	rep(i,1,n)if(ans[i]==inf)puts("-1");else output(ans[i]);
	return 0;
}
}
int main(){
	//freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
