#include<cstdio>

inline int countsg(int x,int y){
	if((x&1)&&(y&1))return 0;
	return countsg((x+1)/2,(y+1)/2)+1;
}
int t,n,ans;
inline bool isNum(char c){
	return c>='0'&&c<='9';
}
inline int read(){
	int x=0;
	char c=getchar();
	while(!isNum(c))c=getchar();
	while(isNum(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main(){
	t=read();
	while(t--){
		n=read();
		ans=0;
		int x,y;
		for(int i=1;i<=n>>1;++i){
			x=read();y=read();
			ans^=countsg(x,y);
		}
		if(ans)puts("YES");else puts("NO");
	}
	return 0;
}
