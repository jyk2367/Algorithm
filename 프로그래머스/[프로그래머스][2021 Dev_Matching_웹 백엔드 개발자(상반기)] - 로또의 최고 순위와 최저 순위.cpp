#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int min_rank,max_rank;
    int cnt=0,cnt_zero=0;
    
    for(int num : lottos){
        if(num==0){
                cnt_zero++;
                continue;
        }
        for(int i=0;i<win_nums.size();i++){
            if(num==win_nums[i])
                cnt++;
        }
    }
    
    min_rank=min(7-cnt,7-(cnt_zero+cnt));
    max_rank=max(7-cnt,7-(cnt_zero+cnt));
    if(min_rank>6){
        min_rank=6;
    }
    if(max_rank>6){
        max_rank=6;
    }
    answer.push_back(min_rank);
    answer.push_back(max_rank);
    return answer;
}