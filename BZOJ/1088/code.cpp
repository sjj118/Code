#include<iostream>
#include<cstdio>
#define maxn 10005

using namespace std;

int n,ans,a[maxn];
bool b[maxn];
bool check(){
	bool f=1;
	for(int i=1;i<n-1;++i){
		int t=a[i]-b[i]-b[i-1];
		if(t==0||t==1)b[i+1]=t;
		else{
			f=0;
			break;
		}
	}
	if(a[n-1]!=b[n-1]+b[n-2])f=0;
	return f;
}

int main(){
	scanf("%d",&n);
	ans=0;
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	if(a[0]==1){
		b[0]=0;b[1]=1;
		ans+=check();
		b[0]=1;b[1]=0;
		ans+=check();
		printf("%d",ans);
	}else{
		b[0]=b[1]=a[0];
		printf("%d",check());
	}
	return 0;
}
