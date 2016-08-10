#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 1<<31
#define ll long long

using namespace std;

int n;
int p[9592],tot;

bool s[100000];
void findP(){
	int arr=100000;
	for(int i=2;i<=arr;++i){
		if(!s[i])p[tot++]=i;
		for(int j=0;j<=tot&&i*p[j]<=arr;++j){
			s[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}

ll phi(ll x){
	ll s=x;
	for(int i=0;i<tot&&p[i]*p[i]<=x;++i)if(x%p[i]==0){
		while(x%p[i]==0)x/=p[i];
		s=s/p[i]*(p[i]-1);
	}
	if(x>1)s=s/x*(x-1);
	return s;
}

int main(){
	findP();
	while(scanf("%d",&n)>0&&n){
		ll ans=0;
		for(int i=1;i<=int(floor(sqrt(n)));++i)if(n%i==0){
			ans+=phi(n/i)*i+phi(i)*(n/i);
		} 
		printf("%lld\n",ans);
	}
	return 0;
} 
