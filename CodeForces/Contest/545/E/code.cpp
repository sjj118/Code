#include<cstdio>

using namespace std;

typedef long long LL;

const int N=300000+10;

int m;
struct Cars{
    LL idx,len,b,s;
    Cars()=default;
    Cars(LL idx,LL len,LL b,LL s):idx(idx),len(len),b(b),s(s){}
}stk[N];
int top;
void push_front(LL x){
    x+=stk[top].idx+stk[top].len;
    stk[top=1]=Cars(0,x,0,0);
}
void merge(){
    --top;
    stk[top].len+=stk[top+1].len;
    stk[top].b+=stk[top+1].b;
    stk[top].s+=stk[top+1].s;
}
void push_back(LL x){
    if(top&&stk[top].b+stk[top].s==0){stk[top].len+=x;return;}
    while(top>=2&&(stk[top-1].b+stk[top-1].s*stk[top-1].idx-1)/stk[top-1].len+1-stk[top].s<=(stk[top].b+stk[top].s*stk[top].idx-1)/stk[top].len+1)merge();
    int idx=stk[top].idx+stk[top].len;
    stk[++top]=Cars(idx,x,0,0);
}
void recalc(LL b,LL s){
    stk[top].b+=b;
    stk[top].s+=s;
    while(top>=2&&stk[top-1].b+stk[top-1].s*stk[top-1].idx<=stk[top].s*stk[top-1].len)merge();
}

int main(){
    int n;
    scanf("%d%d",&n,&m);
    push_front(n);
    while(m--){
        int op;scanf("%d",&op);
        if(op==1){
            int k;scanf("%d",&k);
            push_front(k);
        }
        if(op==2){
            int k;scanf("%d",&k);
            push_back(k);
        }
        if(op==3){
            int b,s;scanf("%d%d",&b,&s);
            recalc(b,s);
        }
        printf("%lld %lld\n",1+stk[top].idx,stk[top].b+stk[top].idx*stk[top].s);
    }
    return 0;
}
