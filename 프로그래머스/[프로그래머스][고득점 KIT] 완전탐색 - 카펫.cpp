#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int xy=brown+yellow;
    for(int x=1;x<=xy;x++){
        if(xy%x==0){
            int y=xy/x;
            if(2*x+2*(y-2)==brown&&(x-2)*(y-2)==yellow){
                answer.push_back(max(x,y));
                answer.push_back(min(x,y));
                break;
            }
        }
    }
    
    return answer;
}