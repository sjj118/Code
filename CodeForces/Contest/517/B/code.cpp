#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

const int N=2000+10;

int n,k;
char a[N][N];
int dp[N][N],tot;
queue<pair<int,int> > q;
pair<int,int> pos[N];
bool inq[N][N];

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("\n%s",a[i]+1);
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)dp[i][j]=-1;
    dp[1][1]=k;
    if(dp[1][1]&&a[1][1]!='a')--dp[1][1];
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
        if(i>1)dp[i][j]=max(dp[i][j],dp[i-1][j]-(a[i][j]!='a'));
        if(j>1)dp[i][j]=max(dp[i][j],dp[i][j-1]-(a[i][j]!='a'));
    }
    int mxl=0;
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(dp[i][j]>=0)mxl=max(mxl,i+j-1);
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(dp[i][j]>=0&&i+j-1==mxl)q.push(make_pair(i,j));
    if(a[1][1]=='a'||k)for(int i=1;i<=mxl;++i)printf("a");
    else printf("%c",a[1][1]);
    while(!q.empty()&&q.front()!=make_pair(n,n)){
        tot=0;
        char mn='z';
        while(!q.empty())pos[++tot]=q.front(),q.pop();
        for(int i=1;i<=tot;++i){
            int x=pos[i].first,y=pos[i].second;
            char t='z';
            if(x<n)t=min(t,a[x+1][y]);
            if(y<n)t=min(t,a[x][y+1]);
            mn=min(mn,t);
        }
        printf("%c",mn);
        for(int i=1;i<=tot;++i){
            int x=pos[i].first,y=pos[i].second;
            if(x<n){
                if(a[x+1][y]==mn)if(!inq[x+1][y]){
                    inq[x+1][y]=1;
                    q.push(make_pair(x+1,y));
                }
            }
            if(y<n){
                if(a[x][y+1]==mn)if(!inq[x][y+1]){
                    inq[x][y+1]=1;
                    q.push(make_pair(x,y+1));
                }
            }
        }
    }
    return 0;
}
