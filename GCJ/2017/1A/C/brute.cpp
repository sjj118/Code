#include<cstdio>
#include<algorithm>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=100+3;
int hd,ad,hk,ak,b,d;
int ql,qr,dis[N][N][N][N];
struct State{
	int hd,ad,hk,ak;
	State(){}
	State(int hd,int ad,int hk,int ak):hd(hd),ad(ad),hk(hk),ak(ak){}
	State attack(){return State(std::max(hd-ak,0),ad,std::max(hk-ad,0),ak);}
	State cure(){return State(std::max(::hd-ak,0),ad,hk,ak);}
	State buff(){return State(std::max(hd-ak,0),std::min(ad+b,hk),hk,ak);}
	State debuff(){return State(std::max(hd-std::max(0,ak-d),0),ad,hk,std::max(0,ak-d));}
	bool win(){return hk<=0;}
	bool lose(){return hd<=0;}
}q[N*N*N*N];
int bfs(int hd,int ad,int hk,int ak){
	cls(dis);ql=qr=0;
	q[qr++]=State(hd,ad,hk,ak);
	dis[hd][ad][hk][ak]=1;
	while(ql!=qr){
		State k=q[ql++];
		if(k.win())return dis[k.hd][k.ad][k.hk][k.ak]-1;
		if(k.lose())continue;
		State tmp=k.attack();
		if(!dis[tmp.hd][tmp.ad][tmp.hk][tmp.ak])dis[tmp.hd][tmp.ad][tmp.hk][tmp.ak]=dis[k.hd][k.ad][k.hk][k.ak]+1,q[qr++]=tmp;
		tmp=k.cure();
		if(!dis[tmp.hd][tmp.ad][tmp.hk][tmp.ak])dis[tmp.hd][tmp.ad][tmp.hk][tmp.ak]=dis[k.hd][k.ad][k.hk][k.ak]+1,q[qr++]=tmp;
		tmp=k.buff();
		if(!dis[tmp.hd][tmp.ad][tmp.hk][tmp.ak])dis[tmp.hd][tmp.ad][tmp.hk][tmp.ak]=dis[k.hd][k.ad][k.hk][k.ak]+1,q[qr++]=tmp;
		tmp=k.debuff();
		if(!dis[tmp.hd][tmp.ad][tmp.hk][tmp.ak])dis[tmp.hd][tmp.ad][tmp.hk][tmp.ak]=dis[k.hd][k.ad][k.hk][k.ak]+1,q[qr++]=tmp;
	}
	return 0;
}
int main(){
	int tasknumber;scanf("%d",&tasknumber);
	rep(taskid,1,tasknumber){
		scanf("%d%d%d%d%d%d",&hd,&ad,&hk,&ak,&b,&d);
		int ans=bfs(hd,ad,hk,ak);
		printf("Case #%d: ",taskid);
		if(ans)printf("%d\n",ans);else puts("IMPOSSIBLE");
	}
	return 0;
}
