
#include<ctime>
#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 200005
#define B 0.63
using namespace std;
int n,p,Ans,D,Q[4],Rt,m,cnt,h[N];
struct KD_node{int d[2],Mx[2],Mn[2],size,sum,ls,rs,val;}T[N];
int R()
{
	char c=getchar();int x=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}
void Min(int &x,int &y){if(y<x)x=y;}
void Max(int &x,int &y){if(y>x)x=y;}
bool cmp(const int &x,const int &y){return T[x].d[D]<T[y].d[D];}
void update(int k)
{
	int l=T[k].ls,r=T[k].rs;
	T[k].sum=T[l].sum+T[r].sum+T[k].val;
	T[k].size=T[l].size+T[r].size+1;
	for (int i=0;i<2;i++)
	{
		if(l)Max(T[k].Mx[i],T[l].Mx[i]),Min(T[k].Mn[i],T[l].Mn[i]);
		if(r)Max(T[k].Mx[i],T[r].Mx[i]),Min(T[k].Mn[i],T[r].Mn[i]);
	}
}
void build(int &k,int l,int r,int now)
{
	int mid=(l+r)>>1;D=now;
	nth_element(h+l,h+mid,h+r+1,cmp);
	k=h[mid];T[k].sum=T[k].val;
	for (int i=0;i<2;i++)
		T[k].Mx[i]=T[k].Mn[i]=T[k].d[i];
	if (l<mid) build(T[k].ls,l,mid-1,now^1);
	if (r>mid) build(T[k].rs,mid+1,r,now^1);
	update(k);
}
void del(int &k)
{
	if (!k) return;
	h[++cnt]=k;del(T[k].ls);del(T[k].rs);k=0;
}
int ccnt;
void rebuild(int &k,int now)
{
	h[cnt=1]=++m;T[m].size=1;
	for (int i=0;i<2;i++)
		T[m].d[i]=T[m].Mx[i]=T[m].Mn[i]=Q[i];
	T[m].sum=T[m].val=Q[2];
	del(k);build(k,1,cnt,now);
}
void ins(int &k,int now)
{
	if (!k)
	{
		k=++m;T[k].size=1;
		for (int i=0;i<2;i++)
			T[k].d[i]=T[k].Mx[i]=T[k].Mn[i]=Q[i];
		T[k].sum=T[k].val=Q[2];
		return;
	}
	if (Q[now]<T[k].d[now])
		if (T[T[k].ls].size>T[k].size*B) rebuild(k,now);
		else ins(T[k].ls,now^1);
	else
		if (T[T[k].rs].size>T[k].size*B) rebuild(k,now);
		else ins(T[k].rs,now^1);
	update(k);
}
bool inter(int k)
{
	if (!k) return 0;
	return Q[0]<=T[k].Mx[0]&&T[k].Mn[0]<=Q[2]&&Q[1]<=T[k].Mx[1]&&T[k].Mn[1]<=Q[3];
}
void qry(int k)
{
	++ccnt;
	if (Q[0]<=T[k].Mn[0]&&T[k].Mx[0]<=Q[2]&&Q[1]<=T[k].Mn[1]&&T[k].Mx[1]<=Q[3])
	{
		Ans+=T[k].sum;return;
	}
	if (Q[0]<=T[k].d[0]&&T[k].d[0]<=Q[2]&&Q[1]<=T[k].d[1]&&T[k].d[1]<=Q[3])
		Ans+=T[k].val;
	if (inter(T[k].ls)) qry(T[k].ls);
	if (inter(T[k].rs)) qry(T[k].rs);
}
int main()
{
	bool flag=0;
	for (n=R(),p=R();p!=3;p=R())
	{
		if (p==1) Q[0]=R(),Q[1]=R(),Q[2]=R(),ins(Rt,0);
		/*else{
			if(!flag)flag=1,cerr<<clock()<<endl;
			Q[0]=R(),Q[1]=R(),Q[2]=R(),Q[3]=R(),Ans=0,qry(Rt),printf("%d\n",Ans);
		}*/
	}
	cerr<<ccnt;
	return 0;
}

