#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    int ID_LEN=new_id.length();
    for(int i=0;i<ID_LEN;i++){
        if(new_id[i]>='A'&&new_id[i]<='Z')
            new_id[i]=tolower(new_id[i]);
        if(isalpha(new_id[i])||isdigit(new_id[i])||new_id[i]=='-'||new_id[i]=='_')
            answer+=new_id[i];
        
        if(new_id[i]=='.'&&answer.back()!='.')
            answer+=new_id[i];
    }

    ID_LEN=answer.length();
    if(answer.front()=='.')
        answer=answer.substr(1);
    if(answer.back()=='.')
        answer.pop_back();
    
    if(answer.empty())
        answer="a";
    if(answer.length()>15)
        answer=answer.substr(0,15);
    while(answer.back()=='.')
            answer.pop_back();
    
    while(answer.length()<=2)
        answer+=answer.back();

    return answer;
}