#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> map;
    for(int i=0; i<participant.size(); i++){
        string name=participant[i];
        map[name]++;
    }
    for(int j=0; j<completion.size(); j++){
        string name=completion[j];
        map[name]--;
    }
    for(auto k: map){
        if(k.second>0){
            answer=k.first;
            break;
        }
    }
    return answer;
}

/*1. completion의 크기가 participant의 길이보다 1짧으니까 completion 기준으로 만드는게 좋을수 있다(이문제에선 크게 차이없지만 만약 100개 100개 차이 이렇게되면 충분히 completion으로 풀어야겠다 생각할수 있어야할듯)
2. 지금은 for문을 3개 돌았는데 이렇게되면 시간복잡도가 3n이 되니까 좀더 줄일수는 없을까 고민해봐야함
for문을 2번 돌고 find함수를 사용하면 2nlogn으로 줄일수 있고, 기존에 먼저 sort를 하면 2nlogn+n으로도 줄일 수 있다
이런식으로 시간복잡도 줄이는 방식을 생각해볼 필요는 있다*/