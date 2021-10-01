#include<iostream>

using namespace std;
int matrix[9] = { 1,1,1,1,1,1,2,1,1};
int cnt[9];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int answer = 1;
    
    for (int i = 0; i < s.length(); i++) {
        int now = s[i] - '0';
        if (now == 9) {
            now = 6;
            cnt[now]++;
        }
        else
            cnt[now]++;
        
        if (cnt[now] > matrix[now]) {
            answer++;
            for (int j = 0; j < 9;j++) {
                if (j == 6) {
                    matrix[j] += 2;
                    continue;
                }
                matrix[j]++;
            }
        }
    }
    
    cout << answer;
}