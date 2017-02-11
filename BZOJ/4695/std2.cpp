
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iostream>
#define ll long long
using namespace std;
const int N=5*(1e5+1),inf=1e9;
struct st{int max,min,se1,se2,num1,num2,tag,tmx,tmn; ll sum;} T[N<<2];
int n,m,i,x,y,z,tp,a[N];
ll ans;
void modify(int,int,int,int,int,int,int);
void pushdown(int,int,int);
void go(int &x,int y){x+=x==inf||x==-inf?0:y;}
inline int max(int x,int y){int temp=x-y; return y+(temp&(~(temp>>31)));}
inline void read(int &x)
{
    char ch=getchar();
    int f=1;
    for (;ch<'0' || ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (x=0;ch>='0' && ch<='9';ch=getchar()) x=x*10+ch-'0';
    if (f==-1) x=-x;
}
 
bool updmax(int t,int l,int r,int x)
{
    if (x<=T[t].min) return 1;
    if (T[t].se2>x)
    {
        T[t].sum+=(ll)T[t].num2*(x-T[t].min);
        T[t].max=max(T[t].max,T[t].min=x);
        T[t].se1=max(T[t].se1,x);
        if (T[t].max==x) T[t].se1=-inf,T[t].se2=inf,T[t].num1=T[t].num2=r-l+1;
        T[t].tmn=max(T[t].tmx=max(T[t].tmx,x),T[t].tmn);
        return 1;
    }
    return 0;
}
 
bool updmin(int t,int l,int r,int x)
{
    if (x>=T[t].max) return 1;
    if (T[t].se1<x)
    {
        T[t].sum-=(ll)T[t].num1*(T[t].max-x);
        T[t].min=min(T[t].min,T[t].max=x);
        T[t].se2=min(T[t].se2,x);
        if (T[t].min==x) T[t].se1=-inf,T[t].se2=inf,T[t].num1=T[t].num2=r-l+1;
        T[t].tmx=min(T[t].tmn=min(T[t].tmn,x),T[t].tmx);
        return 1;
    }
    return 0;
}
 
void pushup(int t)
{
    int ls=t<<1,rs=ls|1;
    T[t].num1=T[t].num2=0;
    if (T[ls].max>=T[rs].max) T[t].max=T[ls].max,T[t].num1=T[ls].num1;
    if (T[rs].max>=T[ls].max) T[t].max=T[rs].max,T[t].num1+=T[rs].num1;
    if (T[ls].min<=T[rs].min) T[t].min=T[ls].min,T[t].num2=T[ls].num2;
    if (T[rs].min<=T[ls].min) T[t].min=T[rs].min,T[t].num2+=T[rs].num2;
    int se=-inf;
    if (T[ls].max<T[rs].max) se=max(se,T[ls].max);
    else se=max(se,T[ls].se1);
    if (T[rs].max<T[ls].max) se=max(se,T[rs].max);
    else se=max(se,T[rs].se1);
    T[t].se1=se;
    se=inf;
    if (T[ls].min>T[rs].min) se=min(se,T[ls].min);
    else se=min(se,T[ls].se2);
    if (T[rs].min>T[ls].min) se=min(se,T[rs].min);
    else se=min(se,T[rs].se2);
    T[t].se2=se;
    T[t].sum=T[ls].sum+T[rs].sum;
}
 
void pushdown(int t,int l,int r)
{
    if (l==r) return;
    int mid=(l+r)>>1,ls=t<<1,rs=ls|1;
    int x=T[t].tag;
    if (x)
    {
        T[ls].max+=x;
        T[ls].min+=x;
        go(T[ls].se1,x);
        go(T[ls].se2,x);
        T[ls].tmx+=x;
        T[ls].tmn+=x;
        T[rs].tmx+=x;
        T[rs].tmn+=x;
        T[ls].sum+=(mid-l+1)*x;
        T[rs].max+=x;
        T[rs].min+=x;
        go(T[rs].se1,x);
        go(T[rs].se2,x);
        T[rs].sum+=(r-mid)*x;
        T[ls].tag+=x;
        T[rs].tag+=x;
        T[t].tag=0;
    }
    if (T[t].tmx!=-inf)
    {
        updmax(ls,l,mid,T[t].tmx);
        updmax(rs,mid+1,r,T[t].tmx);
        T[t].tmx=-inf;
    }
    if (T[t].tmn!=inf)
    {
        updmin(ls,l,mid,T[t].tmn);
        updmin(rs,mid+1,r,T[t].tmn);
        T[t].tmn=inf;
    }
}
 
void build(int t,int l,int r)
{
    T[t].tmx=-inf,T[t].tmn=inf;
    if (l==r)
    {
        T[t].max=T[t].min=T[t].sum=a[l];
        T[t].num1=T[t].num2=1;
        T[t].se1=-inf,T[t].se2=inf;
        return;
    }
    int mid=(l+r)>>1,ls=t<<1,rs=ls|1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(t);
}
 
void modify(int t,int l,int r)
{
    if (x<=l && r<=y)
    {
        if (tp==1)
        {
            T[t].max+=z,T[t].min+=z,T[t].tag+=z,T[t].tmx+=z,T[t].tmn+=z;
            T[t].sum+=(r-l+1)*z;
            go(T[t].se1,z),go(T[t].se2,z);
            pushdown(t,l,r);
            return;
        }
        else if (tp==2 && updmax(t,l,r,z)) return;
        else if (tp==3 && updmin(t,l,r,z)) return;
    }
    pushdown(t,l,r);
    int mid=(l+r)>>1,ls=t<<1,rs=ls|1;
    if (x<=mid) modify(ls,l,mid);
    if (y>mid) modify(rs,mid+1,r);
    pushup(t);
}
 
void query(int t,int l,int r)
{
    pushdown(t,l,r);
    if (x<=l && r<=y)
    {
        if (tp==4) ans+=T[t].sum;
        if (tp==5){if ((ll)T[t].max>ans) ans=T[t].max;}
        if (tp==6){if ((ll)T[t].min<ans) ans=T[t].min;}
        return;
    }
    int mid=(l+r)>>1,ls=t<<1,rs=ls|1;
    if (x<=mid) query(ls,l,mid);
    if (y>mid) query(rs,mid+1,r);
}
 
int main()
{
        read(n);
        for (i=1;i<=n;i++) scanf("%d",&a[i]);
        build(1,1,n);
        for (read(m);m;m--)
        {
            read(tp);
            if (tp<=3)
            {
                read(x),read(y),read(z);
                modify(1,1,n);
            }
            else
            {
                if (tp==4) ans=0;
                if (tp==5) ans=-inf;
                if (tp==6) ans=inf;
                read(x),read(y);
                query(1,1,n);
                printf("%lld\n",ans);
            }
        }
}
