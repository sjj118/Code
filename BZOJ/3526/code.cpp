#include<cstdio>
#include<algorithm>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=2e5+10;
int n,a[N][2],m;
#define ls son[k][0]
#define rs son[k][1]
namespace SGT{
	struct Data{
		bool link[2][2];
		Data(){cls(link);}
		friend Data operator+(const Data&a,const Data&b){
			Data ret;
			rep(i,0,1)rep(j,0,1)rep(k,0,1)ret.link[i][j]|=a.link[i][k]&&b.link[k][j];
			return ret;
		}
	}data[N<<1];
	int tot,son[N<<1][2],rt;
	void update(int k,int l,int r){
		if(l==r)rep(i,0,1)rep(j,0,1)data[k].link[i][j]=(a[l][i]<=a[l+1][j]);
		else data[k]=data[ls]+data[rs];
	}
	void build(int&k,int l,int r){
		k=++tot;
		if(l==r)return update(k,l,r);
		int m=(l+r)>>1;
		build(ls,l,m);build(rs,m+1,r);
		update(k,l,r);
	}
	void modify(int p1,int p2,int k,int l,int r){
		if(l==r)return update(k,l,r);
		int m=(l+r)>>1;
		if(p1<=m||p2<=m)modify(p1,p2,ls,l,m);
		if(p1>m||p2>m)modify(p1,p2,rs,m+1,r);
		update(k,l,r);
	}
	bool isLink(){
		bool ret=0;
		rep(i,0,1)rep(j,0,1)ret|=data[rt].link[i][j];
		return ret;
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&a[i][0],&a[i][1]);
	SGT::build(SGT::rt,1,n-1);
	scanf("%d",&m);
	rep(i,1,m){
		int x,y;scanf("%d%d",&x,&y);
		std::swap(a[x],a[y]);
		SGT::modify(x,x-1,SGT::rt,1,n-1);
		SGT::modify(y,y-1,SGT::rt,1,n-1);
		if(SGT::isLink())puts("TAK");else puts("NIE");
	}
	return 0;
}
