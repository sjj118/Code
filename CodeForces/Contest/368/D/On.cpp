#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e3+10,maxq=1e5+10;
int n,m,q;
int bk[maxn][maxn],rev[maxn],all,sum[maxn];
struct Query{
	int type,x,y,ans;
}Q[maxq];
void apply(Query&q){
	if(q.type==1){
		all-=sum[q.x];
		if(rev[q.x]){
			if(bk[q.x][q.y]==1)++sum[q.x];
			else q.type=0;
			bk[q.x][q.y]=0;
		}else{
			if(bk[q.x][q.y]==0)++sum[q.x];
			else q.type=0;
			bk[q.x][q.y]=1;
		}
		all+=sum[q.x];
	}else if(q.type==2){
		all-=sum[q.x];
		if(!rev[q.x]){
			if(bk[q.x][q.y]==1)--sum[q.x];
			else q.type=0;
			bk[q.x][q.y]=0;
		}else{
			if(bk[q.x][q.y]==0)--sum[q.x];
			else q.type=0;
			bk[q.x][q.y]=1;
		}
		all+=sum[q.x];
	}else if(q.type==3){
		rev[q.x]^=1;
		all-=sum[q.x];
		sum[q.x]=m-sum[q.x];
		all+=sum[q.x];
	}
}
void roll(Query q){
	if(q.type==1){
		all-=sum[q.x];
		if(!rev[q.x]){
			if(bk[q.x][q.y]==1)--sum[q.x];
			bk[q.x][q.y]=0;
		}else{
			if(bk[q.x][q.y]==0)--sum[q.x];
			bk[q.x][q.y]=1;
		}
		all+=sum[q.x];
	}else if(q.type==2){
		all-=sum[q.x];
		if(rev[q.x]){
			if(bk[q.x][q.y]==1)++sum[q.x];
			bk[q.x][q.y]=0;
		}else{
			if(bk[q.x][q.y]==0)++sum[q.x];
			bk[q.x][q.y]=1;
		}
		all+=sum[q.x];
	}else if(q.type==3){
		rev[q.x]^=1;
		all-=sum[q.x];
		sum[q.x]=m-sum[q.x];
		all+=sum[q.x];
	}
}
struct OT{
	int tot,head[maxq],next[maxq],to[maxq];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void dfs(int k){
		apply(Q[k]);
		Q[k].ans=all;
		for(int p=head[k];p;p=next[p])dfs(to[p]);
		roll(Q[k]);
	}
}T;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,q){
		scanf("%d",&Q[i].type);
		if(Q[i].type<=2)scanf("%d%d",&Q[i].x,&Q[i].y);
		else scanf("%d",&Q[i].x);
		if(Q[i].type==4)T.ins(Q[i].x,i);else T.ins(i-1,i);
	}
	T.dfs(0);
	rep(i,1,q)printf("%d\n",Q[i].ans);
	return 0;
}
