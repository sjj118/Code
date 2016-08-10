#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define N 111111

using namespace std;

struct DAT
{
    bool v[2],s[2],x[2];
    void prt() {printf("s:%d      %d\nx:%d      %d\nv:%d      %d\n\n",s[0],s[1],x[0],x[1],v[0],v[1]);}
}dat[N<<2];

bool a[N][2][2];
int n,r1,r2,c1,c2;
int dx[3]={-1,0,1};
int dy[3]={0,1,0};

inline void build(int u,int l,int r)
{
    if(l==r) {dat[u].s[0]=dat[u].s[1]=true;return;}
    int mid=(l+r)>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
}

inline void pack(DAT &u,DAT &ls,DAT &rs,int mid)
{
    u.x[0]=ls.x[0]||(ls.s[0]&&a[mid][0][0]&&rs.x[0]&&a[mid][1][0]&&ls.s[1]);//??-?? 
    u.x[1]=rs.x[1]||(rs.s[0]&&a[mid][0][0]&&ls.x[1]&&a[mid][1][0]&&rs.s[1]);//??-?? 
    u.s[0]=(ls.s[0]&&a[mid][0][0]&&rs.s[0])||(ls.v[0]&&a[mid][1][0]&&rs.v[1]);//??-??
    u.s[1]=(ls.s[1]&&a[mid][1][0]&&rs.s[1])||(ls.v[1]&&a[mid][0][0]&&rs.v[0]);//??-??
    u.v[0]=(ls.s[0]&&a[mid][0][0]&&rs.v[0])||(ls.v[0]&&a[mid][1][0]&&rs.s[1]);//??-??
    u.v[1]=(ls.s[1]&&a[mid][1][0]&&rs.v[1])||(ls.v[1]&&a[mid][0][0]&&rs.s[0]);//??-?? 
}

inline void updata(int u,int l,int r,int p)
{
    if(l==r)
    {
        dat[u].x[0]=dat[u].x[1]=dat[u].v[1]=dat[u].v[0]=a[p][0][1];
        dat[u].s[0]=dat[u].s[1]=true;
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid) updata(u<<1,l,mid,p);
    else updata(u<<1|1,mid+1,r,p);
    pack(dat[u],dat[u<<1],dat[u<<1|1],mid);
}

inline void change(bool pd)
{
    if(r1>r2) swap(r1,r2),swap(c1,c2);
    int dir;
    for(int i=0;i<3;i++)
        if(c1+dx[i]==c2&&r1+dy[i]==r2) dir=i;
    if(dir==0) a[c2][r2][0]=pd,updata(1,1,n,c2);
    else if(dir==1) a[c1][0][1]=pd,updata(1,1,n,c1);
    else a[c1][r1][0]=pd,updata(1,1,n,c1);
}

inline void getpack(DAT &p,int u,int L,int R,int l,int r)
{
    if(l<=L&&r>=R) {p=dat[u];return;}
    int MID=(L+R)>>1;
    if(r<=MID) getpack(p,u<<1,L,MID,l,r);
    else if(l>=MID+1) getpack(p,u<<1|1,MID+1,R,l,r);
    else
    {
        DAT tmp1,tmp2;
        getpack(tmp1,u<<1,L,MID,l,MID);
        getpack(tmp2,u<<1|1,MID+1,R,MID+1,r);
        pack(p,tmp1,tmp2,MID);
    }
}

inline void getans()
{
    if(c1>c2) swap(c1,c2),swap(r1,r2);
    DAT pa,pb,pc;
    getpack(pa,1,1,n,1,c1);
    getpack(pb,1,1,n,c1,c2);
    getpack(pc,1,1,n,c2,n);
    if(r1==r2)
    {
        if(r1==0)
        {
            if(pb.s[0]||(pa.x[1]&&pb.v[1])||(pc.x[0]&&pb.v[0])||(pa.x[1]&&pb.s[1]&&pc.x[0])) puts("Y");
            else puts("N");
        }
        else
        {
            if(pb.s[1]||(pa.x[1]&&pb.v[0])||(pc.x[0]&&pb.v[1])||(pa.x[1]&&pb.s[0]&&pc.x[0])) puts("Y");
            else puts("N");
        }
    }
    else
    {
        if(r1==0)
        {
            if(pb.v[0]||(pa.x[1]&&pb.s[1])||(pc.x[0]&&pb.s[0])) puts("Y");
            else puts("N");
        }
        else
        {
            if(pb.v[1]||(pa.x[1]&&pb.s[0])||(pc.x[0]&&pb.s[1])) puts("Y");
            else puts("N");
        }
    }
}

inline void go()
{
    char str[10];
    scanf("%d",&n);
    build(1,1,n);
    while(scanf("%s",str))
    {
        if(str[0]=='E') break;
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        r1--; r2--;
        if(str[0]=='O') change(1);
        else if(str[0]=='C') change(0);
        else getans();
    }
}

int main()
{
	freopen("code.in","r",stdin);freopen("std.out","w",stdout);
    go();
    return 0;
}
