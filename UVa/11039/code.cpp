#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 500010

using namespace std;

int t,n,a[maxn],f;

bool comp(int a,int b){
	return abs(a)<abs(b);
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		sort(a,a+n,comp);
		f=a[0]>0?1:-1;
		int ans=1;
		for(int i=1;i<n;++i){
			if(a[i]*f<0){
				++ans;
				f=-f;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
