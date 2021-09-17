#include <iostream>
#include <string>

using namespace std;

int n;
int dp[302][2];
int stair[302];



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    stair[0] = 0;
    for (int i = 1; i <=n; i++) {
        cin >> stair[i];
    }

    dp[1][0] = stair[1];
    dp[1][1] = stair[1];
    dp[2][0] = dp[1][0]+stair[2];
    dp[2][1] = +stair[2];
    
    for (int i = 2; i <=n; i++) {
        dp[i][0]=max(dp[i - 2][0] + stair[i], dp[i - 2][1] + stair[i]);
        dp[i][1] = dp[i - 1][0] + stair[i];
    }

    
    cout << max(dp[n][0],dp[n][1]);

}