#include<iostream>
#include<cstdio>
#define maxn 100000

using namespace std;

long long n,m,cnt,p[maxn],t;
bool sieve[maxn];

void findP(){
	for(long long i=2;i<=maxn;i++){
		if(!sieve[i])p[++cnt]=i;
		for(long long j=1;j<=cnt&&i*p[j]<=maxn;j++){
			sieve[i*p[j]]=true;
			if(i%p[j]==0)break;
		}
	}
}

long long get(long long k,long long de,long long mul,long long last,long long n,long long m){
	if(k==de)return (n/mul)*(m/mul);
	long long ans=0;
	for(long long i=last+1;i<=cnt;i++){
		long long t=get(k,de+1,mul*p[i],i,n,m);
		if(t==0)break;
		ans+=t;
	}
	return ans;
}

long long count(long long n,long long m){
	long long ans=0;
	for(long long i=0,j=1;;i++,j=-j){
		long long t=get(i,0,1,0,n,m);
		if(t==0)return ans;
		ans+=j*t;
	}
}

int main(){
	scanf("%d %d",&n,&m);
	findP();
	t=count(n,m);
	long long ans=0;
	for(long long i=1;i<=min(n,m);i++){
		ans+=i*(count(n/i,m/i));
	}
	ans-=m*n;
	ans=ans*2+m*n;
	cout<<ans;
	return 0;
} 
