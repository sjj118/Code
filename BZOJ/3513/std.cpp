#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define LL long long
const int M=500000;
int T,n,sum[M],rev[M],N,L,dig[M];
struct S{
    double x,y;
    S operator + (const S&xx){return (S){x+xx.x,y+xx.y};}
    S operator - (const S&xx){return (S){x-xx.x,y-xx.y};}
    S operator * (const S&xx){return (S){x*xx.x-y*xx.y,x*xx.y+y*xx.x};}
}a[M],b[M],c[M],d[M];
inline int in(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x;   
}
inline void FFT(S *a,int f){
    int i,j,k;
    S wn,w,x,y;
    for(i=0;i<N;++i) d[i]=a[rev[i]];
    for(i=0;i<N;++i) a[i]=d[i];
    for(i=2;i<=N;i<<=1){
        wn=(S){cos(2*M_PI/i),f*sin(2*M_PI/i)};
        for(j=0;j<N;j+=i){
            w=(S){1.,0.};
            for(k=j;k<j+i/2;++k){
                x=a[k];
                y=a[k+i/2]*w;
                a[k]=x+y;
                a[k+i/2]=x-y;
                w=w*wn; 
            }
        }
    }
    if(f==-1) for(i=0;i<N;++i) a[i].x/=(double)N*1.0;
}
int main(){
	freopen("code.in","r",stdin);
	freopen("std.out","w",stdout);
    int i,x,o,j,len,maxn;
    T=in();
    for(o=1;o<=T;++o){
        n=in();
        memset(sum,0,sizeof(sum));
        for(maxn=0,i=1;i<=n;++i){
            x=in();
            ++sum[x];
            maxn=max(maxn,x);
        }
        maxn+=1;
        for(L=0,N=1;N<maxn;N<<=1,L+=1); N<<=1;L+=1;
        memset(dig,0,sizeof(dig));
        memset(rev,0,sizeof(rev));
        for(i=0;i<N;++i){
            a[i].x=a[i].y=b[i].x=b[i].y=0;
            for(j=i,len=0;j;j>>=1) dig[len++]=j&1;
            for(j=0;j<L;++j) rev[i]=rev[i]*2+dig[j];
        }
        for(i=1;i<=maxn;++i){
            a[i]=(S){(double)sum[i],0.};
            b[i]=(S){(double)sum[i],0.};
        }
        FFT(a,1);FFT(b,1);
        for(i=0;i<N;++i) c[i]=a[i]*b[i];
        FFT(c,-1);
        LL ans=0,tot=(LL)n*(LL)(n-1)*(LL)(n-2)/6LL,peace=0;
        for(ans=0,i=0;i<=maxn;++i){
            peace+=(LL)(c[i].x+0.5);
            if(!(i%2)) peace-=sum[i/2];
            if(!sum[i]) continue;
            ans+=peace*sum[i];
        }
        ans/=2;
        printf("%.7f\n",(double)1.-(double)((double)ans*1./(double)tot*1.));
    }
} 
