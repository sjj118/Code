#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 1000010
#define maxk 55
 
using namespace std;
 
int n,k,g[maxk];
struct Stick{
    int len,color;
}s[maxn];
bool comp(Stick a,Stick b){
    return a.len<b.len;
}
 
int main(){
    scanf("%d",&k);
    for(int i=1;i<=k;++i){
        int tmp;scanf("%d",&tmp);
        for(int j=n+1;j<=n+tmp;++j)scanf("%d",&s[j].len),s[j].color=i;
        n+=tmp;
    }
    sort(s+1,s+1+n,comp);
    for(int i=1;i<=n;++i){
        int fir=0,sec=0;
        for(int j=1;j<=k;++j)if(j!=s[i].color){
            if(s[g[j]].len>s[fir].len)sec=fir,fir=g[j];
            else if(s[g[j]].len>s[sec].len)sec=g[j];
        }
        if(s[fir].len+s[sec].len>s[i].len){
            printf("%d %d %d %d %d %d",s[fir].color,s[fir].len,s[sec].color,s[sec].len,s[i].color,s[i].len);
            return 0;
        }
        g[s[i].color]=i;
    }
    printf("NIE");
    return 0;
}
