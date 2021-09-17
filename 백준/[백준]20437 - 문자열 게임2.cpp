#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
string W;
int K;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    
    while (T--) {
        cin >> W;
        cin >> K;
        vector<int> v[30];
        int maximum=0,minimum=0x7fffffff;

        if (K == 1) {
            maximum = 1;
            minimum = 1;
        }

        bool state = 0;

        for (int i = 0; i < W.length(); i++) {
            v[W[i] - 'a'].push_back(i);
        }
        
        for (int i = 0; i < 30; i++) {
            if (v[i].size()<K)
                continue;
            int j = 0;
            state = 1;
            while (j + K - 1 < v[i].size()) {
                //cout<< v[i][j] <<" "<< v[i][j + K - 1] << "\n";
                maximum = max(v[i][j + K - 1]- v[i][j] + 1, maximum);
                minimum = min(v[i][j + K - 1]- v[i][j] + 1, minimum);
                j++;
            }
        }
        if (state)
            cout << minimum << " " << maximum << "\n";
        else
            cout << -1 << "\n";

    }
    
}