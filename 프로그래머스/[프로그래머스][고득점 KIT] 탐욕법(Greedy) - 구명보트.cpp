#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end(),greater<int>());
    int PSIZE=people.size();
    int b_i=PSIZE-1;
    for(int i=0;i<b_i+1;i++){
        if(i!=b_i&&people[i]+people[b_i]<=limit){
            answer++;
            b_i--;
        }
        else{
            answer++;
        }
    }
    
    return answer;
}
​