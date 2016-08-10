#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define cls(a) memset(a,0,sizeof(a))
#define maxn 110
#define inf 1e9

using namespace std;

int n;
struct Tag{
	double x,d,u;
	int t;
}tag[maxn<<1];
bool operator<(Tag a,Tag b){return a.x<b.x;}
bool comp(double*a,double*b){return *a<*b;}
struct Lisan{
	double*val[maxn<<2],len[maxn<<2];
	int tot,maxval;
	void clear(){tot=maxval=0;}
	void ins(double&x){val[++tot]=&x;}
	void work(){
		sort(val+1,val+1+tot,comp);
		double last=-1;
		for(int i=1;i<=tot;++i){
			if(*val[i]>last)len[++maxval]=*val[i]-last,last=*val[i];
			*val[i]=maxval;
		}
		for(int i=1;i<=maxval;++i)len[i]+=len[i-1];
	}
}X,Y;
struct SGT{
	int val[maxn<<3];
	double sum[maxn<<3];
	void clear(){cls(val);cls(sum);}
	void pushup(int k,int l,int r){
		if(l==r){sum[k]=val[k]>0?Y.len[r+1]-Y.len[l]:0;return;}
		sum[k]=val[k]>0?Y.len[r+1]-Y.len[l]:sum[k<<1]+sum[k<<1|1];
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
	int cas=0;
	while(scanf("%d",&n)>0&&n){
		X.clear();Y.clear();
		for(int i=1;i<=n;++i){
			double x1,y1,x2,y2;scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			tag[i*2-1].x=x1;tag[i*2-1].d=y1;tag[i*2-1].u=y2;tag[i*2-1].t=1;
			tag[i*2].x=x2;tag[i*2].d=y1;tag[i*2].u=y2;tag[i*2].t=-1;
		}
		sort(tag+1,tag+1+n*2);
		for(int i=1;i<=2*n;++i)X.ins(tag[i].x),Y.ins(tag[i].d),Y.ins(tag[i].u);
		X.work();Y.work();
		double ans=0;
		for(int i=1,j=1;i<=X.maxval;++i){
			while(j<=2*n&&tag[j].x==i)T.modify(tag[j].t,tag[j].d,tag[j].u-1,1,1,Y.maxval),++j;
			ans+=(X.len[i+1]-X.len[i])*T.sum[1];
		}
		printf("Test case #%d\n",++cas);
		printf("Total explored area: %.2lf\n\n",ans);
	}
	return 0;
}
