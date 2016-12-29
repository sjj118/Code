#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<algorithm>  
#include<set>  
#include<stack>
#include<string>  
#include<ctime>
#include<queue>  
#include<cassert>
#define inf 1000000005  
#define M 2560005 
#define N 20005
#define maxn 210005  
#define eps 1e-8
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL long long  
#define MOD 1000000007
#define sqr(a) ((a)*(a))  
#define Key_value ch[ch[root][1]][0]  
#define test puts("OK");  
#define pi acos(-1.0)
#define lowbit(x) ((-(x))&(x))
#define HASH1 1331
#define HASH2 10001
#define C   240  
#define vi vector<int>
#define TIME 10  
#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;
int a[N],n,q;
int T[M],lson[M],rson[M],sum[M],lx[M],rx[M],tot=0;
pair<int,int>h[N];
void Push_up(int root){
    int l=lson[root];
    int r=rson[root];
    sum[root]=sum[l]+sum[r];
    lx[root]=max(lx[l],sum[l]+lx[r]);
    rx[root]=max(rx[r],sum[r]+rx[l]);
}
int bulid(int l,int r){
    int root=tot++;
    if(l==r){
        lx[root]=rx[root]=sum[root]=1;
        return root;
    }
    int mid=(l+r)>>1;
    lson[root]=bulid(l,mid);
    rson[root]=bulid(mid+1,r);
    Push_up(root);
    return root;
}
int update(int root,int l,int r,int pos,int val){
    int newroot=tot++;
    if(l==r){
        sum[newroot]=lx[newroot]=rx[newroot]=val;
        return newroot;
    }
    int mid=(l+r)>>1;  
    if(pos<=mid){
        lson[newroot]=update(lson[root],l,mid,pos,val);
        rson[newroot]=rson[root];    
        root=lson[root];  
    }
    else{    
        rson[newroot]=update(rson[root],mid+1,r,pos,val); 
        lson[newroot]=lson[root];    
        root=rson[root];    
    }  
    Push_up(newroot);
    return newroot;  
}
int query_all(int root,int L,int R,int l,int r){
    if(l==L&&r==R) return sum[root];
    int mid=(L+R)>>1;
    if(r<=mid) return query_all(lson[root],L,mid,l,r);
    else if(l>mid) return query_all(rson[root],mid+1,R,l,r);
    else return query_all(lson[root],L,mid,l,mid)+query_all(rson[root],mid+1,R,mid+1,r);
}
int query_left(int root,int L,int R,int l,int r){
    if(l==L&&r==R) return lx[root];
    int mid=(L+R)>>1;
    if(r<=mid) return query_left(lson[root],L,mid,l,r);
    else if(l>mid) return query_left(rson[root],mid+1,R,l,r);
    else return max(query_left(lson[root],L,mid,l,mid),query_all(lson[root],L,mid,l,mid)+query_left(rson[root],mid+1,R,mid+1,r));
}
int query_right(int root,int L,int R,int l,int r){
    if(l==L&&r==R) return rx[root];
    int mid=(L+R)>>1;
    if(r<=mid) return query_right(lson[root],L,mid,l,r);
    else if(l>mid) return query_right(rson[root],mid+1,R,l,r);
    else return max(query_right(rson[root],mid+1,R,mid+1,r),query_all(rson[root],mid+1,R,mid+1,r)+query_right(lson[root],L,mid,l,mid));
}
int check(int k,int a,int b,int c,int d){
    int val=0;
    if(b+1<c) val+=query_all(T[k],0,n-1,b+1,c-1);
    val+=query_right(T[k],0,n-1,a,b);
    val+=query_left(T[k],0,n-1,c,d);
    return val>=0;
}
void debug(int root,int l,int r){
    cout<<l<<" "<<r<<" "<<sum[root]<<endl;
    if(l!=r){
        int m=(l+r)>>1;
        debug(lson[root],l,m);
        debug(rson[root],m+1,r);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        h[i]=mp(a[i],i);
    }
    sort(h,h+n);
    T[0]=bulid(0,n-1);
    for(int i=1;i<n;i++)
        T[i]=update(T[i-1],0,n-1,h[i-1].second,-1);
    scanf("%d",&q);
    int ans=0,p[4];
    while(q--){
        scanf("%d%d%d%d",&p[0],&p[1],&p[2],&p[3]);
        for(int i=0;i<4;i++)
            p[i]=(p[i]+ans)%n;
        sort(p,p+4);
        int low=0,high=n-1,mid,ret;
        while(low<=high){
            mid=(low+high)>>1;
            if(check(mid,p[0],p[1],p[2],p[3])){
                low=mid+1;
                ret=mid;
            }
            else
                high=mid-1;
        }
        ans=h[ret].first;
        printf("%d\n",ans);
    }
    return 0;
}
