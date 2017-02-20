#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::map;
typedef long long LL;
const int N=1e5+10,P=N<<1;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
int n;
LL ans=0;
struct SAM{
	int tot,step[P],pr[P];
	map<int,int> son[P];
	SAM(){tot=1;}
	int ins(int p,int c){
		int k=++tot;step[k]=step[p]+1;
		while(p&&!son[p][c])son[p][c]=k,p=pr[p];
		if(p){
			int q=son[p][c];
			if(step[q]==step[p]+1)pr[k]=q,ans+=step[k]-step[q];
			else{
				int nq=++tot;step[nq]=step[p]+1;
				son[nq]=son[q];
				pr[nq]=pr[q];ans+=step[nq]-step[pr[nq]];
				ans-=step[q]-step[pr[q]];ans+=step[q]-step[nq];
				pr[q]=pr[k]=nq;ans+=step[k]-step[nq];
				while(p&&son[p][c]==q)son[p][c]=nq,p=pr[p];
			}
		}else pr[k]=1,ans+=step[k];
		return k;
	}
}sam;
int main(){
	scanf("%d",&n);
	int k=1;
	rep(i,1,n){
		k=sam.ins(k,read());
		printf("%lld\n",ans);
	}
	return 0;
}
