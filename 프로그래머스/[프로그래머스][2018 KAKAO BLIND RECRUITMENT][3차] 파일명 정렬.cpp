#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

bool compare(const string &file1,const string &file2){
    
    int h1=0,h2=0,n1=file1.length(),n2=file2.length(),t1=0,t2=0;
    
    //number1 시작, tail 시작
    for(int i=0;i<file1.length();i++){
        if('0'<=file1[i]&&'9'>=file1[i]){
            n1=min(i,n1);
            if(i-n1<5)
                t1=max(i,t1);
        }
    }
    
    
    //number2 시작, tail 시작
    for(int i=0;i<file2.length();i++){
        if('0'<=file2[i]&&'9'>=file2[i]){
            n2=min(i,n2);
            if(i-n2<5)
                t2=max(i,t2);
        }
    }
    t1+=1;
    t2+=1;
    // cout<<h1<<" "<<n1<<" "<<t1<<"\n";
    // cout<<h2<<" "<<n2<<" "<<t2<<"\n";
    string head1=file1.substr(0,n1);
    string head2=file2.substr(0,n2);
    string num1=file1.substr(n1,t1-n1);
    string num2=file2.substr(n2,t2-n2);
    
    string tail1,tail2;
    if(t1<file1.length())
        tail1=file1.substr(t1);
    else
        tail1="";
    
    if(t2<file2.length())
        tail2=file2.substr(t2);
    else
        tail2="";
    
    transform(head1.begin(),head1.end(),head1.begin(),::toupper);
    transform(head2.begin(),head2.end(),head2.begin(),::toupper);
    
    if(head1==head2){
        if(stoi(num1)==stoi(num2))
            return false;
        else{
            return stoi(num1)<stoi(num2);
        }
    }
    else
        return head1<head2;
    
}

vector<string> solution(vector<string> files) {
    
    stable_sort(files.begin(),files.end(),compare);
    
    return files;
}