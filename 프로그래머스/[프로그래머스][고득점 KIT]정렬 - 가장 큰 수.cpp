#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool comp(const string& s1,const string& s2){
    return s1+s2>s2+s1;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int i:numbers){
        v.push_back(to_string(i));
    }
    
    sort(v.begin(),v.end(),comp);
    
    for(string s:v){
        answer+=s;
    }
    
    if(answer[0]=='0')
        answer="0";
    return answer;
}