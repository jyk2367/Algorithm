#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0x7fffffff;
    int S_SIZE=s.length();
    int j=1;
    
    if(S_SIZE<=1)
        return 1;
    if(S_SIZE==2)
        return 2;
    
    while(j<S_SIZE){
        string tmp;
        int i=0;
        int cnt=1;
        while(i+j<=S_SIZE){
           string sub=s.substr(i,j);
           i+=j;
           while(i+j<=S_SIZE){
               string next_sub=s.substr(i,j);
               if(next_sub==sub){
                   cnt++;
                   i+=j;
               }
               else
                   break;
           }
           if(cnt>1){
               tmp+=to_string(cnt);
               cnt=1;
           }
           tmp+=sub;
        }
        tmp+=s.substr(i);
        answer=min(answer,(int)tmp.length());
        j++;
    }
    
    return answer;
}