#include<iostream>
#include<cstdio>
#define maxn 100010
#define mo 2147483648
#define LL long long 

using namespace std;

int T,n,m;
int tot,prime[maxn],miu[maxn];
LL g[maxn];
bool s[maxn];
void init(){
	miu[1]=1;
	for(int i=2;i<maxn;++i){
		if(!s[i])prime[tot++]=i,miu[i]=-1;
		for(int j=0;j<tot&&i*prime[j]<maxn;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]){
				miu[i*prime[j]]=-miu[i];
			}else{
				miu[i*prime[j]]=0;
				break;
			}
		}
	}
}

int main(){
	init();
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);if(n>m)swap(n,m);
		
	}
	return 0;
}
