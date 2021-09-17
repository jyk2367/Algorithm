#include <string>
#include <vector>
#include <iostream>

using namespace std;

int matrix[102][102];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++){
            matrix[i][j]=((i-1)*columns+j);
        }
    }
    
    for(vector<int> query : queries){
        vector<int> v=query;
        
        pair<int,int> lu=make_pair(v[0],v[1]);
        pair<int,int> ru=make_pair(v[0],v[3]);
        pair<int,int> ld=make_pair(v[2],v[1]);
        pair<int,int> rd=make_pair(v[2],v[3]);

        int ru_point=matrix[ru.first][ru.second];
        int ld_point=matrix[ld.first][ld.second];
        int rd_point=matrix[rd.first][rd.second];
        int minimum=min(ru_point,min(ld_point,rd_point));
        
        for(int i=lu.first,j=rd.second;j>=lu.second;j--){
            if(j==lu.second){
                break;
            }
            matrix[i][j]=matrix[i][j-1];
            minimum=min(minimum,matrix[i][j]);
        }
        
        for(int i=rd.first,j=rd.second;i>=ru.first;i--){
            if(i==ru.first){
                break;
            }
            matrix[i][j]=matrix[i-1][j];
            minimum=min(minimum,matrix[i][j]);
        }
        
        for(int i=ld.first,j=ld.second;j<=rd.second;j++){
            if(j==rd.second){
                break;
            }
            matrix[i][j]=matrix[i][j+1];
            minimum=min(minimum,matrix[i][j]);
        }
        
        for(int i=lu.first,j=lu.second;i<=ld.first;i++){
            if(i==ld.first){
                break;
            }
            matrix[i][j]=matrix[i+1][j];
            minimum=min(minimum,matrix[i][j]);
        }
        
        matrix[ru.first+1][ru.second]=ru_point;
        matrix[ld.first-1][ld.second]=ld_point;
        matrix[rd.first][rd.second-1]=rd_point;
        answer.push_back(minimum);
    }
    
    return answer;
}