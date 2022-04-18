from sys import stdin

read = stdin.readline
V, S = map(int, read().split())

edge = []
for _ in range(S):
    a,b,c=map(int,input().split())
    edge.append((a,b,c))

edge.sort(key=lambda x:x[2])
parent=[i for i in range(V+1)]


# v1, v2 결합
def union(v1,v2):
    a=find(v1)
    b=find(v2)

    if a>b:
        parent[a]=b
    elif b>a:
        parent[b]=a

# 집합의 root노드로 바꿔주는 함수
def find(v):
    if v==parent[v]:
        return v
    parent[v]=find(parent[v])
    return parent[v]


sum=0
for a,b,v in edge:
    if find(a)!=find(b):
        union(a,b)
        sum+=v
print(sum)