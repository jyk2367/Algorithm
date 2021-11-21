#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    unordered_map<string,bool> hm;
    int index=0;
    char lastchar=words[0][0];
    bool state=false;
    
    for(string s:words){
        if(lastchar==s[0]&&hm.count(s)==0){
             hm[s]=true;
        }
        else
            return {index%n+1,index/n+1};
        index++;
        lastchar=s[s.size()-1];
    }
        
    return {0,0};
}