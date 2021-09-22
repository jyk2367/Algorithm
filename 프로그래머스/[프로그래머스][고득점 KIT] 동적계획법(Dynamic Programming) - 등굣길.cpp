#include <string>
#include <vector>
#include <algorithm>

using namespace std;
long long dp[102][102];

bool comp(const vector<int> &p1,const vector<int> &p2){
    if(p1[1]==p2[1])
        return p1[0]<p2[0];
    return p1[1]<p2[1];
} 

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    sort(puddles.begin(),puddles.end(),comp);
    int index=0;
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0){
                dp[i][j]=1;
                continue;
            }
            if(index<puddles.size()&&puddles[index][0]==j&&puddles[index][1]==i){
                dp[i][j]=0;
                index++;
            }
            else if(j==1){
                dp[i][j]=dp[i-1][j];
            }
            else if(i==1){
                dp[i][j]=dp[i][j-1];
            }
            else
                dp[i][j]=(dp[i][j-1]+dp[i-1][j])%1000000007;
        }
    }
    
    return dp[n][m];
}