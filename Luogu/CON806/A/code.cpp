#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=22,maxl=400;
int n,b,m;
struct Name{
	char s[maxl];
}name[maxn];
struct Sentence{
	char s[maxl];
};
const int ha=2333333;
struct Hash{
	int tot,head[ha],val[maxn],next[maxn];
	Name key[maxn];
	int change(Name s){
		int l=strlen(s.s),k=0;
		rep(i,0,l-1)k=(k*13131ll+s.s[i])%ha;
		return k;
	}
	void ins(Name s,int v){
		int k=change(s);
		key[++tot]=s;val[tot]=v;next[tot]=head[k];head[k]=tot;
	}
	int find(Name s){
		int k=change(s);
		for(int p=head[k];p;p=next[p])if(!strcmp(s.s,key[p].s))return val[p];
		return 0;
	}
}hash;
struct Evidence{
	int from,to,type,is;
	Evidence(int f=0,int t=0,int ty=0,int i=0){from=f;to=t;type=ty;is=i;}
};
struct Linkmap{
	int tot,head[maxn],next[maxn];
	Evidence val[maxn];
	void ins(int a,Evidence b){val[++tot]=b;next[tot]=head[a];head[a]=tot;}
}lp;
void deal(int sp,int who,Sentence sen){
	if(!strcmp(sen.s," am killer.")){
		if(who==sp)lp.ins(sp,Evidence(sp,sp,0,1));
	}else if(!strcmp(sen.s," am not killer.")){
		if(who==sp)lp.ins(sp,Evidence(sp,sp,0,0));
	}else if(!strcmp(sen.s," is killer.")){
		if(who)lp.ins(sp,Evidence(sp,who,0,1));
	}else if(!strcmp(sen.s," is not killer.")){
		if(who)lp.ins(sp,Evidence(sp,who,0,0));
	}else if(!strcmp(sen.s," smiled.")){
		if(who==sp)lp.ins(sp,Evidence(sp,sp,1,1));
	}else if(!strcmp(sen.s," didn't smile.")){
		if(who==sp)lp.ins(sp,Evidence(sp,sp,1,0));
	}else if(!strcmp(sen.s," smiled.")){
		if(who)lp.ins(sp,Evidence(sp,who,1,0));
	}else if(!strcmp(sen.s," didn't smile.")){
		if(who)lp.ins(sp,Evidence(sp,who,1,1));
	}
}
bool sel[maxn];
bool posmile[maxn],pokiller[maxn];
bool smile[maxn],killer[maxn];
void solve(){
	rep(i,1,n)smile[i]=killer[i]=2;bool flags=1,flagk=1;
	rep(i,1,n){
		for(int p=lp.head[i];p;p=lp.next[p]){
			if(lp.val[p].type==1){
				if(smile[lp.val[p].to]!=(lp.val[p].is^sel[i]))flags=0;
				smile[lp.val[p].to]=lp.val[p].is^sel[i];
			}else{
				if(killer[lp.val[p].to]!=(lp.val[p].is^sel[i]))flagk=0;
				killer[lp.val[p].to]=lp.val[p].is^sel[i];
			}
		}
	}
	int num0=0,num1=0;
if(flags){
	rep(i,1,n)if(smile[i]==0)++num0;else if(smile[i]==1)++num1;
	if(num0==n-1){
		rep(i,1,n)if(smile[i]!=0)posmile[i]|=1;
	}
	if(num1==1){
		rep(i,1,n)if(smile[i])posmile[i]|=1;
	}
}
if(flagk){
	num0=0,num1=0;
	rep(i,1,n)if(killer[i]==0)++num0;else if(killer[i]==1)++num1;
	if(num0==n-1){
		rep(i,1,n)if(killer[i]!=0)pokiller[i]|=1;
	}
	if(num1==1){
		rep(i,1,n)if(killer[i])pokiller[i]|=1;
	}
}
}
void dfs(int k,int last){
	if(k==b+1){
		solve();
		return;
	}
	rep(i,last+1,n-(b-k))sel[i]=1,dfs(k+1,i),sel[i]=0;
}
int main(){
	scanf("%d%d%d",&n,&b,&m);
	rep(i,1,n){
		scanf("\n%s",name[i].s);
		hash.ins(name[i],i);
	}
	rep(i,1,m){
		Name speaker,who;Sentence senten;
		cls(who.s);cls(speaker.s);cls(senten.s);
		scanf("\n%s: %s",speaker.s,who.s);
		gets(senten.s);
		int people=hash.find(speaker);
		if(people==0)continue;
		int to=hash.find(who);
		if(!strcmp(who.s,"I"))to=people;
		deal(people,to,senten);
	}
	dfs(1,0);
	int num=0,who=0;
	rep(i,1,n)if(pokiller[i])++num,who=i;
	if(num==0)puts("Impossible");
	else if(num>1)puts("Cannot Determine");
	else printf("%s\n",name[who].s);
	num=0,who=0;
	rep(i,1,n)if(posmile[i])++num,who=i;
	if(num==0)puts("Impossible");
	else if(num>1)puts("Cannot Determine");
	else printf("%s\n",name[who].s);
}
