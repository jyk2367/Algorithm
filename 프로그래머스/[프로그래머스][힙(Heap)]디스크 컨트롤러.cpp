#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct comp{
    bool operator()(vector<int> v1,vector<int> v2){
        return v1[1]>v2[1];
    }
};

bool compare(const vector<int> &v1,const vector<int> &v2){
    return v1[0]<v2[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>,vector<vector<int>>,comp> jobqueue;
    
    sort(jobs.begin(),jobs.end(),compare);
    
    int jlen=jobs.size();
    int i=0;
    int currentTime=0;
    
    while(i<jlen||!jobqueue.empty()){
        if(i<jlen&&currentTime>=jobs[i][0]){
            jobqueue.push(jobs[i++]);
            continue;
        }
        if(!jobqueue.empty()){
            currentTime+=jobqueue.top()[1];
            answer+=currentTime-jobqueue.top()[0];
            jobqueue.pop();
        }
        else{
            currentTime=jobs[i][0];
        }
    }
    
    answer/=jlen;
    
    return answer;
}