#include<iostream>
#include<cstdio>
#define sqr(x) ((x)*(x))
#define abs(x) (x)>0?(x):-(x)
#define maxn 12
 
using namespace std;
 
int n;
struct Point{
    double r[maxn];
    void read(){
        for(int i=1;i<=n;++i)scanf("%lf",&r[i]);
    }
}p[maxn],ans;
struct Matrix{
    double v[maxn][maxn];
    void gauss(){
        for(int i=1;i<n;++i){
            int t=i;for(int j=i+1;j<=n;++j)if(abs(v[j][i])>abs(v[t][i]))t=j;
            for(int j=i;j<=n+1;++j)swap(v[i][j],v[t][j]);
            for(int j=i+1;j<=n;++j){
                double p=v[j][i]/v[i][i];
                for(int k=i;k<=n+1;++k)v[j][k]-=p*v[i][k];
            }
        }
    }
    void solve(Point&ans){
        gauss();
        for(int i=n;i;--i){
            ans.r[i]=v[i][n+1]/v[i][i];
            for(int j=1;j<i;++j)v[j][n+1]-=v[j][i]*ans.r[i];
        }
    }
}func;
 
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n+1;++i)p[i].read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)func.v[i][j]=2*(p[i+1].r[j]-p[i].r[j]);
        for(int j=1;j<=n;++j)func.v[i][n+1]+=sqr(p[i+1].r[j])-sqr(p[i].r[j]);
    }
    func.solve(ans);
    for(int i=1;i<n;++i)printf("%.3lf ",ans.r[i]);printf("%.3lf",ans.r[n]);
    return 0;
}
