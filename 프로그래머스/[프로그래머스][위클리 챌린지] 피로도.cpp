#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int answer;
bool visited[10];
void func(int K,int cnt,vector<vector<int>> &dungeons,int fatigue){
    if(K==N||fatigue<0){
        answer=max(answer,cnt);
        return;
    }
    
    for(int i=0;i<N;i++){
        if(!visited[i]&&dungeons[i][0]<=fatigue){
            visited[i]=true;
            func(K+1,cnt+1,dungeons,fatigue-dungeons[i][1]);
            visited[i]=false;
        }
    }
    answer=max(answer,cnt);
    return;
}


int solution(int k, vector<vector<int>> dungeons) {
    N=dungeons.size();
    
    func(0,0,dungeons,k);
    
    return answer;
}