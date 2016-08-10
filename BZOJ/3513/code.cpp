#include<iostream>
#include<cstdio>
#include<complex>
#include<cstring>
#define eps 0.1
#define pi 3.1415926
#define maxn 262144
#define LL long long
#define buffersize 20000000

using namespace std;

struct E{
	double x,y;
	E operator+(const E b){return E{x+b.x,y+b.y};}
	E operator-(const E b){return E{x-b.x,y-b.y};}
	E operator*(const E b){return E{x*b.x-y*b.y,x*b.y+y*b.x};}
};
char buffer[buffersize],*p;
int readint(){
	int tmp=0;
	while(*p<'0'||*p>'9')++p;
	while(*p>='0'&&*p<='9')tmp=tmp*10+*p-'0',++p;
	return tmp;
}
int T,n,a[maxn],fn,maxval,m;
E c[maxn];
int rev[maxn],L;
LL ans,f[maxn],sum[maxn],cnt[maxn],scnt[maxn];
void fft(E*a,int f,int n){
	for(int i=0;i<n;++i)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int i=1;i<n;i<<=1){
		E wn=E{cos(pi/i),f*sin(pi/i)};
		for(int j=0;j<n;j+=(i<<1)){
			E w=E{1,0};
			for(int k=0;k<i;++k,w=w*wn){
				E x=a[j+k],y=w*a[j+k+i];
				a[j+k]=x+y;a[j+k+i]=x-y;
			}
		}
	}
	if(f==-1)for(int i=0;i<n;++i)a[i].x/=n;
}

int main(){
	fread(buffer,sizeof(char),sizeof(buffer),stdin);p=buffer;
	T=readint();
	while(T--){
		memset(cnt,0,sizeof(cnt));ans=0;maxval=0;
		n=readint();
		for(int i=1;i<=n;++i)a[i]=readint(),maxval=max(maxval,a[i]);
		for(int i=1;i<=n;++i)++cnt[a[i]];
		m=maxval*2;L=0;
		for(fn=1;fn<=m;fn<<=1)++L;
		for(int i=0;i<fn;++i)c[i].x=c[i].y=0;
		for(int i=1;i<=maxval;++i)c[i].x=cnt[i]; 
		rev[0]=0;
		for(int i=0;i<fn;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<(L-1));
		fft(c,1,fn);
		for(int i=0;i<fn;++i)c[i]=c[i]*c[i];
		fft(c,-1,fn);
		for(int i=0;i<=m;++i)f[i]=c[i].x+eps;
		for(int i=1;i<=m;++i)f[i]=f[i]-(i%2==0)*cnt[i/2];
		for(int i=1;i<=m;++i)sum[i]=sum[i-1]+f[i];
		for(int i=1;i<=maxval;++i)scnt[i]=scnt[i-1]+cnt[i];
		for(int i=1;i<=maxval;++i)if(cnt[i]){
			ans+=cnt[i]*((scnt[i-1]-1)*(scnt[i-1])-sum[i])/2+(cnt[i]-1)*cnt[i]/2*(scnt[i-1])+cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
		}
		printf("%.7lf\n",ans*6.0/n/(n-1)/(n-2));
	}
	return 0;
}
