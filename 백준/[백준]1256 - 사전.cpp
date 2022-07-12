#include <iostream>
using namespace std;

int N,M,K;
long long dp[102][102];



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = 1;
        }
    }
    for (int i = 1; i <= N;i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = min(dp[i - 1][j] + dp[i][j - 1],(long long)1'000'000'000);
        }
    }
    
    if (dp[N][M] < K) {
        cout << -1 << "\n";
    }
    else { 
        string result = "";
        long long mid=0;
        while (true) {
            if (N == 0) {
                for (int i = 0; i < M; i++) {
                    result += 'z';
                }
                break;
            }
            if (M == 0) {
                for (int i = 0; i < N; i++) {
                    result += 'a';
                }
                break;
            }

            mid = dp[N - 1][M];
            if (K <= mid) {
                result += 'a';
                N -= 1;
            }
            else {
                result += 'z';
                M -= 1;
                K -= mid;
            }
        }
        cout << result << "\n";
    }

    return 0;
}