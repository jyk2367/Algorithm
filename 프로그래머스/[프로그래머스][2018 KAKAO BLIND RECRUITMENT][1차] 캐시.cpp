#include <string>
#include <vector>
#include <list>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> ls;
    if(cacheSize==0)
        return cities.size()*5;

    for(string c:cities){

        for(int i=0;i<c.length();i++){
            c[i]=toupper(c[i]);
        }

        //dq에 동일 도시 이름 존재시
        bool state=false;
        for(list<string>::iterator it=ls.begin();it!=ls.end();it++){
            if(*it==c){
                answer++;
                string tmp=*it;
                ls.erase(it);
                ls.push_back(tmp);
                state=true;
                break;
            }
        }
        if(state)
            continue;

        //dq가 다 안찼을 시
        if(ls.size()<cacheSize){
            ls.push_back(c);
            answer+=5;
            continue;
        }

        //dq는 찼고 도시 일치하는게 없을 시
        ls.pop_front();
        ls.push_back(c);
        answer+=5;
    }

    return answer;
}