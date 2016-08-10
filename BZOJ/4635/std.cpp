#include<cstdio>
const int N=1001,M=7100,P=1000000007;
int T,type,t,n,m,l,r,i,j;
int f[N][N],s[N][N],G[N],V[M],NXT[M],mul[N],g[N],v[M],nxt[M],ed;
int p[N],a[10000001],b[N],ans;
inline void up(int&a,int b){a+=b;while(a>=P)a-=P;}
inline int pow(int a,int b){int t=1;for(;b;b>>=1,a=1LL*a*a%P)if(b&1)t=1LL*t*a%P;return t;}
inline void init(int x,int n){
  int t=0,i,j;
  for(i=2;i<=x;i=j+1)j=x/(x/i),up(t,1LL*(j-i+1)*a[x/i]%P);
  a[x]=(pow(x,n)+P-t)%P;
}
void dfs(int x,int y,int z){
  if(x==t){
    if(z==1)return;
    mul[y>0?y:-y]=z;
    v[++ed]=y;nxt[ed]=g[i];g[i]=ed;
    return;
  }
  dfs(x+1,y,z),dfs(x+1,-y*a[x],z*b[x]);
}
inline void cal(int x){
  up(ans,p[m]);
  for(int i=g[x];i;i=nxt[i]){
    if(v[i]>0)up(ans,p[a[v[i]]]);
    else up(ans,P-p[a[-v[i]]]);
  }
}
int main(){
  freopen("code.in","r",stdin);freopen("std.out","w",stdout);
  scanf("%d%d",&T,&type);
  if(type==1){
    a[1]=1;
    while(T--){
      scanf("%d%d%d%d",&n,&m,&l,&r);ans=0;
      for(i=1;i<=m;i=m/(m/i)+1)v[++t]=m/i;
      while(t)init(v[t--],n);
      for(i=l;i<=r;i=j+1){
        j=m/(m/i);
        if(j>r)j=r;
        up(ans,1LL*(j-i+1)*a[m/i]%P);
      }
      printf("%d\n",ans);
    }
  }else{
    for(i=0;i<N;i++)f[0][i]=f[i][0]=f[i][i]=i;
    for(i=2;i<N;i++)for(j=1;j<i;j++)f[i][j]=f[j][i]=f[i-j][j];
    for(i=1;i<N;i++)for(j=1;j<N;j++)s[i][j]=s[i][j-1]+(f[i][j]==1);
    for(i=1;i<N;i++)for(j=i;j<N;j+=i)V[++ed]=i,NXT[ed]=G[j],G[j]=ed;
    for(ed=0,i=2;i<N;i++){
      for(n=i,t=0,j=2;j<=n;j++)if(n%j==0){
        for(m=1;n%j==0;n/=j,m*=j);
        a[t]=m,b[t++]=j;
      }
      dfs(0,1,1);
    }
    while(T--){
      scanf("%d%d%d%d",&n,&m,&l,&r);ans=0;
      for(i=1;i<=m;i++)p[i]=pow(i,n);
      for(i=2;i<=m;i++)for(a[i]=0,j=G[i/mul[i]];j;j=NXT[j])a[i]+=s[i][m/V[j]];
      while(l<=r)cal(l++);
      printf("%d\n",ans);
    }
  }
  return 0;
}
