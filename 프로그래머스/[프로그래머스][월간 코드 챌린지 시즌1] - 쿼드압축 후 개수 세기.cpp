#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<vector<int>> v;
int cnt_zero,cnt_one;
bool isAllEqual(int k,int x,int y){
    for(int i=x;i<x+k;i++){
        for(int j=y;j<y+k;j++){
            if(v[x][y]!=v[i][j])
                return false;
        }
    }
    return true;
}

void func(int k,int x,int y){
    if(k==1){
        v[x][y]==0?cnt_zero++:cnt_one++;
        return;
    }
    
    int N=k/2;
    if(!isAllEqual(N,x,y)){
        func(N,x,y);
    }
    else{
        v[x][y]==0?cnt_zero++:cnt_one++;
    }
    
    if(!isAllEqual(N,x,y+N)){
        func(N,x,y+N);
    }
    else{
        v[x][y+N]==0?cnt_zero++:cnt_one++;
    }
    
    if(!isAllEqual(N,x+N,y)){
        func(N,x+N,y);
    }
    else{
        v[x+N][y]==0?cnt_zero++:cnt_one++;
    }
    
    if(!isAllEqual(N,x+N,y+N)){
        func(N,x+N,y+N);
    }
    else{
        v[x+N][y+N]==0?cnt_zero++:cnt_one++;
    }
    
}

vector<int> solution(vector<vector<int>> arr) {
    v=arr;
    
    if(!isAllEqual(arr.size(),0,0))
        func(arr.size(),0,0);
    else{
        v[0][0]==0?cnt_zero++:cnt_one++;
    }
    
    
    vector<int> answer;
    answer.push_back(cnt_zero);
    answer.push_back(cnt_one);
    return answer;
}