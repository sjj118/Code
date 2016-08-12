#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
const int maxn=5e4+10;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int tmp=0;char c=getchar();while(vaild(c))tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n,a[maxn],ans;
struct Linkmap{
	int tot,head,next[maxn],pre[maxn],val[maxn];
	void clear(){head=tot=0;val[0]=1e9;next[0]=pre[0]=0;}
	void ins(int x){val[++tot]=x;next[tot]=head;pre[head]=tot;head=tot;pre[tot]=0;}
	void work(){
		for(int p=head;p;){
			if(p[pre][val]<=p[next][val]){
				if(val[pre[p]]==1e9)return;
				else{
					p[val]=p[val]+p[pre][val];
					ans+=p[val];
					p[pre][pre][next]=p[next];
					p[next][pre]=p[pre][pre];
					int t=p[pre][pre],pos=p[pre][pre];if(pos==0)pos=p[next];
					while(t[val]<p[val])t=t[pre];
					p[pre]=t;p[next]=t[next];
					t[next][pre]=p;t[next]=p;
					p=pos;
				}
			}else p=p[next];
		}
	}
}lp;
int main(){
	while((n=read())){
		rep(i,1,n)a[i]=read();
		lp.clear();
		per(i,n,1)lp.ins(a[i]);ans=0;
		lp.work();printf("%d\n",ans);
	}
	return 0;
}
