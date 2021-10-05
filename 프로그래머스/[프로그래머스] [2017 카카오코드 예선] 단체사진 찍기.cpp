//백트래킹

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int cnt,N;
bool visited[8];
vector<string> dt;
void func(int k,string s,char character[8]){
    if(k==8){
        int acpt=0;
        for(string d:dt){
            int from=find(s.begin(),s.end(),d[0])-s.begin();
            int to=find(s.begin(),s.end(),d[2])-s.begin();
            bool state=0;
            switch(d[3]){
                case '=':
                    abs(from-to)-1==d[4]-'0'?state=1:state=0;
                    break;
                case '>':
                    abs(from-to)-1>d[4]-'0'?state=1:state=0;
                    break;
                case '<':
                    abs(from-to)-1<d[4]-'0'?state=1:state=0;
                    break;
            }
            if(state){
                acpt++;
                continue;
            }
            return;
        }
        acpt==N?cnt++:cnt;
        return;
    }
    
    for(int i=0;i<8;i++){
        if(!visited[i]){
            visited[i]=true;
            func(k+1,s+character[i],character);
            visited[i]=false;
        }
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    cnt=0,N=n;
    dt=data;
    for(int i=0;i<8;i++){
        visited[i]=false;
    }
    char character[8]={'A','C','F','J','M','N','R','T'};
    func(0,"",character);
    
    answer=cnt;
    
    return answer;
}

//next_permutation
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    
    string s="ACFJMNRT";
    do{
        int acpt=0;
        bool state=true;
        for(string &d:data){
            const int c1=s.find(d[0]);
            const int c2=s.find(d[2]);
            const int gap=d[4]-'0';
            switch(d[3]){
                case '=':
                    if(abs(c1-c2)-1!=gap)
                        state=false;
                    break;
                case '<':
                    if(abs(c1-c2)-1>=gap)
                        state=false;
                    break;
                case '>':
                    if(abs(c1-c2)-1<=gap)
                        state=false;
            }
            if(!state){
                break;
            }
        }
        if(state)
            answer++;
    }while(next_permutation(s.begin(),s.end()));
    
    
    return answer;
}