#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;
//dist_cnt[거리]=개수
unordered_map<int,vector<int>> hm;
//현재 vector에 저장되어 있는곳에 이미 들린적이 있는지 판단하기 위해 사용
bool visited[20002];
//vector에 다음 들릴 곳들을 저장할 때 중복되는 노드들을 피하기 위해 사용
bool visited2[20002];
int answer;


void func(int sp){
    queue<vector<int>> q;
    
    //1부터 시작(거리 0 방문 이미함)
    visited[sp]=true;
    visited2[sp]=true;
    
    q.push(hm[sp]);
    
    while(!q.empty()){
        //vector로 한번에 방문한애들 한번에 처리
        vector<int> now=q.front();
        vector<int> temp;
        int NSIZE=now.size();
        q.pop();
        
        
        for(int i=0;i<NSIZE;i++){
            //방문하지 않은 곳이였다면 전부 방문처리+거리설정
            if(!visited[now[i]]){
                visited[now[i]]=true;
                visited2[now[i]]=true;
            }
        }
        for(int i=0;i<NSIZE;i++){
            //이번 now 벡터와 연결된 놈들을 담은 vector를 queue에 넣어야함
            int HMSIZE=hm[now[i]].size();
            for(int j=0;j<HMSIZE;j++){
                if(!visited[hm[now[i]][j]]&&!visited2[hm[now[i]][j]]){
                    visited2[hm[now[i]][j]]=true;
                    temp.push_back(hm[now[i]][j]);
                }
            }
        }
        
        if(!temp.empty()){
            q.push(temp);
            answer=temp.size();
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    for(vector<int> e:edge){
        hm[e[0]].push_back(e[1]);
        hm[e[1]].push_back(e[0]);
    }
    
    func(1);
    
    return answer;
}