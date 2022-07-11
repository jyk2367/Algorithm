#include <iostream>
using namespace std;

int N, K;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    int K2 = N - K;
    int result=1;

    while (N) {
        result *= N;
        N--;
    }
    while (K) {
        result /= K;
        K--;
    }
    while (K2) {
        result /= K2;
        K2--;
    }
    
    cout << result;
    
    
}