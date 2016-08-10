#include<iostream>
#include<cstdio>
#define ll long long
#define maxn 100000

using namespace std;

ll n,m;
ll phi[maxn+1];
int prime[50000],tot;
ll ans;
bool s[maxn];
void findPhi(){
	phi[1]=1;
	for(int i=2;i<=maxn;++i){
		if(!s[i]){
			prime[tot++]=i;
			phi[i]=i-1;
		}
		for(int j=0;j<tot&&i*prime[j]<=maxn;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]){
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
			}else{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
		}
	}
}
int getphi(int x){
	int ans=x;
	for(int i=0;i<tot&&prime[i]*prime[i]<=x;++i){
		if(x%prime[i]==0)ans=ans/prime[i]*(prime[i]-1);
		while(x%prime[i]==0)x/=prime[i];
	}
	if(x>1)ans=ans/x*(x-1);
	return ans;
}
//phi(i*prime[j])=phi(i)*phi(prime[j]); 
//phi(i*p)=phi(t*p^k*p))=phi(t)*phi(p^k*p)
//phi(i)=phi(t*p^k)=phi(t)*phi(p^k)
int main(){
	findPhi();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=min(n,m);++i)ans+=phi[i]*(n/i)*(m/i);
	printf("%lld\n",ans*2-m*n);
	return 0;
} 
