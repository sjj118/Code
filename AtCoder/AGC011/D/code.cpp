#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=4e5+10;
inline bool vaild(char c){return c>='A'&&c<='B';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int n,k,a[N],st=1,flag;
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)a[i]=gc()-'A';
	int i;
	for(i=1;i<=k&&st<=n;++i){
		if((a[st]^flag)==0)a[st]^=1;
		else{
			a[n+st]=!flag;++st;
			flag^=1;
		}
	}--i;
	if((a[st]^flag))rep(i,st,st+n-1)printf("%c",'A'+(flag^a[i]));
	else{
		if((k-i)&1)putchar('B');else putchar('A');
		rep(i,st+1,st+n-1)printf("%c",'A'+(flag^a[i]));
	}
	return 0;
}
