#include <string>
#include <queue>
#include <iostream>
using namespace std;
bool matrix[22][22];

int solution(string dirs) {
    int answer = 0;
    int index=0;
    
    pair<int,int> pos={0,0};
    matrix[0][0]=true;
    
    while(index<dirs.length()){
        char c=dirs[index++];
        pair<int,int> lastpos=pos;
        
        if(c=='L'){
            pos.first+=-1;
        }
        else if(c=='R'){
            pos.first+=1;
        }
        else if(c=='U'){
            pos.second+=1;
        }
        else if(c=='D'){
            pos.second+=-1;
        }
        
        //범위 벗어나면 continue
        if(abs(pos.first)>5||abs(pos.second)>5){
            pos=lastpos;
            continue;
        }
        
        //"이전위치->다음위치"값을 가지고 있어야 한다
        if(!matrix[lastpos.first+pos.first+10][lastpos.second+pos.second+10]){
            matrix[lastpos.first+pos.first+10][lastpos.second+pos.second+10]=true;
            answer++;
        }
    }
    
    return answer;
}