#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int len_skill=skill.length();

    
    for(string s:skill_trees){
        int before=-1;
        vector<int> v;
        
        for(int i=0;i<len_skill;i++){
            v.push_back(find(s.begin(),s.end(),skill[i])-s.begin());
        }
        
        bool state=true;
        
        for(int i=0;i<len_skill;i++){
            if(before<=v[i]){
                before=v[i];
                continue;
            }
            state=false;
        }
        if(state)
            answer++;
    }
    
    return answer;
}