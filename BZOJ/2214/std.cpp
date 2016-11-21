#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<ctime>  
#include<cmath>  
#include<algorithm>  
#include<iomanip>  
#include<vector>  
#include<map>  
#include<set>  
#include<bitset>  
#include<queue>  
#include<stack>  
using namespace std;  
#define MAXN 2010  
#define MAXM 1010  
#define INF 1000000000  
#define MOD 1000000007  
#define eps 1e-8  
#define ll long long  
int n,a[MAXN],p[MAXN],f[MAXN];  
int s;  
int tot;  
int c[MAXN*MAXN];  
bool o[MAXN*MAXN];  
int pos(int x){  
    return (p[x]+s-1)%n+1;  
}  
int get(int x){  
    return ((x-s-1)%n+n)%n+1;  
}  
void s1(int x){  
    x%=n;  
    if(!x){  
        return ;  
    }  
    s+=x;  
    c[++tot]=x;  
    o[tot]=0;  
}  
void s2(){  
    int p1=get(1);  
    int p2=get(2);  
    int p3=get(3);  
    int x=f[p1];  
    int y=f[p2];  
    int z=f[p3];  
    int t=p[x];  
    p[x]=p[y];  
    p[y]=p[z];  
    p[z]=t;  
    f[p[x]]=x;  
    f[p[y]]=y;  
    f[p[z]]=z;  
    c[++tot]=1;  
    o[tot]=1;  
}  
void print(){  
    int ans=0;  
    int i;  
    for(i=1;i<=tot;i++){  
        if(i==1||o[i]!=o[ans]){  
            ans++;  
            o[ans]=o[i];  
            c[ans]=c[i];  
        }else{  
            c[ans]+=c[i];  
        }  
    }  
    tot=ans;  
    ans=0;  
    for(i=1;i<=tot;i++){  
        if(o[i]==0){  
            c[i]%=n;  
        }else{  
            c[i]%=3;  
        }  
        if(c[i]){  
            c[++ans]=c[i];  
            o[ans]=o[i];  
        }  
    }  
    printf("%d\n",ans);  
    for(i=1;i<ans;i++){  
        if(o[i]==0){  
            printf("%da ",c[i]);  
        }else{  
            printf("%db ",c[i]);  
        }  
    }  
    if(ans){  
        if(o[i]==0){  
            printf("%da\n",c[i]);  
        }else{  
            printf("%db\n",c[i]);  
        }  
    }  
}  
int main(){  
	freopen("shift.in","r",stdin);freopen("std.out","w",stdout);
    int i;  
    scanf("%d",&n);  
    if(n==1){  
        printf("%d\n",0);  
        return 0;  
    }  
    if(n==2){  
        scanf("%d%d",&a[1],&a[2]);  
        if(a[1]==1){  
            printf("0\n");  
        }else{  
            printf("1\n1a\n");  
        }  
        return 0;  
    }  
    for(i=1;i<=n;i++){  
        scanf("%d",&a[i]);  
        p[a[i]]=i;  
        f[i]=a[i];  
    }  
    for(i=2;i<=n-2;i++){  
        s1(n-pos(i)+1);  
        int t=n-pos(i-1);  
        while(t>1){  
            t-=2;  
            s1(2);  
            s2();  
        }  
        if(t){  
            s1(1);  
            s2();  
            s2();  
        }  
    }  
    if(n==3){  
        s1(n-pos(1)+1);  
    }  
    if(f[get(2)]<f[get(3)]){  
        s1(n-3);  
        print();  
    }else{  
        if(!(n%2)){  
            s1(n-2);  
            for(i=1;i<n/2;i++){  
                s2();  
                s2();  
                s1(n-2);  
            }  
            s1(n-2);  
            print();  
        }else{  
            printf("NIE DA SIE\n");  
        }  
    }  
    return 0;  
}  
