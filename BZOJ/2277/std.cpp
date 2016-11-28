#include <cstdio>  
#include <cstring>  
#include <algorithm>  
  
using namespace std;  
typedef long long LL;  
int m,N,i,j;  
LL n,a[250005],b[250005],p[3000005],ans;  
  
LL gcd(LL a,LL b){  
  while (b) b^=a^=b^=a%=b;  
  return a;  
}  
  
bool Judge(LL x){  
  for (int i=m-1;i>0;i--){  
    if (b[i]<x) return 1;  
    if (b[i]%x==0) return 0;  
  }  
  return 1;  
}  
  
int main(){  
  //freopen("sej.in","r",stdin);  
  //freopen("sej.out","w",stdout);  
  scanf("%lld%d",&n,&m);  
  for (i=1;i<=m;i++){  
    scanf("%lld",&a[i]);  
    if (a[i]==0) a[i]=n;  
  }  
  for (i=1;i<=a[m]/i;i++)  
  if (a[m]%i==0){  
    if (n%i==0) p[++N]=i;  
    if (a[m]/i!=i && n%(a[m]/i)==0)  
      p[++N]=a[m]/i;  
  }  
  sort(p+1,p+N+1);  
  for (i=1;i<m;i++)  
    b[i]=gcd(n,a[i]);  
  sort(b+1,b+m);  
  m=unique(b+1,b+m)-b;  
  for (i=1;i<=N;i++)  
    if (Judge(p[i]))  
      {ans=n/p[i];break;}  
  printf("%lld\n",ans);  
  return 0;  
}  
