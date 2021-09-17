#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

bool pmcompare(const pair<string,int> &p1,const pair<string,int> &p2){
    return p1.second>p2.second;
}
bool hmcompare(const pair<int,int> &p1,const pair<int,int> &p2){
    return p1.first>p2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    //장르 : (플레이횟수,index)
    unordered_map<string,vector<pair<int,int>>> hm;
    //장르 : (총 플레이횟수)
    unordered_map<string,int> pm;
    
    int GSIZE=genres.size();
    int PSIZE=plays.size();
    
    for(int i=0;i<GSIZE;i++){
        hm[genres[i]].push_back({plays[i],i});
        pm[genres[i]]+=plays[i];
    }
    //1. 총 플레이횟수로 정렬
    vector<pair<string,int>> v(pm.begin(),pm.end());
    
    sort(v.begin(),v.end(),pmcompare);
    
    //2. map내부 vector를 플레이횟수로 정렬
    for(pair<string,vector<pair<int,int>>> p:hm){
        sort(hm[p.first].begin(),hm[p.first].end(),hmcompare);
    }
    
    //3. 총 플레이횟수가 큰 놈들부터 2개씩 추출
    for(pair<string,int> p:v){
        if(hm[p.first].size()>=2){
            answer.push_back(hm[p.first][0].second);
            answer.push_back(hm[p.first][1].second);
        }
        else{
            answer.push_back(hm[p.first][0].second);
        }
    }
    
    return answer;
}