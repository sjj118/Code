#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 20005

using namespace std;

int n,m,r[maxn],x[maxn];

int main(){
	while(scanf("%d%d",&n,&m)){
		if(n==0&&m==0)break;
		for(int i=0;i<n;++i)scanf("%d",&r[i]);
		for(int i=0;i<m;++i)scanf("%d",&x[i]);
		sort(r,r+n);
		sort(x,x+m);
		int ans=0;
		for(int i=0,j=0;i<n;){
			if(j>=m){
				ans=-1;
				break;
			}
			if(x[j]>=r[i]){
				ans+=x[j];
				++i;
				++j;
			}else ++j;
		}
		if(ans>=0)printf("%d\n",ans);
		else printf("Loowater is doomed!\n");
	}
}
