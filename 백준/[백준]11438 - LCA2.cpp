#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define NODESIZE 100'002
using namespace std;

int N, M;
int a, b;
vector<int> al[NODESIZE];
int depth[NODESIZE];
bool visited[NODESIZE];
int parent[18][NODESIZE];

int getKthParent(int dif, int x) {
    while (dif > 0) {
        int upper = (int)floor(log2(dif));
        x = parent[upper][x];
        dif -= pow(2, upper);
    }
    return x;
}

int getCommonAncestor(int x, int y) {
    //바로 위 부모가 같다면 return
    if (x == y) {
        return x;
    }
    int answer = 0;
    for (int r = 1; r < 18; r++) {
        int xParent = parent[r][x];
        int yParent = parent[r][y];
        if (xParent != yParent)
            continue;

        answer=getCommonAncestor(parent[r-1][x], parent[r-1][y]);
        break;
    }
    return answer;
}

int LCA(int x, int y) {
    //높이 맞추기
    if (depth[x] < depth[y]) {
        y = getKthParent(depth[y]-depth[x], y);
    }
    else if(depth[x]>depth[y]) {
        x = getKthParent(depth[x] - depth[y], x);
    }
    
    //가장 가까운 공통 조상 찾기
    return getCommonAncestor(x, y);
}

void GetDepth() {
    queue<int> q;
    q.push(1);
    visited[1] = true;
    depth[1] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next : al[now]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                depth[next] = depth[now] + 1;

                //다음 노드(next)의 1번째 부모는 now
                parent[0][next] = now;
            }
        }
    }

    for (int r = 1; r < 18; r++) {
        for (int i = 1; i <= N; i++) {
            parent[r][i] = parent[r - 1][parent[r - 1][i]];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    GetDepth();

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }

    return 0;
}