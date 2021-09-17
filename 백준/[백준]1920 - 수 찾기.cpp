#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v,A;
    int N, M;

    cin >> N;
    while (N--) {
        int num;
        cin >> num;
        A.push_back(num);
    }
    sort(A.begin(), A.end());

    cin >> M;
    while (M--) {
        int num;
        cin >> num;
        int left = 0;
        int right = A.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (A[mid] > num)
                right = mid - 1;
            else if (A[mid] < num)
                left = mid + 1;
            else {
                left = mid;
                break;
            }
        }
        if (A[left] == num)
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }

    
    
}