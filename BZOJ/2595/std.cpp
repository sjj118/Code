#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 2000000
#define N 10
using namespace std;
int dx[]={0,1,0,-1},
    dy[]={1,0,-1,0};
int max_s,n,m;
int mat[N][N],st[N][N],vis[N][N],cnt;
int d[N][N][1<<N],pre[N][N][1<<N];
bool in[N][N][1<<N];
queue<int> Q;
void spfa(){
    int x,y,s,tx,ty,ts;
    while(!Q.empty()){
        x=Q.front()/100000;
        y=(Q.front()-x*100000)/10000;
        s=Q.front()-x*100000-y*10000;
        Q.pop();
        in[x][y][s]=0;
        for(int i=0;i<4;i++){
            tx=x+dx[i],ty=y+dy[i];
            if(tx>=n||ty>=m||tx<0||ty<0) continue;
            ts=s|st[tx][ty];
            if(d[x][y][s]+mat[tx][ty]<d[tx][ty][ts]){
                d[tx][ty][ts]=d[x][y][s]+mat[tx][ty];
                pre[tx][ty][ts]=x*100000+y*10000+s;
                if(!in[tx][ty][ts]&&s==ts) in[tx][ty][ts]=1,Q.push(tx*100000+ty*10000+ts);
            }                
        }
    }
}
void go(int x,int y,int s){
    vis[x][y]=1;
    int t=pre[x][y][s],tx,ty,ts;
    if(!t) return;
    tx=t/100000;
    ty=(t-tx*100000)/10000;
    ts=t-tx*100000-ty*10000;
    go(tx,ty,ts);
    if(x==tx&&y==ty) go(x,y,(s-ts)|st[x][y]);
}
int main(){
    //freopen("in.in","r",stdin);
    scanf("%d%d",&n,&m);    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            scanf("%d",&mat[i][j]);
            if(!mat[i][j]) st[i][j]=1<<(cnt++);
        }    
    max_s=1<<cnt;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            for(int k=0;k<max_s;k++)
                d[i][j][k]=INF;
            if(st[i][j]) d[i][j][st[i][j]]=0;
        }
    for(int k=1;k<max_s;k++){
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(st[i][j]&&!(st[i][j]&k)) continue;                
                for(int x=(k-1)&k;x;x=(x-1)&k){
                    int t=d[i][j][x|st[i][j]]+d[i][j][(k-x)|st[i][j]]-mat[i][j];
                    if(t<d[i][j][k]) d[i][j][k]=t,pre[i][j][k]=i*100000+j*10000+(x|st[i][j]);
                }
                if(d[i][j][k]<INF) Q.push(i*100000+j*10000+k),in[i][j][k]=1;
            }
        spfa();
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(st[i][j]){
                printf("%d\n",d[i][j][max_s-1]);
                go(i,j,max_s-1);
                for(int x=0;x<n;x++){
                    for(int y=0;y<m;y++){
                        if(st[x][y]) putchar('x');
                        else if(vis[x][y]) putchar('o');
                        else putchar('_');
                    }
                    puts("");
                }
                return 0;
            }
}
