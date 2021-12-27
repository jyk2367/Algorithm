#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> board)
{
    int rowSIZE=board.size();
    int colSIZE=board[0].size();
    int answer=0;
    bool state=false;
    
    for(int i=0;i<rowSIZE;i++){
        for(int j=0;j<colSIZE;j++){
            if(board[i][j]==1){
                state=true;
                if(i-1<0||j-1<0)
                    continue;
                board[i][j]=min(board[i][j-1],min(board[i-1][j],board[i-1][j-1]))+1;
                answer=max(board[i][j],answer);
            }
        }
    }
    if(state==true&&answer==0)
        answer=1;
    return answer*answer;
}

// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;


// int rowSIZE;
// int colSIZE;

// bool func(int x,int y,int k,vector<vector<int>> &board){
//     for(int i=0;i<=k;i++){
//         if(i+x>=rowSIZE)
//              return false;
//         for(int j=k;j>=0;j--){
//             if(!(i==k||j==k))
//                 continue;
//             if(j+y>=colSIZE)
//                 return false;
//             if(board[i+x][j+y]==0)
//                 return false;
//         }
//     }
//     return true;
// }

// int solution(vector<vector<int>> board)
// {
//     rowSIZE=board.size();
//     colSIZE=board[0].size();
//     int answer=0;
//     int minSIZE=min(rowSIZE,colSIZE);
    
//     for(int i=0;i<rowSIZE;i++){
//         for(int j=0;j<colSIZE;j++){
//             if(board[i][j]==1){
//                 int n=1;
//                 while(func(i,j,n,board)){
//                     n++;
//                 }
//                 answer=max(answer,n);
                
//                 if(answer>minSIZE-i)
//                     return answer*answer;
//             }
//         }
//     }

//     return answer*answer;
// }