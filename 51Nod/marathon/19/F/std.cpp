    #include <cstdio>  
    #include <cstdlib>  
    #include <cstring>  
    #include <iostream>  
    #include <algorithm>  
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
typedef long long LL;
    const int mo=104857601;  
    using namespace std;  
    struct Coe{  
        LL p[53333+10];  
        Coe operator *(const Coe &b) const;   
    };  
    LL ans[53333+10],h[53333+10],N,k,K[53333+10];  
    LL a[53333+10],b[53333+10];  
    Coe Coe::operator *(const Coe &b) const  
    {  
        Coe c;  
        for (int i=0;i<=k+k;i++) h[i]=0;  
        for (int i=0;i<k;i++)  
            for (int j=0;j<k;j++)  
                (h[i+j]+=p[i]*b.p[j])%=mo;  
        for (int i=k+k-2;i>=k;i--)  
            for (int j=i-1;j>=i-k;j--)  
                (h[j]+=h[i]*K[k-(i-j)])%=mo;  
        for (int i=0;i<k;i++) c.p[i]=h[i];  
        return c;  
    }  
    Coe fgm(int e)  
    {  
        Coe sum,b;  
        for (int i=0;i<k;i++) sum.p[i]=b.p[i]=0;  
        sum.p[0]=1;  
        if (k>1) b.p[1]=1;else b.p[0]=K[0];  
        for (;e;e>>=1) {  
            if (e&1) sum=sum*b;  
            b=b*b;  
        }  
        return sum;  
    }  
LL m;
int n;
    int main()  
    {  
		k=1000;
		scanf("%d%lld",&n,&m);
		int Aa,Bb;
	scanf("%lld%d%d",&a[1],&Aa,&Bb);
    rep(i,2,n)a[i]=(a[i-1]*Aa+Bb)%23333+1;
	rep(i,1,n)++b[k-a[i]];
	rep(i,0,k-2)a[i]=0;a[k-1]=1;
		N=m+k-1;
            for (int i=0;i<=50000;i++) K[i]=0;  
            K[k-1]=b[k-1];  
            for (int i=k-2;i>=0;i--) {  
                K[i]=b[i];  
    //          if ((k-1-i+1+1)&1) K[i]=-K[i];  
    //          if ((k-1-i)&1) K[i]=-K[i];  
            }  
            Coe B=fgm(N-(k-1));  
            for (int i=k;i<=k+k;i++) {  
                a[i]=0;  
                for (int j=i-1;j>=i-k;j--) (a[i]+=a[j]*b[k-(i-j)])%=mo;  
            }  
            for (int i=k-1;i>=0;i--) ans[i]=0;  
            for (int i=0;i<=k-1;i++)  
                for (int j=i;j<=i+k-1;j++) (ans[j-i]+=a[j]*B.p[i]%mo)%=mo;  
            printf("%lld\n",(ans[k-1]%mo+mo)%mo);  
        return 0;  
    }  
