#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=5e4+10;
int n,k,eat[maxn],eaten[maxn];
struct UFS{
	int pa[maxn],rank[maxn],mark[maxn];
	void clear(){rep(i,1,n)pa[i]=i;}
	int find(int k){
		if(k==pa[k])return k;
		int t=find(pa[k]);
		mark[k]=(mark[pa[k]]+mark[k])%3;
		return pa[k]=t;
	}
	int unio(int a,int b,int c){
		int x=find(a),y=find(b);
		c=(c+3-mark[a])%3;
		c=(c+mark[b])%3;
		if(!a||!b)return a+b;
		if(a==b)return a;
		if(rank[x]>rank[y])swap(x,y),c=(3-c)%3;
		pa[x]=y;mark[x]=c%3;if(rank[x]==rank[y])++rank[y];
		return y;
	}
}S;
int main(){
	scanf("%d%d",&n,&k);S.clear();int ans=0;
	rep(i,1,k){
		int d,x,y;scanf("%d%d%d",&d,&x,&y);
		if(x>n||y>n){++ans;continue;}
		int a=S.find(x),b=S.find(y);
		if(d==1){
			if(a==b&&S.mark[x]!=S.mark[y]){++ans;continue;}
			S.unio(x,y,0);
		}else{
			if(a==b&&(S.mark[x]+1)%3!=S.mark[y]){++ans;continue;}
			S.unio(y,x,1);
		}
	}
	printf("%d",ans);
	return 0;
}
