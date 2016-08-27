#include<iostream>
#include<cstdio>
#define ls (k<<1)
#define rs (k<<1|1)
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=3e5+10,maxp=12e5+10,buffersize=1e7;
char buffer[buffersize],*p;
inline int read(){
	int tmp=0;
	while(*p<'0'||*p>'9')++p;
	while(*p>='0'&&*p<='9')tmp=tmp*10+*p-'0',++p;
	return tmp;
}
inline void write(LL x){
	int a[20],l=0;
	while(x)a[++l]=x%10,x/=10;
	if(!l)putchar('0');
	while(l)putchar(a[l--]+'0');puts("");
}
LL sum[maxn];
int lg[maxn<<1];
int pos[maxn],top[maxn],key[maxn],dfn[maxn],sign,post[maxn],id[maxn<<1],w,st[maxn<<1][19];
int getmax(int l,int r){
	return max(st[l][lg[r-l+1]-1],st[r-(1<<(lg[r-l+1]-1))+1][lg[r-l+1]-1]);
}
struct Tree{
	int tot,head[maxn],next[maxn<<1],to[maxn<<1],dep[maxn],pa[maxn],size[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		pa[k]=pre;dep[k]=dep[pre]+1;size[k]=0;id[dfn[k]=++sign]=k;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k),size[k]+=size[to[p]]+1,sum[k]+=sum[to[p]]+size[to[p]];
		id[post[k]=++sign]=k;
	}
	int q[maxn],ql,qr;
	void bfs(){
		ql=1;qr=0;q[++qr]=1;w=0;
		while(ql<=qr){
			int k=q[ql++];key[pos[k]=++w]=k;
			if(dep[k]>dep[q[ql-2]])top[dep[k]]=w;
			for(int p=head[k];p;p=next[p])if(dep[to[p]]>dep[k])q[++qr]=to[p];
		}
	}
}G;
struct SGT{
	LL val[maxp];
	void build(int k,int l,int r){
		if(l==r){val[k]=sum[key[l]];return;}
		int m=(l+r)>>1;
		build(ls,l,m);build(rs,m+1,r);
		val[k]=val[ls]+val[rs];
	}
	LL query(int ll,int rr,int k,int l,int r){
		if(ll>rr)return 0;
		if(ll<=l&&r<=rr)return val[k];
		int m=(l+r)>>1;
		if(rr<=m)return query(ll,rr,ls,l,m);
		if(ll>m)return query(ll,rr,rs,m+1,r);
		return query(ll,rr,ls,l,m)+query(ll,rr,rs,m+1,r);
	}
}T;
int findl(int l,int r,int h){
	++r;
	while(l<r){
		int m=(l+r)>>1;
		if(getmax(l,m)>=h)r=m;else l=m+1;
	}
	return l;
}
int findr(int l,int r,int h){
	--l;
	while(l<r){
		int m=(l+r+1)>>1;
		if(getmax(m,r)>=h)l=m;else r=m-1;
	}
	return r;
}
void getst(){
	rep(i,1,sign)st[i][0]=G.dep[id[i]];
	per(i,sign,1)rep(j,1,18)st[i][j]=max(st[i][j-1],st[min(sign,i+(1<<(j-1)))][j-1]);
}
int n,q;
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	fread(buffer,sizeof(char),sizeof(buffer),stdin);p=buffer;
	n=read();q=read();
	lg[0]=0;rep(i,1,n<<1)lg[i]=lg[i>>1]+1;
	rep(i,1,n-1){
		int u=read(),v=read();G.addedge(u,v);
	}
	G.dfs(1,0);G.bfs();getst();T.build(1,1,w);
	rep(i,1,q){
		int p=read(),k=read();
		int l=findl(dfn[p],post[p],G.dep[p]+k),r=findr(dfn[p],post[p],G.dep[p]+k);
		LL tmp=0;
		if(l<=post[p]){
			l=pos[id[l]],r=pos[id[r]];
			if(l>r)swap(l,r);
			tmp=T.query(l,r,1,1,w);
		}
		write((LL)min(k,G.dep[p]-1)*(G.size[p])+sum[p]-tmp);
	}
	return 0;
}
