#include <iostream>
using namespace std;

int T,M,N,x,y;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b%a,a);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> M >> N >> x >> y;
        bool state = 0;
        if (x == M)
            x = 0;
        if (y == N)
            y = 0;
        int l = lcm(M,N);

        
        for (int j = x; j<=l; j+=M) {
            if (j == 0)
                continue;
            if (j % N == y) {
                cout << j << "\n";
                state = 1;
                break;
            }
        }
        if (!state)
            cout << -1 << "\n";

    }
    
}