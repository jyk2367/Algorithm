#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[125252];
int solution(vector<vector<int>> triangle) {
    
    int TSIZE=triangle.size();
    dp[0]=triangle[0][0];
    for(int i=1;i<TSIZE;i++){
        for(int j=0;j<triangle[i].size();j++){
            dp[(i*(i+1))/2+j]=max(j-1>=0?dp[((i-1)*i/2)+j-1]+triangle[i][j]:0,j<=triangle[i-1].size()-1?dp[((i-1)*i/2)+j]+triangle[i][j]:0);
        }
    }
    
    int *answer=max_element(dp,dp+125252);
    
    return *answer;
}