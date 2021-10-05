#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    int LSIZE=lines.size();
    vector<pair<int,int>> logs;
    
    for(string line:lines){
        stringstream st(line);
        string date,rt,pt;
        st>>date>>rt>>pt;
        
        int T=stod(pt.substr(0,pt.length()-1))*1000-1;
        int endTime=stoi(rt.substr(0,2))*3600*1000+stoi(rt.substr(3,2))*60*1000+stoi(rt.substr(6,2))*1000+stoi(rt.substr(9));
        int startTime=endTime-T;
        logs.push_back(make_pair(startTime,endTime));
    }
    
    for(int i=0;i<LSIZE;i++){
        int cnt=0;
        pair<int,int> p=logs[i];
        int sT=p.second,eT=p.second+999;
        
        for(int j=i;j<LSIZE;j++){
            pair<int,int> p2=logs[j];
            if(p2.first<=sT&&sT<=p2.second)
                cnt++;
            else if(p2.first<=eT&&eT<=p2.second)
                cnt++;
            else if(sT<=p2.first&&p2.second<=eT)
                cnt++;
        }
        answer=max(cnt,answer);
    }
    
    
    return answer;
}