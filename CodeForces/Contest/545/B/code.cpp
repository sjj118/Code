#include<cstdio>
#include<cstring>

using namespace std;

const int N=500000+10;

void kmp(char s[],int nxt[]){//下标从1开始
    nxt[0]=-1;
    for(int i=1,j=-1;s[i];++i){
        while(j!=-1&&s[i]!=s[j+1])j=nxt[j];
        nxt[i]=++j;
    }
}

char s[N],t[N];
int nxt[N];
int cnt[2];

int main(){
    scanf("\n%s",s+1);
    for(int i=1;s[i];++i)++cnt[s[i]-'0'];
    scanf("\n%s",t+1);
    kmp(t,nxt);
    int n=strlen(t+1);
    n-=nxt[n];
    for(int i=1,j=1;s[i];++i){
        int d=t[j]-'0';
        if(cnt[d])printf("%d",d),--cnt[d];
        else printf("%d",!d),--cnt[!d];
        j=j%n+1;
    }
    return 0;
}
