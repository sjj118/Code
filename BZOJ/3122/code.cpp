#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define cls(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long LL;
inline void ck(LL&x,LL p){if(x>=p)x-=p;if(x<0)x+=p;}
int p,a,b,x,t;
LL exgcd(LL a,LL b,LL&x,LL&y){
	if(!b)return x=1,y=0,a;
	LL d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
int inv(LL n,LL p){
	LL x,y;
	if(exgcd(n,p,x,y)>1)cerr<<"NO_INV"<<endl;
	ck(x,p);return x;
}
const int ha=2333333;
struct Hash{
	int tot,head[ha],next[ha],key[ha],val[ha];
	void clear(){tot=0;cls(head);}
	void ins(int a,int b){val[++tot]=b;key[tot]=a;next[tot]=head[a%ha];head[a%ha]=tot;}
	int find(int a){for(int p=head[a%ha];p;p=next[p])if(key[p]==a)return val[p];return -1;}
}hash;
int bsgs(int a,int b,int p){
	hash.clear();
	int L=floor(sqrt(p)),base=1;
	for(int i=0;i<L;++i,base=(LL)base*a%p){hash.ins(base,i);if(base==b)return i;}
	base=inv(base,p);
	for(int i=1,tmp=base;i*L<p;++i,tmp=(LL)tmp*base%p){int t=hash.find((LL)b*tmp%p);if(t!=-1)return t+i*L;}
	return -2;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&p,&a,&b,&x,&t);
		if(t==x)printf("1\n");
		else if(a==1){if(b)printf("%d\n",(LL)(t-x+p)*inv(b,p)%p+1);else printf("-1\n");}
		else if(a==0)printf("%d\n",t==b?2:-1);
		else{
			int tmp=inv(a-1,p);
			if((x+(LL)tmp*b)%p==0){printf("-1\n");continue;}
			printf("%d\n",bsgs(a,(t+(LL)tmp*b)%p*inv((x+(LL)tmp*b)%p,p)%p,p)+1);
		}
	}
}
