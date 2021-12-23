#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;
string make_bin(int len){
    string tmp="";
    while(len!=0){
        tmp+=to_string(len%2==0?0:1);
        len/=2;
    }
    reverse(tmp.begin(),tmp.end());
    return tmp;
}

vector<int> solution(string s) {
    vector<int> answer;
    int zero_cnt=0,loop_cnt=0;
    while(s!="1"){
        loop_cnt++;
        string tmp="";
        for(int i=0;i<s.length();i++){
            if(s[i]!='0')
                tmp+=s[i];
            else
                zero_cnt++;
        }
        s=make_bin(tmp.length());
    }
    answer.push_back(loop_cnt);
    answer.push_back(zero_cnt);
    return answer;
}