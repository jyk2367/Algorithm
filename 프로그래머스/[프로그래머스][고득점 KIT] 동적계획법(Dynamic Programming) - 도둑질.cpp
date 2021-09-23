#include <string>
#include <vector>
int dp[1000001];
int dp2[1000001];

using namespace std;
int solution(vector<int> money) {
    int answer = 0;
    int MSIZE=money.size();
    
    //dp : 맨처음부터 시작, 마지막은 선택못함
    dp[0]=money[0];
    dp[1]=money[0];
    //dp2 : 두번째부터 시작
    dp2[0]=0;
    dp2[1]=money[1];
    for(int i=2;i<MSIZE-1;i++){
        dp[i]=max(dp[i-2]+money[i],dp[i-1]);
        dp2[i]=max(dp2[i-2]+money[i],dp2[i-1]);
    }
    dp2[MSIZE-1]=max(dp2[MSIZE-3]+money[MSIZE-1],dp2[MSIZE-2]);
    
    return max(dp[MSIZE-2],dp2[MSIZE-1]);
}