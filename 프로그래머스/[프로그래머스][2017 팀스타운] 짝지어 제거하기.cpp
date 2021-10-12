#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> characters;
    int S_SIZE=s.length();
    for(int i=0;i<S_SIZE;i++){
        if(characters.empty())
            characters.push(s[i]);
        else{
            char top=characters.top();
            if(top==s[i])
                characters.pop();
            else
                characters.push(s[i]);
        }
    }
    
    if(characters.empty())
        answer=1;
    else
        answer=0;
    
    return answer;
}