#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset()
#define maxn 200010

using namespace std;

int n,a[maxn],c[maxn],y[maxn];
char s[maxn];
void SA(){
	for(int i=1;i<=n;++i)c[a[i]]=1;
	for(int i=1;i<256;++i)c[i]+=c[i-1];
	
	for(int i=1;i<n;i<<=1){
		
	}
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)s[n+i]=s[i];
	n<<=1;SA();
	
	return 0;
}
