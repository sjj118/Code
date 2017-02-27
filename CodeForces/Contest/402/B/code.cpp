#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::string;
using std::map;
const int N=5000+10,M=1000+10;
int n,m;
map<string,int> id;
int val[N][M];
int ansmx[M],ansmn[M];
struct Euq{
	int l,r,op;
}a[N];
int xx[N];
int work(int p,int x){
	rep(i,1,n){
		if(a[i].op==0)xx[i]=val[i][p];
		else{
			int l,r;
			if(a[i].l==0)l=x;
			else l=xx[a[i].l];
			if(a[i].r==0)r=x;
			else r=xx[a[i].r];
			if(a[i].op==1)xx[i]=l&r;
			else if(a[i].op==2)xx[i]=l|r;
			else if(a[i].op==3)xx[i]=l^r;
		}
	}
	int ret=0;
	rep(i,1,n)ret+=xx[i];
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		char var[14];scanf("\n%s := ",var);
		id[var]=i;
		char c=getchar();
		if(c=='0'||c=='1'){
			rep(j,1,m)val[i][j]=c-'0',c=getchar();
		}else{
			string lf,op,rf;
			while(c!=' ')lf+=c,c=getchar();
			c=getchar();while(c!=' ')op+=c,c=getchar();
			c=getchar();while(c!='\n')rf+=c,c=getchar();
			if(op[0]=='A')a[i].op=1;
			else if(op[0]=='O')a[i].op=2;
			else if(op[0]=='X')a[i].op=3;
			if(lf[0]=='?')a[i].l=0;
			else a[i].l=id[lf];
			if(rf[0]=='?')a[i].r=0;
			else a[i].r=id[rf];
		}
	}
	rep(i,1,m){
		int t0=work(i,0),t1=work(i,1);
		if(t0>=t1)ansmx[i]=0;
		else ansmx[i]=1;
		if(t0<=t1)ansmn[i]=0;
		else ansmn[i]=1;
	}
	rep(i,1,m)printf("%d",ansmn[i]);puts("");
	rep(i,1,m)printf("%d",ansmx[i]);
	return 0;
}
