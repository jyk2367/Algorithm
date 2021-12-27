#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> list;
    for(string n: phone_book)
        list[n]=1;
    
    for(string number : phone_book)
        for(int i = 0; i < number.length(); i++)
            if(list.find(number.substr(0,i)) != list.end())
                return false;
    return answer;
}