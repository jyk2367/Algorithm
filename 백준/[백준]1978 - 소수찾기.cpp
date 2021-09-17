#include <iostream>
using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int cnt = 0;
    cin >> N;
    while (N--) {
        int num;
        cin >> num;
        if (num == 1)
            continue;
        bool state = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                state = 0;
                break;
            }
        }
        cnt += state;
    }

    cout << cnt;
}