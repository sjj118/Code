#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 200005

using namespace std;

int n,m,s,k[maxn],cnt[maxn],to[maxn];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",&k[i]);
	s=floor(sqrt(n));
	for(int i=0;i<n;++i){
		to[i]=i+k[i];cnt[i]=1;
		while(to[i]<n&&to[i]/s==i/s)++cnt[i],to[i]=to[i]+k[to[i]];
	}
	scanf("%d",&m);
	for(int i=0;i<m;++i){
		int op;
		scanf("%d",&op);
		if(op==1){
			int x,ans=0;
			scanf("%d",&x);
			while(x<n)ans+=cnt[x],x=to[x];
			printf("%d\n",ans);
		}else{
			int x,t;
			scanf("%d%d",&x,&t);
			k[x]=t;to[x]=x+t;cnt[x]=1;
			while(to[x]/s==x/s)++cnt[x],to[x]=to[x]+k[to[x]];
			for(int i=x-1;i>=x/s*s;--i){
				cnt[i]=1;to[i]=i+k[i];
				if(to[i]<n&&i/s==to[i]/s)cnt[i]+=cnt[to[i]],to[i]=to[to[i]];
			}
		}
	}
	return 0;
}
