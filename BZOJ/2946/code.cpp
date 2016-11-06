#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

const int N=5+2,L=2000+10,P=N*L,alp=36;
char s[L];
int a[P],l[N],st[N];
int m;
int inwhich(int p){
	rep(i,1,m)if(p>=st[i]&&p<st[i+1])return i;
	return 0;
}
struct SA{
	int n,sa[P],rank[P],hgt[P];
	int wa[P],wb[P],c[P];
	bool cmp(int*r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}
	void build(int*a,int n,int m){
		int *x=wa,*y=wb;this->n=n;
		cls(c);rep(i,1,n)++c[x[i]=a[i]];
		rep(i,1,m)c[i]+=c[i-1];
		per(i,n,1)sa[c[a[i]]--]=i;
		for(int j=1,p=1;p<n;m=p,j<<=1){
			p=0;rep(i,n-j+1,n)y[++p]=i;
			rep(i,1,n)if(sa[i]>j)y[++p]=sa[i]-j;
			cls(c);rep(i,1,n)++c[x[i]];
			rep(i,1,m)c[i]+=c[i-1];
			per(i,n,1)sa[c[x[y[i]]]--]=y[i];
			swap(x,y);x[sa[1]]=p=1;
			rep(i,2,n)x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p:++p;
		}
		rep(i,1,n)rank[sa[i]]=i;
		for(int i=1,j,k=0;i<=n;hgt[rank[i++]]=k)for(k?--k:k,j=sa[rank[i]-1];a[i+k]==a[j+k];++k);
	}
	bool check(int h){
		int l=1,vis[N];
		rep(r,1,n){
			if(hgt[r]<h)cls(vis),vis[inwhich(sa[r])]=1,l=r;
			else vis[inwhich(sa[r])]=1;
			bool flag=0;
			rep(i,1,m)if(!vis[i])flag=1;
			if(!flag)return 1;
		}
		return 0;
	}
}sa;
int main(){
	scanf("%d",&m);
	st[1]=1;
	rep(i,1,m){
		scanf("\n%s",s);
		l[i]=strlen(s);
		rep(j,0,l[i]-1)a[st[i]+j]=s[j]-'a'+10;
		st[i+1]=st[i]+l[i]+1;
		a[st[i+1]-1]=i;
	}
	sa.build(a,st[m+1]-1,alp);
	int l=0,r=st[m+1]-2;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(sa.check(mid))l=mid;else r=mid-1;
	}
	printf("%d",l);
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
