#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0, idx=0;
    for(int i=0; i<4; i++)//땅따먹기 시작
        if(answer<land[0][i]){
            answer=land[0][i];
            idx=i;
        }
    
    for(int i=1; i<land.size(); i++){
        int max=0;
        int ex_idx=idx;
        for(int j=0; j<4; j++){
            if(max<land[i][j]&&j!=ex_idx){
                max=land[i][j];
                idx=j;
            }
        }
        answer+=max;
    }
    
    return answer;
}