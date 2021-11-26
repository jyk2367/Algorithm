#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

bool matrix[102][102];

int div_bfs(int &n,pair<int,int> p){
    //연결 끊기
    matrix[p.first][p.second]=0;
    matrix[p.second][p.first]=0;
    
    int cnt=0;
    bool visited[102]={0,};
    // p.first에서 bfs
    queue <int> q;
    q.push(p.first);
    visited[p.first]=true;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        cnt++;
        for(int i=1;i<=n;i++){
            if(visited[i])
                continue;
            if(!matrix[now][i])
                continue;
            q.push(i);
            visited[i]=true;
        }
    }
    
    //복구
    matrix[p.first][p.second]=1;
    matrix[p.second][p.first]=1;
    
    return abs((n-cnt)-cnt);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    queue<pair<int,int>> q;
    for(vector<int> w:wires){
        matrix[w[0]][w[1]]=1;
        matrix[w[1]][w[0]]=1;
        q.push({w[0],w[1]});
    }
    
    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        answer=min(answer, div_bfs(n,p));
        if(answer==0)
            break;
    }
        
    return answer;
}