s1=str(input())
s2=str(input())
n=len(s1)
m=len(s2)
a=[0]*n
b=[0]*m
for i in range(0,n-2):
    if s1[i]=='1':
        a[i]=a[i]+1
    a[i+1]+=a[i]
    a[i+2]+=a[i];
if(s1[n-2]=='1'):
    a[n-2]+=1
if(s1[n-1]=='1'):
    a[n-1]+=1
for i in range(0,m-2):
    if s2[i]=='1':
        ++b[i];
    b[i+1]+=b[i]
    b[i+2]+=b[i];
if(s2[m-2]=='1'):
    b[m-2]+=1
if(s2[m-1]=='1'):
    b[m-1]+=1
t1=5*pow(a[n-2]-b[m-2],2)
t2=pow(2*(b[m-1]-a[n-1])-(a[n-2]-b[m-2]),2)
if(t1<t2):
    print("<")
if(t1==t2):
    print("=")
if(t1>t2):
    print(">")
