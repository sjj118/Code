#include<iostream>
#include<cstdio>
#include<vector>
#define pb push_back
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e6+10,alp=26,mo=1e9+7;
inline bool vaild(char c){return c>='a'&&c<='z';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int n;
vector<int> pos[N];
struct Trie{
	int tot,son[N][alp],fail[N],pa[N][20],dep[N],val[N];
	Trie(){tot=1;}
	int ins(int k,int c){
		if(son[k][c])return son[k][c];
		val[++tot]=(val[k]*26ll+c)%mo;
		return son[k][c]=tot;
	}
	int q[N],ql,qr;
	void buildAC(){
		ql=qr=0;
		dep[1]=1;
		fail[1]=1;
		rep(i,0,alp-1)if(son[1][i]){
			fail[son[1][i]]=1;
			dep[son[1][i]]=2;
			q[qr++]=son[1][i];
		}else son[1][i]=1;
		while(ql!=qr){
			int k=q[ql++];
			rep(i,0,alp-1)if(son[k][i]){
				fail[son[k][i]]=son[fail[k]][i];
				dep[son[k][i]]=dep[fail[son[k][i]]]+1;
				q[qr++]=son[k][i];
			}else son[k][i]=son[fail[k]][i];
		}
		rep(i,1,tot)pa[i][0]=fail[i];
		rep(i,1,19)rep(j,1,tot)pa[j][i]=pa[pa[j][i-1]][i-1];
	}
	int lca(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		per(i,19,0)if(dep[pa[a][i]]>=dep[b])a=pa[a][i];
		if(a==b)return a;
		per(i,19,0)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
		return pa[a][0];
	}
}T;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		char c=gc();
		pos[i].pb(1);
		while(vaild(c))pos[i].pb(T.ins(pos[i].back(),c-'a')),c=getchar();
	}
	T.buildAC();
	int m;scanf("%d",&m);
	while(m--){
		int i,j,k,l;scanf("%d%d%d%d",&i,&j,&k,&l);
		printf("%d\n",T.val[T.lca(pos[i][j],pos[k][l])]);
	}
	return 0;
}
