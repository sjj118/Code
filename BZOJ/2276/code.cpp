#include<iostream>
#include<cstdio>
#define maxn 1010010
 
using namespace std;
 
int n,l[maxn],r[maxn];
int q[maxn],ql,qr,ans;
 
int main(){
    scanf("%d",&n);ql=1;qr=0;
    for(int i=1;i<=n;++i)scanf("%d%d",&l[i],&r[i]);
    for(int i=1,j=1;i<=n;++i){
        while(ql<=qr&&l[q[qr]]<=l[i])--qr;q[++qr]=i;
        while(l[q[ql]]>r[i]){
            ++j;
            if(q[ql]<j)++ql;
        }
        ans=max(ans,i-j+1);
    }
    printf("%d",ans);
    return 0;
}
