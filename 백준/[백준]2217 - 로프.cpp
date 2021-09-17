#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;

int *rope;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    rope = new int[N];
    
    for (int i = 0; i <N; i++) {
        cin >> rope[i];
    }
    sort(rope,rope+N);

    int maximum = rope[N - 1];
    for (int i = 2; i <=N; i++) {
        maximum = max(maximum, rope[N - i] * i);
    }
    cout << maximum;
}