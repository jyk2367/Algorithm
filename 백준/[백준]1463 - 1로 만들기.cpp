#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n;
int dp[1000002];
int minimum=0x7fffffff;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <=n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i/2]+1);
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    cout << dp[n];
   
}