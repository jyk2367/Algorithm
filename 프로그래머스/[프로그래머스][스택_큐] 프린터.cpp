#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int PSIZE=priorities.size();
    
    map<int,int> mp;
    for(int i=0;i<PSIZE;i++){
        mp[i]=priorities[i];
    }
    
    deque<pair<int,int>> dq(mp.begin(),mp.end());
    vector<pair<int,int>> v;
    
    while(!dq.empty()){
        pair<int,int> p=dq.front();
        dq.pop_front();
        bool state=0;
        
        if(dq.size()>1){
            for(deque<pair<int,int>>::iterator it=dq.begin();it!=dq.end();it++){
                if(p.second<(*it).second){
                    dq.push_back(p);
                    state=1;
                    break;
                }
            }
        }
        
        if(state==0){
            v.push_back(p);
        }
    }
    
    answer=find(v.begin(),v.end(),make_pair(location,priorities[location]))-v.begin();
    answer++;
    
    return answer;
}

// #include <string>
// #include <vector>
// #include <map>
// #include <queue>
// #include <algorithm>

// using namespace std;

// int solution(vector<int> priorities, int location) {
//     int answer = 0;
//     int PSIZE=priorities.size();
    
//     queue<int> q;
//     vector<int> v;
//     for(int i=0;i<PSIZE;i++){
//         q.push(i);
//     }
    
    
//     while(!q.empty()){
//         int now=q.front();
//         q.pop();
        
//         if(priorities[now]!=*max_element(priorities.begin(),priorities.end()))
//             q.push(now);
//         else{
//             v.push_back(now);
//             priorities[now]=0;
//         }
//     }
    
//     for(int i=0;i<PSIZE;i++){
//         if(v[i]==location)
//             answer=i+1;
//     }
    
//     return answer;
// }