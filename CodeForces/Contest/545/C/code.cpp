#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>

using namespace std;

const int M=100000+10,N=50*M;
inline void dn(int&x,int y){if(y<x)x=y;}
char gc(){char c=getchar();if(c!='0'&&c!='1')c=getchar();return c;}

int n,m,d;
bool open[M][50+5];
int id(int u,int t){return (u-1)*d+t;}

struct Edge{
    int u,v;
}eg[N],escc[N],tmp[N];
int idxg[N],idxscc[N];
void isort(int n,Edge*e,int m,int*idx){
    for(int i=0;i<m;++i)++idx[e[i].u],tmp[i]=e[i];
    ++idx[1];for(int i=2;i<=n+1;++i)idx[i]+=idx[i-1];
    for(int i=0;i<m;++i)e[--idx[tmp[i].u]]=tmp[i];
}
int nscc,idscc[N],dfn[N],lowlink[N],clo;
int stk[N],top;
bool instk[N];
void dfscc(int k){
    dfn[k]=lowlink[k]=++clo;
    instk[stk[top++]=k]=true;
    for(int p=idxg[k];p<idxg[k+1];++p){
        if(!dfn[eg[p].v])dfscc(eg[p].v),dn(lowlink[k],lowlink[eg[p].v]);
        else if(instk[eg[p].v])dn(lowlink[k],dfn[eg[p].v]);
    }
    if(lowlink[k]==dfn[k]){
        ++nscc;
        while(top&&stk[top]!=k){
            instk[stk[--top]]=false;
            idscc[stk[top]]=nscc;
        }
    }
}
void getSCC(int n){
    for(int k=1;k<=n;++k)if(!dfn[k])dfscc(k); 
    int m=0;
    for(int k=1;k<=n;++k){
        for(int p=idxg[k];p<idxg[k+1];++p){
            if(idscc[k]!=idscc[eg[p].v])escc[m++]=Edge{idscc[k],idscc[eg[p].v]};
        }
    }
    isort(nscc,escc,m,idxscc);
}

int ops[N];
int dp[N];
bool vis[N];
int dfsdp(int k){
    if(vis[k])return dp[k];
    for(int p=idxscc[k];p<idxscc[k+1];++p)dp[k]=max(dp[k],dfsdp(escc[p].v));
    dp[k]+=ops[k];
    vis[k]=1;
    return dp[k];
}

int main(){
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1;i<=m;++i){
        int u,v;scanf("%d%d",&u,&v);
        for(int j=1;j<=d;++j)eg[(i-1)*d+j-1]=Edge{id(u,j),id(v,j%d+1)};
    }
    isort(n*d,eg,m*d,idxg);
    for(int i=1;i<=n;++i)for(int j=1;j<=d;++j)open[i][j]=gc()-'0';
    getSCC(n*d);
    for(int i=1;i<=n;++i){
        int tmp[50],ntmp=0;
        for(int j=1;j<=d;++j)if(open[i][j])tmp[ntmp++]=idscc[id(i,j)];
        sort(tmp,tmp+ntmp);
        ntmp=unique(tmp,tmp+ntmp)-tmp;
        for(int j=0;j<ntmp;++j)++ops[tmp[j]];
    }
    printf("%d",dfsdp(idscc[id(1,1)]));
    return 0;
}
