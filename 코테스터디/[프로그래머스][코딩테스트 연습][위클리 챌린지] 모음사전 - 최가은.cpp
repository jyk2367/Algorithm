#include <string>
#include <vector>
#include <map>
using namespace std;

int cnt=1;
vector<string> alphabet={"A","E","I","O","U"};
map<string, int> dic;

void dfs(string s){
    if(s.size()>5)
        return;
    dic[s]=cnt++;
    for(string c: alphabet)
        dfs(s+c);
}

int solution(string word) {
    for(int i=0; i<alphabet.size();i++)
        dfs(alphabet[i]);
    return dic[word];
}