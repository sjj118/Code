#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=55*55;
const double EPS=1e-12;
double tt;
void Rabit_swap(double &x,double &y){tt=x,x=y,y=tt;}
bool Rabit_0(double x){
	return x<0?(-x<EPS):(x<EPS);
}
int n,m,num[105][105],N=0;
double a[maxn][maxn];
void Rabit_in(){
	scanf("%d%d",&n,&m);int i,j,k;double x;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			num[i][j]=++N;
	for(k=0;k<4;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++){
				scanf("%lf",&x);
				if(!Rabit_0(x)){
					if(k==0)a[num[i][j]][num[i+1][j]]-=x;
					else if(k==1)a[num[i][j]][num[i][j+1]]-=x;
					else if(k==2)a[num[i][j]][num[i-1][j]]-=x;
					else a[num[i][j]][num[i][j-1]]-=x;
				}
			}
	for(i=1;i<=N;i++)a[i][i]+=1.0,a[i][N+1]+=1.0;
	a[num[n][m]][N+1]=0;
}
long double tmp;
void Rabit_run(int i){
	int j,k;
	for(j=1;j<=N;j++)
		if((i^j)&&!Rabit_0(a[j][i])){
			tmp=a[j][i]/a[i][i];
			for(k=1;k<=N+1;k++)
				if(!Rabit_0(a[i][k]))a[j][k]-=tmp*a[i][k];
		}
}
void Rabit_ans(){
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if((i+j)&1)Rabit_run(num[i][j]);
	for(i=n;i;i--)
		for(j=m;j;j--)
			if(((i+j)&1)==0)Rabit_run(num[i][j]);
	if(Rabit_0(a[num[1][1]][num[1][1]])||Rabit_0(a[num[1][1]][N+1]))while(1);
	else printf("%.3f\n",a[num[1][1]][N+1]/a[num[1][1]][num[1][1]]);
}
int main(){
	Rabit_in();
	Rabit_ans();
}
