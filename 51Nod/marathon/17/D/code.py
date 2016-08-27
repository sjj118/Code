import math
hash={}
def getf(n):
    if(n==0):
        return 0
    if(n==1):
        return 1
    if n in hash:
        return hash[n]
    if n%2==0:
        hash[n]=2*getf(n//2)+2*getf(n//2-1)-(n//2)*(n//2+1)//2+n*(n//2)*((n//2)+1)
    else:
        hash[n]=4*getf(n//2)-(n//2*(n//2+1))//2+n*(n+1)//2*(n+1)//2
    return hash[n]
n=int(input())
print(getf(n))
