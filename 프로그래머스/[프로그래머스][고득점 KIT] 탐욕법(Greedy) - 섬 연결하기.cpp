#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
vector<pair<int,int>> graph[102];
bool visited[102];
int answer;

struct comp{
    bool operator()(const pair<int,int> &p1,const pair<int,int> &p2){
        return p1.second>p2.second;
    }
};

void func(int k){
    //지나간 점
    visited[k]=true;
    
    //현재 점에서 갈 수 있는 모든 지점 저장
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
    for(int i=0;i<graph[k].size();i++){
        pq.push(graph[k][i]);
    }
    
    //가장 cost작은 점 선택 
    while(!pq.empty()){
        pair<int,int> p=pq.top();
        pq.pop();
        
        //이미 지나간 곳이라면 continue
        if(visited[p.first])
            continue;
        
        //아니라면 갈수 있는 곳이므로
        //현재 cost를 결과값에 더하기+방문
        visited[p.first]=true;
        answer+=p.second;
        //그 노드에서 갈수있는 모든 값들 pq에 삽입
        for(int i=0;i<graph[p.first].size();i++){
            pq.push(graph[p.first][i]);
        }
    }
}

int solution(int n, vector<vector<int>> costs) {
    
    for(vector<int> cost:costs){
        graph[cost[0]].push_back({cost[1],cost[2]});
        graph[cost[1]].push_back({cost[0],cost[2]});
    }
    
    func(0);
    
    
    return answer;
}