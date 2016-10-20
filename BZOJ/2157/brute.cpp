#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#define M 20200  
using namespace std;  
  
struct Segtree{  
    Segtree *ls,*rs;  
    int sum,max_val,min_val;  
    bool rev_mark;  
    void* operator new (size_t)  
    {  
        static Segtree mempool[M<<1],*C=mempool;  
        return C++;  
    }  
    void Reverse()  
    {  
        sum=-sum;  
        max_val=-max_val;  
        min_val=-min_val;  
        swap(max_val,min_val);  
        rev_mark^=1;  
    }  
    void Push_Up()  
    {  
        sum=ls->sum+rs->sum;  
        max_val=max(ls->max_val,rs->max_val);  
        min_val=min(ls->min_val,rs->min_val);  
    }  
    void Push_Down()  
    {  
        if(rev_mark)  
        {  
            ls->Reverse();  
            rs->Reverse();  
            rev_mark=false;  
        }  
    }  
    void Build_Tree(int x,int y,int a[])  
    {  
        int mid=(x+y)>>1;  
        if(x==y)  
        {  
            sum=max_val=min_val=a[mid];  
            return ;  
        }  
        (ls=new Segtree)->Build_Tree(x,mid,a);  
        (rs=new Segtree)->Build_Tree(mid+1,y,a);  
        Push_Up();  
    }  
    void Modify(int x,int y,int pos,int val)  
    {  
        int mid=(x+y)>>1;  
        if(x==y)  
        {  
            sum=min_val=max_val=val;  
            return ;  
        }  
        Push_Down();  
        if(pos<=mid)  
            ls->Modify(x,mid,pos,val);  
        else  
            rs->Modify(mid+1,y,pos,val);  
        Push_Up();  
    }  
    void Reverse(int x,int y,int l,int r)  
    {  
        int mid=(x+y)>>1;  
        if(x==l&&y==r)  
        {  
            Reverse();  
            return ;  
        }  
        Push_Down();  
        if(r<=mid)  
            ls->Reverse(x,mid,l,r);  
        else if(l>mid)  
            rs->Reverse(mid+1,y,l,r);  
        else  
            ls->Reverse(x,mid,l,mid),rs->Reverse(mid+1,y,mid+1,r);  
        Push_Up();  
    }  
    int Get_Sum(int x,int y,int l,int r)  
    {  
        int mid=x+y>>1;  
        if(x==l&&y==r)  
            return sum;  
        Push_Down();  
        if(r<=mid)  
            return ls->Get_Sum(x,mid,l,r);  
        if(l>mid)  
            return rs->Get_Sum(mid+1,y,l,r);  
        return ls->Get_Sum(x,mid,l,mid) + rs->Get_Sum(mid+1,y,mid+1,r);  
    }  
    int Get_Max(int x,int y,int l,int r)  
    {  
        int mid=x+y>>1;  
        if(x==l&&y==r)  
            return max_val;  
        Push_Down();  
        if(r<=mid)  
            return ls->Get_Max(x,mid,l,r);  
        if(l>mid)  
            return rs->Get_Max(mid+1,y,l,r);  
        return max( ls->Get_Max(x,mid,l,mid) , rs->Get_Max(mid+1,y,mid+1,r) );  
    }  
    int Get_Min(int x,int y,int l,int r)  
    {  
        int mid=x+y>>1;  
        if(x==l&&y==r)  
            return min_val;  
        Push_Down();  
        if(r<=mid)  
            return ls->Get_Min(x,mid,l,r);  
        if(l>mid)  
            return rs->Get_Min(mid+1,y,l,r);  
        return min( ls->Get_Min(x,mid,l,mid) , rs->Get_Min(mid+1,y,mid+1,r) );  
    }  
}*tree=new Segtree;  
  
struct abcd{  
    int to,f,next;  
}table[M<<1];  
  
int head[M],tot;  
int n,m,X[M],Y[M],Z[M];  
int fa[M],son[M],dpt[M],size[M],top[M],pos[M],a[M],cnt;  
  
void Add(int x,int y,int z)  
{  
    table[++tot].to=y;  
    table[tot].f=z;  
    table[tot].next=head[x];  
    head[x]=tot;  
}  
  
void DFS1(int x)  
{  
    int i;  
    dpt[x]=dpt[fa[x]]+1;  
    size[x]=1;  
    for(i=head[x];i;i=table[i].next)  
        if(table[i].to!=fa[x])  
        {  
            fa[table[i].to]=x;  
            DFS1(table[i].to);  
            size[x]+=size[table[i].to];  
            if(size[table[i].to]>size[son[x]])  
                son[x]=table[i].to;  
        }  
}  
  
void DFS2(int x)  
{  
    int i;  
    if(son[fa[x]]==x)  
        top[x]=top[fa[x]];  
    else  
        top[x]=x;  
    pos[x]=++cnt;  
    if(son[x]) DFS2(son[x]);  
    for(i=head[x];i;i=table[i].next)  
        if( table[i].to!=fa[x] && table[i].to!=son[x] )  
            DFS2(table[i].to);  
}  
  
void Reverse(int x,int y)  
{  
    int fx=top[x],fy=top[y];  
    while(fx!=fy)  
    {  
        if(dpt[fx]<dpt[fy])  
            swap(x,y),swap(fx,fy);  
        tree->Reverse(1,n,pos[fx],pos[x]);  
        x=fa[fx];fx=top[x];  
    }  
    if(x==y) return ;  
    if(dpt[x]<dpt[y])  
        swap(x,y);  
    tree->Reverse(1,n,pos[son[y]],pos[x]);  
}  
  
int Get_Sum(int x,int y)  
{  
    int re=0,fx=top[x],fy=top[y];  
    while(fx!=fy)  
    {  
        if(dpt[fx]<dpt[fy])  
            swap(x,y),swap(fx,fy);  
        re+=tree->Get_Sum(1,n,pos[fx],pos[x]);  
        x=fa[fx];fx=top[x];  
    }  
    if(x==y) return re;  
    if(dpt[x]<dpt[y])  
        swap(x,y);  
    return re+tree->Get_Sum(1,n,pos[son[y]],pos[x]);  
}  
  
int Get_Max(int x,int y)  
{  
    int re=-1e9,fx=top[x],fy=top[y];  
    while(fx!=fy)  
    {  
        if(dpt[fx]<dpt[fy])  
            swap(x,y),swap(fx,fy);  
        re=max(re,tree->Get_Max(1,n,pos[fx],pos[x]) );  
        x=fa[fx];fx=top[x];  
    }  
    if(x==y) return re;  
    if(dpt[x]<dpt[y])  
        swap(x,y);  
    return max(re,tree->Get_Max(1,n,pos[son[y]],pos[x]) );  
}  
  
int Get_Min(int x,int y)  
{  
    int re=1e9,fx=top[x],fy=top[y];  
    while(fx!=fy)  
    {  
        if(dpt[fx]<dpt[fy])  
            swap(x,y),swap(fx,fy);  
        re=min(re,tree->Get_Min(1,n,pos[fx],pos[x]) );  
        x=fa[fx];fx=top[x];  
    }  
    if(x==y) return re;  
    if(dpt[x]<dpt[y])  
        swap(x,y);  
    return min(re,tree->Get_Min(1,n,pos[son[y]],pos[x]) );  
}  
  
int main()  
{  
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
    int i,x,y,z;  
    char p[10];  
    cin>>n;  
    for(i=1;i<n;i++)  
    {  
        scanf("%d%d%d",&x,&y,&z);  
        ++x;++y;  
        X[i]=x;Y[i]=y;Z[i]=z;  
        Add(x,y,z);  
        Add(y,x,z);  
    }  
    DFS1(1);DFS2(1);  
    for(i=1;i<n;i++)  
    {  
        x=X[i];y=Y[i];  
        a[ pos[dpt[x]>dpt[y]?x:y] ]=Z[i];  
    }  
    tree->Build_Tree(1,n,a);  
    cin>>m;  
    for(i=1;i<=m;i++)  
    {  
        scanf("%s",p);  
        if(p[0]=='C')  
        {  
            scanf("%d%d",&x,&y);  
            tree->Modify(1,n,pos[dpt[X[x]]>dpt[Y[x]]?X[x]:Y[x]],y);  
        }  
        else if(p[0]=='N')  
        {  
            scanf("%d%d",&x,&y);  
            Reverse(x+1,y+1);  
        }  
        else if(p[0]=='S')  
        {  
            scanf("%d%d",&x,&y);  
            printf("%d\n", Get_Sum(x+1,y+1) );  
        }  
        else if(p[1]=='I')  
        {  
            scanf("%d%d",&x,&y);  
            printf("%d\n", Get_Min(x+1,y+1) );  
        }  
        else  
        {  
            scanf("%d%d",&x,&y);  
            printf("%d\n", Get_Max(x+1,y+1) );  
        }  
    }  
    return 0;  
}  
