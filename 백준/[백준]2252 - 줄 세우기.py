from collections import deque
N,M=map(int,input().split())

class Graph:
    def __init__(self,N):
        self.N=N
        self.L=[ [] for _ in range(self.N)]
        self.inDegree=[0 for _ in range(self.N)]
        self.visited=[False for _ in range(self.N)]
        self.result=deque()

    def link(self,i,j):
        self.L[i].append(j)
        self.inDegree[j]+=1
        

    def topologicalSort(self):
        queue=deque()
        for i in range(self.N):
            if self.inDegree[i]==0:
                queue.append(i)

        while queue:
            now=queue.popleft()
            print(now+1)
            for n in self.L[now]:
                self.inDegree[n]-=1
                if self.inDegree[n]==0:
                    queue.append(n)

    def DFS(self,now):
        self.visited[now]=True

        while(len(self.L[now])>0):
            next=self.L[now].pop(0)
            if self.visited[next]==True:
                continue
            self.DFS(next)
        self.result.appendleft(now+1)

        

        

g=Graph(N)

for i in range(M):
    a,b=map(int,input().split())
    g.link(a-1,b-1)


for i in range(N):
    if g.visited[i]==False:
        g.DFS(i)


for i in g.result:
    print(i,end=" ")

#g.topologicalSort()
