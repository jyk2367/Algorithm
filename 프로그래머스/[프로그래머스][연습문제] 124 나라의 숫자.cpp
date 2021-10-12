#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    char end[3]={'4','1','2'};
    
    while(n!=0){
        int rm=n%3;
        n=(n-1)/3;
        
        answer=end[rm]+answer;
    }
    
    return answer;
}