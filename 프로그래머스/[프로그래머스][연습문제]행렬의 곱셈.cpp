#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int ISIZE=arr1.size();
    int JSIZE=arr2[0].size();
    int KSIZE=arr2.size();//arr1[0].size()==arr2.size()
    
    for(int i=0;i<ISIZE;i++){
        answer.push_back(vector<int>());
        for(int j=0;j<JSIZE;j++){
            int sum=0;
            for(int k=0;k<KSIZE;k++){
                sum+=arr1[i][k]*arr2[k][j];
            }
            answer[i].push_back(sum);
        }
    }
    
    return answer;
}