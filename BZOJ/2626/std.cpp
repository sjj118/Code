
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define ll long long
#define lowbit(x) (x&(-x))
#define N 1000500
#define inf 1e9
#define sqr(x) (x)*(x)
#define L t[x].l
#define R t[x].r
#define mid (l+r>>1)
using namespace std;
int sc()
{
    int i=0,f=1; char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')i=i*10+c-'0',c=getchar();
    return i*f;
}
struct W{
    int d[2],mx[2],mn[2],l,r,num;
}t[N],now;
int n,m,root,D,K;
bool operator <(W a,W b){return a.d[D]<b.d[D];}
void push_up(int x)
{
    for(int i=0;i<=1;i++)
    {
        t[x].mn[i]=min(t[x].mn[i],min(t[L].mn[i],t[R].mn[i]));
        t[x].mx[i]=max(t[x].mx[i],max(t[L].mx[i],t[R].mx[i]));
    }
}
void build(int &x,int l,int r,int dir)
{
    D=dir; x=mid; 
    nth_element(t+l,t+x,t+r+1);
    for(int i=0;i<=1;i++)
        t[x].mx[i]=t[x].mn[i]=t[x].d[i];
    if(l<x)build(L,l,mid-1,dir^1);
    if(x<r)build(R,mid+1,r,dir^1);
    push_up(x);
}
//------------------------------------------------------------------------
struct Q{
    ll dis;int num;
};
bool operator <(Q a,Q b)
{
    return a.dis>b.dis||(a.dis==b.dis&&a.num<b.num);
}
priority_queue<Q>q;
ll dis(W a,W b){return (ll)sqr(a.d[0]-b.d[0])+(ll)sqr(a.d[1]-b.d[1]);}
ll cal(int x)
{
    if(!x)return -2;
    ll ans=0;
    for(int i=0;i<=1;i++)
        ans+=max((ll)sqr(t[x].mx[i]-now.d[i]),(ll)sqr(t[x].mn[i]-now.d[i]));
    return ans;
}
void query(int x)
{
    if(!x)return ;
    ll dl=cal(L),dr=cal(R),d=dis(t[x],now);
    if(d>q.top().dis||(d==q.top().dis&&t[x].num<q.top().num))
        q.pop(),q.push((Q){d,t[x].num});
    if(dl>dr)
    {
        if(dl>=q.top().dis)query(L);
        if(dr>=q.top().dis)query(R);
    }
    else
    {
        if(dr>=q.top().dis)query(R);
        if(dl>=q.top().dis)query(L);
    }
}   
int main()
{
    t[0].mn[0]=t[0].mn[1]=inf;
    t[0].mx[0]=t[0].mx[1]=-inf;
    n=sc();
    for(int i=1;i<=n;i++)
        t[i].d[0]=sc(),t[i].d[1]=sc(),t[i].num=i;
    build(root,1,n,1);
    m=sc();
    while(m--)
    {
        now.d[0]=sc(),now.d[1]=sc(),K=sc();
        while(!q.empty())q.pop();
        for(int i=1;i<=K;i++)q.push((Q){-1,0});
        query(root);
        printf("%d\n",q.top().num);
    }
    return 0;
}
