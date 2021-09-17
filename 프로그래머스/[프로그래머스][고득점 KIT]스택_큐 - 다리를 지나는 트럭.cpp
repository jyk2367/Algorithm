#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int max_weight, vector<int> truck_weights) {
    int answer = 0;
    int avail_weight=max_weight;
    queue<int> q;
    vector<pair<int,int>> crossing;
    vector<int> crossed;
    
    for(int i=0;i<truck_weights.size();i++){
        q.push(truck_weights[i]);
    }
    
    while(crossed.size()!=truck_weights.size()){
        
        if(!q.empty()&&crossing.size()==0){
            int weight=q.front();
            q.pop();
            avail_weight-=weight;
            crossing.push_back({0,weight}); 
        }
        else if(!q.empty()&&avail_weight>=q.front()){
            int weight=q.front();
            q.pop();
            avail_weight-=weight;
            crossing.push_back({0,weight});
        }
        
        for(int i=0;i<crossing.size();i++){
            crossing[i].first++;
        }

        if(!crossing.empty()&&(crossing[0].first==bridge_length)){
            crossed.push_back(crossing[0].second);
            avail_weight+=crossing[0].second;
            crossing.erase(crossing.begin());
        }

        answer++;
    }
    
    return answer+1;
}