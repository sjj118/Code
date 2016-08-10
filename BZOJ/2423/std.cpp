#include<cstdio>
#include<cctype>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
#define ren for(int i=first[x];i;i=next[i])
using namespace std;
const int mod=100000000;
const int maxn=5010;
char A[maxn],B[maxn];
int f[2][maxn],g[2][maxn];
int main() {
    scanf("%s%s",A+1,B+1);
    int n=strlen(A+1)-1,m=strlen(B+1)-1,cur=0;
    rep(i,0,m) g[0][i]=1;
    rep(i,1,n) {
        cur^=1;g[cur][0]=1;
        rep(j,1,m) {
            if(A[i]==B[j]) f[cur][j]=f[cur^1][j-1]+1,g[cur][j]=g[cur^1][j-1];
            else f[cur][j]=max(f[cur^1][j],f[cur][j-1]),g[cur][j]=0;
            if(f[cur][j]==f[cur^1][j]) (g[cur][j]+=g[cur^1][j])%=mod;
            if(f[cur][j]==f[cur][j-1]) (g[cur][j]+=g[cur][j-1])%=mod;
            if(A[i]!=B[j]&&f[cur][j]==f[cur^1][j-1]) (g[cur][j]-=g[cur^1][j-1]-mod)%=mod;
        }
    }
    printf("%d\n%d\n",f[cur][m],g[cur][m]);
    return 0;
}
