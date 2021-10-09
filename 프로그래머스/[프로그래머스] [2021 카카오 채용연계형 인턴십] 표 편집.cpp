#include <string>
#include <vector>
#include <stack>
#include <set>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer(n,'X');
    stack<int> s;
    set<int> table;
    set<int>::iterator now;

    pair<int,int> p;
    
    for(int i=0;i<n;i++)
        table.insert(i);
    
    now=table.find(k);
    
    
    for(string c:cmd){
        if(c[0]=='U'||c[0]=='D'){
            int num=stoi(c.substr(2));
            while(num--){
                if(c[0]=='D')
                    now++;
                else
                    now--;
            }
        }
        else if(c[0]=='C'){
            s.push(*now);
            now=table.erase(now);
            if(now==table.end())
                now--;
        }
        else{
            table.insert(s.top());
                s.pop(); 
        }
    }
               
    for(int i:table){
        answer[i]='O';
    }
    
    return answer;
}