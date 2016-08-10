#include<iostream>
#include<cstdio>
#include<cstring>
#define ld long double
 
using namespace std;
 
int n,len,alp;
 
struct matrix{
    int width,height;
    ld val[100][100];
    matrix(int h,int w,int t=0){
        memset(val,0,sizeof(val));
        width=w;
        height=h;
        for(int i=0;i<h;++i){
            val[i][i]=t;
        }
    }
};
matrix operator*(matrix a,matrix b){
    matrix ans(b.height,a.width);
    for(int i=0;i<ans.height;++i){
        for(int j=0;j<ans.width;++j){
            for(int k=0;k<a.height;++k) ans.val[i][j]+=a.val[k][j]*b.val[i][k];
        }
    }
    return ans;
}
matrix power(matrix base,int exp){
    matrix ans(base.width,base.height,1);
    while(exp){
        if(exp&1)ans=ans*base;
        base=base*base;
        exp>>=1;
    }
    return ans;
}
struct Trie{
    int next[100][26],mark[100],fail[100];
    int tot;
    void add(){
        char c[20];
        scanf("%s",c);
        int k=0;
        int l=strlen(c);
        for(int i=0;i<l;++i){
            if(!next[k][c[i]-'a'])next[k][c[i]-'a']=tot++;
            k=next[k][c[i]-'a'];
        }
        mark[k]=1;
    }
    int q[100],head,tail;
    void bfs(){
        for(int i=0;i<alp;++i){
            if(next[0][i]){
                q[tail++]=next[0][i];
            }else{
                fail[i]=0;
                next[0][i]=0;
            }
        }
        while(head!=tail){
            int k=q[head++];
            for(int i=0;i<alp;++i){
                if(mark[fail[k]])mark[k]=1;
                if(next[k][i]){
                    fail[next[k][i]]=next[fail[k]][i];
                    q[tail++]=next[k][i];
                }else{
                    next[k][i]=next[fail[k]][i];
                }
            }
        }
    }
    void getans(){
        matrix start(tot+1,1),base(tot+1,tot+1);
        for(int i=0;i<tot;++i) start.val[i][0]=0;start.val[tot][0]=1;
        for(int i=0;i<tot;++i){
            for(int j=0;j<alp;++j){
                if(mark[next[i][j]]){
                    base.val[i][0]+=1.0/alp;
                    base.val[i][tot]+=1.0/alp;
                }else{
                    base.val[i][next[i][j]]+=1.0/alp;
                }
            }
        }
        base.val[tot][tot]=1;
        start=start*power(base,len);
        double ans=start.val[0][0];
        printf("%lf",ans);
    }
    void output(){
        for(int i=0;i<tot;++i){
            printf("%d: ",i);
            for(int j=0;j<alp;++j)printf("%d ",next[i][j]);
            printf("%d %d\n",fail[i],mark[i]);
        }
    }
    Trie(){
        tot=1;
    }
} T;
 
int main(){
    scanf("%d%d%d",&n,&len,&alp);
    for(int i=0;i<n;++i){
        T.add();
    }
    T.bfs();
    T.getans();
    return 0;
}
