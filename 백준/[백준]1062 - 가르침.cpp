#include <bits/stdc++.h>

using namespace std;
string word[52];
int num[52];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, answer = 0;
    int fixed = 0, learned = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> word[i];
    }
    
    if (K < 5) {
        answer = 0;
    }
    else {
        string s = "antic";
        for (int i = 0; i < s.length(); i++) {
            fixed |= (1 << ('z' - s[i]));
            learned |= (1 << ('z' - s[i]));
        }
        s = "";

        for (int i = 0; i < N; i++) {
            int WLEN = word[i].length();
            for (int j = 0; j < WLEN; j++) {
                num[i] |= (1 << ('z' - word[i][j]));
                if (!(learned & (1 << ('z' - word[i][j])))) {
                    learned |= (1 << ('z' - word[i][j]));
                    s += word[i][j];
                }
            }
        }

        int SLEN = s.length();
        K -= 5;

        if (SLEN >= K) {

            string perm = "";
            for (int i = 0; i < SLEN-K; i++) {
                perm += "0";
            }
            for (int i = 0; i < K; i++) {
                perm += "1";
            }
            int PLEN = perm.length();
            do {
                int bitmask = fixed;
                int cnt = 0;
                for (int i = 0; i < PLEN; i++) {
                    if (perm[i] == '1')
                        bitmask |= (1 << 'z' - s[i]);
                }
                for (int i = 0; i < N; i++) {
                    if ((bitmask & num[i]) == num[i])
                        cnt++;
                }
                answer = max(answer, cnt);
            } while (next_permutation(perm.begin(), perm.end()));
        }
        else {
            answer = N;
        }
    }
    
    cout << answer << "\n";

  
    return 0;
}