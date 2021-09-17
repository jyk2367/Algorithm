#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> v:commands){
        vector<int> tmp;
        for(int i=v[0]-1;i<v[1];i++){
            tmp.push_back(array[i]);
        }
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[v[2]-1]);
    }
    
    
    return answer;
}