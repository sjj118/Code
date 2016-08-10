#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int maxn=60000,maxv=6000000;
typedef long long LL;
using namespace std;
int p[7],val[maxn],ans;
struct Graph{
	int tot,head[maxn],to[maxv],next[maxv];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	bool dfs(int h,int start,int k){
		if(h==6)return 0;
		for(int p=head[k];p;p=next[p]){
			if(to[p]==start){ans+=val[k];return 1;}
			if(dfs(h+1,start,to[p])){ans+=val[k];return 1;}
		}
		return 0;
	}
	void clear(){tot=0;cls(head);}
}G;
int f[7],mark[7];
void dfs(int k){
	if(k==7){
		G.clear();
		rep(i,1,6){
			rep(j,p[f[i]-1]+1,p[f[i]])rep(k,p[f[i%6+1]-1]+1,p[f[i%6+1]])if(val[j]%100==val[k]/100)G.ins(j,k);
		}
		rep(i,1,p[1])if(G.dfs(0,i,i))printf("%d\n",ans),ans=0;
		return;
	}
	rep(i,1,6)if(!mark[i]){
		mark[i]=1;f[k]=i;
		dfs(k+1);
		mark[i]=0;
	}
}
int main(){
	for(LL i=1;i*(i+1)/2<10000;++i)if(i*(i+1)/2>=1000)val[++p[1]]=i*(i+1)/2;
	p[2]=p[1];for(LL i=1;i*i<10000;++i)if(i*i>=1000)val[++p[2]]=i*i;
	p[3]=p[2];for(LL i=1;i*(3*i-1)/2<10000;++i)if(i*(3*i-1)/2>=1000)val[++p[3]]=i*(3*i-1)/2;
	p[4]=p[3];for(LL i=1;i*(2*i-1)<10000;++i)if(i*(2*i-1)>=1000)val[++p[4]]=i*(2*i-1);
	p[5]=p[4];for(LL i=1;i*(5*i-3)/2<10000;++i)if(i*(5*i-3)/2>=1000)val[++p[5]]=i*(5*i-3)/2;
	p[6]=p[5];for(LL i=1;i*(3*i-2)<10000;++i)if(i*(3*i-2)>=1000)val[++p[6]]=i*(3*i-2);
	mark[1]=f[1]=1;dfs(2);
	return 0;
}
