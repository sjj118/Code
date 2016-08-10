#include<cstdio>
#include<algorithm>
#define maxn 5010
#define maxp 80010
#define inf 1e9

using namespace std;

int n;
struct Tag{
	int x,u,d,t;
}tag[maxn<<1];
bool operator<(Tag a,Tag b){return a.x<b.x||a.x==b.x&&a.t>b.t;}
struct SGT{
	int val[maxp],line[maxp],sum[maxp],lp[maxp],rp[maxp];
	void build(int k,int l,int r){
		val[k]=line[k]=sum[k]=0;lp[k]=inf;rp[k]=-inf;
		if(l==r)return;
		int m=(l+r)>>1;
		build(k<<1,l,m);build(k<<1|1,m+1,r);
	}
	void pushup(int k,int l,int r){
		if(l==r){if(val[k])line[k]=1,sum[k]=1,lp[k]=l,rp[k]=r;else line[k]=0,sum[k]=0,lp[k]=inf,rp[k]=-inf;return;}
		if(val[k])line[k]=1,sum[k]=r-l+1,lp[k]=l,rp[k]=r;
		else line[k]=line[k<<1]+line[k<<1|1]-(rp[k<<1]+1==lp[k<<1|1]),sum[k]=sum[k<<1]+sum[k<<1|1],lp[k]=min(lp[k<<1],lp[k<<1|1]),rp[k]=max(rp[k<<1],rp[k<<1|1]);
	}
	void modify(int v,int ll,int rr,int k,int l,int r){
		if(ll<=l&&r<=rr)return val[k]+=v,pushup(k,l,r);
		int m=(l+r)>>1;
		if(ll<=m)modify(v,ll,rr,k<<1,l,m);
		if(rr>m)modify(v,ll,rr,k<<1|1,m+1,r);
		pushup(k,l,r);
	}
}T;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		tag[i*2-1].x=x1;tag[i*2-1].d=y1;tag[i*2-1].u=y2;tag[i*2-1].t=1;
		tag[i*2].x=x2;tag[i*2].d=y1;tag[i*2].u=y2;tag[i*2].t=-1;
	}
	sort(tag+1,tag+1+2*n);
	T.build(1,-10000,10000);
	int ans=0;
	for(int i=-10000,j=1;i<=10000;++i){
		int t=T.sum[1];
		while(j<=2*n&&tag[j].x==i&&tag[j].t==1)
		T.modify(1,tag[j].d,tag[j].u-1,1,-10000,10000),++j;
		ans+=T.sum[1]-t;t=T.sum[1];
		while(j<=2*n&&tag[j].x==i&&tag[j].t==-1)
		T.modify(-1,tag[j].d,tag[j].u-1,1,-10000,10000),++j;
		ans+=t-T.sum[1];
		ans+=T.line[1]*2;
	}
	printf("%d",ans);
	return 0;
}
