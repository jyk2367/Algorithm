#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int> m;

int solution(vector<vector<string>> clothes) {
    int answer=1;
    for(vector<string> v:clothes){
        m[v[1]]++;
    }
    
    for(pair<string,int> p: m){
        answer*=p.second+1;
    }
    return answer-1;//선택 아예 안하는 경우 빼기
}