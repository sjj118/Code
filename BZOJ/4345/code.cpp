#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010
#define LL long long
#define inf 2000000000
 
using namespace std;
 
LL n,k,a[maxn],b[maxn];
LL m,num,sum;
int top,last[maxn];
void dfs(){
    ++num;sum+=b[last[top]];
    for(int i=last[top]+1;sum+b[i]<=m&&i<=n&&num<=k;++i)last[++top]=i,dfs(),--top;
    sum-=b[last[top]];
}
int v[2100000];
void build(int x,int a,int b){
  if(a==b){v[x]=::a[a];return;}
  int mid=(a+b)>>1;
  build(x<<1,a,mid),build(x<<1|1,mid+1,b),v[x]=min(v[x<<1],v[x<<1|1]);
}
int ask(int x,int a,int b,int c,LL p){
  if(c<=a){
    if(v[x]>p)return 0;
    if(a==b)return a;
  }
  int mid=(a+b)>>1;
  if(c<=mid){
    int t=ask(x<<1,a,mid,c,p);
    if(t)return t;
  }
  return ask(x<<1|1,mid+1,b,c,p);
}
int sta[maxn],tot;
void dfs2(int p){
    sum+=a[p];sta[tot++]=p;
    if(sum==m){
        ++num;
        if(num==k)for(int i=1;i<tot;++i)printf("%d ",sta[i]);
    }
    int t=p;
    while(num<k&&t<n&&(t=ask(1,1,n,t+1,m-sum)))dfs2(t);
    --tot;sum-=a[p];
}
int read(){
	int tmp=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();
	return tmp;
}
 
int main(){
    n=read();k=read();
    if(k==1)return puts("0"),0;
    LL l=0,r=0;
    for(int i=1;i<=n;++i)a[i]=read(),b[i]=a[i],r+=b[i];
    sort(b+1,b+1+n);
    while(l<r){
        m=(l+r)>>1;sum=num=0;
        last[top=1]=0;
        dfs();
        if(num<k)l=m+1;else r=m;
    }
    printf("%lld\n",l);
    m=l-1;sum=num=0;
    last[top=1]=0;
    dfs();
    k-=num;
    m=l;
    build(1,1,n);
    sum=num=0;
    dfs2(0);
    return 0;
}
