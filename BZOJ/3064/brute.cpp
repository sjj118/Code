#include<iostream>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=1e5+10;
inline void up(int&x,int y){if(y>x)x=y;}
int n,m,a[N],b[N];
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]),b[i]=a[i];
	scanf("%d",&m);
	while(m--){
		char op;scanf("\n%c",&op);
		if(op=='Q'){
			int x,y;scanf("%d%d",&x,&y);
			int ret=a[x];
			rep(i,x,y)up(ret,a[i]);
			printf("%d\n",ret);
		}else if(op=='A'){
			int x,y;scanf("%d%d",&x,&y);
			int ret=b[x];
			rep(i,x,y)up(ret,b[i]);
			printf("%d\n",ret);
		}else if(op=='P'){
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			rep(i,x,y)a[i]+=z,up(b[i],a[i]);
		}else{
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			rep(i,x,y)a[i]=z,up(b[i],a[i]);
		}
	}
	return 0;
}
