#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
struct STR{
    string u="";
    string v="";
};

bool isEmpty(string p){
    return p.length()==0; 
}

bool isBalanced(string p){
    int cnt1=0,cnt2=0;
    for(int i=0;i<p.length();i++){
        p[i]=='('?cnt1++:cnt2++;
    }
    return cnt1==cnt2;
}

bool isCorrect(string s){
    if(isEmpty(s))
        return true;
    if(isBalanced(s)){
        int cnt1=0,cnt2=0;
        for(int i=0;i<s.length();i++){
            s[i]=='('?cnt1++:cnt2++;
            if(cnt1<cnt2)
                return false;
        }
        return true;
    }
    return false;
}

STR makeBalStr(string s){
    STR w;
    w.u+=s[0];
    int i=1;
    
    while(!isBalanced(w.u)){
         w.u+=s[i];
         i++;
    }
    if(i<s.length()){
        w.v+=s.substr(i);
    }
    else{
        w.v="";
    }
    return w;
}

string RAR(string s){
    string w="";
    s.erase(0,1);
    if(s.length()!=0)
        s.erase(s.length()-1,1);
    for(int i=0;i<s.length();i++){
        s[i]=='('?w+=')':w+='(';
    }
    return w;
}

string func(string s){
    if(isCorrect(s)||isEmpty(s))
        return s;
    if(isBalanced(s)){
        STR w;
        w=makeBalStr(s);

        if(isCorrect(w.u)){
            w.u+=func(w.v);
            return w.u;
        }
        else{
            string tmp="(";
            tmp+=func(w.v);
            tmp+=")";
            tmp+=RAR(w.u);
            return tmp;
        }
    }
}

string solution(string p) {
    string answer = "";
    answer=func(p);
    return answer;
}