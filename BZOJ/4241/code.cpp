#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int maxn=1e5+1000,B=320;
typedef long long LL;
using namespace std;
inline void up(LL&x,LL y){if(y>x)x=y;}
inline LL read(){LL tmp=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n,q;
LL a[maxn],b[B][B],c[B][maxn],cnt[maxn];
bool comp(LL*a,LL*b){return *a<*b;}
struct Lisan{
    LL*val[maxn],tot,maxval,real[maxn];
    void ins(LL&x){val[++tot]=&x;}
    void work(){
        sort(val+1,val+1+tot,comp);
        for(LL i=1,last=0;i<=tot;++i){
            if(*val[i]>last)real[++maxval]=last=*val[i];
            *val[i]=maxval;
        }
    }
}lisan;
 
int main(){
    scanf("%d%d",&n,&q);
    rep(i,1,n)lisan.ins(a[i]=read());
    lisan.work();
    rep(i,1,n/B+1){
        rep(j,i,n/B+1){
            b[i][j]=b[i][j-1];
            rep(k,j*B-B,j*B-1)up(b[i][j],lisan.real[a[k]]*(++cnt[a[k]]));
        }
        cls(cnt);
    }
    rep(i,1,n/B+1){
        rep(j,1,n)c[i][j]=c[i-1][j];
        rep(j,i*B-B,i*B-1)++c[i][a[j]];
    }
    rep(i,1,q){
        int l=read(),r=read();
        LL ans=b[l/B+2][r/B];
        if(l/B==r/B){
        	rep(j,l,r)up(ans,lisan.real[a[j]]*(++cnt[a[j]]));
        	rep(j,l,r)--cnt[a[j]];
        }else{
	        rep(j,l,l/B*B+B-1)up(ans,lisan.real[a[j]]*(++cnt[a[j]]+c[r/B][a[j]]-c[l/B+1][a[j]]));
	        rep(j,r/B*B,r)up(ans,lisan.real[a[j]]*(++cnt[a[j]]+c[r/B][a[j]]-c[l/B+1][a[j]]));
	        rep(j,l,l/B*B+B-1)--cnt[a[j]];
	        rep(j,r/B*B,r)--cnt[a[j]];
	    }
        printf("%lld\n",ans);
    }
    return 0;
}
