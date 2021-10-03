#include <string>
#include <vector>

using namespace std;
bool matrix[102][102];

int solution(int n, vector<vector<int>> results) {
    vector<int> v;
    int answer = 0;
    
    for(vector<int> r:results){
        matrix[r[0]][r[1]]=1;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i][k]&&matrix[k][j])
                    matrix[i][j]=true;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(matrix[i][j]||matrix[j][i])
                cnt++;
        }
        if(cnt==n-1)
            answer++;
    }
    
    
    return answer;
}