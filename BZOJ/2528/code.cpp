#include<iostream>
#include<cstdio>
#include<cstring>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2e5+10;
int n,next[N],col[N];
char s[N];
struct UFS{
	int pa[N],rank[N],mark[N];
	int find(int k,int&v){
		if(k==pa[k])return k;
		pa[k]=find(pa[k],mark[k]);
		v^=mark[k];
		return pa[k];
	}
	bool unio(int a,int b,int v){
		a=find(a,v);b=find(b,v);
		if(a==b)return v==0;
		if(rank[a]>rank[b])swap(a,b);
		pa[a]=b;
		if(rank[a]==rank[b])++rank[b];
		return 1;
	}
	void clear(){rep(i,1,n)pa[i]=i,rank[i]=0,mark[i]=0;}
}S;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("\n%s",s+1);n=strlen(s+1);
		bool ans=1;
		S.clear();
		next[1]=0;
		for(int i=2,j=0;i<=n;++i){
			while(j){
				if(s[i]==s[j+1]){ans&=S.unio(i,j+1,0);break;}
				else ans&=S.unio(i,j+1,1),j=next[j];
			}
			if(s[i]==s[j+1])ans&=S.unio(i,j+1,0),++j;
			else ans&=S.unio(i,j+1,1);
			next[i]=j;
		}
		if(!ans)puts("XXX");
		else{
			rep(i,1,n){
				int v=0;
				S.find(i,v);
				printf("%d",v);
			}
			puts("");
		}
	}
	return 0;
}
