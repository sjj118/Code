#include<iostream>
#include<cstdio>
#define maxn 40000

using namespace std;

int n,cnt,p[maxn];
bool sieve[maxn]={0};

void findP(){
	for(int i=2;i<=n;i++){
		if(!sieve[i])p[++cnt]=i;
		for(int j=1;j<=cnt&&i*p[j]<=n;j++){
			sieve[i*p[j]]=true;
			if(i%p[j]==0)break;
		}
	}
}

int get(int k,int de,int mul,int last,int n,int m){
	if(de==k)return (n/mul)*(m/mul);
	int ans=0;
	for(int i=last+1;i<=cnt;i++){
		int t=get(k,de+1,mul*p[i],i,n,m);
		if(t==0)break;
		ans+=t;
	}
	return ans;
}

int count(int n,int m){
	int ans=0;
	for(int i=0,j=1;;i++){
		int t=get(i,0,1,0,n,m);
		if(t==0)return ans;
		ans+=j*t;
		j=-j;
	}
}

int main(){
	scanf("%d",&n);
	findP();
	printf("%d",count(n-1,n-1)+2);
	return 0;
}
