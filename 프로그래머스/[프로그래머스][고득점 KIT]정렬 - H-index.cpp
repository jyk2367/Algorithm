#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(),citations.end(),greater<int>());
    
    int csize=citations.size();
    for(int h=0;h<csize;h++){
        if(h+1<=citations[h])
            answer=h+1;
    }
    
    return answer;
}