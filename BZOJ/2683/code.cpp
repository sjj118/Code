#include<iostream>
#include<cstdio>
#include<algorithm>
#define lowbit(x) x&(-x)
#define maxn 1000110
#define maxm 200010
#define inf 1e9

using namespace std;

int n,ans[maxm];
struct fenwichtree{
	int arr[maxn],maxnum;
	void add(int x,int t){
		while(x<=maxnum)arr[x]+=t,x+=lowbit(x);
	}
	int sum(int x){
		int s=0;
		while(x)s+=arr[x],x-=lowbit(x);
		return s;
	}
} T;
int tot_sign,tot_query;
struct query{
	int x,y,y2,sign,val,pos;
} qs[maxn],temp[maxn];
bool operator<(query a,query b){
	return a.x<b.x||a.x==b.x&&a.sign<b.sign;
}
void solve(int l,int r){
	if(l==r||qs[l].sign==qs[r].sign&&qs[l].sign!=0)return;
	int m=(l+r)>>1;
	if(qs[m].sign==qs[m+1].sign&&qs[m].sign!=0)--m;
	solve(l,m);
	solve(m+1,r);
	for(int i=l,j=m+1;i<=m||j<=r;){
		if(j>r||i<=m&&qs[i]<qs[j])temp[i+j-l-m]=qs[i++];
		else temp[i+j-l-m]=qs[j++];
	}
	for(int i=l;i<=r;++i)qs[i]=temp[i-l+1];
	for(int i=l;i<=r;++i){
		if(qs[i].sign==0&&qs[i].pos<=m) T.add(qs[i].y,qs[i].val);
		else if(qs[i].sign&&qs[i].pos>m)ans[qs[i].sign]+=T.sum(qs[i].y)-T.sum(qs[i].y2);
	}
	for(int i=l;i<=r;++i){
		if(qs[i].sign==0&&qs[i].pos<=m) T.add(qs[i].y,-qs[i].val);
	}
}

int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&n);
	int op;
	while(scanf("%d",&op)>0&&op!=3){
		++tot_query;
		if(op==1){
			scanf("%d%d%d",&qs[tot_query].x,&qs[tot_query].y,&qs[tot_query].val);
			qs[tot_query].pos=tot_query;
		}else{
			qs[tot_query].sign=++tot_sign;
			qs[tot_query].pos=tot_query;
			qs[++tot_query].sign=tot_sign;
			qs[tot_query].pos=tot_query;
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			qs[tot_query-1].x=x1-1;qs[tot_query].x=x2;
			qs[tot_query-1].y=y1-1;qs[tot_query-1].y2=y2;
			qs[tot_query].y=y2;qs[tot_query].y2=y1-1;
		}
	}
	T.maxnum=n;
	solve(1,tot_query);
	for(int i=1;i<=tot_sign;++i)printf("%d\n",ans[i]);
	return 0;
}
