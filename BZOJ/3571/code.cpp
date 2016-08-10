#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000010
#define LL long long
#define bs 131
#define mo 233333333

using namespace std;

int n,ans,next[maxn],f[maxn];
LL hash[maxn];
char s[maxn];
void getnext(char*s){
	int l=strlen(s+1);
	for(int i=2,j=0;i<=l;++i){
		while(j&&s[i]!=s[j+1])j=next[j];
		if(s[i]==s[j+1]&&(j+1)*2<=i)++j;
		next[i]=j;
	}
}
LL power(LL base,LL exp){
	LL ans=1;
	while(exp){
		if(exp&1)ans=ans*base%mo;
		base=base*base%mo;
		exp>>=1;
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	getnext(s);
	f[1]=next[n];
	for(int i=1;i<=n;++i)hash[i]=(hash[i-1]+s[i]*power(bs,i-1))%mo;
	
	printf("%d",ans);
	return 0;
}
