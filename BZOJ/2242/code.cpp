#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
typedef long long LL;
const int ha=2333333;
using namespace std;
LL power(LL base,LL exp,LL mo){
	LL ans=1;
	while(exp){
		if(exp&1)ans=ans*base%mo;
		base=base*base%mo;
		exp>>=1;
	}
	return ans;
}
struct Hash{
	int tot,head[ha],next[ha],key[ha],val[ha];
	void clear(){tot=0;cls(head);}
	void ins(int k,int v){val[++tot]=v;key[tot]=k;next[tot]=head[k%ha];head[k%ha]=tot;}
	int find(int k){
		for(int p=head[k%ha];p;p=next[p])if(key[p]==k)return val[p];
		return -1;
	}
}hash;
int BSGS(LL a,LL b,LL p){
	if(a==0)return -1;
	LL pp=p-1,l=floor(sqrt(pp));hash.clear();
	for(LL i=0,tmp=1;i<l;++i,tmp=tmp*a%p)hash.ins(tmp,i);
	LL al=power(a,l,p);
	for(LL i=0,tmp=1;i*l<=pp;++i,tmp=tmp*al%p){
		int t=hash.find(power(tmp,p-2,p)*b%p);
		if(t>=0)return i*l+t;
	}
	return -1;
}
int main(){
	int T,k;scanf("%d%d",&T,&k);
	while(T--){
		int y,z,p;scanf("%d%d%d",&y,&z,&p);y%=p;
		if(k==1)printf("%lld\n",power(y,z,p));
		else if(k==2){
			if(y)printf("%lld\n",power(y,p-2,p)*z%p);
			else printf("Orz, I cannot find x!\n");
		}else{
			z%=p;
			int ans=BSGS(y,z,p);
			if(ans!=-1)printf("%d\n",ans);
			else printf("Orz, I cannot find x!\n");
		}
	}
	return 0;
}
