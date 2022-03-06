#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <cmath>
using namespace std;

int total[10002];
unordered_map<int,int> hm;
set<int> carNumbers;
vector<int> answer;

/*
int gause(int time,int fee){
    if(time%fee==0){
        return time/fee;
    }
    return time/fee+1;
}
*/

vector<int> solution(vector<int> fees, vector<string> records) {

    for(string rec:records){
        int hour=stoi(rec.substr(0,2));
        int mnt=stoi(rec.substr(3,2));
        int carNum=stoi(rec.substr(6,4));
        carNumbers.insert(carNum);
        
        int time=(hour*60)+mnt+1000;
        if(hm[carNum]==0){
            hm[carNum]=time;
        }
        else{
            total[carNum]+=time-hm[carNum];
            hm[carNum]=0;
        }
    }
    
    for(int carNum:carNumbers){
        if(hm[carNum]!=0){
            total[carNum]+=2439-hm[carNum];
        }
        int price=fees[1];
        if(total[carNum]>fees[0])
            price+=ceil((total[carNum]-fees[0])/(double)fees[2])*fees[3];
        answer.push_back(price);
    }
    
    return answer;
}