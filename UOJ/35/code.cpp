#include<bits/stdc++.h>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10;
int n,a[N];
char s[N];
struct SA{
	int sa[N],rank[N],hgt[N];
	int c[N],wa[N],wb[N];
	bool cmp(int*r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}
	void build(int*a){
		int m=27,*x=wa,*y=wb;
		cls(c);rep(i,1,n)++c[x[i]=a[i]];
		rep(i,1,m)c[i]+=c[i-1];
		per(i,n,1)sa[c[a[i]]--]=i;
		for(int j=1,p=1;p<n;j<<=1,m=p){
			p=0;rep(i,n-j+1,n)y[++p]=i;
			rep(i,1,n)if(sa[i]>j)y[++p]=sa[i]-j;
			cls(c);rep(i,1,n)++c[x[i]];
			rep(i,1,m)c[i]+=c[i-1];
			per(i,n,1)sa[c[x[y[i]]]--]=y[i];
			swap(x,y);x[sa[1]]=p=1;
			rep(i,2,n)x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p:++p;
		}
		rep(i,1,n)rank[sa[i]]=i;
		for(int k=0,i=1,j;i<=n;hgt[rank[i++]]=k)
			for(k?--k:k,j=sa[rank[i]-1];a[i+k]==a[j+k];++k);
	}
}A;
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	rep(i,1,n)a[i]=s[i]-'a'+1;
	A.build(a);
	rep(i,1,n)printf("%d ",A.sa[i]);puts("");
	rep(i,2,n)printf("%d ",A.hgt[i]);
	return 0;
}
