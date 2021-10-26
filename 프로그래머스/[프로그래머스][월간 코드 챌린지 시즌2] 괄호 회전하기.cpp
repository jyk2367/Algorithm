#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len_s=s.length();
    for(int i=0;i<len_s;i++){
        string tmp1=s.substr(0,i);
        string tmp2=s.substr(i);
        string new_s=tmp2+tmp1;
        int len_new_s=new_s.length();
        stack<char> stk;
        bool state=false;
        for(int j=0;j<len_new_s;j++){
            if(new_s[j]=='['||new_s[j]=='('||new_s[j]=='{')
                stk.push(new_s[j]);
            else if(!stk.empty()){
                char c=stk.top();
                stk.pop();
                if((c=='['&&new_s[j]!=']')||(c=='('&&new_s[j]!=')')||(c=='{'&&new_s[j]!='}')){
                    state=true;
                    break;
                }
            }
            else{
                state=true;
                break;
            }
        }
        if(!stk.empty())
            state=true;
        if(state==false)
            answer++;
        
        //cout<<new_s<<" "<<answer<<"\n";
    }
    
    
    return answer;
}