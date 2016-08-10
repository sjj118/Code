#include<iostream>
#include<cstdio>
#define maxn 110
#define maxm 100010
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))

using namespace std;

int T,f,n;
int sg[maxm];
int getsg(int n){
	if(sg[n]!=-1)return sg[n];
	if(n<f)return 0;
	bool hash[maxm];cls(hash);
	for(int i=2,ne;i<=n;i=ne+1){
		ne=min(n,n/(n/i));
		for(int j=i;j<=i+1&&j<=ne;++j){
			int tmp=n/j,x=tmp*j+j-n;
			int t=0;
			if(x&1)t^=getsg(tmp);
			if((j-x)&1)t^=getsg(tmp+1);
			hash[t]=1;
		}
	}
	for(int i=0;i<=n;++i)if(!hash[i]){
		sg[n]=i;
		return sg[n];
	}
}
int read(){
	int tmp=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();
	return tmp;
}

int main(){
	memset(sg,-1,sizeof(sg));
	T=read();f=read();
	while(T--){
		n=read();int x,ans=0;
		for(int i=1;i<=n;++i)x=read(),ans^=getsg(x);
		if(T)printf("%d ",ans>0);else printf("%d",ans>0);
	}
	return 0;
}
