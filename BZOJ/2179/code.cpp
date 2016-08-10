#include<iostream>
#include<cstdio>
#include<complex>
#define pi acos(-1)
#define E complex<double>
#define maxn 200010

using namespace std;

int readnum(){
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	return c-'0';
}
int n,m,L;
E a[maxn],b[maxn];
int c[maxn];
int rev[maxn];
void fft(E*a,int f){
	for(int i=0;i<n;++i)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int i=1;i<n;i<<=1){
		E wn(cos(pi/i),f*sin(pi/i));
		for(int j=0;j<n;j+=(i<<1)){
			E w(1,0);
			for(int k=0;k<i;++k,w*=wn){
				E x=a[j+k],y=w*a[j+k+i];
				a[j+k]=x+y;a[j+k+i]=x-y;
			}
		}
	}
	if(f==-1)for(int i=0;i<n;++i)a[i]/=n;
}

int main(){
	scanf("%d",&n);--n;m=n*2;
	for(int i=n;i>=0;--i)a[i]=readnum();
	for(int i=n;i>=0;--i)b[i]=readnum();
	for(n=1;n<=m;n<<=1)++L;
	for(int i=0;i<n;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<(L-1));
	fft(a,1);fft(b,1);
	for(int i=0;i<n;++i)a[i]*=b[i];
	fft(a,-1);
	for(int i=0;i<=m;++i)c[i]=a[i].real()+0.1;
	for(int i=0;i<=m;++i)c[i+1]+=c[i]/10,c[i]%=10;
	while(c[m+1])++m,c[m+1]+=c[m]/10,c[m]%=10;
	for(int i=m;i>=0;--i)printf("%d",c[i]);
	return 0;
}
