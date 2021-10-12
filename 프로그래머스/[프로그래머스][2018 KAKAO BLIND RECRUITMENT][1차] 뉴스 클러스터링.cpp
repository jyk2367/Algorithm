#include <string>
#include <set>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int s1_SIZE=str1.length();
    int s2_SIZE=str2.length();
    
    multiset<string> set1,set2;
    int buffer=2;
    string tmp="";
    for(int i=0;i<s1_SIZE-1;i++){
        int j=i+1;
        
        string tmp="";
        tmp+=toupper(str1[i]);
        tmp+=toupper(str1[j]);
        
        if(isalpha(toupper(str1[i]))&&isalpha(toupper(str1[j]))){
            set1.insert(tmp);
        }
    }
    
    for(int i=0;i<s2_SIZE-1;i++){
        int j=i+1;
        
        string tmp="";
        tmp+=toupper(str2[i]);
        tmp+=toupper(str2[j]);
        
        if(isalpha(toupper(str2[i]))&&isalpha(toupper(str2[j]))){
            set2.insert(tmp);
        }
    }
    
    int set1_SIZE=set1.size();
    int set2_SIZE=set2.size();
    
    int U=set2_SIZE;
    int n=0;
    
    for(multiset<string>::iterator it=set1.begin();it!=set1.end();it++){
        if(set2.find(*it)==set2.end())
            U++;
        else{
            int cnt1=set1.count(*it);
            int cnt2=set2.count(*it);
            if(cnt1>cnt2){
                U+=cnt1-cnt2;
                n+=cnt2;
            }
            else{
                n+=cnt1;
            }
            while(cnt1-1>0){
                it++;
                cnt1--;
            }
        }
    }
    
    if(U==0)
        return 65536;
    
    return ((double)n/(double)U)*(double)65536/1;
}