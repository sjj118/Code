#include<iostream>
#include<cstdio>
#define lson son[k][0]
#define rson son[k][1]
#define maxp 200100

using namespace std;

inline bool isEnglish(char c){return c>='a'&&c<='z'||c>='A'&&c<='Z';}
inline void readop(char*op){
	char c=getchar();int tmp=0;
	while(!isEnglish(c))c=getchar();
	while(isEnglish(c))op[tmp++]=c,c=getchar();
}
int n;
struct Link{
	bool l[4][4];
	Link(){
		for(int i=0;i<4;++i)for(int j=0;j<4;++j)l[i][j]=0;
		l[0][0]=l[1][1]=l[2][2]=l[3][3]=1;
	}
};
Link getsum(Link x){
	Link sum;
	sum.l[0][1]=x.l[0][1]||x.l[0][3]&&x.l[3][2]&&x.l[2][1];
	sum.l[0][2]=x.l[0][1]&&x.l[1][2]||x.l[0][3]&&x.l[3][2];
	sum.l[0][3]=x.l[0][3]||x.l[0][1]&&x.l[1][2]&&x.l[2][3];
	sum.l[1][0]=sum.l[0][1];
	sum.l[1][2]=x.l[1][2]||x.l[1][0]&&x.l[0][3]&&x.l[3][2];
	sum.l[1][3]=x.l[1][0]&&x.l[0][3]||x.l[1][2]&&x.l[2][3];
	sum.l[2][0]=sum.l[0][2];
	sum.l[2][1]=sum.l[1][2];
	sum.l[2][3]=x.l[2][3]||x.l[2][1]&&x.l[1][0]&&x.l[0][3];
	sum.l[3][0]=sum.l[0][3];
	sum.l[3][1]=sum.l[1][3];
	sum.l[3][2]=sum.l[2][3];
	return sum;
}
Link getsum(Link a,Link b){
	Link sum;
	sum.l[0][1]=a.l[0][1]&&b.l[0][1]||a.l[0][2]&&b.l[3][1];
	sum.l[0][2]=a.l[0][1]&&b.l[0][2]||a.l[0][2]&&b.l[3][2];
	sum.l[0][3]=a.l[0][3]||a.l[0][1]&&b.l[0][3]&&a.l[2][3];
	sum.l[1][0]=sum.l[0][1];
	sum.l[1][2]=b.l[1][2]||b.l[1][0]&&a.l[1][2]&&b.l[3][2];
	sum.l[1][3]=b.l[1][0]&&a.l[1][3]||b.l[1][3]&&a.l[2][3];
	sum.l[2][0]=sum.l[0][2];
	sum.l[2][1]=sum.l[1][2];
	sum.l[2][3]=b.l[2][3]&&a.l[2][3]||b.l[2][0]&&a.l[1][3];
	sum.l[3][0]=sum.l[0][3];
	sum.l[3][1]=sum.l[1][3];
	sum.l[3][2]=sum.l[2][3];
	return sum;
}
struct segtree{
	int tot,son[maxp][2];
	Link val[maxp],sum[maxp];
	void pushup(int k){
		if(lson)sum[k]=getsum(sum[lson],sum[rson]);else sum[k]=getsum(val[k]);
	}
	void molify(int p,int x,int y,int v,int k=1,int l=0,int r=n){
		if(l==r)val[k].l[x][y]=v,val[k].l[y][x]=v;
		else{
			int m=(l+r)>>1;
			if(!lson)lson=++tot,rson=++tot;
			if(p<=m)molify(p,x,y,v,lson,l,m);
			else molify(p,x,y,v,rson,m+1,r);
		}
		pushup(k);
	}
	Link query(int ll,int rr,int k=1,int l=0,int r=n){
		if(k==0)return sum[0];
		if(ll<=l&&r<=rr)return sum[k];
		else{
			int m=(l+r)>>1;
			if(rr<=m)return query(ll,rr,lson,l,m);
			if(ll>m)return query(ll,rr,rson,m+1,r);
			return getsum(query(ll,rr,lson,l,m),query(ll,rr,rson,m+1,r));
		}
	}
	segtree(){tot=1;}
}T;
bool getans(int r1,int c1,int r2,int c2){
	if(c1>c2)swap(r1,r2),swap(c1,c2);
	--r1;--r2;
	if(r1==r2&&c1==c2)return 1;
	if(c1==c2)return T.query(c1,n).l[0][3]||T.query(0,c1-1).l[1][2];
	return T.query(c1,c2-1).l[r1*3][r2+1]||T.query(0,c1-1).l[1][2]&&T.query(c1,c2-1).l[(!r1)*3][r2+1]||T.query(c2,n).l[0][3]&&T.query(c1,c2-1).l[(!r2)+1][r1*3]||T.query(0,c1-1).l[1][2]&&T.query(c2,n).l[0][3]&&T.query(c1,c2-1).l[(!r1)*3][(!r2)+1];
}

int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d",&n);
	char op[10];
	readop(op);
	while(op[0]!='E'){
		int r1,c1,r2,c2;scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		if(op[0]=='C'){
			if(r1==r2){
				if(c1>c2)swap(c1,c2);
				T.molify(c1,r1*2-2,r1*2-1,0);
			}else{
				T.molify(c1,0,3,0);
				T.molify(c1-1,1,2,0);
			}
		}else if(op[0]=='O'){
			if(r1==r2){
				if(c1>c2)swap(c1,c2);
				T.molify(c1,r1*2-2,r1*2-1,1);
			}else{
				T.molify(c1,0,3,1);
				T.molify(c1-1,1,2,1);
			}
		}else{
			if(getans(r1,c1,r2,c2))printf("Y\n");else printf("N\n");
		}
		readop(op);
	}
	return 0;
}
