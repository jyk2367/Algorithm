#include <iostream>
#include <vector>

using namespace std;
int answer;
void func(int k,vector<int> &v) {
    while (1) {
        int mul = 1;
        vector<int> zero;
        for (int i = 0; i<v.size(); i++) {
            if (v[i] == 0) {
                zero.push_back(i);
                continue;
            }
            if (v[i] <= -1) {
                k += -1 - v[i];
                v[i] = -1;
            }
            if (v[i] >= 1) {
                k += v[i] - 1;
                v[i] = 1;
            }
            mul *= v[i];
        }
        if (mul==1) {
            for (int i = 0; i < zero.size(); i++) {
                v[zero[i]] = 1;
                k++;
            }
        }
        else if(mul==-1){
            if (!zero.empty()) {
                v[zero[0]] = -1;
                k++;
                for (int i = 1; i < zero.size(); i++) {
                    v[zero[i]] = 1;
                    k++;
                }
            }
            else {
                for (int i = 0; i < v.size(); i++) {
                    if (v[i] == 1) {
                        v[i] = -1;
                        k += 2;
                        break;
                    }
                }
            }
        }

        mul = 1;
        for (int i = 0; i<v.size(); i++) {
            mul *= v[i];
        }

        if (mul == 1) {
            answer = k;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N=0;
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    func(0, v);


    cout << answer;
}