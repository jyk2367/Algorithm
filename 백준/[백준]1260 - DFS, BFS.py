class Graph:
    def __init__(self,N,M,V):
        self.N=N
        self.M=M
        self.V=V
        self.matrix=[ [0 for _ in range(N)] for _ in range(N)]
        self.visited=[False for _ in range(N)]
        self.points=[]
    
    def link(self, i,j):
        self.matrix[i-1][j-1]=1
        self.matrix[j-1][i-1]=1

    def dfs(self,now):
        
        self.visited[now]=True
        self.points.append(now+1)
        
        for next in range(self.N):
            if self.visited[next]==True:
                continue
            if self.matrix[now][next]==0:
                continue
            self.dfs(next)

    def reset(self):
        self.visited=[False for _ in range(N)]
        self.points=[]

    def bfs(self,NOW):
        now=NOW
        L=[]
        L.append(now)
        self.visited[now]=True
        self.points.append(now+1)

        while(len(L)>0):
            now=L.pop(0)
            
            for next in range(self.N):
                if self.visited[next]==True:
                    continue
                if self.matrix[now][next]==0:
                    continue
                self.visited[next]=True
                self.points.append(next+1)
                L.append(next)
                

            
            
N,M,V=map(int,input().split())
g=Graph(N,M,V)
L=[]
for i in range(M):
    L.append(list(map(int,input().split())))

for l in L:
    g.link(l[0],l[1])

g.dfs(V-1)
for i in g.points:
    print(i,end=" ")
g.reset()
print()
g.bfs(V-1)
for i in g.points:
    print(i,end=" ")
