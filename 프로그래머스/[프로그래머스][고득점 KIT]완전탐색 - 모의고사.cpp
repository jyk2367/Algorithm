#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int arr1[5]={1,2,3,4,5};
int arr2[8]={2,1,2,3,2,4,2,5};
int arr3[10]={3,3,1,1,2,2,4,4,5,5};
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> scores(3,0);
        
    int ASIZE=answers.size();
    for(int i=0;i<ASIZE;i++){
        if(answers[i]==arr1[i%5])
            scores[0]++;
        if(answers[i]==arr2[i%8])
            scores[1]++;
        if(answers[i]==arr3[i%10])
            scores[2]++;
    }
    
    int scores_max=*max_element(scores.begin(),scores.end());
    for(int i=0;i<3;i++){
        if(scores[i]==scores_max)
            answer.push_back(i+1);
    }
    sort(answer.begin(),answer.end());
    return answer;
}