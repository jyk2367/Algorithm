#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int answer;
vector<int> ans_candidate;
int row_size;
int col_size;
//하 우 상 좌
int dir_xy[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
vector<vector<bool>> visited(102,vector<bool>(102,false));



int solution(vector<vector<int> > maps)
{
    answer = -1;
    row_size=maps.size();
    col_size=maps[0].size();
    
    if(row_size>=2&&col_size>=2&&maps[row_size-2][col_size-2]==0&&maps[row_size-1][col_size-2]==0&&maps[row_size-2][col_size-1]==0)
        return -1;
    
    queue<pair<pair<int,int>,int>> q;
    q.push({{1,1},1});
    visited[1][1]=true;

    while(!q.empty()){
        pair<pair<int,int>,int> p=q.front();
        q.pop();
        if(answer!=-1&&p.second>answer)
            break;
        
        if(p.first.first==row_size&&p.first.second==col_size)
            answer=p.second;
        
        for(int dir=0;dir<4;dir++){
            int next_x=p.first.first+dir_xy[dir][0];
            int next_y=p.first.second+dir_xy[dir][1];

            if(next_x>row_size||next_y>col_size||next_x<1||next_y<1)
                continue;
            if(visited[next_x][next_y])
                continue;
            if(maps[next_x-1][next_y-1]==0)
                continue;
            visited[next_x][next_y]=true;
            q.push({{next_x,next_y},p.second+1});
        }
        
    }
    
    
    return answer;
}