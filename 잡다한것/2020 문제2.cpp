#include <iostream>
#include <list>

using namespace std;

bool visited[34];
int N, K;
int cnt = 0;

void func(int k,int sp,list<int> lt) {
    if (k == K) {
        cout << "{ ";
        for (list<int>::iterator it = lt.begin(); it != lt.end(); it++)
            cout << *it << " ";
        cout << "}\n";
        cnt++;
        return;
    }
    for (int i = sp; i <=N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            lt.push_back(i);
            func(k + 1, i,lt);
            lt.pop_back();
            visited[i] = false;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    list<int> lt;
    func(0,1,lt);
    cout << "부분집합의 수 = " << cnt << "\n";

}