#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> answer;
bool first_time=0;
void func(vector<string> &tmp,int k,string s,vector<bool> &visited,vector<vector<string>> & tickets){
    tmp.push_back(s);
    if(k==tickets.size()&&first_time==0){
        answer.assign(tmp.begin(),tmp.end());
        first_time=1;
        return;
    }
    
    for(int i=0;i<tickets.size();i++){
        if(!visited[i]&&tickets[i][0]==tmp.back()){
            visited[i]=true;
            func(tmp,k+1,tickets[i][1],visited,tickets);
            visited[i]=false;
        }
    }
    tmp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> tmp;
    vector<bool> visited(tickets.size(),0);
    sort(tickets.begin(),tickets.end());
    
    func(tmp,0,"ICN",visited,tickets);
    return answer;
}