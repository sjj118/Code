/*
ID:sj22451
PROG:skidesign
LANG:C++
*/ 
#include<iostream>
#include<cstdio>
#define maxn 1004
#define inf 1e9

using namespace std;

int n,h[maxn];

int main(){
	freopen("skidesign.in","r",stdin);
	freopen("skidesign.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",&h[i]);
	int ans=inf;
	for(int i=0;i<=100-17;++i){
		int r=i+17,x=0;
		for(int j=0;j<n;++j){
			if(h[j]<i)x+=(i-h[j])*(i-h[j]);
			else if(h[j]>r)x+=(h[j]-r)*(h[j]-r);
		}
		ans=min(ans,x);
	}
	printf("%d\n",ans);
	return 0;
}
