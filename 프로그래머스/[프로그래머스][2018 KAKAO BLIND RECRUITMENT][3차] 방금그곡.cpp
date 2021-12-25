#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct info{
    int startTHour;
    int startTMin;
    int endTHour;
    int endTMin;
    string title;
    string music;
};

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int longest=0;
    int minfoSIZE=musicinfos.size();
    int mLen=m.length();
    info *info=new struct info[musicinfos.size()];
    
    //m에서 #을 가진놈들은 전부 소문자로
    for(int i=0;i<mLen;i++){
        if(m[i]=='#')
            m[i-1]=tolower(m[i-1]);
    }
    
    for(int i=0;i<minfoSIZE;i++){
        string s=musicinfos[i];
        if(s.length()==0)
            continue;
        info[i].startTHour=stoi(s.substr(0,2));
        info[i].startTMin=stoi(s.substr(3,2));
        info[i].endTHour=stoi(s.substr(6,2));
        info[i].endTMin=stoi(s.substr(9,2));
        info[i].title=s.substr(12,s.substr(12).find(","));
        info[i].music=s.substr(12+s.substr(12).find(",")+1);
        
        int sharpcnt=count(info[i].music.begin(),info[i].music.end(),'#');
        int totalMinute=(info[i].endTHour-info[i].startTHour)*60+info[i].endTMin-info[i].startTMin;
        int infomLen=info[i].music.length();
        string musicNow="";
        
        for(int j=0;j<totalMinute;j++){
            if(info[i].music[(j+1)%infomLen]=='#'){
                musicNow+=tolower(info[i].music[j%infomLen]);
                musicNow+='#';
                totalMinute++;
                continue;
            }
            else if(info[i].music[j%infomLen]=='#')
                continue;
            else{
                musicNow+=info[i].music[j%infomLen];
            }
        }
        auto pos=musicNow.find(m);
        
        if(pos==string::npos)
            continue;
        else{
            if(longest>=totalMinute)
                    continue;
            answer=info[i].title;
            longest=totalMinute;
            continue;
        }
    }
    if(answer=="")
        answer="(None)";
    return answer;
}