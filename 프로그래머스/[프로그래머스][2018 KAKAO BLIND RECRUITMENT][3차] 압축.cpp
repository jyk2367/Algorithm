#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    int MSGLEN=msg.length();
    unordered_map<string,int> hm;   
    
    int dic_index=1;
    for(;dic_index<=26;dic_index++){
        string tmp(1,'A'+dic_index-1);
        hm.insert({tmp,dic_index});
    }
    
    for(int i=0;i<MSGLEN;i++){
        string w="",c="";
        w+=msg[i];
        int now=i;
        
        while(hm.count(w+c)){
            w=w+c;
            c=msg[++now];
        }
        
        hm.insert({w+c,dic_index++});
        answer.push_back(hm[w]);
        i=now-1;
    }
    
    
    return answer;
}