#include<iostream>
#include<cstdio>
#include<cstring>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=4e5+10,alp=26,P=N<<1;
inline bool vaild(char c){return c>='a'&&c<='z';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int n,s[N];
struct SAM{
	int tot,last,son[P][alp],step[P],pr[P],sz[2][P];
	SAM(){tot=1;}
	void ins(int c,int t){
		int k=++tot;step[tot]=step[last]+1;++sz[t][k];
		while(last&&son[last][c]==0)son[last][c]=k,last=pr[last];
		if(last){
			int q=son[last][c];
			if(step[q]==step[last]+1)pr[k]=q;
			else{
				int nq=++tot;
				step[nq]=step[last]+1;
				memcpy(son[nq],son[q],sizeof(son[q]));
				pr[nq]=pr[q];
				pr[q]=pr[k]=nq;
				while(last&&son[last][c]==q)son[last][c]=nq,last=pr[last];
			}
		}else pr[k]=1;
		last=k;
	}
	int q[P],ql,qr,deg[P];
	void topsort(){
		ql=qr=0;
		rep(i,2,tot)++deg[pr[i]];
		rep(i,2,tot)if(deg[i]==0)q[qr++]=i;
		while(ql!=qr){
			int k=q[ql++];
			sz[0][pr[k]]+=sz[0][k];
			sz[1][pr[k]]+=sz[1][k];
			if(--deg[pr[k]]==0)q[qr++]=pr[k];
		}
	}
	void build(int*s,int n,int t){
		last=1;
		rep(i,1,n)ins(s[i],t);
	}
	LL count(){
		LL ret=0;
		rep(i,1,tot)ret+=1ll*(step[i]-step[pr[i]])*sz[0][i]*sz[1][i];
		return ret;
	}
}sam;
int main(){
	char c=gc();
	while(vaild(c))s[++n]=c-'a',c=getchar();
	sam.build(s,n,0);
	c=gc();n=0;
	while(vaild(c))s[++n]=c-'a',c=getchar();
	sam.build(s,n,1);
	sam.topsort();
	printf("%lld",sam.count());
	return 0;
}
