#include <cmath>  
#include <cstdio>  
#include <cstring>  
#include<ctime>
#include <iomanip>  
#include <iostream>  
#include <algorithm>  
#define M 100100  
#define EPS 1e-10  
using namespace std;  
typedef long double ld;  
struct Point{  
    ld x,y;  
    Point() {}  
    Point(ld _,ld __):  
        x(_),y(__) {}  
    friend istream& operator >> (istream &_,Point &p)  
    {  
        double x,y;  
        scanf("%lf%lf",&x,&y);  
        p.x=x;p.y=y;  
        return _;  
    }  
    friend Point operator + (const Point &p1,const Point &p2)  
    {  
        return Point(p1.x+p2.x,p1.y+p2.y);  
    }  
    friend Point operator - (const Point &p1,const Point &p2)  
    {  
        return Point(p1.x-p2.x,p1.y-p2.y);  
    }  
    friend ld operator * (const Point &p1,const Point &p2)  
    {  
        return p1.x*p2.y-p1.y*p2.x;  
    }  
    friend Point operator * (const Point &p,ld rate)  
    {  
        return Point(p.x*rate,p.y*rate);  
    }  
    friend ld Distance(const Point &p1,const Point &p2)  
    {  
        return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) ) ;  
    }  
    friend Point Rotate(const Point &p)  
    {  
        return Point(-p.y,p.x);  
    }  
}points[M];  
struct Line{  
    Point p,v;  
    Line() {}  
    Line(const Point &_,const Point &__):  
        p(_),v(__) {}  
    friend Point Get_Intersection(const Line &l1,const Line &l2)  
    {  
        Point u=l1.p-l2.p;  
        ld temp=(l2.v*u)/(l1.v*l2.v);  
        return l1.p+l1.v*temp;  
    }  
};  
struct Circle{  
    Point o;  
    ld r;  
    Circle() {}  
    Circle(const Point &_,ld __):  
        o(_),r(__) {}  
    bool In_Circle(const Point &p)  
    {  
        return Distance(p,o) < r + EPS ;  
    }  
};  
int n,m;  
int cnt=0;
Circle Min_Circle_Cover(int l,int r)  
{  
    static Point points[M];  
    int i,j,k;  
    Circle ans(Point(0,0),0);  
    //memcpy(points+l,::points+l,sizeof(Point)*(r-l+1));  
    for(int i=l;i<=r;++i)points[i]=::points[i];
    random_shuffle(points+l,points+r+1);  
    for(i=l;i<=r;i++)  
        if(!ans.In_Circle(points[i]))  
        {  
            ans=Circle(points[i],0);  
            for(j=l;j<i;j++)  
                if(!ans.In_Circle(points[j]))  
                {  
                    ans=Circle((points[i]+points[j])*0.5,Distance(points[i],points[j])*0.5);  
                    for(k=l;k<j;k++)  
                        if(!ans.In_Circle(points[k]))  
                        {  
                            Line l1=Line((points[i]+points[j])*0.5,Rotate(points[i]-points[j]));  
                            Line l2=Line((points[i]+points[k])*0.5,Rotate(points[i]-points[k]));  
                            Point p=Get_Intersection(l1,l2);  
                            ans=Circle(p,Distance(p,points[i]));  
                            ++cnt;
                        }  
                }  
        }  
    return ans;  
}  
int Extend(int pos,ld limit)  
{  
    int i;  
    for(i=1;;i=min(i<<1,n-pos+1))  
    {  
        if(Min_Circle_Cover(pos,pos+i-1).r>limit+EPS)  
            break;  
        if(i==n-pos+1) return n;  
    }  
    int l=pos+(i>>1)-1,r=pos+i-1;  
    while(l+1<r)  
    {  
        int mid=l+r>>1;  
        if(Min_Circle_Cover(pos,mid).r<limit+EPS)  
            l=mid;  
        else  
            r=mid;  
    }  
    return l;  
}  
bool Judge(ld limit)  
{  
    int i,last,cnt=0;  
    for(i=1;i<=n;i=last+1)  
    {  
        if(++cnt==m+1)  
            return false;  
        last=Extend(i,limit);  
    }  
    return true;  
}  
ld Bisection()  
{  
    ld l=0,r=Min_Circle_Cover(1,n).r;  
    int cout=0;
    while(r-l>EPS)  
    {  
        ld mid=(l+r)/2;  
        if( Judge(mid) )  
            r=mid;  
        else  
            l=mid;  
            cerr<<++cout<<endl;
    }  
    return r;  
}  
void Output(double limit)  
{  
    static Point stack[M];  
    int i,last,top=0;  
    for(i=1;i<=n;i=last+1)  
    {  
        last=Extend(i,limit);  
        stack[++top]=Min_Circle_Cover(i,last).o;  
    }  
    cout<<top<<endl;  
    for(i=1;i<=top;i++)  
        printf("%.15lf %.15lf\n",(double)stack[i].x,(double)stack[i].y);  
}  
int main()  
{  
	freopen("wyk10b.in","r",stdin); 
    int i;  
    cin>>n>>m;  
    for(i=1;i<=n;i++)  
        cin>>points[i];  
    for(int i=1;i<=10000000;++i){
    	Line l1=Line((points[1]+points[2])*0.5,Rotate(points[1]-points[2]));  
        Line l2=Line((points[1]+points[3])*0.5,Rotate(points[1]-points[3]));  
        Point p=Get_Intersection(l1,l2);  
        Circle(p,Distance(p,points[1]));  
    }
    //for(int i=1;i<=100;++i)Min_Circle_Cover(1,n);
    /*ld ans=Bisection();  
    cout<<fixed<<setprecision(15)<<ans<<endl;  
    Output(ans+EPS);  
    cerr<<cnt<<endl;*/
    return 0;  
} 
