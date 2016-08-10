#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int t,n,m,M,use[310];
long long s[310],f[310][310],c[310][310];
bool ff=true;
int main()
{
	freopen("code.in","r",stdin);
	freopen("std.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        memset(use,0,sizeof(use));
        memset(s,0,sizeof(s));
        memset(f,0,sizeof(f));
        memset(c,0,sizeof(c));
        int i,j,x,y,k;
        ff=true;
        scanf("%d%d%d",&n,&m,&M);
        for(i=1;i<=m;++i){
            scanf("%d%d",&x,&y);
            use[y]+=1;
        }
        for(i=n;i>=1;--i){
            s[i]=s[i+1]+use[i];
            if(s[i]>n-i+1){
                ff=false;
                printf("NO\n");
                break;
            }
        }
        if(!ff) continue;
        for(i=0;i<=n;++i){
            c[i][0]=c[i][i]=1;
            for(j=1;j<i;++j)
              c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;
        }
        f[n+1][0]=1;
        for(i=1;i<=n;++i) f[n+1][i]=0;
        for(i=n;i>=1;--i){
            for(j=0;j<=n-s[i]-i+1;++j){
                for(k=0;k<=j;++k){
                    f[i][j]=(f[i][j]+f[i+1][j-k]*c[j][k])%M;
                }
            }
        }
        printf("YES %d\n",f[1][n-m]);
    }
}
