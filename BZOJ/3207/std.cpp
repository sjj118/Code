/**************************************************************
    Problem: 3207
    User: BLADEVIL
    Language: C++
    Result: Accepted
    Time:6580 ms
    Memory:130804 kb
****************************************************************/
 
//By BLADEVIL
#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 500010
#define LL long long
  
using namespace std;
   
struct segment {
    int left,right,cnt;
    int son[2];
    segment() {
        left=right=cnt=0;
        memset(son,0,sizeof son);
    }
}t[12*maxn];
   
struct rec {
    int num,key;
    LL hash;
    rec() {
        hash=num=key=0;
    }
}a[maxn];
   
int n,m,k,sum,tot;
int rot[maxn];
map<LL,int>tree;
   
bool cmp1(rec x,rec y) {
    return x.hash<y.hash;
}
   
bool cmp2(rec x,rec y) {
    return x.num<y.num;
}
   
void map_insert(LL x,int y) {
    if (tree.find(x)==tree.end()) tree.insert(pair<LL,int>(x,y));
}
   
void build(int &x,int l,int r) {
    if (!x) x=++tot;
    t[x].left=l; t[x].right=r;
    if (l==r) return ;
    int mid=t[x].left+t[x].right>>1;
    build(t[x].son[0],l,mid); build(t[x].son[1],mid+1,r);
}
   
void insert(int &x,int rot,int y) {
    if (!x) x=++tot;
    t[x].left=t[rot].left; t[x].right=t[rot].right;
    if (t[x].left==t[x].right) {
        t[x].cnt=t[rot].cnt+1;
        return ;
    }
    int mid=t[x].left+t[x].right>>1;
    if (y>mid) {
        t[x].son[0]=t[rot].son[0];
        insert(t[x].son[1],t[rot].son[1],y);
    } else {
        t[x].son[1]=t[rot].son[1];
        insert(t[x].son[0],t[rot].son[0],y);
    }
    t[x].cnt=t[rot].cnt+1;
}
   
int query(int lx,int rx,int y) {
    if (t[lx].left==t[lx].right) return t[rx].cnt-t[lx].cnt;
    int mid=t[lx].left+t[lx].right>>1;
    if (y>mid) return query(t[lx].son[1],t[rx].son[1],y); else return query(t[lx].son[0],t[rx].son[0],y);
}
   
int main() {
	freopen("code.in","r",stdin);
	freopen("std.out","w",stdout); 
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i].key);
    n=n-k+1;
    for (int i=1;i<=n;i++) 
        for (int j=i;j<=i+k-1;j++) a[i].hash=a[i].hash*107+a[j].key;
    for (int i=1;i<=n;i++) a[i].num=i;
    sort(a+1,a+n+1,cmp1); sum=1; LL cur=a[1].hash;
    //for (int i=1;i<=n;i++) printf("%d ",a[i].hash); printf("\n");
    for (int i=1;i<=n;i++)
        if (a[i].hash==cur) a[i].key=sum; else cur=a[i].hash,a[i].key=++sum;
    sort(a+1,a+n+1,cmp2);
    //for (int i=1;i<=n;i++) printf("%d ",a[i].key); printf("\n"); 
    for (int i=1;i<=n;i++) map_insert(a[i].hash,a[i].key);
    build(rot[0],1,sum);
    for (int i=1;i<=n;i++) insert(rot[i],rot[i-1],a[i].key);
    while (m--) {
        int l,r; scanf("%d%d",&l,&r); if (r>n) r=n;
        LL ha=0;
        for (int i=1;i<=k;i++) {
            int x; scanf("%d",&x);
            ha=ha*107+x;
        }
        map<LL,int>::iterator p=tree.find(ha);
        if (p==tree.end()) {
            printf("Yes\n");
            continue;
        }
        int y=p->second;
        if (query(rot[l-1],rot[r],y)>0) printf("No\n"); else printf("Yes\n");
        //printf("%d\n",query(rot[l-1],rot[r],y));
    }
    return 0;
}
