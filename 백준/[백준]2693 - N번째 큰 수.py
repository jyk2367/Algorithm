N=int(input())

MAP=[list(map(int, input().split())) for _ in range(N)]


for i in range(N):
    for j in range(2):
        MAP[i].remove(max(MAP[i]))
    print(max(MAP[i]))