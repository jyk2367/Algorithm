#include <string>
#include <vector>
#include <map>

using namespace std;


vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    map<string,pair<string,int>> M;
    
    M.insert(make_pair("-",make_pair("",0)));
    for(int i=0;i<enroll.size();i++){
        M.insert(make_pair(enroll[i],make_pair(referral[i],0)));
    }
 
    for(int i=0;i<seller.size();i++){
        string now=seller[i];
        string next=M[now].first;

        int cost=amount[i]*100;
        M[now].second+=amount[i]*100;
        
        while(now!="-"){
            if(cost<1)
                break;
            cost/=10;
            M[now].second-=cost;
            now=next;
            next=M[now].first;
            M[now].second+=cost;
        }
    }
    
    for(int i=0;i<enroll.size();i++){
        answer.push_back(M[enroll[i]].second);
    }
    
    return answer;
}