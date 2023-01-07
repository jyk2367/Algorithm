#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    const int todayYear=stoi(today.substr(0,4));
    const int todayMonth=stoi(today.substr(5,7));
    const int todayDay=stoi(today.substr(8,10));
    
    unordered_map<char,int> t_i;
    for(string term:terms){
        t_i.insert({term[0],stoi(term.substr(2))});
    }
    
    for(int i=0;i<privacies.size();i++){
        int privacyYear=stoi(privacies[i].substr(0,4));
        int privacyMonth=stoi(privacies[i].substr(5,7));
        int privacyDay=stoi(privacies[i].substr(8,10));
        char privacyType=privacies[i][11];
        int validMonth = t_i[privacyType];
        
        
        int todayNum=todayYear*12*28+todayMonth*28+todayDay;
        int limitNum=28*validMonth+privacyYear*12*28+privacyMonth*28+privacyDay;
        
        if(todayNum>=limitNum)
            answer.push_back(i+1);
    }

    return answer;
}