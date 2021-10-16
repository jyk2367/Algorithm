#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
// 각 칸은 S,L,R
// S는 직진, L은 좌회전, R은 우회전
// 빛이 격자의 끝을 넘어가면 반대편 끝으로 다시돌아옴
// 격자 내 빛이 이동할 수 있는 경로 사이클(빛이 이동하는 순환경로)+각 사이클의 길이
// 주어진 격자를 통해 만들어지는 빛의 경로 사이클의 모든 길이들(값 같아도 넣어야함)+오름차순

// 상하좌우
int dir_x[4]={0,0,-1,1};
int dir_y[4]={-1,1,0,0};

char c[502][502];
bool out[502][502][4];

vector<int> answer;
//세로 길이 ====
int row_size=0;
//가로 길이(grid는 항상 1이상)   ||||
int col_size=0;

void bfs(int x,int y,int dir){
    int next_x=((x+dir_x[dir])+row_size)%row_size;
    int next_y=((y+dir_y[dir])+col_size)%col_size;
    
    queue<pair<int,int>> q;
    
    q.push({next_x,next_y});
    int cnt=0;
    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        cnt++;
        
        if(c[p.first][p.second]=='S'){
            if(out[p.first][p.second][dir])
               break; 
            out[p.first][p.second][dir]=true;
            next_x=((next_x+dir_x[dir])+row_size)%row_size;
            next_y=((next_y+dir_y[dir])+col_size)%col_size;
            q.push({next_x,next_y});
        }
        else if(c[p.first][p.second]=='L'){
            if(dir==0){
                dir=2;
            }
            else if(dir==1){
                dir=3;
            }
            else if(dir==2){
                dir=1;
            }
            else{
                dir=0;
            }
            if(out[p.first][p.second][dir])
               break; 
            out[p.first][p.second][dir]=true;
            next_x=((next_x+dir_x[dir])+row_size)%row_size;
            next_y=((next_y+dir_y[dir])+col_size)%col_size;
            q.push({next_x,next_y});
        }
        else if(c[p.first][p.second]=='R'){
            if(dir==0){
                dir=3;
            }
            else if(dir==1){
                dir=2;
            }
            else if(dir==2){
                dir=0;
            }
            else{
                dir=1;
            }
            if(out[p.first][p.second][dir])
               break; 
            out[p.first][p.second][dir]=true;
            next_x=((next_x+dir_x[dir])+row_size)%row_size;
            next_y=((next_y+dir_y[dir])+col_size)%col_size;
            q.push({next_x,next_y});
        }
        
    }
    answer.push_back(cnt);
}


vector<int> solution(vector<string> grid) {
    //세로 길이 ====
    row_size=grid.size();
    //가로 길이(grid는 항상 1이상)   ||||
    col_size=grid[0].length();
    
    for(int i=0;i<row_size;i++){
        for(int j=0;j<col_size;j++){
            c[i][j]=grid[i][j];
        }
    }
    
    
    for(int i=0;i<row_size;i++){
        for(int j=0;j<col_size;j++){
            //4방향중 안뚫린게 있다면 그쪽으로 cycle시작
            //cycle중에 가려고 하는 방향이 이미 뚫려있으면 cycle이 있다는 뜻이므로 break
            for(int dir=0;dir<4;dir++){
                if(out[i][j][dir]==true)
                    continue;
                out[i][j][dir]=true;
                bfs(i,j,dir);
            }
        }
    }    
    sort(answer.begin(),answer.end());
    return answer;
}