#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define N 520
using namespace std;
typedef long long LL;
int p,len; int a[N],ans[N];
inline int in(){
	int x=0; char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar(); 
	return x;
}
void chenggao(int a[],int b[]){
	int c[N];
	memset(c,0,sizeof(c));
	for (int i=1;i<=min(500,a[0]);++i)
	  for (int j=1;j<=min(501-i,b[0]);++j)
	  	c[i+j-1]+=a[i]*b[j];
	c[0]=min(500,a[0]+b[0]-1);
	for (int i=1;i<=c[0];++i){
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	while (c[c[0]+1]){
		c[0]++;
		c[c[0]+1]+=c[c[0]]/10;
		c[c[0]]%=10;
	} 
	for (int i=0;i<=c[0];++i)
	  a[i]=c[i];
}
void fast_pow(int a[],LL p){
	ans[0]=1; ans[1]=1;
	for (;p;p>>=1,chenggao(a,a))
	  if (p&1)
	    chenggao(ans,a);
} 
int main(){
	p=in()-1;
	a[0]=1; a[1]=2;
	fast_pow(a,1ll<<p);
	++ans[1];
	LL len=floor(log(2)/log(10)*(1ll<<p))+1;
	printf("%lld\n",len);
	for (int i=500;i>=1;--i){
		if (i%50==1) printf("%d\n",ans[i]);
		else printf("%d",ans[i]);
	}
}
