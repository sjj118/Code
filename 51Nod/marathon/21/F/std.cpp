#include<cstdio>
#include<cstring>
#include<algorithm>
#include<assert.h>
using namespace std;
#define rep(i,x,y) for(i=x;i<=y;i++)
#define _rep(i,x,y) for(i=x;i>=y;i--)
#define CL(S,x) memset(S,x,sizeof(S))
#define CP(S1,S2) memcpy(S1,S2,sizeof(S2))
typedef long long ll;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
inline char getc(){char c;for(c=getchar();c<=32;c=getchar());return c;}

const int N=300010;
const int D=N<<1;
const ll inf=ll(2e18);
int i,j,k,t,p,sg0;ll K,Btot;
	
ll add(ll a,ll b){if(a+b>inf)return inf;return a+b;}
ll mul(ll a,ll b){if(a==0||b==0)return 0;if(inf/a<b)return inf;return a*b;}
struct SAM
{
    int now,t,node,p,np,q,r;
    int ch[D][26],f[D],l[D],sg[D],pos[D];
    void addc(int la,int c)
    {
        np=++node;pos[now]=np;p=pos[la];l[np]=l[p]+1;
        for(;p>0&&ch[p][c]==0;p=f[p])ch[p][c]=np;
        q=ch[p][c];
        if(p==0)f[np]=1;
        else if(l[p]+1==l[q])f[np]=q;
        else
        {
            r=++node;CP(ch[r],ch[q]);f[r]=f[q];l[r]=l[p]+1;
            f[q]=f[np]=r;
            for(;p>0&&ch[p][c]==q;p=f[p])ch[p][c]=r;
        }
    }
    bool v[D];ll g[D][28],tot[D],res[D];
    int s[D],Q[D];

    void bfs()
    {
        int i,j,u,t,t2;bool cnt[28];
        rep(i,1,node)s[l[i]]++;
        rep(i,1,node)s[i]+=s[i-1];
        rep(i,1,node)Q[s[l[i]]--]=i;
        _rep(j,node,1)
        {
            i=Q[j];CL(cnt,0);
            for(t=0;t<=25;t++)if(ch[i][t])
            {
                u=ch[i][t];cnt[sg[u]]=1;
                rep(t2,0,27)g[i][t2]+=g[u][t2];
            }
            for(t=0;cnt[t];t++);sg[i]=t;g[i][sg[i]]++;
        }
    }
    void go()
    {
        p=1;
    	while(1)
    	{
            int u;
            if(K<=res[p])break;
            K-=res[p];
            rep(t,0,25)
            {
                u=ch[p][t];   
                if(u>0)
                if(K<=tot[u]){putchar('a'+t);break;}
                else K-=tot[u];
            }
            p=ch[p][t];
        }
        putchar('\n');
        sg0=sg[p];
    }
    bool hash[N];
	void init()
	{
		node=1;pos[1]=1;
		int n,x;
		read(n);
		rep(now,2,n+1)
		{
			read(x);x++;
			addc(x,getc()-'a');
		}
		bfs();
	}
}A,B;


int main()
{
	read(K);
	A.init();
	B.init();
	
	rep(t,0,27)Btot+=B.g[1][t];
	rep(i,1,A.node)rep(t,0,27)A.tot[i]=add(A.tot[i],mul(A.g[i][t],(Btot-B.g[1][t])));
	rep(i,1,A.node)A.res[i]=Btot-B.g[1][A.sg[i]];
	if(A.tot[1]<K){printf("K is too large!\n");return 0;}
	
	
    A.go();
    rep(i,1,B.node)rep(t,0,27)if(t!=sg0)B.tot[i]+=B.g[i][t];
    rep(i,1,B.node)B.res[i]=(sg0!=B.sg[i]);
    B.go();
	
    return 0;
}
