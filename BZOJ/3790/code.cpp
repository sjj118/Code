#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2e5+10;
int n,a[N],r[N],sta[N],top;
char s[N];
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	while(scanf("\n%s",s+1)>0){
		n=strlen(s+1);
		a[0]=100;
		rep(i,1,n)a[i*2]=s[i]-'a';
		rep(i,1,n+1)a[i*2-1]=40;
		a[n*2+2]=101;
		n=n*2+1;
		int ms=1;cls(r);
		rep(i,1,n){
			r[i]=min(r[2*i-ms],ms+r[ms]-i);
			while(a[i+r[i]]==a[i-r[i]])++r[i];
			if(i+r[i]>ms+r[ms])ms=i;
		}
		top=0;
		rep(i,1,n){
			while(top&&i-r[i]<=sta[top-1]&&i+r[i]-1>sta[top])--top;
			if(i+r[i]-1>sta[top])sta[++top]=i+r[i]-1;
		}
		printf("%d\n",top-1);
	}
	return 0;
}
