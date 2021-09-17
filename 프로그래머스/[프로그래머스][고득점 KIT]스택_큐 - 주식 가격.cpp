#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    queue<int> origin;
    vector<int> v;
    vector<int> answer;
    
    for(int p:prices){
        origin.push(p);
        answer.push_back(0);
    }
    
    while(!origin.empty()){
        int now=origin.front();
        origin.pop();
        
        for(int i=0;i<v.size();i++){
            if(v[i]==-1)
                continue;
            if(now>=v[i])
                answer[i]++;
            else{
                answer[i]+=1;
                v[i]=-1;
            }
        }
        v.push_back(now);
    }
    
    
    return answer;
}