#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int maximum=0x80000000,minimum=0x7fffffff;
    
    string tmp="";
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            maximum=max(maximum,stoi(tmp));
            minimum=min(minimum,stoi(tmp));
            tmp="";
            continue;
        }
        tmp+=s[i];
    }
    //마지막 단계
    maximum=max(maximum,stoi(tmp));
    minimum=min(minimum,stoi(tmp));
    
    return to_string(minimum)+" "+to_string(maximum);
}