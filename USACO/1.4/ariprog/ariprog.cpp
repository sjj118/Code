/*
ID:sj22451
PROG:ariprog
LANG:C++
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 251000 

using namespace std;

int n,m,tot;
bool c[maxn];
int f[maxn];
int p[maxn],cnt;

int main(){
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int p=0;p<=m;++p){
		for(int q=p;q<=m;++q){
			if(!c[p*p+q*q])++tot;
			c[p*p+q*q]=1;
		}
	}
	for(int i=m*m*2;i>=0;--i)if(c[i])p[cnt++]=i;
	if(n==1)printf("%d\n",tot);
	else{
		tot=0;
		for(int b=1;b<=m*m*2/(n-1);++b){
			for(int i=0;i<cnt;++i)if(c[p[i]+b])f[p[i]]=f[p[i]+b]+1;else f[p[i]]=1;
			for(int i=0;i<=m*m*2;++i)if(f[i]>=n)printf("%d %d\n",i,b),++tot;
		}
	}
	if(!tot)printf("NONE\n");
	return 0;
}
