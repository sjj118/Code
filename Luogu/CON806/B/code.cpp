#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int maxn=0,mo=0;
/*
int sieve[maxn],prime[maxn],tot;
void pre(){
	for(int i=2;i<maxn;++i){
		if(!sieve[i])prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<maxn;++j){
			sieve[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
// */
inline bool vaild(char c){return c>='0'&&c<='9'||c=='-';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline ULL read(){ULL tmp=0;char c=gc();while(vaild(c))tmp=tmp*10+c-'0',c=getchar();return tmp;}
inline int power(int x,int y,int p){int a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
ULL a,b;
int f;
void reada(){
	char c=gc();
	if(c=='-')f=-1,c=getchar();else f=1;
	while(vaild(c))a=a*10+c-'0',c=getchar();
}
char s[13]="Hello,World!";
int main(){
	reada();b=read();
	int m=power(a%10+10,b%4+4,10);
	int n=power(a%26+26,b%12+12,26);
	if(f==-1&&(b&1))n=0;
	rep(i,0,12)if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z'){
		rep(j,1,n){
			if(s[i]=='z')s[i]='a';
			else if(s[i]=='Z')s[i]='A';
			else ++s[i];
		}
	}
	rep(i,1,m+1)puts(s);
	return 0;
}
