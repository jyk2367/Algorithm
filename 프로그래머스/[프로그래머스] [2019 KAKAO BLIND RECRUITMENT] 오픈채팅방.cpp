#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> mp;
    
    for(string r:record){
        istringstream st(r);
        string itt,userid,username;
        st>>itt>>userid>>username;
        if(itt=="Enter"||itt=="Change")
            mp[userid]=username;
    }
    
    for(string r:record){
        istringstream st(r);
        string itt,userid,username;
        st>>itt>>userid>>username;
        
        if(itt=="Change")
            continue;
        
        if(itt=="Enter")
            answer.push_back(mp[userid]+"님이 들어왔습니다.");
        else if(itt=="Leave")
            answer.push_back(mp[userid]+"님이 나갔습니다.");
    }
    
    
    return answer;
}