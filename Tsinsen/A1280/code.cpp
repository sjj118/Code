#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 300010

using namespace std;

namespace manacher{
	
int n;
char s[maxn];
char gets(int x){
	if(x==0)return '$';
	if(x>n)return '*';
	if(x&1)return '#';
	return s[x>>1];
}
int rad[maxn],lmax[maxn],rmax[maxn];
void manacher(int n){
	int id,mx=0;
	for(int i=1;i<=n;++i){
		if(mx>i)rad[i]=min(mx-i,rad[id*2-i]);else rad[i]=1;
		while(gets(i+rad[i])==gets(i-rad[i]))++rad[i];
		if(i+rad[i]>mx)mx=i+rad[i],id=i;
	}
	for(int i=1,j=1;i<=n;++i){
		while(j<i+rad[i])lmax[j++]=j-i;
	}
	for(int i=n,j=n;i;--i){
		while(j>i-rad[i])rmax[j--]=i-j;
	}
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);n=n*2+1;
	manacher(n);
	int ans=0;
	for(int i=3;i<n-1;i+=2)ans=max(ans,lmax[i-1]+rmax[i+1]);
	printf("%d\n",ans);
	return 0;
}

}

int main(){
	return manacher::main();
}
