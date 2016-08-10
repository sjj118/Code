#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 10010
#define C(k) ((k-1)/C+1)

using namespace std;

int n,m,c[maxn],cnt,C,num[110][maxn<<1],ans[110][110],mark[maxn<<1];
struct Query{
	int kind,l,r;
}q[maxn];
bool comp(int*a,int*b){return *a<*b;}
struct Lisan{
	int*val[maxn<<1],tot;
	void ins(int*x){val[++tot]=x;}
	void work(){
		sort(val+1,val+tot+1,comp);
		for(int i=1,last=0;i<=tot;++i){
			if(*val[i]!=last)++cnt;last=*val[i];
			*val[i]=cnt;
		}
	}
}lisan;
void pre(){
	for(int i=1;i<=n;++i)++num[C(i)][c[i]];
	int K=C(n);
	for(int i=2;i<=K;++i)for(int j=1;j<=cnt;++j)num[i][j]+=num[i-1][j];
	for(int i=1;i<=K;++i){
		for(int j=(i-1)*C+1;j<=n;++j)if(mark[c[j]]!=i)mark[c[j]]=i,++ans[i][C(j)];
		for(int j=i+1;j<=K;++j)ans[i][j]+=ans[i][j-1];
	}
	memset(mark,0,sizeof(mark));
}

int main(){
	scanf("%d%d",&n,&m);C=floor(sqrt(n));
	for(int i=1;i<=n;++i)scanf("%d",&c[i]),lisan.ins(&c[i]);
	for(int i=1;i<=m;++i){
		char op;scanf("\n%c",&op);
		scanf("%d%d",&q[i].l,&q[i].r);
		if(op=='Q')q[i].kind=0;else q[i].kind=1,lisan.ins(&q[i].r);
	}
	lisan.work();
	pre();
	for(int i=1;i<=m;++i){
		if(q[i].kind){
			int p=q[i].l,col=q[i].r;
			int J=C(p),K=C(n);
			for(int j=1;j<=J;++j)
				for(int k=J;k<=K;++k){
					if(num[k][c[p]]-num[j-1][c[p]]==1)--ans[j][k];
					if(num[k][col]==num[j-1][col])++ans[j][k];
				}
			for(int j=J;j<=K;++j)--num[j][c[p]];
			for(int j=J;j<=K;++j)++num[j][col];
			c[p]=col;
		}else{
			int l=q[i].l,r=q[i].r,tmp=0;
			int J=C(l)+1,K=C(r)-1;
			if(J<=K)tmp=ans[J][K];
			for(int j=l;C(j)<J;++j){
				int col=c[j];
				if(mark[col]!=i&&num[K][col]==num[J-1][col])mark[col]=i,++tmp;
			}
			for(int k=r;C(k)>K;--k){
				int col=c[k];
				if(mark[col]!=i&&num[K][col]==num[J-1][col])mark[col]=i,++tmp;
			}
			printf("%d\n",tmp);
		}
	}
	return 0;
}
