#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int make_offset(int num){
    int result=1;
    while(num-->0){
        result*=5;
        result+=1;
    }
    return result;
}

int solution(string word) {
    int answer=0;
    unordered_map<char,int> letter;
    // letter : 'A'와 떨어진 거리를 저장함
    letter['A']=0,letter['E']=1,letter['I']=2,letter['O']=3,letter['U']=4;
    
    for(int i=0;i<word.length();i++){
        answer+=letter[word[i]]*make_offset(4-i);
    }
    
    
    //    시작점들 : hm["A"]=1,hm["AA"]=2,hm["AAA"]=3,hm["AAAA"]=4,hm["AAAAA"]=5;
    answer+=word.length();
    
    return answer;
}