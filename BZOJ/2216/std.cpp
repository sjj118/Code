#include<ctime>
#include<cstdio>
#include<iostream>
#include<cmath>
#define N 500010
using namespace std;
namespace sjj118{

int n,i,l,r,mid,a[N],b[N],f[N],g[N];
inline void read(int&a){char c;while(!(((c=getchar())>='0')&&(c<='9')));a=c-'0';while(((c=getchar())>='0')&&(c<='9'))(a*=10)+=c-'0';}
void dp1(int l,int r,int dl,int dr){
  if(l>r)return;
  int m=(l+r)>>1,i,dm;double t,fm=0;
  for(i=dl;i<=dr&&i<=m;i++)if((t=std::sqrt(m-i)+a[i])>=fm)dm=i,fm=t;
  f[m]=a[dm]+b[m-dm];
  dp1(l,m-1,dl,dm),dp1(m+1,r,dm,dr);
}
void dp2(int l,int r,int dl,int dr){
  if(l>r)return;
  int m=(l+r)>>1,i,dm;double t,fm=0;
  for(i=dr;i>=dl&&i>=m;i--)if((t=std::sqrt(i-m)+a[i])>=fm)dm=i,fm=t;
  g[m]=a[dm]+b[dm-m];
  dp2(l,m-1,dl,dm),dp2(m+1,r,dm,dr);
}
int main(){
  for(read(n),i=1;i<=n;i++)read(a[i]);
  for(i=1;i<n;i++){
    l=1,r=708;
    while(l<=r){
      mid=(l+r)>>1;
      if(mid*mid>=i)r=(b[i]=mid)-1;else l=mid+1;
    }
  }
  cerr<<clock()<<endl;
  dp1(1,n,1,n);
  cerr<<clock()<<endl;
  dp2(1,n,1,n);
  cerr<<clock()<<endl;
  for(i=1;i<=n;i++)printf("%d\n",(f[i]>g[i]?f[i]:g[i])-a[i]);
  return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("std.out","w",stdout);
	return sjj118::main();
}
