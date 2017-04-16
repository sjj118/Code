#include<iostream>
#include<assert.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
typedef long long LL;
typedef long double real;
const int N=1e7+10;
int n,m;
bool a[N];
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){char c=gc();int ret=0;while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
int main(){
	scanf("%d%d",&n,&m);
	LL sum=0;
	rep(i,1,m){
		int x=read();
		assert(!a[x]);
		a[x]=1;
		sum+=x;
	}
	real ave;
	if(n!=m)ave=(real)((LL)n*(n-1)/2-sum)/(n-m);
	else ave=0;
	real ave2=(real)sum/m;
	printf("%.6lf",double(ave*(n-m)/n/(1-(real)(n-m)/n)+(real)m/n*ave2/(1-(real)(n-m)/n)));
	return 0;
}
