#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define N 1000010
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n,k,i,a[N],b[N],ret,q[N],t,v[2100000];ll f[N];
priority_queue<P,vector<P>,greater<P> >Q;
inline void read(int&a){char c;while(!(((c=getchar())>='0')&&(c<='9')));a=c-'0';while(((c=getchar())>='0')&&(c<='9'))(a*=10)+=c-'0';}
void build(int x,int a,int b){
  if(a==b){v[x]=::a[a];return;}
  int mid=(a+b)>>1;
  build(x<<1,a,mid),build(x<<1|1,mid+1,b),v[x]=min(v[x<<1],v[x<<1|1]);
}
int ask(int x,int a,int b,int c,ll p){
  if(c<=a){
    if(v[x]>p)return 0;
    if(a==b)return a;
  }
  int mid=(a+b)>>1;
  if(c<=mid){
    int t=ask(x<<1,a,mid,c,p);
    if(t)return t;
  }
  return ask(x<<1|1,mid+1,b,c,p);
}
void dfs(int x,ll s){
  if(!ret)return;
  if(!s){
    if(!(--ret))for(int i=1;i<=t;i++)printf("%d ",q[i]);
    return;
  }
  for(;x<=n;x++){
    x=ask(1,1,n,x,s);
    if(!x)return;
    q[++t]=x;
    dfs(x+1,s-a[x]);
    t--;
  }
}
int main(){
  read(n),read(k);k--;
  if(!k)return puts("0"),0;
  for(i=1;i<=n;i++)read(a[i]),b[i]=a[i];
  sort(b+1,b+n+1);
  Q.push(P(b[1],1));
  for(i=1;i<=k;i++){
    P t=Q.top();Q.pop();f[i]=t.first;
    if(t.second==n)continue;
    Q.push(P(t.first+b[t.second+1],t.second+1));
    Q.push(P(t.first-b[t.second]+b[t.second+1],t.second+1));
  }
  printf("%lld\n",f[k]);
  for(i=k;f[i]==f[k];i--);
  ret=k-i;
  build(1,1,n);
  dfs(1,f[k]);
  return 0;
}

