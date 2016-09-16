#include<iostream>
#include<cstdio>
#include<map>
#define maxn 50007

using namespace std;

int t,n;
map<int,bool> ma;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ma.clear();
		bool f=1;
		for(int i=0;i<n;++i){
			int x;
			scanf("%d",&x);
			if(ma.find(x)==ma.end()){
				if(f){
					f=0;
					printf("%d",x);
				}else printf(" %d",x);
				ma[x]=1;
			}
		}
		printf("\n");
	}
	return 0;
}
