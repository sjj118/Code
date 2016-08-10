#include<cstdio>
#define LL long long
using namespace std;
int f[100000];
LL ans;
int main(){
	f[1]=1;f[2]=2;ans=2;
	for(int i=3;;++i){
		f[i]=f[i-1]+f[i-2];
		if(f[i]>4000000)break;
		if((f[i]&1)==0)ans+=f[i];
	}
	printf("%d",ans);
}
