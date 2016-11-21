#include<iostream>  
#include<cstdlib>  
#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<ctime>  
#include<algorithm>  
#include<iomanip>  
#include<vector>  
#include<stack>  
#include<queue>  
#include<map>  
#include<set>  
#include<bitset>  
using namespace std;  
#define MAXN 100010  
#define MAXM 1010  
#define ll long long  
#define INF 1000000000  
#define MOD 1000000007  
#define eps 1e-8  
struct data{  
    int s;  
    int v;  
    data(){  
          
    }  
    data(int _s){  
        s=_s;  
    }  
    friend bool operator <(data x,data y){  
        return x.s>y.s;  
    }  
};  
struct tree{  
    int fa;  
    int num;  
    friend bool operator <(tree x,tree y){  
        return x.fa<y.fa;  
    }  
};  
tree tr[MAXN];  
priority_queue<data>q;  
int n;  
int s[MAXN];  
ll ans;  
int main(){  
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
    int i;  
    scanf("%d",&n);  
    s[1]=1;  
    for(i=2;i<=n;i++){  
        scanf("%d",&tr[i].fa);  
        tr[i].num=i;  
        s[i]=1;  
    }  
    sort(tr+1,tr+n+1);  
    for(i=n;i!=1;i--){  
        int tf=tr[i].fa;  
        while(tr[i].fa==tf){  
            q.push(data(s[tr[i].num]));  
            i--;  
        }  
        i++;  
        while(q.size()!=1){  
            data t1=q.top();  
            q.pop();  
            data t2=q.top();  
            q.pop();  
            data t;  
            t.s=t1.s+t2.s;  
            ans+=t.s;  
            q.push(t);  
        }  
        s[tf]=q.top().s+1;  
        q.pop();  
    }  
    printf("%lld\n",ans);  
    return 0;  
}  
