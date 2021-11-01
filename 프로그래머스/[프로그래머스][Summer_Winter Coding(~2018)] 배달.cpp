#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct comp{
    bool operator()(const pair<int,int> &p1,const pair<int,int> &p2){
        return p1.second>p2.second;
    }
};

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int dist[52]; // 1번 마을에서 떨어진 거리
    int edge[52][52];// 마을간 거리
    bool visited[52];
        
    for(int i=1;i<=N;i++){
        dist[i]=0x7fffffff;
        visited[i]=false;
        for(int j=1;j<=N;j++){
            edge[i][j]=0x7fffffff;
        }
    }
    
    for(vector<int> r:road){
        edge[r[0]][r[1]]=min(edge[r[0]][r[1]],r[2]);
        edge[r[1]][r[0]]=min(edge[r[1]][r[0]],r[2]);
    }
    
    dist[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
    pq.push({1,dist[1]});
    while(!pq.empty()){
        pair<int,int> now=pq.top();
        pq.pop();
        if(visited[now.first])
            continue;
        visited[now.first]=true;
        cout<<now.first<<" "<<now.second<<"\n";
        for(int i=1;i<=N;i++){
            if(edge[now.first][i]==0x7fffffff||visited[i])
                continue;
            if(now.second+edge[now.first][i]<dist[i]){
                pq.push({i,now.second+edge[now.first][i]});
                dist[i]=now.second+edge[now.first][i];
            }
            else{
                pq.push({i,dist[i]});
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        if(dist[i]<=K)
            answer++;
    }
    

    return answer;
}