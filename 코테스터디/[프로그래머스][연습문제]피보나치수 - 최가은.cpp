#include <string>
#include <vector>
using namespace std;

int fibo(int n){
    int dp[100002];
    dp[0]=0;
    dp[1]=1;
    for(int i = 2; i <= n; i++)
        dp[i] = (dp[i-1] + dp[i-2])%1234567;
    return dp[n];
}

int solution(int n) {
    int answer=fibo(n);
    return answer;
}