#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int PSIZE=progresses.size();
    for(int i=0;i<PSIZE;i++){
        q.push((99-progresses[i])/speeds[i]+1);
    }
    
    while(!q.empty()){
        int cnt=1;
        int p=q.front();
        q.pop();
        while(!q.empty()&&q.front()<=p){
            q.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}