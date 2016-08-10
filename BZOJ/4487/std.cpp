#include<iostream>
#include<cstdio>
const int maxn=410,mo=1e9+7;
typedef long long LL;
using namespace std;
 
int n,m,c;
inline void ad(int&x,int y){x=x+y;if(x>=mo)x-=mo;if(x<0)x+=mo;}
int pow[maxn][maxn*maxn];
int ans=0,fact[maxn],ifact[maxn];
int exgcd(int a,int b,int&x,int&y){
    if(!b)return x=1,y=0,a;
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
int inv(int n,int mo){
    int x,y;
    if(exgcd(n,mo,x,y)>1)return 1;
    return x<0?x+mo:x;
}
inline int C(int n,int m){
    if(m>n)return 0;
    return (LL)fact[n]*ifact[m]%mo*ifact[n-m]%mo;
}
void pre(){
    fact[0]=ifact[0]=1;int t1=max(c,max(n,m));
    for(int i=1;i<=t1;++i)fact[i]=(LL)fact[i-1]*i%mo,ifact[i]=inv(fact[i],mo);
    for(int i=1;i<=c+1;++i){
        pow[i][0]=1;
        for(int j=1;j<=n*m;++j)pow[i][j]=(LL)pow[i][j-1]*i%mo;
    }
}
int count(int n,int m){
    int ans=0;
    for(int i=0,f=1;i<=c;++i,f=-f){
        ad(ans,(LL)f*C(c,i)*pow[c-i+1][n*m]%mo);
    }
    return ans;
}
  
int main(){
	freopen("code.in","r",stdin);freopen("std.out","w",stdout);
    scanf("%d%d%d",&n,&m,&c);pre();
    for(int i=0,f1=1;i<=n;++i,f1=-f1){
        for(int j=0,f2=1;j<=m;++j,f2=-f2){
            ad(ans,(LL)f1*f2*count(n-i,m-j)*C(n,i)%mo*C(m,j)%mo);
        }
    }
    printf("%d",ans);
    return 0;
}

