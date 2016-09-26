#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=100+10,maxm=500;
char s[maxn];
int a[maxn];
int c[maxm],n,l;
void div2(){
	per(i,n,1){
		a[i-1]+=(a[i]&1)*10;
		a[i]>>=1;
	}
	while(n&&a[n]==0)--n;
}
struct Bigint{
	int deg,arr[maxn];
	Bigint(){deg=0;cls(arr);}
	void output(){
		per(i,deg,1)printf("%d",arr[i]);puts("");
	}
}A[maxm],B[maxm];
Bigint operator+(const Bigint&a,const Bigint&b){
	Bigint c;c.deg=max(a.deg,b.deg);
	rep(i,1,c.deg){
		c.arr[i]+=a.arr[i]+b.arr[i];
		c.arr[i+1]+=c.arr[i]/10;
		c.arr[i]%=10;
	}
	if(c.arr[c.deg+1])++c.deg;
	return c;
}
int pre[maxm];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("\n%s",s+1);n=strlen(s+1);
		if(n==1&&s[1]=='0'){puts("0");continue;}
		rep(i,1,n)a[i]=s[n-i+1]-'0';
		l=0;
		while(n){
			c[++l]=a[1]&1;div2();
		}
		rep(i,1,l>>1)swap(c[i],c[l-i+1]);
		int last=0;rep(i,1,l){
			if(c[i]==0)last=i;
			pre[i]=last;
		}
		A[1].deg=1;A[1].arr[1]=1;
		B[0].deg=1;B[0].arr[1]=1;
		rep(i,2,l){
			if(c[i]){
				A[i]=A[i-1]+B[pre[i-1]];
			}else{
				A[i]=A[i-1];
				B[i]=A[i-1]+B[pre[i-1]];
			}
		}
		A[l].output();
	}
	return 0;
}
