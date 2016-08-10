#include<iostream>
#include<cstdio>
#define maxn 1000010
int n,Q,k,d[maxn],f[maxn],q[maxn],ql,qr;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&d[i]);
	scanf("%d",&Q);
	for(int i=1;i<=Q;++i){
		scanf("%d",&k);
		ql=1;qr=0;q[++qr]=1;
		f[1]=0;
		for(int i=2;i<=n;++i){
			while(ql<=qr&&q[ql]+k<i)++ql;
			f[i]=f[q[ql]]+(d[q[ql]]<=d[i]);
			while(ql<=qr&&(f[i]<f[q[qr]]||f[i]==f[q[qr]]&&d[i]>=d[q[qr]]))--qr;
			q[++qr]=i;
		}
		printf("%d\n",f[n]);
	}
	return 0;
}
