#include <string>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int dir_x[]={0,1,0,1};
int dir_y[]={0,0,1,1};

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(true){
        //지울 것 (x,y)를 저장할 set
        set<pair<int,int>> hs;
        
        //set에 지울 놈들 저장
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bool state=false;
                char start=toupper(board[i][j]);
                for(int dir=0;dir<4;dir++){
                    int next_x=i+dir_x[dir];
                    int next_y=j+dir_y[dir];
                    if(next_x<0||next_x>=m||next_y<0||next_y>=n){
                        state=true;
                        break;
                    }
                    if(board[next_x][next_y]=='1'){
                        state=true;
                        break;
                    }
                    if(board[next_x][next_y]!=start){
                        state=true;
                        break;
                    }
                }
                if(!state){
                    for(int dir=0;dir<4;dir++){
                        int next_x=i+dir_x[dir];
                        int next_y=j+dir_y[dir];
                        hs.insert({next_x,next_y});
                    }
                }
            }
        }
        
        
        
        //지울 것이 없다면 break;
        if(hs.empty())
            break;
        //지우기
        for(pair<int,int> p:hs){
            board[p.first][p.second]='1';
            answer++;
        }
        //아래로 이동
        for(int i=0;i<n;i++){
            stack<char> s;
            for(int j=0;j<m;j++){
                if(board[j][i]!='1')
                    s.push(board[j][i]);
            }
            
            for(int j=m-1;j>=0;j--){
                if(s.size()>0){
                    board[j][i]=s.top();
                    s.pop();
                }
                else
                    board[j][i]='1';
            }
            
        }
        
        
    }
    
    
    return answer;
}