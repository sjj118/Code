#include<iostream>
#include<cstdio>
#include<complex>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef complex<double> E;
const int maxn=3e5+10;
const double pi=acos(-1);
int n,a[maxn],b[maxn],R[maxn],m,L;
E A[maxn],B[maxn];
void fft(E*a,int f,int n){
	rep(i,0,n-1)if(i<R[i])swap(a[i],a[R[i]]);
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
	if(f==-1)rep(i,0,n-1)a[i]/=n;
}
int main(){
	scanf("%d",&n);
	rep(i,0,n-1)scanf("%d%d",&a[i],&b[n-i-1]);
	rep(i,0,n-1)A[i]=a[i];
	rep(i,0,n-1)B[i]=b[i];
	for(m=1;m<n*2;m<<=1)++L;
	rep(i,0,m-1)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	fft(A,1,m);
	fft(B,1,m);
	rep(i,0,m-1)A[i]*=B[i];
	fft(A,-1,m);
	rep(i,n-1,n*2-2)printf("%d\n",int(A[i].real()+0.5));
	return 0;
}
