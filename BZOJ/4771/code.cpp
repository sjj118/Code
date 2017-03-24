#include<cstdio>
#include<algorithm>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
const int N=1e5+10,P=4e6+10;
int n,m,c[N];
int root[N];
struct SGT{
#define ls son[k][0]
#define rs son[k][1]
	int tot,son[P][2],val[P];
	void clear(){rep(i,1,tot)val[i]=son[i][0]=son[i][1]=0;tot=0;}
	void update(int k){val[k]=val[ls]+val[rs];}
	int modify(int p,int v,int k,int l,int r){
		int t=++tot;val[t]=val[k];
		if(l==r){val[t]+=v;return t;}
		int m=(l+r)>>1;
		if(p<=m)son[t][0]=modify(p,v,ls,l,m),son[t][1]=rs;
		else son[t][0]=ls,son[t][1]=modify(p,v,rs,m+1,r);
		update(t);
		return t;
	}
	int query(int ll,int rr,int k,int l,int r){
		if(!k)return 0;
		if(ll<=l&&r<=rr)return val[k];
		int m=(l+r)>>1;
		if(rr<=m)return query(ll,rr,ls,l,m);
		if(ll>m)return query(ll,rr,rs,m+1,r);
		return query(ll,rr,ls,l,m)+query(ll,rr,rs,m+1,r);
	}
}T;
struct Graph{
	int tot,head[N],to[N],next[N],dep[N],ver[N],in[N],out[N],clo,size[N],pr[N];
	int f[N];
	bool cmp(int a,int b){return dep[a]<dep[b]||(dep[a]==dep[b]&&in[a]<in[b]);}
	void clear(){tot=0;rep(i,1,n)head[i]=pr[i]=0;clo=0;}
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void build(int k,int pre){
		dep[k]=dep[pre]+1;in[k]=++clo;size[k]=1;ver[clo]=k;
		for(int p=head[k];p;p=next[p])build(to[p],k),size[k]+=size[to[p]];
		out[k]=clo;
	}
	void dfs(int k,bool keep){
		int mx=0;
		for(int p=head[k];p;p=next[p])if(size[to[p]]>size[mx])mx=to[p];
		for(int p=head[k];p;p=next[p])if(to[p]!=mx)dfs(to[p],0);
		if(mx)dfs(mx,1);
		if(f[c[k]]){
			if(cmp(k,f[c[k]]))pr[f[c[k]]]=k,f[c[k]]=k;
			else pr[k]=k;
		}else f[c[k]]=k;
		for(int p=head[k];p;p=next[p])if(to[p]!=mx)rep(i,in[to[p]],out[to[p]])if(!pr[ver[i]]){
			int g=ver[i];
			if(f[c[g]]){
				if(cmp(g,f[c[g]]))pr[f[c[g]]]=k,f[c[g]]=g;
				else pr[g]=k;
			}else f[c[g]]=g;
		}
		if(!keep)rep(i,in[k],out[k])f[c[ver[i]]]=0;
	}
	int q[N],ql,qr;
	void bfs(){
		ql=qr=0;q[qr++]=1;
		while(ql!=qr){
			int k=q[ql++];
			for(int p=head[k];p;p=next[p])q[qr++]=to[p];
			if(!root[dep[k]])root[dep[k]]=root[dep[k]-1];
			root[dep[k]]=T.modify(in[k],1,root[dep[k]],1,n);
			if(pr[k])root[dep[k]]=T.modify(in[pr[k]],-1,root[dep[k]],1,n);
		}
		rep(i,dep[q[qr-1]]+1,n)root[i]=root[i-1];
	}
}G;
int main(){
	int cas;scanf("%d",&cas);
	while(cas--){
		scanf("%d%d",&n,&m);
		rep(i,1,n)scanf("%d",&c[i]);
		rep(i,0,n)root[i]=0;
		G.clear();T.clear();
		rep(i,2,n)G.ins(read(),i);
		G.build(1,0);
		G.dfs(1,0);
		G.bfs();
		int ans=0;
		while(m--){
			int x,d;scanf("%d%d",&x,&d);
			x^=ans;d^=ans;
			printf("%d\n",ans=T.query(G.in[x],G.out[x],root[std::min(G.dep[x]+d,n)],1,n));
		}
	}
	return 0;
}
