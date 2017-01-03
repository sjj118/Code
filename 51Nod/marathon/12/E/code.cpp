#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define pb push_back
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,P=2e6+10,alp=26;
inline bool vaild(char c){return c>='a'&&c<='z';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int s[N],n,m;
vector<int> pos[N];
struct SAM{
	int tot,pr[P],son[P][alp],step[P],num[P],pa[P][20];
	SAM(){tot=1;}
	int ins(int c,int p){
		if(son[p][c]){
			int q=son[p][c];
			if(step[q]==step[p]+1){num[q]=1;return q;}
			int nq=++tot;step[nq]=step[p]+1;
			num[nq]=1;
			memcpy(son[nq],son[q],sizeof(son[q]));
			pr[nq]=pr[q];pr[q]=nq;
			while(p&&son[p][c]==q)son[p][c]=nq,p=pr[p];
			return nq;
		}
		int k=++tot;step[k]=step[p]+1;num[k]=1;
		while(p&&son[p][c]==0)son[p][c]=k,p=pr[p];
		if(p){
			int q=son[p][c];
			if(step[q]==step[p]+1)pr[k]=q;
			else{
				int nq=++tot;step[nq]=step[p]+1;
				memcpy(son[nq],son[q],sizeof(son[q]));
				pr[nq]=pr[q];pr[q]=pr[k]=nq;
				while(p&&son[p][c]==q)son[p][c]=nq,p=pr[p];
			}
		}else pr[k]=1;
		return k;
	}
	int q[P],c[P];
	void init(){
		rep(i,1,tot)++c[step[i]];
		rep(i,1,tot)c[i]+=c[i-1];
		per(i,tot,1)q[c[step[i]]--]=i;
		per(i,tot,1)num[pr[q[i]]]+=num[q[i]];
		rep(i,1,tot)pa[i][0]=pr[i];
		rep(i,1,19)rep(j,1,tot)pa[j][i]=pa[pa[j][i-1]][i-1];
	}
	int jump(int k,int l){
		per(i,19,0)if(step[pa[k][i]]>=l)k=pa[k][i];
		return k;
	}
}sam;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		pos[i].pb(1);
		char c=gc();
		while(vaild(c))pos[i].pb(sam.ins(c-'a',pos[i].back())),c=getchar();
	}
	sam.init();
	scanf("%d",&m);
	rep(i,1,m){
		int p,x,y;scanf("%d%d%d",&p,&x,&y);
		int t=sam.jump(pos[p][y],y-x+1);
		printf("%d\n",sam.num[t]);
	}
	return 0;
}
