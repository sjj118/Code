#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#define pa pair<int,int>
#define ll long long
#define inf 1000000000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,blo,cnt;
int a[100005],ans[1000005];
int bl[100005],l[1005],r[1005];
int c[100005],bloans[1005];
struct que{
	int l,r,a,b,id;
}q[1000005];
bool operator<(que a,que b)
{
	if(bl[a.l]!=bl[b.l])return a.l<b.l;
	return a.r<b.r;
}
int query(int x,int y)
{
	int tmp=0;
	int L=bl[x],R=bl[y];
	for(int i=L+1;i<R;i++)
		tmp+=bloans[i];
	if(L==R)
		for(int i=x;i<=y;i++)
		{
			if(c[i])tmp++;
		}
	else 
	{
		for(int i=x;i<=r[L];i++)
			if(c[i])tmp++;
		for(int i=l[R];i<=y;i++)
			if(c[i])tmp++;
	}
	return tmp;
}
void del(int x)
{
   	c[x]--;
	if(c[x]==0)bloans[bl[x]]--;
}
void add(int x)
{
	c[x]++;
	if(c[x]==1)bloans[bl[x]]++;
}
void solve()
{
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		while(l<q[i].l)del(a[l]),l++;
		while(r>q[i].r)del(a[r]),r--;
		while(l>q[i].l)l--,add(a[l]);
		while(r<q[i].r)r++,add(a[r]);
		ans[q[i].id]=query(q[i].a,q[i].b);
	}
}
int main()
{
	freopen("code.in","r",stdin);freopen("std.out","w",stdout);
	n=read();m=read();blo=sqrt(n/2);
	cnt=n/blo+n%blo!=0;
	for(int i=1;i<=n;i++)bl[i]=(i-1)/blo+1;
	for(int i=1;i<=n;i++)
	{
		r[bl[i]]=i;
		if(!l[bl[i]])l[bl[i]]=i;
	}
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)
	{
		q[i].l=read();q[i].r=read();
		q[i].a=read();q[i].b=read();
		q[i].id=i;
	}
	sort(q+1,q+m+1);
	solve();
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}
