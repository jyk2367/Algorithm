#include <string>
#include <vector>
#include <queue>

using namespace std;
//상하좌우
int dir_x[4]={0,0,-1,1};
int dir_y[4]={-1,1,0,0};

bool bfs(int x,int y,bool visited[][5],int matrix[][5]){
    queue<pair<int,int>> q;
    
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        for(int dir=0;dir<4;dir++){
            int next_x=p.first+dir_x[dir];
            int next_y=p.second+dir_y[dir];

            if(next_x<0||next_x>=5||next_y<0||next_y>=5)
                continue;
            if(matrix[next_x][next_y]==0)
                continue;
            if(visited[next_x][next_y])
                continue;
            
            visited[next_x][next_y]=true;
            if(abs(next_x-x)+abs(next_y-y)<2)
                q.push({next_x,next_y});
            if(abs(next_x-x)+abs(next_y-y)<=2&&matrix[next_x][next_y]==2){
                return 0;
            }
        }

    }
    return 1;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(vector<string> v:places){
        int matrix[5][5];
        bool visited[5][5];
        bool state=0;
        
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                visited[i][j]=false;
                if(v[i][j]=='P'){
                    matrix[i][j]=2;
                }
                else if(v[i][j]=='O')
                    matrix[i][j]=1;
                else
                    matrix[i][j]=0;
            }
        }
        
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(!visited[i][j]&&matrix[i][j]==2){
                    visited[i][j]=true;
                    if(!bfs(i,j,visited,matrix))
                        state=1;
                    visited[i][j]=false;
                }  
            }
        }
        
        if(state==1)
            answer.push_back(0);
        else
            answer.push_back(1);
    }
    
    return answer;
}