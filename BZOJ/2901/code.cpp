#include<iostream>
#include<cstdio>
#define maxn 2016
#define LL long long
#define buffersize 100000000

using namespace std;

char buffer[buffersize],*p;
int readint(){
	int tmp=0;
	while(*p<'0'||*p>'9')++p;
	while(*p>='0'&&*p<='9')tmp=tmp*10+*p-'0',++p;
	return tmp;
}
int n,m,sa[maxn][maxn],sb[maxn][maxn];

int main(){
	fread(buffer,sizeof(buffer),sizeof(char),stdin);p=buffer;
	n=readint();m=readint();
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)sa[i][j]=sa[i-1][j]+readint();
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)sb[i][j]=sb[i][j-1]+readint();
	for(int i=1;i<=m;++i){
		LL ans=0;
		int a=readint(),b=readint(),c=readint(),d=readint();
		if(a>c)swap(a,c);if(b>d)swap(b,d);
		for(int i=1;i<=n;++i)ans+=(LL)(sa[c][i]-sa[a-1][i])*(sb[i][d]-sb[i][b-1]);
		printf("%lld\n",ans);
	}
	return 0;
}
