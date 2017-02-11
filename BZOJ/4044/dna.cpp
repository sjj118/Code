#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define maxn 101005
#define getl(x) min(w[(x)],min(r-(x)+1,(x)-l))
#define inf 1e9

using namespace std;

int t,n,w[maxn];
char dna[maxn];
bool ok(char c){
	return c=='A'||c=='T'||c=='C'||c=='G';
}
int count(int l,int r){
	int maxl=0;
	int ans=r-l+1;
	for(int i=l+1;i<=r;++i)maxl=max(maxl,getl(i));
	if(maxl*2==r-l+1)return count(l,(l+r)/2)+1;
	for(int i=l+1;i<=r;++i){
		int k=getl(i);
		if(k*2-int(ceil(log(k*2)/log(2)))>=maxl){
			if(i-k!=l||i+k-1!=r)ans=min(ans,count(i-k,i+k-1)+r-(i+k-1)+i-k-l);
		}
	}
	return ans;
}

int main(){
	scanf("%d",&t);
	for(int test=0;test<t;++test){
		char ch=getchar();
		while(!ok(ch))ch=getchar();
		for(n=0;ok(ch);++n,ch=getchar())dna[n]=ch;
		int ms=1,r=0;
		memset(w,0,sizeof(w));
		for(int i=1;i<n;++i){
			w[i]=min(max(0,ms+r-i),w[2*ms-i]);
			while(i+w[i]<n&&i-w[i]-1>=0&&dna[i+w[i]]==dna[i-w[i]-1])++w[i];
			if(i+w[i]>ms+r)ms=i,r=w[i];
		}
		printf("%d\n",count(0,n-1));
	}
	return 0;
}
