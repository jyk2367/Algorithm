#include <iostream>
using namespace std;

int N, M;
struct Node {
    int parent;
    int weight;
};

Node mtrx[100'002];

int Find(int a) {
    if (mtrx[a].parent == a)
        return a;
    else {
        int parent = Find(mtrx[a].parent);
        mtrx[a].weight += mtrx[mtrx[a].parent].weight;//오류 : mtrx[a].weight += mtrx[parent].weight;
        mtrx[a].parent = parent;
        return mtrx[a].parent;
    }
}
void Union(int a, int b, int w) {
    int a_Parent = Find(a);
    int b_Parent = Find(b);

    if (a_Parent == b_Parent)
        return;

    //B는 A의 소속으로 변경된다 + B는 A보다 W만큼 더 무겁다
    mtrx[b_Parent].weight = mtrx[a].weight - mtrx[b].weight + w;
    mtrx[b_Parent].parent = a_Parent;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;

        for (int i = 1; i <= N; i++) {
            mtrx[i].parent = i;
            mtrx[i].weight = 0;
        }
         
        while (M-- > 0) {
            char op;
            int a, b, w;
            cin >> op;
            if (op == '!') {
                cin >> a >> b >> w;
                if (a > b) {
                    swap(a, b);
                    w = -w;
                }
                Union(a, b, w);
            }
            else {
                cin >> a >> b;
                int a_Parent = Find(a);
                int b_Parent = Find(b);

                if (a_Parent != b_Parent) {
                    cout << "UNKNOWN" << "\n";
                }
                else {
                    cout << mtrx[b].weight - mtrx[a].weight << "\n";
                }

            }
        }
    }

    return 0;
}