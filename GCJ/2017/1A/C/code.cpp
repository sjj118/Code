#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
const LL inf=1e18;
inline void dn(LL&x,LL y){if(y<x)x=y;}
int hd,ad,hk,ak,b,d;
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
};
LL calc(int de,int bu){
	int ret=0;
	State st(::hd,::ad,::hk,::ak);
	rep(i,1,de){
		if(st.debuff().lose()){
			++ret;st=st.cure();
			if(st.debuff().lose())return inf;
		}
		++ret;st=st.debuff();
	}
	rep(i,1,bu){
		if(st.buff().lose()){
			++ret;st=st.cure();
			if(st.buff().lose())return inf;
		}
		++ret;st=st.buff();
	}
	while(!st.win()){
		if(st.attack().win())return ret+1;
		if(st.attack().lose()){
			++ret;st=st.cure();
			if(st.attack().win())return ret+1;
			if(st.attack().lose())return inf;
		}
		++ret;st=st.attack();
	}
	return ret;
}
LL work(int de){
	LL ret=inf;
	int l=0,r=hk;
	while(r-l>6){
		int d=(r-l)/3;
		int m1=l+d,m2=r-d;
		LL w1=calc(de,m1),w2=calc(de,m2);
		dn(ret,w1);dn(ret,w2);
		if(w1<w2)r=m2;else l=m1;
	}
	rep(i,l,r)dn(ret,calc(de,i));
	return ret;
}
int main(){
	int tasknumber;scanf("%d",&tasknumber);
	rep(taskid,1,tasknumber){
		scanf("%d%d%d%d%d%d",&hd,&ad,&hk,&ak,&b,&d);
		LL ans=inf;
		//rep(i,0,ak)rep(j,0,hk)dn(ans,calc(i,j));
		int l=0,r=std::min((LL)ak,work(0));
		while(r-l>6){
			int d=(r-l)/3;
			int m1=l+d,m2=r-d;
			LL w1=work(m1),w2=work(m2);
			dn(ans,w1);dn(ans,w2);
			if(w1<w2)r=m2;else l=m1;
		}
		rep(i,l,r)dn(ans,work(i));
		printf("Case #%d: ",taskid);
		if(ans==inf)puts("IMPOSSIBLE");else printf("%lld\n",ans);
	}
	return 0;
}
