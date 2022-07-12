#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
struct Edge {
    int a;
    int b;
    int c;
    bool operator <(const Edge& e)const {
        return this->c < e.c;
    }
};
Edge edge[100'002];

int group[1001];

int Find(int a) {
    if (group[a] == a) {
        return a;
    }
    else
        return group[a]=Find(group[a]);
}

void Union(int a,int b) {
    int aRoot = Find(a);
    int bRoot = Find(b);
    group[bRoot] = aRoot;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;
    int a, b, c;
    int answer = 0;
    for (int i = 0; i < M; i++) {
        cin >> edge[i].a >> edge[i].b >> edge[i].c;
    }
    
    //sort
    sort(edge, edge + M);

    for (int i = 1; i <= N; i++) {
        group[i] = i;
    }

    for (int i = 0; i < M; i++) {
        //연결 확인 후 안되어 있으면 Union
        if (Find(edge[i].a) != Find(edge[i].b)) {
            Union(edge[i].a, edge[i].b);
            answer += edge[i].c;
        }
    }

    printf("%d\n", answer);
    return 0;
}