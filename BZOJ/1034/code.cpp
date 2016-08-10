#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100010
using namespace std;
int n,a[maxn],b[maxn],head,tail,ans;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	for(int i=0;i<n;++i)scanf("%d",&b[i]);
	sort(a,a+n);sort(b,b+n);
	head=0;tail=n-1;ans=0;
	for(int i=n-1;i>=0;--i){
		if(a[i]>b[tail])++tail,++ans;
		else 
	}
	return 0;
}
