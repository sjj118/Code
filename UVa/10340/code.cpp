#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000

using namespace std;

bool f;

int main(){
	char s[maxn],t[maxn];
	while(scanf("%s%s",s,t)>=0){
		int j=0;
		f=true;
		for(int i=0;i<strlen(s);++i){
			while(j<strlen(t)&&s[i]!=t[j])++j;
			++j;
			if(j>strlen(t)){
				f=false;
				break;
			}
		}
		if(!f)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
} 
