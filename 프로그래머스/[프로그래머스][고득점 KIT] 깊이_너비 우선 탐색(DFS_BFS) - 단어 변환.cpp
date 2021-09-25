#include <string>
#include <vector>

using namespace std;
int answer,N;
string ST,END;
vector<string> wd;
bool visited[52];

void func(int k,int cnt,string s){
    if(s==END){
        answer=cnt;
        return;
    }
    if(k==N){
        return;
    }
    for(int i=0;i<N;i++){
        if(!visited[i]){
            visited[i]=true;
            
            int count=0;
            for(int j=0;j<wd[i].size();j++){
                if(s[j]!=wd[i][j])
                    count++;
            }

            if(count==1){
                func(k+1,cnt+1,wd[i]);
            }
            
            visited[i]=false;
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    wd=words;
    ST=begin,END=target;
    N=words.size();
    
    func(0,0,begin);
    
    return answer;
}