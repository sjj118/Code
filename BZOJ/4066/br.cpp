
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#define M 200009
#define inf 100000000
#define ll long long
using namespace std;
struct A
{
    int l,r,mn[2],mx[2],d[2],v;
    int sum;
}a[M],b,p[M];
int n,m,root,N,tot;
int lans;
bool cmp(A a1,A a2)
{
	return a1.d[N]<a2.d[N];
}
struct KDT{
	void updata(int k)
	{
		A l1=a[a[k].l],r1=a[a[k].r];
		for(int i=0;i<2;i++)
		  {
			a[k].mn[i]=a[k].mx[i]=a[k].d[i];
			if(a[k].l)
			  a[k].mn[i]=min(a[k].mn[i],l1.mn[i]),a[k].mx[i]=max(a[k].mx[i],l1.mx[i]);
			if(a[k].r)
			  a[k].mn[i]=min(a[k].mn[i],r1.mn[i]),a[k].mx[i]=max(a[k].mx[i],r1.mx[i]);
		  }
		a[k].sum=l1.sum+r1.sum+(int)a[k].v;
		return;
	}
	int rebuild(int l1,int r1,int now)
	{
		N=now;
		int mid=(l1+r1)>>1;
		nth_element(p+l1,p+mid,p+r1+1,cmp);
		a[mid]=p[mid];
		if(l1<mid)
		  a[mid].l=rebuild(l1,mid-1,now^1);
		else
		  a[mid].l=0;
		if(r1>mid)
		  a[mid].r=rebuild(mid+1,r1,now^1);
		else
		  a[mid].r=0;
		updata(mid);
		return mid;
	}
	void cha(int &k,A b,int now)
	{
		if(!k)
		  {
			k=++m;
			for(int i=0;i<2;i++)
			  a[k].mn[i]=a[k].mx[i]=a[k].d[i]=b.d[i];
			a[k].l=a[k].r=0;
		  }
		if(a[k].d[0]==b.d[0]&&a[k].d[1]==b.d[1])
		  {
			a[k].v+=b.v;
			a[k].sum+=b.v;
			return;
		  }
		if(a[k].d[now]>b.d[now])
		  cha(a[k].l,b,now^1);
		else
		  cha(a[k].r,b,now^1);
		updata(k);
	}
	int cnt;
	int zhao(int k,int x1,int y1,int x2,int y2)
	{
		if(a[k].mn[0]>=x1&&a[k].mn[1]>=y1&&a[k].mx[0]<=x2&&a[k].mx[1]<=y2)
		  return a[k].sum;
		++cnt;
		if(a[k].mn[0]>x2||a[k].mn[1]>y2||a[k].mx[0]<x1||a[k].mx[1]<y1)
		  return 0;
		int tmp=0;
		if(a[k].d[0]>=x1&&a[k].d[1]>=y1&&a[k].d[0]<=x2&&a[k].d[1]<=y2)
		  tmp+=a[k].v;
		return tmp+zhao(a[k].l,x1,y1,x2,y2)+zhao(a[k].r,x1,y1,x2,y2);
	}
}T;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    n=read();
    tot=10000;
    for(;;)
      {
        int a1,a2,a3,a4;
        a1=read();
        if(a1==3)
          break;
        a2=read();
        a3=read();
        a4=read();
        if(a1==1)
          {
            b.d[0]=a2;
            b.d[1]=a3;
            b.v=a4;
            T.cha(root,b,0);
            if(m==tot)
              {
                for(int i=1;i<=m;i++)
                  p[i]=a[i];
                root=T.rebuild(1,m,0);
                tot+=10000;
              }
          }
       /* else
          {
            int a5;
            a5=read();
            printf("%d\n",lans=T.zhao(root,a2,a3,a4,a5));
          }*/
      }
    return 0;
}
