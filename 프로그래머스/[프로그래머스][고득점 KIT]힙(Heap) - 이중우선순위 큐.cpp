#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comp1(const int &i,const int &j){
    return i>j;
}
bool comp2(const int &i,const int &j){
    return i<j;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> v;
    
    for(string s: operations){
        switch(s[0]){
            case 'I':
                v.push_back(stoi(s.substr(2)));
                break;
            case 'D':
                if(!v.empty()){
                    if(s[2]=='-')
                        sort(v.begin(),v.end(),comp1);
                    else
                        sort(v.begin(),v.end(),comp2);
                    v.pop_back();
                }
                break;
        }
    }
    if(!v.empty()){
        sort(v.begin(),v.end(),comp2);
        answer.push_back(v.back());
        answer.push_back(v.front());
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}