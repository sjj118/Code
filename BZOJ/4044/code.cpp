#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,alp=4;
inline void up(int&x,int y){if(y>x)x=y;}
inline bool vaild(char c){return c=='A'||c=='T'||c=='G'||c=='C';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int trans(char c){
	if(c=='A')return 0;
	if(c=='T')return 1;
	if(c=='G')return 2;
	return 3;
}
int f[N],g[N],h[N];
struct PAM{
	int a[N],n,tot,son[N][alp],pa[N],pr[N],step[N],trans[N];
	void clear(){
		rep(i,0,tot){
			cls(son[i]);
			f[i]=g[i]=h[i]=trans[i]=0;
		}
		tot=1;n=0;
		a[0]=-1;pr[0]=1;step[1]=-1;
	}
	PAM(){clear();}
	int ins(int p,int c){
		a[++n]=c;
		while(a[n-step[p]-1]!=c)p=pr[p];
		if(son[p][c])return son[p][c];
		int k=++tot;step[k]=step[p]+2;
		int q=pr[p];while(a[n-step[q]-1]!=c)q=pr[q];
		pr[k]=son[q][c];
		if(step[k]<=2)trans[k]=pr[k];
		else{
			trans[k]=trans[p];
			while(a[n-step[trans[k]]-1]!=c||(step[trans[k]]+2)*2>step[k])trans[k]=pr[trans[k]];
			trans[k]=son[trans[k]][c];
		}
		son[p][c]=k;pa[k]=p;
		return k;
	}
	int count(){
		rep(i,2,tot){
			g[i]=max(g[pa[i]],f[trans[i]]);
			if(step[i]%2==0)h[i]=g[i]+step[i]/2-1;
			f[i]=max(h[i],f[pr[i]]);
		}
		int ret=0;
		rep(i,0,tot)up(ret,h[i]);
		return n-ret;
	}
}pam;
char s[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		pam.clear();
		scanf("\n%s",s);
		int k=1,n=strlen(s);
		rep(i,0,n-1)k=pam.ins(k,trans(s[i]));
		printf("%d\n",pam.count());
	}
	return 0;
}
