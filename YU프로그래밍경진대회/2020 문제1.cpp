#include <iostream>
#include <string>
using namespace std;
int cnt;
int palin;

bool checkpalin(long long n) {
    string s = to_string(n);
    int D = s.length() / 2;
    string sub1 = s.substr(0, D);
    string sub2 = s.substr(s.length() - D);
    for (int i = 0; i < D; i++) {
        if (sub1[i] != sub2[sub2.length()-1-i])
            return false;
    }
    return true;
}

bool func(long long n) {
    cnt = 0;
    while (1) {
        if (checkpalin(n)) {
            //회문이면
            palin = n;
            return true;
        }
        cnt++;
        string s = to_string(n);
        int NLEN = s.length();

        string rs = "";
        for (int i = NLEN-1; i>=0; i--) {
            rs += s[i];
        }
        long long result =stoll(s) + stoll(rs);
        if (stoll(s)>0x7ffffffe-1-stoll(rs)) {
            return false;
        }
        else
            n = result;
    }
    


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N1, N2;
    cin >> N1 >> N2;

    for (int i = N1; i <= N2; i++) {
        if (func(i))
            cout << i << ": " << cnt << "번만에 회문 " << palin << "를 생성하였습니다.\n";
        else
            cout << i << ": 회문을 만들 수 없습니다.\n";
    }

}