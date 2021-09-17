#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
string solution(string number, int k) {
    string answer="";
    int index=0;
    for(int i=k;i<number.length();i++){
        string::iterator it=max_element(number.begin()+index,number.begin()+i+1);
        answer+=*it;
        while(number[index]!=*it){
            index++;
        }
        index++;
    }
    
    
    return answer;
}