#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string,bool> hm;
const string word[]={"","aya","ye","woo","ma"};

void StoreByBacktracking(int k,string s,int wordChecker){
    if(k==5){
        return;
    }
    
    for(int i=1;i<5;i++){
        if((wordChecker>>i)==1)
            continue;
        
        hm.insert({s+word[i],true});
        StoreByBacktracking(k+1,s+word[i],wordChecker+(1<<i));
    }
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    hm[""]=true;
    StoreByBacktracking(0,"",1);
    
    for(string s:babbling){
        if(hm.count(s)==1)
            answer++;
    }
    
    return answer;
}