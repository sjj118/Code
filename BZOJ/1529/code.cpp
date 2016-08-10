#include<iostream>
#include<cstdio>
#define maxn 1000010

using namespace std;

int n,p[maxn],ans,mark[maxn];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=1;i<=n;++i)if(!mark[i]){
		int k;
		for(k=i;!mark[k];k=p[k])mark[k]=i;
		if(mark[k]==i)++ans;
	}
	printf("%d",ans);
	return 0;
}
