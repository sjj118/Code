#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{
 
typedef long long LL;
const int N=1e7+10;
const LL inf=1e18;
template<class T>inline void up(T&x,T y){if(y>x)x=y;}
template<class T>inline void dn(T&x,T y){if(y<x)x=y;}
int n;
LL dissum[N],ans[N],dissumup[N];
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],size[N],firdis[N],fir[N],secdis[N],disup[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	int getsize(int k,int pre){
		size[k]=1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)size[k]+=getsize(to[p],k);
		return size[k];
	}
	void getdis(int k,int pre){
		fir[k]=k;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			getdis(to[p],k);
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
	}
	void getans(int k,int pre){
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)getans(to[p],k);
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
	scanf("%d",&n);
	if(n==1){puts("0");return 0;} 
	rep(i,1,n-1){int a,b;scanf("%d%d",&a,&b);G.addedge(a,b);}
	G.getsize(1,0);
	G.getdis(1,0);
	G.getup(1,0);
	G.getans(1,0);
	rep(i,1,n)if(ans[i]==inf)puts("-1");else printf("%lld\n",ans[i]);
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("bigrange.out","w",stdout);
	return sjj118::main();
}
