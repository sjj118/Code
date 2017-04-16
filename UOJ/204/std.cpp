
#include<cstdio>
#include<algorithm>
const int N=502,M=N*2,P=1000000007;
int n,m,i,j,k,t,len,inv[N],a[N],b[N],c[M],C[M][N],f[N][M],g[M],G[M],h[M][N],ans;
inline int getl(int x){for(int i=1;;i++)if(c[i-1]==x)return i;return -1;}
inline int getr(int x){for(int i=1;;i++)if(c[i]==x)return i;return -1;}
inline void up(int&a,int b){a+=b;if(a>=P)a-=P;}
int main(){
  scanf("%d",&n);
  for(i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]),c[++m]=--a[i],c[++m]=b[i];
  std::sort(c+1,c+m+1);
  for(j=0,i=1;i<=m;i++)if(c[i]!=c[i-1])c[++j]=c[i];
  m=j;
  for(i=1;i<=n;i++)a[i]=getl(a[i]),b[i]=getr(b[i]);
  for(inv[0]=inv[1]=1,i=2;i<=n;i++)inv[i]=1LL*(P-inv[P%i])*(P/i)%P;
  for(i=1;i<=m;i++){
    C[i][1]=len=c[i]-c[i-1];
    for(j=2;j<=n&&j<=len;j++)C[i][j]=1LL*C[i][j-1]*(len-j+1)%P*inv[j]%P;
  }
  for(i=0;i<=m;i++)g[i]=1;
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++)f[i][j]=f[i-1][j];
    for(j=a[i];j<=b[i];j++)f[i][j]++;
  }
  for(i=1;i<=n;i++){
    for(j=0;j<=m;j++)G[j]=0;
    for(j=b[i];j>=a[i];j--){
      for(k=f[i][j];k>=2;k--){
        t=h[j][k-1];
        up(G[j],1LL*t*C[j][k]%P);
        up(h[j][k],t);
      }
      t=g[j-1];
      up(G[j],1LL*t*C[j][1]%P);
      up(h[j][1],t);
    }
    for(j=a[i];j<=m;j++){
      up(G[j],G[j-1]);
      up(g[j],G[j]);
    }
  }
  for(i=1;i<=m;i++)for(j=1;j<=n;j++)up(ans,1LL*h[i][j]*C[i][j]%P);
  return printf("%d",ans),0;
}
