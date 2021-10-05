#include <vector>
#include <queue>
#define MAX_MN 102

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int number_of_area;
int max_size_of_one_area;
int M,N;
vector<vector<int>> pic;
bool visited[MAX_MN][MAX_MN];
void func(int x,int y,int x_dir[4],int y_dir[4]){
    visited[x][y]=true;
    
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    
    int NUM=pic[x][y];
    if(NUM==0)
        return;
    int cnt=0;

    
    while(!q.empty()){
        pair<int,int> p=q.front();
        int now_x=p.first,now_y=p.second;
        q.pop();
        cnt++;
        
        for(int dir=0;dir<4;dir++){
            int next_x=now_x+x_dir[dir];
            int next_y=now_y+y_dir[dir];
            
            if(0>next_x||next_x>=M||next_y>=N||next_y<0)
                continue;
            if(pic[next_x][next_y]!=NUM)
                continue;
            if(visited[next_x][next_y])
                continue;
            
            visited[next_x][next_y]=true;
            q.push(make_pair(next_x,next_y));
        }
    }
    max_size_of_one_area=max(cnt,max_size_of_one_area);
    number_of_area++;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    pic=picture;
    M=m,N=n;
    number_of_area = 0;
    max_size_of_one_area = 0;
    for(int i=0;i<MAX_MN;i++)
        for(int j=0;j<MAX_MN;j++)
            visited[i][j]=false;
    
    // 상 하 좌 우
    int x_dir[4]={0,0,-1,1};
    int y_dir[4]={-1,1,0,0};
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j])
                func(i,j,x_dir,y_dir);
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
