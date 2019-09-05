#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

const int N=100000+10;

int n,a[N];
int m,o[N][3];
int find(int t){
    for(int i=t+1;i<=n;++i)if(a[i]==1)return i;
    return n+1;
}
bool tryto(int x){
    int y=find(x);
    if(y+y-x>n)y=(n+x)/2;
    if(y<=x)return 0;
    ++m;
    o[m][0]=x;o[m][1]=y;o[m][2]=y+y-x;
    a[x]^=1;a[y]^=1;a[y+y-x]^=1;
    return 1;
}
int nxt[1<<11];
queue<int> q;
void output(int x){
    while(x){
        printf("%d",x&1);
        x>>=1;
    }
    puts("");
}

int main(){
    q.push(0);
    n=7;
    for(int i=0;i<(1<<n);++i)nxt[i]=-1;
    nxt[0]=0;
    while(!q.empty()){
        int t=q.front();q.pop();
        for(int i=0;i<10;++i)for(int j=i+1;j<10;++j)if(j+j-i<n){
            int tmp=t^(1<<i)^(1<<j)^(1<<(j+j-i));
            if(nxt[tmp]==-1)nxt[tmp]=t,q.push(tmp);
        }
    }
 //   output(nxt[1]);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)if(a[i]){
        if(a[i+1]&&!a[i+2])tryto(i+1);
        tryto(i);
    }
    if(a[n-1]&&a[n]){
        if(n<8){puts("NO");return 0;}
        ++m;o[m][0]=n-7;o[m][1]=n-6;o[m][2]=n-5;
        ++m;o[m][0]=n-5;o[m][1]=n-4;o[m][2]=n-3;
        ++m;o[m][0]=n-7;o[m][1]=n-4;o[m][2]=n-1;
        ++m;o[m][0]=n-6;o[m][1]=n-3;o[m][2]=n;
    }else if(a[n-1]&&!a[n]){
        if(n<8){puts("NO");return 0;}
        ++m;o[m][0]=n-7;o[m][1]=n-5;o[m][2]=n-3;
        ++m;o[m][0]=n-5;o[m][1]=n-4;o[m][2]=n-3;
        ++m;o[m][0]=n-7;o[m][1]=n-4;o[m][2]=n-1;
    }else if(a[n]){
        if(n<7){puts("NO");return 0;}
        ++m;o[m][0]=n-5;o[m][1]=n-4;o[m][2]=n-3;
        ++m;o[m][0]=n-6;o[m][1]=n-5;o[m][2]=n-4;
        ++m;o[m][0]=n-6;o[m][1]=n-3;o[m][2]=n;
    }
    puts("YES");
    printf("%d\n",m);
    for(int i=1;i<=m;++i)printf("%d %d %d\n",o[i][0],o[i][1],o[i][2]);
    return 0;
}
