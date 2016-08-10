#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
#define maxn 100005
#define nlogn 2000000
#define lson son[k][0]
#define rson son[k][1]

using namespace std;

int n,m,k,dj[maxn],qu[25];
bool check(int a){
	for(int i=0;i<k;++i)if(dj[a+i]!=qu[i])return 0;
	return 1;
}

int main(){
	freopen("code.in","r",stdin);
	freopen("brute.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)scanf("%d",&dj[i]);
	for(int i=0;i<m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		for(int j=0;j<k;++j)scanf("%d",&qu[j]);
		bool flag=0;
		for(int j=x;j<=y;++j){
			if(check(j)){
				flag=1;break;
			}
		}
		if(flag)printf("No\n");else printf("Yes\n");
	}
	return 0;
}
