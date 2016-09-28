#include<bitset>  
#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
#define M 10000001  
using namespace std;  
typedef long long ll;  
bool not_prime[M+100];  
ll prime[500500],ans[M+100],fac[M+100],rev[M+100];  
int n,m,p,T,tot;  
void Linear_Shaker()  
{  
    ll i,j;  
    for(i=2;i<=M;i++)  
    {  
        if(!not_prime[i])  
            prime[++tot]=i;  
        for(j=1;j<=tot&&prime[j]*i<=M;j++)  
        {  
            not_prime[prime[j]*i]=1;  
            if(i%prime[j]==0)  
                break;  
        }  
    }  
    fac[1]=1;  
    for(i=2;i<=M;i++)  
        fac[i]=fac[i-1]*i%p;  
    rev[1]=1;  
    for(i=2;i<=M&&i<p;i++)  
        rev[i]=(p-p/i)*rev[p%i]%p;  
    ans[1]=1;  
    for(i=2;i<=M;i++)  
    {  
        if(!not_prime[i])  
            ans[i]=ans[i-1]*(i-1)%p*rev[i%p]%p;  
        else  
            ans[i]=ans[i-1];  
    }  
}  
int main()  
{  
    scanf("%d%d",&T,&p);  
    Linear_Shaker();  
    for(int i=1;i<=T;++i)  
    {  
        scanf("%d%d",&n,&m);  
        printf("%d\n",fac[n]*ans[m]%p);  
    }  
}  
