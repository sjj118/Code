#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxm 1000010
#define ha 2333333
#define LL long long

using namespace std;

char readchar(){
	char c=getchar();
	while(c<'A'||c>'Z')c=getchar();
	return c;
}
int ans[maxm];
LL IP(int ip[5]){
	LL tmp=0;
	for(int i=0,t=1;i<4;++i,t<<=8)tmp+=ip[4-i]*t;
	if(ip[0])tmp>>=(32-ip[0]);
	tmp+=(LL)ip[0]<<32;
	return tmp;
}
struct Query{
	LL ip;
	int a,b,pos,low,ans;
}q[maxm];
int m;
bool comp1(Query a,Query b){return a.a<b.a;}
LL a[maxm];
int cnt;
struct Hash{
	int tot,head[ha],next[ha];
	LL key[ha],val[ha];
	void ins(LL k,LL x){key[++tot]=k;val[tot]=x;next[tot]=head[k%ha];head[k%ha]=tot;}
	LL getval(LL k){for(int p=head[k%ha];p;p=next[p])if(key[p]==k)return val[p];return 0;}
	void clear(){
		tot=0;memset(head,0,sizeof(head));
	}
}hash;
int n;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		char op=readchar();int ip[5],l,r;
		if(op=='A'){
			scanf("%d.%d.%d.%d/%d",&ip[1],&ip[2],&ip[3],&ip[4],&ip[0]);
			a[++cnt]=IP(ip);
		}else{
			scanf("%d.%d.%d.%d %d %d",&ip[1],&ip[2],&ip[3],&ip[4],&l,&r);ip[0]=0;
			q[++m].a=l;q[m].b=r;q[m].ip=IP(ip);q[m].pos=m;
		}
	}
	sort(q+1,q+1+m,comp1);
	for(int i=1,j=1;i<=m;++i){
		while(j<=cnt&&q[i].a>j)hash.ins(a[j],j),++j;
		q[i].low=0;
		for(LL l=32;l;--l)if(hash.getval((q[i].ip>>(32-l))+(l<<32))){q[i].low=l;break;}
	}
	hash.clear();
	for(int i=m,j=cnt;i;--i){
		while(j&&q[i].a<=j)hash.ins(a[j],j),--j;
		for(LL l=32;l>q[i].low;--l){
			int t=hash.getval((q[i].ip>>(32-l))+(l<<32));
			if(t&&t<=q[i].b)++q[i].ans,q[i].b=t;
		}
	}
	for(int i=1;i<=m;++i)ans[q[i].pos]=q[i].ans;
	for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
	return 0;
}
