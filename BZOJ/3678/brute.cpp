#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=100000+10;
int n,m,v[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&v[i]);
	while(m--){
		int op;scanf("%d",&op);
		if(op==0){
			int p,a,b;scanf("%d%d%d",&p,&a,&b);
			per(i,n,p+1)v[i+b-a+1]=v[i];
			rep(i,p+1,p+b-a+1)v[i]=i-p+a-1;
			n+=b-a+1;
		}else if(op==1){
			int a,b;scanf("%d%d",&a,&b);
			for(int i=a,j=b+1;j<=n;++i,++j)v[i]=v[j];
			n-=b-a+1;
		}else{
			int p;scanf("%d",&p);
			printf("%d\n",v[p]);
		}
	}
	return 0;
}
