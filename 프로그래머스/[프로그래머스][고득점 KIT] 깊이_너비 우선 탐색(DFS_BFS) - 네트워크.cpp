#include <string>
#include <vector>
#include <queue>

using namespace std;
int cnt,N;
vector<vector<int>> cpt;
bool visited[202];

void bfs(int k){
    cnt++;
    queue<int> q;
    visited[k]=true;
    for(int i=0;i<N;i++){
        if(cpt[k][i]==1 && k!=i && !visited[i])
            q.push(i);
    }
    
    while(!q.empty()){
        int next=q.front();
        q.pop();
        visited[next]=true;
        for(int i=0;i<N;i++){
            if(cpt[next][i]==1&&next!=i&&!visited[i])
                q.push(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    N=computers.size();
    cpt=computers;
    
    for(int i=0;i<N;i++){
        if(!visited[i])
            bfs(i);
    }
    
    return cnt;
}