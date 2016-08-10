#include<cstdio>
#include<cmath>
#include<algorithm>
#define maxn 100010
#define maxm 1000010

using namespace std;

int readint(){
	int tmp=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();
	return tmp;
}
int C,l,r;
int n,m,s[maxn],ans[maxm];
struct Query{
	int l,r,a,b,pos;
}q[maxm];
bool comp(Query a,Query b){
	return a.l/C<b.l/C||a.l/C==b.l/C&&a.r<b.r;
}
struct Chunk{
	int val[maxn],chu[400];
	void ins(int x){
		if(val[x]==0)++chu[x/C];
		++val[x];
	}
	void del(int x){
		--val[x];
		if(val[x]==0)--chu[x/C];
	}
	int query(int l,int r){
		int tmp=0;
		for(int i=l;i<=r;){
			if(i%C||i/C==r/C)tmp+=(val[i]>0),++i;
			else tmp+=chu[i/C],i+=C;
		}
		return tmp;
	}
}chunk;

int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	n=readint();m=readint();C=floor(sqrt(n));
	for(int i=1;i<=n;++i)s[i]=readint();
	for(int i=0;i<m;++i){q[i].l=readint();q[i].r=readint();q[i].a=readint();q[i].b=readint();q[i].pos=i;}
	sort(q,q+m,comp);l=1,r=0;
	for(int i=0;i<m;++i){
		while(l>q[i].l)chunk.ins(s[--l]);
		while(r<q[i].r)chunk.ins(s[++r]);
		while(l<q[i].l)chunk.del(s[l++]);
		while(r>q[i].r)chunk.del(s[r--]);
		ans[q[i].pos]=chunk.query(q[i].a,q[i].b);
	}
	for(int i=0;i<m;++i)printf("%d\n",ans[i]);
	return 0;
}
