from sys import stdout,stdin
input=stdin.readline
print=stdout.write

def gcd(m,n):
    if n==0:
        return m
    if m%n==0:
        return n
    else:
        return gcd(n,m%n)


a,b=map(int,input().split())

if(a<b):
    tmp=a
    a=b
    b=tmp

L=list()

if(a==b):
    print(str(a)+"\n")
    print(str(a))
else:
    GCD=gcd(a,b)
    print(str(GCD)+"\n")
    print(str(int(a*b/GCD)))