#include<iostream>
#include<cstdio>
#define maxn 1000000

using namespace std;

int prime[maxn],tot;
bool s[maxn];
void pre(){
	for(int i=2;i<maxn;++i){
		if(!s[i])prime[tot++]=i;
		for(int j=0;j<tot&&i*prime[j]<maxn;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]){
			}else{
				break;
			}
		}
	}
}
int n=100000;

int main(){
	freopen("code.in","w",stdout);
	pre();
	printf("%d\n",n);
	for(int i=1,j=1,t;i<=n;++i,++j){
		while(t<tot&&j==prime[t])++j,++t;
		printf("%d\n",j);
	}
	return 0;
}
