
/*
BOTTLE checker  zzq
Please keep in mind that
the judge used by the problem
is actually stricter
请注意题目中实际使用的spj比这个严格
Usage: input problem name in the first line.
       input data number to test in the second line.
	   (0 for hand)
用法：第一行输你要测试的程序名（同一目录下就不用输路径了）
      第二行输要测试的测试点名字（手玩的话第二行输0就行） 
*/
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define M 10001234
#define MAX 10000000
int maxn[M],wat[M];
char f1[2333333];
typedef vector<int> vi;
#define pb push_back
vi test(vi inp)
{
	int an=0,cnt=0,id=0;
	vi ans;
	char buf[233];
	FILE* fp=fopen(f1,"r");
	while(fscanf(fp,"%s",buf)!=EOF)
	{
		++cnt;
		if(cnt>MAX)
		{
			puts("Too many lines!");
			exit(-1);
		}
		switch(buf[0])
		{
			int x,s,a,b,dr;
			case 'I':
				if(id==inp.size())
				{
					puts("Nothing to input!");
					exit(-1);
				}
				x=inp[id++];
				++an; maxn[an]=wat[an]=x;
				break;
			case 'F':
				fscanf(fp,"%d",&s);
				wat[s]=maxn[s]; break;
			case 'E':
				fscanf(fp,"%d",&s);
				wat[s]=0; break;
			case 'C':
				fscanf(fp,"%d",&s);
				++an; maxn[an]=s; wat[an]=0; break;
			case 'M':
				fscanf(fp,"%d",&s);
				++an; maxn[an]=wat[s]; wat[an]=0; break;
			case 'T':
				fscanf(fp,"%d%d",&a,&b);
				dr=min(maxn[b]-wat[b],wat[a]);
				wat[a]-=dr; wat[b]+=dr; break;
			case 'O':
				fscanf(fp,"%d",&s);
				ans.pb(wat[s]); break;
			case 'K':
				fscanf(fp,"%d%d",&a,&b);
				if((long long)maxn[a]*maxn[b]>1000000000)
				{
					puts("K exceed 10^9");
					exit(-1);
				}
				++an; maxn[an]=maxn[a]*maxn[b]; wat[an]=0; break;
			default:
			puts("Wrong option!");
			exit(-1);
		}
	}
	fclose(fp);
	return ans;
}
void hand()
{
	char buf[233];
	int an=0,cnt=0;
	FILE* fp=fopen(f1,"r");
	while(fscanf(fp,"%s",buf)!=EOF)
	{
		++cnt;
		if(cnt>MAX)
		{
			puts("Too many lines!");
			exit(-1);
		}
		switch(buf[0])
		{
			int x,s,a,b,dr;
			case 'I':
				scanf("%d",&x);
				++an; maxn[an]=wat[an]=x;
				break;
			case 'F':
				fscanf(fp,"%d",&s);
				wat[s]=maxn[s]; break;
			case 'E':
				fscanf(fp,"%d",&s);
				wat[s]=0; break;
			case 'C':
				fscanf(fp,"%d",&s);
				++an; maxn[an]=s; wat[an]=0; break;
			case 'M':
				fscanf(fp,"%d",&s);
				++an; maxn[an]=wat[s]; wat[an]=0; break;
			case 'T':
				fscanf(fp,"%d%d",&a,&b);
				dr=min(maxn[b]-wat[b],wat[a]);
				wat[a]-=dr; wat[b]+=dr; break;
			case 'O':
				fscanf(fp,"%d",&s);
				printf("%d\n",wat[s]); break;
			case 'K':
				fscanf(fp,"%d%d",&a,&b);
				if((long long)maxn[a]*maxn[b]>1000000000)
				{
					puts("K exceed 10^9");
					exit(-1);
				}
				++an; maxn[an]=maxn[a]*maxn[b]; wat[an]=0; break;
			default:
			puts("Wrong option!");
			exit(-1);
		}
	}
	fclose(fp);
}
int ran()
{
	int x=0;
	for(int i=1;i<=10;i++) x=x*23333+rand();
	if(x<0) x=-x;
	return x;
}
#define S30 for(int S=1;S<=30;S++)
void test(int p)
{
	if(p==1)
	{
		S30
		{
			int a=ran()%100001,b=ran()%100001;
			printf("Test %d\n",S);
			vi inp; inp.pb(a); inp.pb(b);
			vi ans; ans.pb(a+b);
			vi op=test(inp);
			if(op!=ans)
			{
				printf("WA on test %d\n",S);
				exit(-1);
			}
		}
		puts("OK");
	}
	else if(p==2)
	{
		S30
		{
			int a=ran()%100001,b=ran()%100001;
			printf("Test %d\n",S);
			vi inp; inp.pb(a); inp.pb(b);
			vi ans; ans.pb(abs(a-b));
			vi op=test(inp);
			if(op!=ans)
			{
				printf("WA on test %d\n",S);
				exit(-1);
			}
		}
		puts("OK");
	}
	else if(p==3)
	{
		S30
		{
			int a=ran()%100001,b=ran()%100001;
			printf("Test %d\n",S);
			vi inp; inp.pb(a); inp.pb(b);
			vi ans; ans.pb(max(a,b));
			vi op=test(inp);
			if(op!=ans)
			{
				printf("WA on test %d\n",S);
				cerr<<op[0]<<endl<<ans[0]<<endl;
				exit(-1);
			}
		}
		puts("OK");
	}
	else if(p==4)
	{
		S30
		{
			int a=ran()%1000+1,b=ran()%1000+1;
			printf("Test %d\n",S);
			vi inp; inp.pb(a); inp.pb(b);
			vi ans; ans.pb(__gcd(a,b));
			vi op=test(inp);
			if(op!=ans)
			{
				printf("WA on test %d\n",S);
				exit(-1);
			}
		}
		puts("OK");
	}
	else if(p==5)
	{
		S30
		{
			int a=ran()%100001;
			printf("Test %d\n",S);
			vi inp; inp.pb(a);
			vi ans;
			for(int i=0;i<32;i++) ans.push_back(a&1), a>>=1;
			reverse(ans.begin(),ans.end());
			vi op=test(inp);
			if(op!=ans)
			{
				printf("WA on test %d\n",S);
				exit(-1);
			}
		}
		puts("OK");
	}
	else if(p==6)
	{
		S30
		{
			int a=ran()%1001,b=ran()%1001;
			printf("Test %d\n",S);
			vi inp; inp.pb(a); inp.pb(b);
			vi ans; ans.pb(a*b);
			vi op=test(inp);
			if(op!=ans)
			{
				printf("WA on test %d\n",S);
				exit(-1);
			}
		}
		puts("OK");
	}
	else if(p==7)
	{
		S30
		{
			int a=ran()%100001,b=ran()%100001;
			printf("Test %d\n",S);
			vi inp; inp.pb(a); inp.pb(b);
			vi ans; ans.pb(a^b);
			vi op=test(inp);
			if(op!=ans)
			{
				printf("WA on test %d\n",S);
				exit(-1);
			}
		}
		puts("OK");
	}
	else if(p==8)
	{
		S30
		{
			int a=ran()%10000+1;
			printf("Test %d\n",S);
			vi inp; inp.pb(a);
			vi ans; ans.pb(a/10);
			vi op=test(inp);
			if(op!=ans)
			{
				printf("WA on test %d\n",S);
				exit(-1);
			}
		}
		puts("OK");
	}
	else if(p==9)
	{
		S30
		{
			int a=ran()%100001,b=ran()%100001;
			printf("Test %d\n",S);
			vi inp; inp.pb(a); inp.pb(b);
			vi ans; ans.pb(a*(long long)b%262144);
			vi op=test(inp);
			if(op!=ans)
			{
				printf("WA on test %d\n",S);
				exit(-1);
			}
		}
		puts("OK");
	}
	else if(p==10)
	{
		S30
		{
			int a=ran()%1000+1,b=(a==1)?(rand()%1000+1):(rand()%int(log(1000000)/log(a))+1);
			printf("Test %d\n",S);
			vi inp; inp.pb(a); inp.pb(b);
			int qq=1;
			{
			int bb=b,aa=a;
			while(bb)
			{
				if(bb&1) qq=qq*aa;
				aa=aa*aa; bb>>=1;
			}
			}
			vi ans; ans.pb(qq);
			vi op=test(inp);
			if(op!=ans)
			{
				printf("WA on test %d\n",S);
				exit(-1);
			}
		}
		puts("OK");
	}
}
int main()
{
	srand(time(0));
	printf("Input program name: ");
	gets(f1);
	printf("Input test no: ");
	int s; scanf("%d",&s);
	if(s==0) hand();
	test(s);
}
