#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end());
    int booksize=phone_book.size();
    for(int i=0;i<booksize-1;i++){
        if(phone_book[i]==phone_book[i+1].substr(0,phone_book[i].size())){
            answer=false;
            break;
        }
    }
        
        
    return answer;
}