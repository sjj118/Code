#include<iostream>
#include<cstdio>
#include<complex>
#define E complex<double>
#define maxn 300000
#define pi acos(-1)

using namespace std;

int tn,n,m,L,R[maxn];
E g[maxn],q1[maxn],q2[maxn];
void fft(E*a,int f){
	for(int i=0;i<n;++i)if(i<R[i])swap(a[i],a[R[i]]);
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
	scanf("%d",&n);tn=n;
	for(int i=1;i<=n;++i)scanf("%lf",&q1[i]);
	for(int i=1;i<=n;++i)q2[i]=q1[n-i+1];
	for(int i=1;i<=n;++i)g[i]=1.0/i/i;
	m=n*2;for(n=1;n<=m;n<<=1)++L;
	for(int i=0;i<n;++i)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	fft(g,1);fft(q1,1);fft(q2,1);
	for(int i=0;i<n;++i)q1[i]*=g[i],q2[i]*=g[i];
	fft(q1,-1);fft(q2,-1);
	for(int i=1;i<=tn;++i)printf("%lf\n",q1[i].real()-q2[tn-i+1].real());
	return 0;
}
