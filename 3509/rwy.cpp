#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#define For(i,x,y) for(int i=x;i<=y;++i)
using namespace std;
const int N = 4e5 + 5;
const double pi = 3.14159265358979323846264338327950;
const double eps = 1e-2;
#define min(a,b) ((a)<(b)?(a):(b)) 
struct Complex{
    double r,i;
    Complex operator + (Complex b){return (Complex){r+b.r,i+b.i};}
    Complex operator - (Complex b){return (Complex){r-b.r,i-b.i};}
    Complex operator * (Complex b){return (Complex){r*b.r-i*b.i,r*b.i+i*b.r};}
    Complex operator ^ (int f){return (Complex){r,i*f};}
}w[N],a[N],b[N],c[N],tmp[N];
int p[N];
inline void init_w(int n){For(i,0,n-1){w[i]=(Complex){cos(2*pi*i/n),sin(2*pi*i/n)};}}
inline void fft(int n,Complex*buf,int beg,int step,int f){
    if(n==1) return;
    int m=n>>1;
    fft(m,buf,beg,step<<1,f);
    fft(m,buf,beg+step,step<<1,f);
    For(i,0,m-1){
        int pos=i*step*2;
        tmp[i]=buf[beg+pos]+(w[i*step]^f)*(buf[beg+pos+step]);
        tmp[i+m]=buf[beg+pos]-(w[i*step]^f)*(buf[beg+pos+step]);
    }
    For(i,0,n-1) buf[beg+step*i] = tmp[i];
}
int n;
int Bg;
int block_size;
long long ans=0;
void solve_out(){
    for(int l=1;l<=n;l+=block_size){
        int m=-1;        int r=min(n,l+block_size-1);
        For(i,0,Bg) a[i]=b[i]=(Complex){0,0};
        For(i,1,l-1) a[p[i]].r+=1,m=max(p[i],m);
        For(i,r+1,n) b[p[i]].r+=1,m=max(p[i],m);
        int len=1;for(;len<=m+m;len<<=1);
//        len<<=1;
        init_w(len);
        fft(len,a,0,1,1);
        fft(len,b,0,1,1);
        For(i,0,len) a[i]=a[i]*b[i];
        fft(len,a,0,1,-1);
        For(i,l,r){
            ans+=(long long)((a[p[i]<<1].r+0.01)/len);
        }
    }
}
int L[N],R[N];
void solve_in(){
    For(i,1,n) R[p[i]]++;
    for(int l=1;l<=n;l+=block_size){
        int r=min(n,l+block_size-1);
        For(i,l,r) R[p[i]]--;
        For(i,l,r){
            For(j,i+1,r){
                if(2*p[i]-p[j]>=0)ans+=L[2*p[i]-p[j]];
                if(2*p[j]-p[i]>=0)ans+=R[2*p[j]-p[i]];
            }
            L[p[i]]++;
        }
    }
}
int main()
{
//    freopen("3509.in","r",stdin);
//    freopen("3509.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n) scanf("%d",&p[i]),Bg=max(Bg,p[i]);
    int rwy233=Bg;Bg=1; while(Bg<rwy233) Bg<<=1; 
    Bg<<=1;
    block_size=(int)sqrt(n)*16;
    if(rwy233<=1000) block_size = 2000;
//    block_size=3;
    if(block_size<1) block_size=1;
    if(block_size>n) block_size=n;
    solve_out();
    solve_in();
    printf("%lld",ans);
    return 0;
}
