#include<iostream>
#include<cstdio>
#include<cstring>
#define p 30011
using namespace std;

int n,m,cnt; struct matrix{ int t[105][105]; }a,b,c;
matrix tms(matrix x,matrix y){
	matrix z; int i,j,k;
	for (i=1; i<=cnt; i++)
		for (j=1; j<=cnt; j++){
			z.t[i][j]=0;
			for (k=1; k<=cnt; k++) z.t[i][j]=(z.t[i][j]+x.t[i][k]*y.t[k][j])%p;
		}
	return z;
}
int main(){
	freopen("code.in","r",stdin);freopen("std.out","w",stdout);
	scanf("%d%d",&n,&m); cnt=n<<1; int i,k;
	m--; if (m==1){ puts((n<3)?"1":"0"); return 0; }
	for (i=1; i<=n; i++){
		a.t[i][i]=a.t[i+n][i+n]=b.t[i][i]=b.t[i+n][i+n]=1;
		for (k=i-1; k<=i+1; k++)
			if (k>0 && k<=n) a.t[i][k+n]=b.t[i+n][k]=1;
	}
	c.t[1][1]=1; if (m&1){ c.t[1][2]=c.t[1][n+1]=1; }
	m>>=1; a=tms(a,b); memcpy(b.t,a.t,sizeof(a.t));
	for (i=m-1; i; i>>=1,a=tms(a,a)) if (i&1) c=tms(c,a);
	printf("%d\n",(tms(c,b).t[1][n]-c.t[1][n]+p)%p);
	return 0;
}

