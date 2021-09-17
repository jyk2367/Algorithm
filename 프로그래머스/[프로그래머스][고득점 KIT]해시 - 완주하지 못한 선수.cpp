#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> h;
    for(string p:participant){
        h[p]++;
    }
    for(string c:completion){
        h[c]--;
    }
    for(string p:participant){

        if(h[p]>0){
            answer=p;
            break;
        }
    }
    return answer;
}