#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{
	
const int N=1e5+10,L=10+2;
int n,m,pos;
int a[N];
char name[N][L];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d %s",&a[i],name[i]);
	pos=1;
	rep(i,1,m){
		int x,y;scanf("%d%d",&x,&y);
		if(a[pos]^x){
			pos+=y;
			if(pos>n)pos-=n;
		}else{
			pos-=y;
			if(pos<=0)pos+=n;
		}
	}
	printf("%s",name[pos]);
	return 0;
}
}
int main(){
	freopen("toy.in","r",stdin);freopen("toy.out","w",stdout);
	return sjj118::main();
}

